/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "rc.asn1"
 * 	`asn1c -pdu=auto -fno-include-deps -fcompound-names -findirect-choice -gen-PER -gen-OER`
 */

#include "TriggerType-Choice-UEID.h"

asn_TYPE_member_t asn_MBR_TriggerType_Choice_UEID_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct TriggerType_Choice_UEID, ueIDchange_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ueIDchange-ID"
		},
};
static const ber_tlv_tag_t asn_DEF_TriggerType_Choice_UEID_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_TriggerType_Choice_UEID_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* ueIDchange-ID */
};
asn_SEQUENCE_specifics_t asn_SPC_TriggerType_Choice_UEID_specs_1 = {
	sizeof(struct TriggerType_Choice_UEID),
	offsetof(struct TriggerType_Choice_UEID, _asn_ctx),
	asn_MAP_TriggerType_Choice_UEID_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_TriggerType_Choice_UEID = {
	"TriggerType-Choice-UEID",
	"TriggerType-Choice-UEID",
	&asn_OP_SEQUENCE,
	asn_DEF_TriggerType_Choice_UEID_tags_1,
	sizeof(asn_DEF_TriggerType_Choice_UEID_tags_1)
		/sizeof(asn_DEF_TriggerType_Choice_UEID_tags_1[0]), /* 1 */
	asn_DEF_TriggerType_Choice_UEID_tags_1,	/* Same as above */
	sizeof(asn_DEF_TriggerType_Choice_UEID_tags_1)
		/sizeof(asn_DEF_TriggerType_Choice_UEID_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_TriggerType_Choice_UEID_1,
	1,	/* Elements count */
	&asn_SPC_TriggerType_Choice_UEID_specs_1	/* Additional specs */
};

