/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "f.asn"
 * 	`asn1c -fcompound-names -fno-include-deps -findirect-choice -pdu=auto -gen-PER -gen-OER -no-gen-example`
 */

#ifndef	_RANFunctionDefinition_Insert_H_
#define	_RANFunctionDefinition_Insert_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include "RIC-Style-Type.h"
#include "RIC-Style-Name.h"
#include "RIC-Format-Type.h"
#include "RIC-InsertIndication-ID.h"
#include "RIC-InsertIndication-Name.h"
#include "RANParameter-ID.h"
#include "RANParameter-Name.h"
#include <constr_SEQUENCE.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward definitions */
typedef struct RANFunctionDefinition_Insert__ric_InsertStyle_List__Member__ric_InsertIndication_List__Member__ran_InsertIndicationParameters_List__Member {
	RANParameter_ID_t	 ranParameter_ID;
	RANParameter_Name_t	 ranParameter_Name;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANFunctionDefinition_Insert__ric_InsertStyle_List__Member__ric_InsertIndication_List__Member__ran_InsertIndicationParameters_List__Member;
typedef struct RANFunctionDefinition_Insert__ric_InsertStyle_List__Member__ric_InsertIndication_List__Member {
	RIC_InsertIndication_ID_t	 ric_InsertIndication_ID;
	RIC_InsertIndication_Name_t	 ric_InsertIndication_Name;
	struct RANFunctionDefinition_Insert__ric_InsertStyle_List__Member__ric_InsertIndication_List__Member__ran_InsertIndicationParameters_List {
		A_SEQUENCE_OF(RANFunctionDefinition_Insert__ric_InsertStyle_List__Member__ric_InsertIndication_List__Member__ran_InsertIndicationParameters_List__Member) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ran_InsertIndicationParameters_List;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANFunctionDefinition_Insert__ric_InsertStyle_List__Member__ric_InsertIndication_List__Member;
typedef struct RANFunctionDefinition_Insert__ric_InsertStyle_List__Member {
	RIC_Style_Type_t	 ric_InsertStyle_Type;
	RIC_Style_Name_t	 ric_InsertStyle_Name;
	RIC_Style_Type_t	 ric_SupportedEventTriggerStyle_Type;
	RIC_Format_Type_t	 ric_ActionDefinitionFormat_Type;
	struct RANFunctionDefinition_Insert__ric_InsertStyle_List__Member__ric_InsertIndication_List {
		A_SEQUENCE_OF(RANFunctionDefinition_Insert__ric_InsertStyle_List__Member__ric_InsertIndication_List__Member) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ric_InsertIndication_List;
	RIC_Format_Type_t	 ric_IndicationHeaderFormat_Type;
	RIC_Format_Type_t	 ric_IndicationMessageFormat_Type;
	RIC_Format_Type_t	 ric_CallProcessIDFormat_Type;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANFunctionDefinition_Insert__ric_InsertStyle_List__Member;

/* RANFunctionDefinition-Insert */
typedef struct RANFunctionDefinition_Insert {
	struct RANFunctionDefinition_Insert__ric_InsertStyle_List {
		A_SEQUENCE_OF(RANFunctionDefinition_Insert__ric_InsertStyle_List__Member) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ric_InsertStyle_List;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANFunctionDefinition_Insert_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANFunctionDefinition_Insert;
extern asn_SEQUENCE_specifics_t asn_SPC_RANFunctionDefinition_Insert_specs_1;
extern asn_TYPE_member_t asn_MBR_RANFunctionDefinition_Insert_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _RANFunctionDefinition_Insert_H_ */
#include <asn_internal.h>
