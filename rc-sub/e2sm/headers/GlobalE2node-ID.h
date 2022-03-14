/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-RC"
 * 	found in "e2sm-kpm-rc.asn"
 * 	`asn1c -fcompound-names -fno-include-deps -findirect-choice -pdu=auto -gen-PER -gen-OER -no-gen-example -D .`
 */

#ifndef	_GlobalE2node_ID_H_
#define	_GlobalE2node_ID_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum GlobalE2node_ID_PR {
	GlobalE2node_ID_PR_NOTHING,	/* No components present */
	GlobalE2node_ID_PR_gNB,
	GlobalE2node_ID_PR_en_gNB,
	GlobalE2node_ID_PR_ng_eNB,
	GlobalE2node_ID_PR_eNB
	/* Extensions may appear below */
	
} GlobalE2node_ID_PR;

/* Forward declarations */
struct GlobalE2node_gNB_ID;
struct GlobalE2node_en_gNB_ID;
struct GlobalE2node_ng_eNB_ID;
struct GlobalE2node_eNB_ID;

/* GlobalE2node-ID */
typedef struct GlobalE2node_ID {
	GlobalE2node_ID_PR present;
	union GlobalE2node_ID_u {
		struct GlobalE2node_gNB_ID	*gNB;
		struct GlobalE2node_en_gNB_ID	*en_gNB;
		struct GlobalE2node_ng_eNB_ID	*ng_eNB;
		struct GlobalE2node_eNB_ID	*eNB;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GlobalE2node_ID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GlobalE2node_ID;
extern asn_CHOICE_specifics_t asn_SPC_GlobalE2node_ID_specs_1;
extern asn_TYPE_member_t asn_MBR_GlobalE2node_ID_1[4];
extern asn_per_constraints_t asn_PER_type_GlobalE2node_ID_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _GlobalE2node_ID_H_ */
#include <asn_internal.h>
