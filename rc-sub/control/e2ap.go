package control

/*
#include <stdlib.h>
#include <e2ap/wrapper.h>
#cgo LDFLAGS: -L/usr/local/lib -le2apwrapper
#cgo CFLAGS: -I/usr/local/include/e2ap
*/
import "C"

import (
	"errors"
	"unsafe"
)

type E2ap struct {
}

func (c *E2ap) SetSubscriptionRequestPayload(payload []byte, ricRequestorID uint16, ricRequestSequenceNumber uint16, ranFunctionID uint16, eventTriggerDefinition []byte, eventTriggerDefinitionSize int, actionCount int, actionIds []int64, actionTypes []int64, actionDefinitions []ActionDefinition, subsequentActions []SubsequentAction) (newPayload []byte, err error) {
	cptr := unsafe.Pointer(&payload[0])
	eventTrigger := unsafe.Pointer(&eventTriggerDefinition[0])
	actIds := unsafe.Pointer(&actionIds[0])
	actTypes := unsafe.Pointer(&actionTypes[0])

	count := len(actionDefinitions)
	actDefs := (*C.RICactionDefinition)(C.calloc(C.size_t(len(actionDefinitions)), C.sizeof_RICactionDefinition))
	for index := 0; index < count; index++ {
		ptr := *(*C.RICactionDefinition)(unsafe.Pointer((uintptr)(unsafe.Pointer(actDefs)) + (uintptr)(C.sizeof_RICactionDefinition*C.int(index))))
		ptr.size = C.int(actionDefinitions[index].Size)
		if ptr.size != 0 {
			ptr.actionDefinition = (*C.uint8_t)(C.CBytes(actionDefinitions[index].Buf))
		}
	}
	defer C.free(unsafe.Pointer(actDefs))

	count = len(subsequentActions)
	subActs := (*C.RICSubsequentAction)(C.calloc(C.size_t(len(subsequentActions)), C.sizeof_RICSubsequentAction))
	for index := 0; index < count; index++ {
		ptr := *(*C.RICSubsequentAction)(unsafe.Pointer((uintptr)(unsafe.Pointer(subActs)) + (uintptr)(C.sizeof_RICSubsequentAction*C.int(index))))
		ptr.isValid = C.int(subsequentActions[index].IsValid)
		ptr.subsequentActionType = C.long(subsequentActions[index].SubsequentActionType)
		ptr.timeToWait = C.long(subsequentActions[index].TimeToWait)
	}
	defer C.free(unsafe.Pointer(subActs))

	size := C.e2ap_encode_ric_subscription_request_message(cptr, C.size_t(len(payload)), C.long(ricRequestorID), C.long(ricRequestSequenceNumber), C.long(ranFunctionID), eventTrigger, C.size_t(eventTriggerDefinitionSize), C.int(actionCount), (*C.long)(actIds), (*C.long)(actTypes), actDefs, subActs)
	if size < 0 {
		return make([]byte, 0), errors.New("e2ap wrapper is unable to set Subscription Request Payload due to wrong or invalid payload")
	}
	newPayload = C.GoBytes(cptr, (C.int(size)+7)/8)
	return
}

func (c *E2ap) GetSubscriptionResponseMessage(payload []byte) (decodedMsg *DecodedSubscriptionResponseMessage, err error) {
        cptr := unsafe.Pointer(&payload[0])
        decodedMsg = &DecodedSubscriptionResponseMessage{}
        decodedCMsg := C.e2ap_decode_ric_subscription_response_message(cptr, C.size_t(len(payload)))
        defer C.free(unsafe.Pointer(decodedCMsg))

        if decodedCMsg == nil {
                return decodedMsg, errors.New("e2ap wrapper is unable to decode subscription response message due to wrong or invalid payload")
        }

        decodedMsg.RequestID = int32(decodedCMsg.requestorID)
        decodedMsg.RequestSequenceNumber = int32(decodedCMsg.requestSequenceNumber)
        decodedMsg.FuncID = int32(decodedCMsg.ranfunctionID)

        admittedCount := int(decodedCMsg.ricActionAdmittedList.count)
        for index := 0; index < admittedCount; index++ {
                decodedMsg.ActionAdmittedList.ActionID[index] = int32(decodedCMsg.ricActionAdmittedList.ricActionID[index])
        }
        decodedMsg.ActionAdmittedList.Count = admittedCount

        notAdmittedCount := int(decodedCMsg.ricActionNotAdmittedList.count)
        for index := 0; index < notAdmittedCount; index++ {
                decodedMsg.ActionNotAdmittedList.ActionID[index] = int32(decodedCMsg.ricActionNotAdmittedList.ricActionID[index])
                decodedMsg.ActionNotAdmittedList.Cause[index].CauseType = int32(decodedCMsg.ricActionNotAdmittedList.ricCause[index].ricCauseType)
                decodedMsg.ActionNotAdmittedList.Cause[index].CauseID = int32(decodedCMsg.ricActionNotAdmittedList.ricCause[index].ricCauseID)
        }
        decodedMsg.ActionNotAdmittedList.Count = notAdmittedCount

        return
}
