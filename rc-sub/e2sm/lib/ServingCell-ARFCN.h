/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "e2sm.asn1"
 * 	`asn1c -pdu=auto -fno-include-deps -fcompound-names -findirect-choice -gen-PER -gen-OER`
 */

#ifndef	_ServingCell_ARFCN_H_
#define	_ServingCell_ARFCN_H_


#include <asn_application.h>

/* Including external dependencies */
#include "E-UTRA-ARFCN.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ServingCell_ARFCN_PR {
	ServingCell_ARFCN_PR_NOTHING,	/* No components present */
	ServingCell_ARFCN_PR_nR,
	ServingCell_ARFCN_PR_eUTRA
	/* Extensions may appear below */
	
} ServingCell_ARFCN_PR;

/* Forward declarations */
struct NR_ARFCN;

/* ServingCell-ARFCN */
typedef struct ServingCell_ARFCN {
	ServingCell_ARFCN_PR present;
	union ServingCell_ARFCN_u {
		struct NR_ARFCN	*nR;
		E_UTRA_ARFCN_t	 eUTRA;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ServingCell_ARFCN_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ServingCell_ARFCN;
extern asn_CHOICE_specifics_t asn_SPC_ServingCell_ARFCN_specs_1;
extern asn_TYPE_member_t asn_MBR_ServingCell_ARFCN_1[2];
extern asn_per_constraints_t asn_PER_type_ServingCell_ARFCN_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _ServingCell_ARFCN_H_ */
#include <asn_internal.h>
