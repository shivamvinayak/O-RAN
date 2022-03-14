package control

/*
#include <e2sm/wrapper.h>
#cgo LDFLAGS: -L/usr/local/lib -le2smwrapper -lm
#cgo CFLAGS: -I/usr/local/include/e2sm
*/
import "C"
import (
	"errors"
	"unsafe"
)

type E2sm struct {
}

func (c *E2sm) SetEventTriggerDefinition(buffer []byte, eventTriggerCount int, conditionID int, rrcID int64) (newBuffer []byte, err error) {
	cptr := unsafe.Pointer(&buffer[0])
	size := C.e2sm_encode_ric_event_trigger_definition(cptr, C.size_t(len(buffer)), C.size_t(eventTriggerCount), C.int(conditionID), (C.long)(rrcID))
	if size < 0 {
		return make([]byte, 0), errors.New("e2sm wrapper is unable to set EventTriggerDefinition due to wrong or invalid input")
	}
	newBuffer = C.GoBytes(cptr, (C.int(size)+7)/8)
	return
}

func (c *E2sm) SetActionDefinition(buffer []byte, ricStyleType int64) (newBuffer []byte, err error) {
	cptr := unsafe.Pointer(&buffer[0])
	size := C.e2sm_encode_ric_action_definition(cptr, C.size_t(len(buffer)), C.size_t(ricStyleType))
	if size < 0 {
		return make([]byte, 0), errors.New("e2sm wrapper is unable to set ActionDefinition due to wrong or invalid input")
	}
	newBuffer = C.GoBytes(cptr, (C.int(size)+7)/8)
	return
}
