/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "rc.asn1"
 * 	`asn1c -pdu=auto -fno-include-deps -fcompound-names -findirect-choice -gen-PER -gen-OER`
 */

#ifndef	_RANParameter_Testing_Item_Choice_List_H_
#define	_RANParameter_Testing_Item_Choice_List_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RANParameter_Testing_LIST;

/* RANParameter-Testing-Item-Choice-List */
typedef struct RANParameter_Testing_Item_Choice_List {
	struct RANParameter_Testing_LIST	*ranParameter_List;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANParameter_Testing_Item_Choice_List_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANParameter_Testing_Item_Choice_List;
extern asn_SEQUENCE_specifics_t asn_SPC_RANParameter_Testing_Item_Choice_List_specs_1;
extern asn_TYPE_member_t asn_MBR_RANParameter_Testing_Item_Choice_List_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _RANParameter_Testing_Item_Choice_List_H_ */
#include <asn_internal.h>
