package control

import (
	"errors"
	"log"
	"os"
	"strconv"
	"strings"
	"sync"
	"time"
	"gerrit.o-ran-sc.org/r/ric-plt/sdlgo"
	"gerrit.o-ran-sc.org/r/ric-plt/xapp-frame/pkg/xapp"
	//"github.com/go-redis/redis"
)

type Control struct {
	ranList               []string             //nodeB list
	eventCreateExpired    int32                //maximum time for the RIC Subscription Request event creation procedure in the E2 Node
	eventDeleteExpired    int32                //maximum time for the RIC Subscription Request event deletion procedure in the E2 Node
	rcChan                chan *xapp.RMRParams //channel for receiving rmr message
	//client                *redis.Client        //redis client
	eventCreateExpiredMap map[string]bool      //map for recording the RIC Subscription Request event creation procedure is expired or not
	eventDeleteExpiredMap map[string]bool      //map for recording the RIC Subscription Request event deletion procedure is expired or not
	eventCreateExpiredMu  *sync.Mutex          //mutex for eventCreateExpiredMap
	eventDeleteExpiredMu  *sync.Mutex          //mutex for eventDeleteExpiredMap
	sdl                   *sdlgo.SdlInstance
}

func init() {
	file := "/opt/rc-xapp.log"
	logFile, err := os.OpenFile(file, os.O_RDWR|os.O_CREATE|os.O_APPEND, 0766)
	if err != nil {
		panic(err)
	}
	log.SetOutput(logFile)
	log.SetPrefix("[qSkipTool]")
	log.SetFlags(log.LstdFlags | log.Lshortfile | log.LUTC)
	xapp.Logger.SetLevel(4)
}

func NewControl() Control {
	str := os.Getenv("ranList")
	return Control{strings.Split(str, ","),
		5, 5,
		make(chan *xapp.RMRParams),
		make(map[string]bool),
		make(map[string]bool),
		&sync.Mutex{},
		&sync.Mutex{},
		sdlgo.NewSdlInstance("rc-xapp", sdlgo.NewDatabase())}
}

func ReadyCB(i interface{}) {
	c := i.(*Control)

	c.startTimerSubReq()
	go c.controlLoop()
}

func (c *Control) Run() {
	//_, err := c.client.Ping().Result()
	//if err != nil {
	//	xapp.Logger.Error("Failed to connect to Redis DB with %v", err)
	//	log.Printf("Failed to connect to Redis DB with %v", err)
	//}
	if len(c.ranList) > 0 {
		xapp.SetReadyCB(ReadyCB, c)
		xapp.Run(c)
	} else {
		xapp.Logger.Error("gNodeB not set for subscription")
		log.Printf("gNodeB not set for subscription")
	}

}

func (c *Control) startTimerSubReq() {
	timerSR := time.NewTimer(5 * time.Second)
	count := 0

	go func(t *time.Timer) {
		defer timerSR.Stop()
		for {
			<-t.C
			count++
			xapp.Logger.Debug("send RIC_SUB_REQ to gNodeB with cnt=%d", count)
			log.Printf("send RIC_SUB_REQ to gNodeB with cnt=%d", count)
			err := c.sendRicSubRequest(1001, 1001, 0)
			if err != nil && count < MAX_SUBSCRIPTION_ATTEMPTS {
				t.Reset(5 * time.Second)
			} else {
				break
			}
		}
	}(timerSR)
}

func (c *Control) Consume(rp *xapp.RMRParams) (err error) {
	c.rcChan <- rp
	return
}

func (c *Control) rmrSend(params *xapp.RMRParams) (err error) {
	if !xapp.Rmr.Send(params, false) {
		err = errors.New("rmr.Send() failed")
		xapp.Logger.Error("Failed to rmrSend to %v", err)
		log.Printf("Failed to rmrSend to %v", err)
	}
	return
}

func (c *Control) rmrReplyToSender(params *xapp.RMRParams) (err error) {
	if !xapp.Rmr.Send(params, true) {
		err = errors.New("rmr.Send() failed")
		xapp.Logger.Error("Failed to rmrReplyToSender to %v", err)
		log.Printf("Failed to rmrReplyToSender to %v", err)
	}
	return
}

func (c *Control) controlLoop() {
	for {
		msg := <-c.rcChan
		xapp.Logger.Debug("Received message type: %d", msg.Mtype)
		log.Printf("Received message type: %d", msg.Mtype)
		switch msg.Mtype {
		case 12050:
			c.handleIndication(msg)
		case 12011:
			c.handleSubscriptionResponse(msg)
		default:
			err := errors.New("Message Type " + strconv.Itoa(msg.Mtype) + " is discarded")
			xapp.Logger.Error("Unknown message type: %v", err)
			log.Printf("Unknown message type: %v", err)
		}
	}
}

func (c *Control) handleIndication(params *xapp.RMRParams) (err error) {
	//var e2ap *E2ap
	//var e2sm *E2sm

	//Indication to follow
	return
}

