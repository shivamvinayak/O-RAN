/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "rc.asn1"
 * 	`asn1c -pdu=auto -fno-include-deps -fcompound-names -findirect-choice -gen-PER -gen-OER`
 */

#include "RIC-EventTrigger-Cell-ID.h"

/*
 * This type is implemented using NativeInteger,
 * so here we adjust the DEF accordingly.
 */
static const ber_tlv_tag_t asn_DEF_RIC_EventTrigger_Cell_ID_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (2 << 2))
};
asn_TYPE_descriptor_t asn_DEF_RIC_EventTrigger_Cell_ID = {
	"RIC-EventTrigger-Cell-ID",
	"RIC-EventTrigger-Cell-ID",
	&asn_OP_NativeInteger,
	asn_DEF_RIC_EventTrigger_Cell_ID_tags_1,
	sizeof(asn_DEF_RIC_EventTrigger_Cell_ID_tags_1)
		/sizeof(asn_DEF_RIC_EventTrigger_Cell_ID_tags_1[0]), /* 1 */
	asn_DEF_RIC_EventTrigger_Cell_ID_tags_1,	/* Same as above */
	sizeof(asn_DEF_RIC_EventTrigger_Cell_ID_tags_1)
		/sizeof(asn_DEF_RIC_EventTrigger_Cell_ID_tags_1[0]), /* 1 */
	{ 0, 0, NativeInteger_constraint },
	0, 0,	/* No members */
	0	/* No specifics */
};

