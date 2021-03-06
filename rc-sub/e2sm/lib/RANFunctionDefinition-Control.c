/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "rc.asn1"
 * 	`asn1c -pdu=auto -fno-include-deps -fcompound-names -findirect-choice -gen-PER -gen-OER`
 */

#include "RANFunctionDefinition-Control.h"

static int
memb_ran_ControlActionParameters_List_constraint_7(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 65535)) {
		/* Perform validation of the inner elements */
		return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_ric_ControlAction_List_constraint_3(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 65535)) {
		/* Perform validation of the inner elements */
		return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_ran_ControlOutcomeParameters_List_constraint_3(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 255)) {
		/* Perform validation of the inner elements */
		return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_ric_ControlStyle_List_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 63)) {
		/* Perform validation of the inner elements */
		return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_type_ran_ControlActionParameters_List_constr_10 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..65535)) */};
static asn_per_constraints_t asn_PER_type_ran_ControlActionParameters_List_constr_10 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 16,  16,  1,  65535 }	/* (SIZE(1..65535)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_ran_ControlActionParameters_List_constr_10 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..65535)) */};
static asn_per_constraints_t asn_PER_memb_ran_ControlActionParameters_List_constr_10 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 16,  16,  1,  65535 }	/* (SIZE(1..65535)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_ric_ControlAction_List_constr_6 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..65535)) */};
static asn_per_constraints_t asn_PER_type_ric_ControlAction_List_constr_6 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 16,  16,  1,  65535 }	/* (SIZE(1..65535)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_ran_ControlOutcomeParameters_List_constr_20 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..255)) */};
static asn_per_constraints_t asn_PER_type_ran_ControlOutcomeParameters_List_constr_20 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 8,  8,  1,  255 }	/* (SIZE(1..255)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_ric_ControlAction_List_constr_6 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..65535)) */};
static asn_per_constraints_t asn_PER_memb_ric_ControlAction_List_constr_6 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 16,  16,  1,  65535 }	/* (SIZE(1..65535)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_ran_ControlOutcomeParameters_List_constr_20 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..255)) */};
static asn_per_constraints_t asn_PER_memb_ran_ControlOutcomeParameters_List_constr_20 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 8,  8,  1,  255 }	/* (SIZE(1..255)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_ric_ControlStyle_List_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..63)) */};
static asn_per_constraints_t asn_PER_type_ric_ControlStyle_List_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 6,  6,  1,  63 }	/* (SIZE(1..63)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_ric_ControlStyle_List_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..63)) */};
static asn_per_constraints_t asn_PER_memb_ric_ControlStyle_List_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 6,  6,  1,  63 }	/* (SIZE(1..63)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_Member_11[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ric_ControlAction_List__Member__ran_ControlActionParameters_List__Member, ranParameter_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANParameter_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ranParameter-ID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ric_ControlAction_List__Member__ran_ControlActionParameters_List__Member, ranParameter_Name),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANParameter_Name,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ranParameter-Name"
		},
};
static const ber_tlv_tag_t asn_DEF_Member_tags_11[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Member_tag2el_11[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ranParameter-ID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* ranParameter-Name */
};
static asn_SEQUENCE_specifics_t asn_SPC_Member_specs_11 = {
	sizeof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ric_ControlAction_List__Member__ran_ControlActionParameters_List__Member),
	offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ric_ControlAction_List__Member__ran_ControlActionParameters_List__Member, _asn_ctx),
	asn_MAP_Member_tag2el_11,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_Member_11 = {
	"SEQUENCE",
	"SEQUENCE",
	&asn_OP_SEQUENCE,
	asn_DEF_Member_tags_11,
	sizeof(asn_DEF_Member_tags_11)
		/sizeof(asn_DEF_Member_tags_11[0]), /* 1 */
	asn_DEF_Member_tags_11,	/* Same as above */
	sizeof(asn_DEF_Member_tags_11)
		/sizeof(asn_DEF_Member_tags_11[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_Member_11,
	2,	/* Elements count */
	&asn_SPC_Member_specs_11	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ran_ControlActionParameters_List_10[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_Member_11,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_ran_ControlActionParameters_List_tags_10[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_ran_ControlActionParameters_List_specs_10 = {
	sizeof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ric_ControlAction_List__Member__ran_ControlActionParameters_List),
	offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ric_ControlAction_List__Member__ran_ControlActionParameters_List, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ran_ControlActionParameters_List_10 = {
	"ran-ControlActionParameters-List",
	"ran-ControlActionParameters-List",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_ran_ControlActionParameters_List_tags_10,
	sizeof(asn_DEF_ran_ControlActionParameters_List_tags_10)
		/sizeof(asn_DEF_ran_ControlActionParameters_List_tags_10[0]) - 1, /* 1 */
	asn_DEF_ran_ControlActionParameters_List_tags_10,	/* Same as above */
	sizeof(asn_DEF_ran_ControlActionParameters_List_tags_10)
		/sizeof(asn_DEF_ran_ControlActionParameters_List_tags_10[0]), /* 2 */
	{ &asn_OER_type_ran_ControlActionParameters_List_constr_10, &asn_PER_type_ran_ControlActionParameters_List_constr_10, SEQUENCE_OF_constraint },
	asn_MBR_ran_ControlActionParameters_List_10,
	1,	/* Single element */
	&asn_SPC_ran_ControlActionParameters_List_specs_10	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_Member_7[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ric_ControlAction_List__Member, ric_ControlAction_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RIC_ControlAction_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-ControlAction-ID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ric_ControlAction_List__Member, ric_ControlAction_Name),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RIC_ControlAction_Name,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-ControlAction-Name"
		},
	{ ATF_POINTER, 1, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ric_ControlAction_List__Member, ran_ControlActionParameters_List),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		0,
		&asn_DEF_ran_ControlActionParameters_List_10,
		0,
		{ &asn_OER_memb_ran_ControlActionParameters_List_constr_10, &asn_PER_memb_ran_ControlActionParameters_List_constr_10,  memb_ran_ControlActionParameters_List_constraint_7 },
		0, 0, /* No default value */
		"ran-ControlActionParameters-List"
		},
};
static const int asn_MAP_Member_oms_7[] = { 2 };
static const ber_tlv_tag_t asn_DEF_Member_tags_7[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Member_tag2el_7[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ric-ControlAction-ID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ric-ControlAction-Name */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* ran-ControlActionParameters-List */
};
static asn_SEQUENCE_specifics_t asn_SPC_Member_specs_7 = {
	sizeof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ric_ControlAction_List__Member),
	offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ric_ControlAction_List__Member, _asn_ctx),
	asn_MAP_Member_tag2el_7,
	3,	/* Count of tags in the map */
	asn_MAP_Member_oms_7,	/* Optional members */
	1, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_Member_7 = {
	"SEQUENCE",
	"SEQUENCE",
	&asn_OP_SEQUENCE,
	asn_DEF_Member_tags_7,
	sizeof(asn_DEF_Member_tags_7)
		/sizeof(asn_DEF_Member_tags_7[0]), /* 1 */
	asn_DEF_Member_tags_7,	/* Same as above */
	sizeof(asn_DEF_Member_tags_7)
		/sizeof(asn_DEF_Member_tags_7[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_Member_7,
	3,	/* Elements count */
	&asn_SPC_Member_specs_7	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ric_ControlAction_List_6[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_Member_7,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_ric_ControlAction_List_tags_6[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_ric_ControlAction_List_specs_6 = {
	sizeof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ric_ControlAction_List),
	offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ric_ControlAction_List, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ric_ControlAction_List_6 = {
	"ric-ControlAction-List",
	"ric-ControlAction-List",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_ric_ControlAction_List_tags_6,
	sizeof(asn_DEF_ric_ControlAction_List_tags_6)
		/sizeof(asn_DEF_ric_ControlAction_List_tags_6[0]) - 1, /* 1 */
	asn_DEF_ric_ControlAction_List_tags_6,	/* Same as above */
	sizeof(asn_DEF_ric_ControlAction_List_tags_6)
		/sizeof(asn_DEF_ric_ControlAction_List_tags_6[0]), /* 2 */
	{ &asn_OER_type_ric_ControlAction_List_constr_6, &asn_PER_type_ric_ControlAction_List_constr_6, SEQUENCE_OF_constraint },
	asn_MBR_ric_ControlAction_List_6,
	1,	/* Single element */
	&asn_SPC_ric_ControlAction_List_specs_6	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_Member_21[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ran_ControlOutcomeParameters_List__Member, ranParameter_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANParameter_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ranParameter-ID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ran_ControlOutcomeParameters_List__Member, ranParameter_Name),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANParameter_Name,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ranParameter-Name"
		},
};
static const ber_tlv_tag_t asn_DEF_Member_tags_21[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Member_tag2el_21[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ranParameter-ID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* ranParameter-Name */
};
static asn_SEQUENCE_specifics_t asn_SPC_Member_specs_21 = {
	sizeof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ran_ControlOutcomeParameters_List__Member),
	offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ran_ControlOutcomeParameters_List__Member, _asn_ctx),
	asn_MAP_Member_tag2el_21,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_Member_21 = {
	"SEQUENCE",
	"SEQUENCE",
	&asn_OP_SEQUENCE,
	asn_DEF_Member_tags_21,
	sizeof(asn_DEF_Member_tags_21)
		/sizeof(asn_DEF_Member_tags_21[0]), /* 1 */
	asn_DEF_Member_tags_21,	/* Same as above */
	sizeof(asn_DEF_Member_tags_21)
		/sizeof(asn_DEF_Member_tags_21[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_Member_21,
	2,	/* Elements count */
	&asn_SPC_Member_specs_21	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ran_ControlOutcomeParameters_List_20[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_Member_21,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_ran_ControlOutcomeParameters_List_tags_20[] = {
	(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_ran_ControlOutcomeParameters_List_specs_20 = {
	sizeof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ran_ControlOutcomeParameters_List),
	offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member__ran_ControlOutcomeParameters_List, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ran_ControlOutcomeParameters_List_20 = {
	"ran-ControlOutcomeParameters-List",
	"ran-ControlOutcomeParameters-List",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_ran_ControlOutcomeParameters_List_tags_20,
	sizeof(asn_DEF_ran_ControlOutcomeParameters_List_tags_20)
		/sizeof(asn_DEF_ran_ControlOutcomeParameters_List_tags_20[0]) - 1, /* 1 */
	asn_DEF_ran_ControlOutcomeParameters_List_tags_20,	/* Same as above */
	sizeof(asn_DEF_ran_ControlOutcomeParameters_List_tags_20)
		/sizeof(asn_DEF_ran_ControlOutcomeParameters_List_tags_20[0]), /* 2 */
	{ &asn_OER_type_ran_ControlOutcomeParameters_List_constr_20, &asn_PER_type_ran_ControlOutcomeParameters_List_constr_20, SEQUENCE_OF_constraint },
	asn_MBR_ran_ControlOutcomeParameters_List_20,
	1,	/* Single element */
	&asn_SPC_ran_ControlOutcomeParameters_List_specs_20	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_Member_3[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member, ric_ControlStyle_Type),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RIC_Style_Type,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-ControlStyle-Type"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member, ric_ControlStyle_Name),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RIC_Style_Name,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-ControlStyle-Name"
		},
	{ ATF_POINTER, 1, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member, ric_ControlAction_List),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		0,
		&asn_DEF_ric_ControlAction_List_6,
		0,
		{ &asn_OER_memb_ric_ControlAction_List_constr_6, &asn_PER_memb_ric_ControlAction_List_constr_6,  memb_ric_ControlAction_List_constraint_3 },
		0, 0, /* No default value */
		"ric-ControlAction-List"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member, ric_ControlHeaderFormat_Type),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RIC_Format_Type,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-ControlHeaderFormat-Type"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member, ric_ControlMessageFormat_Type),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RIC_Format_Type,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-ControlMessageFormat-Type"
		},
	{ ATF_POINTER, 1, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member, ric_CallProcessIDFormat_Type),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RIC_Format_Type,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-CallProcessIDFormat-Type"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member, ric_ControlOutcomeFormat_Type),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RIC_Format_Type,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-ControlOutcomeFormat-Type"
		},
	{ ATF_POINTER, 1, offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member, ran_ControlOutcomeParameters_List),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		0,
		&asn_DEF_ran_ControlOutcomeParameters_List_20,
		0,
		{ &asn_OER_memb_ran_ControlOutcomeParameters_List_constr_20, &asn_PER_memb_ran_ControlOutcomeParameters_List_constr_20,  memb_ran_ControlOutcomeParameters_List_constraint_3 },
		0, 0, /* No default value */
		"ran-ControlOutcomeParameters-List"
		},
};
static const int asn_MAP_Member_oms_3[] = { 2, 5, 7 };
static const ber_tlv_tag_t asn_DEF_Member_tags_3[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Member_tag2el_3[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ric-ControlStyle-Type */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ric-ControlStyle-Name */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* ric-ControlAction-List */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* ric-ControlHeaderFormat-Type */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* ric-ControlMessageFormat-Type */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* ric-CallProcessIDFormat-Type */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* ric-ControlOutcomeFormat-Type */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 } /* ran-ControlOutcomeParameters-List */
};
static asn_SEQUENCE_specifics_t asn_SPC_Member_specs_3 = {
	sizeof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member),
	offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List__Member, _asn_ctx),
	asn_MAP_Member_tag2el_3,
	8,	/* Count of tags in the map */
	asn_MAP_Member_oms_3,	/* Optional members */
	3, 0,	/* Root/Additions */
	8,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_Member_3 = {
	"SEQUENCE",
	"SEQUENCE",
	&asn_OP_SEQUENCE,
	asn_DEF_Member_tags_3,
	sizeof(asn_DEF_Member_tags_3)
		/sizeof(asn_DEF_Member_tags_3[0]), /* 1 */
	asn_DEF_Member_tags_3,	/* Same as above */
	sizeof(asn_DEF_Member_tags_3)
		/sizeof(asn_DEF_Member_tags_3[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_Member_3,
	8,	/* Elements count */
	&asn_SPC_Member_specs_3	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ric_ControlStyle_List_2[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_Member_3,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_ric_ControlStyle_List_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_ric_ControlStyle_List_specs_2 = {
	sizeof(struct RANFunctionDefinition_Control__ric_ControlStyle_List),
	offsetof(struct RANFunctionDefinition_Control__ric_ControlStyle_List, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ric_ControlStyle_List_2 = {
	"ric-ControlStyle-List",
	"ric-ControlStyle-List",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_ric_ControlStyle_List_tags_2,
	sizeof(asn_DEF_ric_ControlStyle_List_tags_2)
		/sizeof(asn_DEF_ric_ControlStyle_List_tags_2[0]) - 1, /* 1 */
	asn_DEF_ric_ControlStyle_List_tags_2,	/* Same as above */
	sizeof(asn_DEF_ric_ControlStyle_List_tags_2)
		/sizeof(asn_DEF_ric_ControlStyle_List_tags_2[0]), /* 2 */
	{ &asn_OER_type_ric_ControlStyle_List_constr_2, &asn_PER_type_ric_ControlStyle_List_constr_2, SEQUENCE_OF_constraint },
	asn_MBR_ric_ControlStyle_List_2,
	1,	/* Single element */
	&asn_SPC_ric_ControlStyle_List_specs_2	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_RANFunctionDefinition_Control_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RANFunctionDefinition_Control, ric_ControlStyle_List),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_ric_ControlStyle_List_2,
		0,
		{ &asn_OER_memb_ric_ControlStyle_List_constr_2, &asn_PER_memb_ric_ControlStyle_List_constr_2,  memb_ric_ControlStyle_List_constraint_1 },
		0, 0, /* No default value */
		"ric-ControlStyle-List"
		},
};
static const ber_tlv_tag_t asn_DEF_RANFunctionDefinition_Control_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RANFunctionDefinition_Control_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* ric-ControlStyle-List */
};
asn_SEQUENCE_specifics_t asn_SPC_RANFunctionDefinition_Control_specs_1 = {
	sizeof(struct RANFunctionDefinition_Control),
	offsetof(struct RANFunctionDefinition_Control, _asn_ctx),
	asn_MAP_RANFunctionDefinition_Control_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_RANFunctionDefinition_Control = {
	"RANFunctionDefinition-Control",
	"RANFunctionDefinition-Control",
	&asn_OP_SEQUENCE,
	asn_DEF_RANFunctionDefinition_Control_tags_1,
	sizeof(asn_DEF_RANFunctionDefinition_Control_tags_1)
		/sizeof(asn_DEF_RANFunctionDefinition_Control_tags_1[0]), /* 1 */
	asn_DEF_RANFunctionDefinition_Control_tags_1,	/* Same as above */
	sizeof(asn_DEF_RANFunctionDefinition_Control_tags_1)
		/sizeof(asn_DEF_RANFunctionDefinition_Control_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_RANFunctionDefinition_Control_1,
	1,	/* Elements count */
	&asn_SPC_RANFunctionDefinition_Control_specs_1	/* Additional specs */
};

