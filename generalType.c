/*
 * Note: this file originally auto-generated by mib2c using
 *        $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "generalType.h"

char typeName[SNMP_OID_TYPE_LENGTH] = SNMP_OID_TYPE_4PORT;

/** Initializes the generalType module */
void
init_generalType(void)
{
    const oid generalType_oid[] = { 1,3,6,1,4,1,332,11,5,3,3,20,12 };

  DEBUGMSGTL(("generalType", "Initializing\n"));

    netsnmp_register_scalar(
        netsnmp_create_handler_registration("generalType", handle_generalType,
                               generalType_oid, OID_LENGTH(generalType_oid),
                               HANDLER_CAN_RONLY
        ));
}

int
handle_generalType(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                     (u_char *) typeName,
                                     sizeof(typeName));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_generalType\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
