/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "rc.asn1"
 * 	`asn1c -pdu=auto -fno-include-deps -fcompound-names -findirect-choice -gen-PER -gen-OER`
 */

#ifndef	_E2SM_RC_EventTrigger_Format4_H_
#define	_E2SM_RC_EventTrigger_Format4_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include "RIC-EventTriggerCondition-ID.h"
#include "LogicalOR.h"
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2SM_RC_EventTrigger_Format4__uEInfoChange_List__Member__triggerType_PR {
	E2SM_RC_EventTrigger_Format4__uEInfoChange_List__Member__triggerType_PR_NOTHING,	/* No components present */
	E2SM_RC_EventTrigger_Format4__uEInfoChange_List__Member__triggerType_PR_triggerType_Choice_RRCstate,
	E2SM_RC_EventTrigger_Format4__uEInfoChange_List__Member__triggerType_PR_triggerType_Choice_UEID,
	E2SM_RC_EventTrigger_Format4__uEInfoChange_List__Member__triggerType_PR_triggerType_Choice_L2state
	/* Extensions may appear below */
	
} E2SM_RC_EventTrigger_Format4__uEInfoChange_List__Member__triggerType_PR;

/* Forward declarations */
struct EventTrigger_UE_Info;
struct TriggerType_Choice_RRCstate;
struct TriggerType_Choice_UEID;
struct TriggerType_Choice_L2state;

/* Forward definitions */
typedef struct E2SM_RC_EventTrigger_Format4__uEInfoChange_List__Member {
	RIC_EventTriggerCondition_ID_t	 ric_eventTriggerCondition_ID;
	struct E2SM_RC_EventTrigger_Format4__uEInfoChange_List__Member__triggerType {
		E2SM_RC_EventTrigger_Format4__uEInfoChange_List__Member__triggerType_PR present;
		union E2SM_RC_EventTrigger_Format4__uEInfoChange_List__Member__triggerType_u {
			struct TriggerType_Choice_RRCstate	*triggerType_Choice_RRCstate;
			struct TriggerType_Choice_UEID	*triggerType_Choice_UEID;
			struct TriggerType_Choice_L2state	*triggerType_Choice_L2state;
			/*
			 * This type is extensible,
			 * possible extensions are below.
			 */
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} triggerType;
	struct EventTrigger_UE_Info	*associatedUEInfo;	/* OPTIONAL */
	LogicalOR_t	*logicalOR;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_EventTrigger_Format4__uEInfoChange_List__Member;

/* E2SM-RC-EventTrigger-Format4 */
typedef struct E2SM_RC_EventTrigger_Format4 {
	struct E2SM_RC_EventTrigger_Format4__uEInfoChange_List {
		A_SEQUENCE_OF(E2SM_RC_EventTrigger_Format4__uEInfoChange_List__Member) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} uEInfoChange_List;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_EventTrigger_Format4_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_EventTrigger_Format4;
extern asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_EventTrigger_Format4_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_RC_EventTrigger_Format4_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_EventTrigger_Format4_H_ */
#include <asn_internal.h>
