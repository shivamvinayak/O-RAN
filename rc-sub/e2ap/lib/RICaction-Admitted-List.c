/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "E2AP-PDU-Contents-v01.00.asn"
 * 	`asn1c -pdu=auto -fno-include-deps -fcompound-names -findirect-choice -gen-PER -gen-OER -no-gen-example`
 */

#include "RICaction-Admitted-List.h"

#include "ProtocolIE-SingleContainer.h"
static asn_oer_constraints_t asn_OER_type_RICaction_Admitted_List_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..16)) */};
asn_per_constraints_t asn_PER_type_RICaction_Admitted_List_constr_1 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 4,  4,  1,  16 }	/* (SIZE(1..16)) */,
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_RICaction_Admitted_List_1[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_ProtocolIE_SingleContainer_90P1,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_RICaction_Admitted_List_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_SET_OF_specifics_t asn_SPC_RICaction_Admitted_List_specs_1 = {
	sizeof(struct RICaction_Admitted_List),
	offsetof(struct RICaction_Admitted_List, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
asn_TYPE_descriptor_t asn_DEF_RICaction_Admitted_List = {
	"RICaction-Admitted-List",
	"RICaction-Admitted-List",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_RICaction_Admitted_List_tags_1,
	sizeof(asn_DEF_RICaction_Admitted_List_tags_1)
		/sizeof(asn_DEF_RICaction_Admitted_List_tags_1[0]), /* 1 */
	asn_DEF_RICaction_Admitted_List_tags_1,	/* Same as above */
	sizeof(asn_DEF_RICaction_Admitted_List_tags_1)
		/sizeof(asn_DEF_RICaction_Admitted_List_tags_1[0]), /* 1 */
	{ &asn_OER_type_RICaction_Admitted_List_constr_1, &asn_PER_type_RICaction_Admitted_List_constr_1, SEQUENCE_OF_constraint },
	asn_MBR_RICaction_Admitted_List_1,
	1,	/* Single element */
	&asn_SPC_RICaction_Admitted_List_specs_1	/* Additional specs */
};

