/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "rc.asn1"
 * 	`asn1c -pdu=auto -fno-include-deps -fcompound-names -findirect-choice -gen-PER -gen-OER`
 */

#ifndef	_E2SM_RC_EventTrigger_Format1_H_
#define	_E2SM_RC_EventTrigger_Format1_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include "RIC-EventTriggerCondition-ID.h"
#include <NativeEnumerated.h>
#include "LogicalOR.h"
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2SM_RC_EventTrigger_Format1__message_List__Member__messageType_PR {
	E2SM_RC_EventTrigger_Format1__message_List__Member__messageType_PR_NOTHING,	/* No components present */
	E2SM_RC_EventTrigger_Format1__message_List__Member__messageType_PR_messageType_Choice_NI,
	E2SM_RC_EventTrigger_Format1__message_List__Member__messageType_PR_messageType_Choice_RRC
	/* Extensions may appear below */
	
} E2SM_RC_EventTrigger_Format1__message_List__Member__messageType_PR;
typedef enum E2SM_RC_EventTrigger_Format1__message_List__Member__messageDirection {
	E2SM_RC_EventTrigger_Format1__message_List__Member__messageDirection_incoming	= 0,
	E2SM_RC_EventTrigger_Format1__message_List__Member__messageDirection_outgoing	= 1
	/*
	 * Enumeration is extensible
	 */
} e_E2SM_RC_EventTrigger_Format1__message_List__Member__messageDirection;

/* Forward declarations */
struct EventTrigger_UE_Info;
struct EventTrigger_UEevent_Info;
struct MessageType_Choice_NI;
struct MessageType_Choice_RRC;

/* Forward definitions */
typedef struct E2SM_RC_EventTrigger_Format1__message_List__Member {
	RIC_EventTriggerCondition_ID_t	 ric_eventTriggerCondition_ID;
	struct E2SM_RC_EventTrigger_Format1__message_List__Member__messageType {
		E2SM_RC_EventTrigger_Format1__message_List__Member__messageType_PR present;
		union E2SM_RC_EventTrigger_Format1__message_List__Member__messageType_u {
			struct MessageType_Choice_NI	*messageType_Choice_NI;
			struct MessageType_Choice_RRC	*messageType_Choice_RRC;
			/*
			 * This type is extensible,
			 * possible extensions are below.
			 */
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} messageType;
	long	*messageDirection;	/* OPTIONAL */
	struct EventTrigger_UE_Info	*associatedUEInfo;	/* OPTIONAL */
	struct EventTrigger_UEevent_Info	*associatedUEEvent;	/* OPTIONAL */
	LogicalOR_t	*logicalOR;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_EventTrigger_Format1__message_List__Member;

/* E2SM-RC-EventTrigger-Format1 */
typedef struct E2SM_RC_EventTrigger_Format1 {
	struct E2SM_RC_EventTrigger_Format1__message_List {
		A_SEQUENCE_OF(E2SM_RC_EventTrigger_Format1__message_List__Member) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} message_List;
	struct EventTrigger_UE_Info	*globalAssociatedUEInfo;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_EventTrigger_Format1_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_messageDirection_9;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_EventTrigger_Format1;
extern asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_EventTrigger_Format1_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_RC_EventTrigger_Format1_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_EventTrigger_Format1_H_ */
#include <asn_internal.h>