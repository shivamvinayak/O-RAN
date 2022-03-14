/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "e2sm.asn1"
 * 	`asn1c -pdu=auto -fno-include-deps -fcompound-names -findirect-choice -gen-PER -gen-OER`
 */

#ifndef	_InterfaceID_F1_H_
#define	_InterfaceID_F1_H_


#include <asn_application.h>

/* Including external dependencies */
#include "GlobalRANNodeID.h"
#include "GNB-DU-ID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* InterfaceID-F1 */
typedef struct InterfaceID_F1 {
	GlobalRANNodeID_t	 global_NG_RAN_ID;
	GNB_DU_ID_t	 gNB_DU_ID;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} InterfaceID_F1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_InterfaceID_F1;
extern asn_SEQUENCE_specifics_t asn_SPC_InterfaceID_F1_specs_1;
extern asn_TYPE_member_t asn_MBR_InterfaceID_F1_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _InterfaceID_F1_H_ */
#include <asn_internal.h>