func (c *Control) handleSubscriptionResponse(params *xapp.RMRParams) (err error) {
	xapp.Logger.Debug("The SubId in RIC_SUB_RESP is %d", params.SubId)
	log.Printf("The SubId in RIC_SUB_RESP is %d", params.SubId)

	ranName := params.Meid.RanName
	c.eventCreateExpiredMu.Lock()
	_, ok := c.eventCreateExpiredMap[ranName]
	if !ok {
		c.eventCreateExpiredMu.Unlock()
		xapp.Logger.Debug("RIC_SUB_REQ has been deleted!")
		log.Printf("RIC_SUB_REQ has been deleted!")
		return nil
	} else {
		c.eventCreateExpiredMap[ranName] = true
		c.eventCreateExpiredMu.Unlock()
	}

	var cep *E2ap
	subscriptionResp, err := cep.GetSubscriptionResponseMessage(params.Payload)
	if err != nil {
		xapp.Logger.Error("Failed to decode RIC Subscription Response message: %v", err)
		log.Printf("Failed to decode RIC Subscription Response message: %v", err)
		return
	}

	log.Printf("RIC Subscription Response message from {%s} received", params.Meid.RanName)
	log.Printf("SubscriptionID: %d", params.SubId)
	log.Printf("RequestID: %d", subscriptionResp.RequestID)
	log.Printf("RequestSequenceNumber: %d", subscriptionResp.RequestSequenceNumber)
	log.Printf("FunctionID: %d", subscriptionResp.FuncID)

	log.Printf("ActionAdmittedList:")
	for index := 0; index < subscriptionResp.ActionAdmittedList.Count; index++ {
		log.Printf("[%d]ActionID: %d", index, subscriptionResp.ActionAdmittedList.ActionID[index])
	}

	log.Printf("ActionNotAdmittedList:")
	for index := 0; index < subscriptionResp.ActionNotAdmittedList.Count; index++ {
		log.Printf("[%d]ActionID: %d", index, subscriptionResp.ActionNotAdmittedList.ActionID[index])
		log.Printf("[%d]CauseType: %d CauseID: %d", index, subscriptionResp.ActionNotAdmittedList.Cause[index].CauseType, subscriptionResp.ActionNotAdmittedList.Cause[index].CauseID)
	}

	return nil
}

func (c *Control) setEventCreateExpiredTimer(ranName string) {
	c.eventCreateExpiredMu.Lock()
	c.eventCreateExpiredMap[ranName] = false
	c.eventCreateExpiredMu.Unlock()

	timer := time.NewTimer(time.Duration(c.eventCreateExpired) * time.Second)
	go func(t *time.Timer) {
		defer t.Stop()
		xapp.Logger.Debug("RIC_SUB_REQ[%s]: Waiting for RIC_SUB_RESP...", ranName)
		log.Printf("RIC_SUB_REQ[%s]: Waiting for RIC_SUB_RESP...", ranName)
		for {
			select {
			case <-t.C:
				c.eventCreateExpiredMu.Lock()
				isResponsed := c.eventCreateExpiredMap[ranName]
				delete(c.eventCreateExpiredMap, ranName)
				c.eventCreateExpiredMu.Unlock()
				if !isResponsed {
					xapp.Logger.Debug("RIC_SUB_REQ[%s]: RIC Event Create Timer experied!", ranName)
					log.Printf("RIC_SUB_REQ[%s]: RIC Event Create Timer experied!", ranName)
					// c.sendRicSubDelRequest(subID, requestSN, funcID)
					return
				}
			default:
				c.eventCreateExpiredMu.Lock()
				flag := c.eventCreateExpiredMap[ranName]
				if flag {
					delete(c.eventCreateExpiredMap, ranName)
					c.eventCreateExpiredMu.Unlock()
					xapp.Logger.Debug("RIC_SUB_REQ[%s]: RIC Event Create Timer canceled!", ranName)
					log.Printf("RIC_SUB_REQ[%s]: RIC Event Create Timer canceled!", ranName)
					return
				} else {
					c.eventCreateExpiredMu.Unlock()
				}
			}
			time.Sleep(100 * time.Millisecond)
		}
	}(timer)
}

