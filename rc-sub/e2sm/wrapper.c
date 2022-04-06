#include <errno.h>
#include "wrapper.h"
typedef OCTET_STRING_t	 RICactionDefinition_t;
typedef struct RICSubsequentAction {
        int isValid;
        long subsequentActionType;
        long timeToWait;
} RICSubsequentAction;

ssize_t e2sm_encode_ric_event_trigger_definition(void *buffer, size_t buf_size, 
        size_t event_trigger_count, int triggerConditionID, long rrc_id) 
{
    E2SM_RC_EventTrigger_t *eventTriggerDef = (E2SM_RC_EventTrigger_t *)calloc(1, sizeof(E2SM_RC_EventTrigger_t));
    if(!eventTriggerDef) {
        fprintf(stderr, "alloc EventTriggerDefinition failed\n");
        return -1;
    }

    E2SM_RC_EventTrigger_Format1_t *innerDef = (E2SM_RC_EventTrigger_Format1_t *)calloc(1, sizeof(E2SM_RC_EventTrigger_Format1_t));
    if(!innerDef) {
        fprintf(stderr, "alloc EventTriggerDefinition Format1 failed\n");
        ASN_STRUCT_FREE(asn_DEF_E2SM_RC_EventTrigger, eventTriggerDef);
        return -1;
    }

    eventTriggerDef->ric_eventTrigger_formats.present = E2SM_RC_EventTrigger__ric_eventTrigger_formats_PR_eventTrigger_Format1;

    int index = 0;
    while(index < event_trigger_count) {

        E2SM_RC_EventTrigger_Format1__message_List__Member *member = (E2SM_RC_EventTrigger_Format1__message_List__Member *)calloc(1,sizeof(E2SM_RC_EventTrigger_Format1__message_List__Member));
        
        //encoding Event Trigger Definition ID
        RIC_EventTriggerCondition_ID_t *triggerConditionID_t = (RIC_EventTriggerCondition_ID_t *)calloc(1, sizeof(RIC_EventTriggerCondition_ID_t));
        *triggerConditionID_t = triggerConditionID;
        member->ric_eventTriggerCondition_ID = *triggerConditionID_t;
        
        //encoding RRC message
        member->messageType.present = E2SM_RC_EventTrigger_Format1__message_List__Member__messageType_PR_messageType_Choice_RRC;
        MessageType_Choice_RRC_t *rrcmessage = (MessageType_Choice_RRC_t *)calloc(1,sizeof(MessageType_Choice_RRC_t));

        member->messageDirection = NULL;      
        member->associatedUEInfo = NULL;     
        member->associatedUEEvent = NULL;     
        member->logicalOR = NULL; 


        RRC_MessageID_t rrcmessageid; 
        memset(&rrcmessageid, 0, sizeof(RRC_MessageID_t));

        rrcmessageid.rrcType.present = RRC_MessageID__rrcType_PR_lTE;
        rrcmessageid.rrcType.choice.lTE = RRCclass_LTE_dL_DCCH;
        rrcmessageid.messageID = rrc_id;

        rrcmessage->rRC_Message = rrcmessageid;
        member->messageType.choice.messageType_Choice_RRC = *rrcmessage;

        ASN_SEQUENCE_ADD(&innerDef->message_List.list, member);
        index++;
    }

    asn_enc_rval_t encode_result;

    xer_fprint(stderr, &asn_DEF_E2SM_RC_EventTrigger_Format1, innerDef);
    encode_result = aper_encode_to_buffer(&asn_DEF_E2SM_RC_EventTrigger_Format1, NULL, innerDef, buffer, buf_size); 
    if(encode_result.encoded == -1) {
        fprintf(stderr, "Cannot encode %s: %s\n", encode_result.failed_type->name, strerror(errno));
        return -1;
    } else {
      printf("Success!\n");
     }

    eventTriggerDef->ric_eventTrigger_formats.choice.eventTrigger_Format1 = *innerDef;

    xer_fprint(stderr, &asn_DEF_E2SM_RC_EventTrigger, eventTriggerDef);
    encode_result = aper_encode_to_buffer(&asn_DEF_E2SM_RC_EventTrigger, NULL, eventTriggerDef, buffer, buf_size); 
    ASN_STRUCT_FREE(asn_DEF_E2SM_RC_EventTrigger, eventTriggerDef);
    if(encode_result.encoded == -1) {
        fprintf(stderr, "Cannot encode %s: %s\n", encode_result.failed_type->name, strerror(errno));
        return -1;
    } else {
        return encode_result.encoded;
    }
}