func (c *Control) setEventDeleteExpiredTimer(ranName string) {
	c.eventDeleteExpiredMu.Lock()
	c.eventDeleteExpiredMap[ranName] = false
	c.eventDeleteExpiredMu.Unlock()

	timer := time.NewTimer(time.Duration(c.eventDeleteExpired) * time.Second)
	go func(t *time.Timer) {
		defer t.Stop()
		xapp.Logger.Debug("RIC_SUB_DEL_REQ[%s]: Waiting for RIC_SUB_DEL_RESP...", ranName)
		log.Printf("RIC_SUB_DEL_REQ[%s]: Waiting for RIC_SUB_DEL_RESP...", ranName)
		for {
			select {
			case <-t.C:
				c.eventDeleteExpiredMu.Lock()
				isResponsed := c.eventDeleteExpiredMap[ranName]
				delete(c.eventDeleteExpiredMap, ranName)
				c.eventDeleteExpiredMu.Unlock()
				if !isResponsed {
					xapp.Logger.Debug("RIC_SUB_DEL_REQ[%s]: RIC Event Delete Timer experied!", ranName)
					log.Printf("RIC_SUB_DEL_REQ[%s]: RIC Event Delete Timer experied!", ranName)
					return
				}
			default:
				c.eventDeleteExpiredMu.Lock()
				flag := c.eventDeleteExpiredMap[ranName]
				if flag {
					delete(c.eventDeleteExpiredMap, ranName)
					c.eventDeleteExpiredMu.Unlock()
					xapp.Logger.Debug("RIC_SUB_DEL_REQ[%s]: RIC Event Delete Timer canceled!", ranName)
					log.Printf("RIC_SUB_DEL_REQ[%s]: RIC Event Delete Timer canceled!", ranName)
					return
				} else {
					c.eventDeleteExpiredMu.Unlock()
				}
			}
			time.Sleep(100 * time.Millisecond)
		}
	}(timer)
}

func (c *Control) sendRicSubRequest(subID int, requestSN int, funcID int) (err error) {
	var e2ap *E2ap
	var e2sm *E2sm

	var eventTriggerCount int = 1
	var eventTriggerConditionID int = 12
	var rrcID int64 = 1
	var eventTriggerDefinition []byte = make([]byte,1024)
	_, err = e2sm.SetEventTriggerDefinition(eventTriggerDefinition, eventTriggerCount, eventTriggerConditionID, rrcID)
	if err != nil {
		xapp.Logger.Error("Failed to send RIC_SUB_REQ: %v", err)
		log.Printf("Failed to send RIC_SUB_REQ: %v", err)
		return err
	}
	log.Printf("Set EventTriggerDefinition: %x", eventTriggerDefinition)

	var actionCount int = 1
	var ricStyleType int64 = 1
	var actionIds []int64 = []int64{0}
	var actionTypes []int64 = []int64{0}
	var actionDefinitions []ActionDefinition = make([]ActionDefinition, actionCount)
	var subsequentActions []SubsequentAction = []SubsequentAction{SubsequentAction{0, 0, 0}}

	for index := 0; index < actionCount; index++ {
		if ricStyleType == 0 {
			actionDefinitions[index].Buf = nil
			actionDefinitions[index].Size = 0
		} else {
			actionDefinitions[index].Buf = make([]byte, 1024)
			_, err = e2sm.SetActionDefinition(actionDefinitions[index].Buf, ricStyleType)
			if err != nil {
				xapp.Logger.Error("Failed to send RIC_SUB_REQ: %v", err)
				log.Printf("Failed to send RIC_SUB_REQ: %v", err)
				return err
			}
			actionDefinitions[index].Size = len(actionDefinitions[index].Buf)

			log.Printf("Set ActionDefinition[%d]: %x", index, actionDefinitions[index].Buf)
		}
	}

	for index := 0; index < 1; index++ { 
		//len(c.ranList)
		params := &xapp.RMRParams{}
		params.Mtype = 12010
		params.SubId = subID

		//xapp.Logger.Debug("Send RIC_SUB_REQ to {%s}", c.ranList[index])
		//log.Printf("Send RIC_SUB_REQ to {%s}", c.ranList[index])

		params.Payload = make([]byte, 1024)
		params.Payload, err = e2ap.SetSubscriptionRequestPayload(params.Payload, 1001, uint16(requestSN), uint16(funcID), eventTriggerDefinition, len(eventTriggerDefinition), actionCount, actionIds, actionTypes, actionDefinitions, subsequentActions)
		if err != nil {
			xapp.Logger.Error("Failed to send RIC_SUB_REQ: %v", err)
			log.Printf("Failed to send RIC_SUB_REQ: %v", err)
			return err
		}

		log.Printf("Set Payload: %x", params.Payload)

		//params.Meid = &xapp.RMRMeid{RanName: c.ranList[index]}
		params.Meid = &xapp.RMRMeid{PlmnID: "373437", EnbID: "10110101110001100111011110001", RanName: "gnb_734_733_b5c67788"}
		xapp.Logger.Debug("The RMR message to be sent is %d with SubId=%d", params.Mtype, params.SubId)
		log.Printf("The RMR message to be sent is %d with SubId=%d", params.Mtype, params.SubId)

		err = c.rmrSend(params)
		if err != nil {
			xapp.Logger.Error("Failed to send RIC_SUB_REQ: %v", err)
			log.Printf("Failed to send RIC_SUB_REQ: %v", err)
			return err
		}

		c.setEventCreateExpiredTimer(params.Meid.RanName)
	}

	return nil
}