ssize_t e2sm_rc_encode_ric_action_definition(void *buffer, size_t buf_size, long ric_style_type) 
 {
        char mybuff[1000];
        long rc_sty_loc = 1;
        printf("************* The data of RIC Action Def: %ld Style : %ld",buf_size, ric_style_type);
        E2SM_RC_ActionDefinition_t *actionDef = (E2SM_RC_ActionDefinition_t *)calloc(1, sizeof(E2SM_RC_ActionDefinition_t));
        if(!actionDef) {
                fprintf(stderr, "alloc RIC ActionDefinition failed\n");
                return -1;
        }

        actionDef->ric_Style_Type = rc_sty_loc;

        if (ric_style_type == 1) {
         actionDef->ric_actionDefinition_formats.present = 
                     E2SM_RC_ActionDefinition__ric_actionDefinition_formats_PR_actionDefinition_Format1;
          E2SM_RC_ActionDefinition_Format1_t *innerDef = 
                             (E2SM_RC_ActionDefinition_Format1_t *) calloc(1, sizeof(E2SM_RC_ActionDefinition_Format1_t));


          E2SM_RC_ActionDefinition_Format1__ranP_ToBeReported_List__Member *ric_report = 
                         (E2SM_RC_ActionDefinition_Format1__ranP_ToBeReported_List__Member *)calloc(1,
                            sizeof(E2SM_RC_ActionDefinition_Format1__ranP_ToBeReported_List__Member));
          ric_report->ranParameter_ID = 3;
          ASN_SEQUENCE_ADD(&innerDef->ranP_ToBeReported_List.list, ric_report);
          actionDef->ric_actionDefinition_formats.choice.actionDefinition_Format1 = *innerDef;

        }

    xer_fprint(stderr, &asn_DEF_E2SM_RC_ActionDefinition, actionDef);
    asn_enc_rval_t encode_result;


    encode_result = aper_encode_to_buffer(&asn_DEF_E2SM_RC_ActionDefinition, NULL, actionDef, mybuff, sizeof(mybuff));
    ASN_STRUCT_FREE(asn_DEF_E2SM_RC_ActionDefinition, actionDef);
    if(encode_result.encoded == -1) {
        fprintf(stderr, "Cannot encode Action Definition %s: %s\n", encode_result.failed_type->name, strerror(errno));
        return -1;
    } else {
        return encode_result.encoded;
    }
}

void rc_subscription_request(){

  static char trigger_def_buf[1024];
  int trig_size;
  static struct ric_action {
       char ric_action_def_buf[1024];
       long size;
  } ric_actions[1];
  long actionIds[] = {0};
  long actionType[1] = {0};
  static char sub_req_buf[1024];
  int result;

  /* eventTrigger definition */


trig_size = e2sm_encode_ric_event_trigger_definition(trigger_def_buf, sizeof (trigger_def_buf),12, 13, 1);
 printf("trig size : %d\n", trig_size);
ric_actions[0].size = e2sm_rc_encode_ric_action_definition(ric_actions[0].ric_action_def_buf,
                                                 sizeof (ric_actions[0].ric_action_def_buf), 1);
printf("ric action size : %d\n", ric_actions[0].size);

  actionType[0] = 1; /*REPORT service */


   printf("About to call e2ap\n");
   e2ap_test();


  RICSubsequentAction RICsubsequentAction;
  RICsubsequentAction.isValid = 0;
  
  RICactionDefinition_t *RICactionDefinition = calloc(1, sizeof(RICactionDefinition_t));
  RICactionDefinition->buf = ric_actions[0].ric_action_def_buf;
  RICactionDefinition->size = ric_actions[0].size;

  result = e2ap_encode_ric_subscription_request_message(sub_req_buf, sizeof (sub_req_buf), 1, 1, 400,
                                               trigger_def_buf, trig_size, 1, actionIds, actionType,
                                               RICactionDefinition, &RICsubsequentAction);

  printf("result : %d\n", result);


}