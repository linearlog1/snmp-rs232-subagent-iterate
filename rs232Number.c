/*
 * Note: this file originally auto-generated by mib2c using
 *        $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "rs232Number.h"

/*
 * The variables we want to tie the relevant OIDs to.
 * The agent will handle all GET and (if applicable) SET requests
 * to these variables automatically, changing the values as needed.
 */

long    rs232Number = RS232_4PORTS;  /* XXX: set default value */

/*
 * Our initialization routine, called automatically by the agent 
 * (Note that the function name must match init_FILENAME()) 
 */
void
init_rs232Number(void)
{
  netsnmp_handler_registration *reg;

    const oid rs232Number_oid[] = { 1,3,6,1,2,1,10,33,1 };
  static netsnmp_watcher_info rs232Number_winfo;

  /*
   * a debugging statement.  Run the agent with -Drs232Number to see
   * the output of this debugging statement. 
   */
  DEBUGMSGTL(("rs232Number", "Initializing the rs232Number module\n"));


    /*
     * Register scalar watchers for each of the MIB objects.
     * The ASN type and RO/RW status are taken from the MIB definition,
     * but can be adjusted if needed.
     *
     * In most circumstances, the scalar watcher will handle all
     * of the necessary processing.  But the NULL parameter in the
     * netsnmp_create_handler_registration() call can be used to
     * supply a user-provided handler if necessary.
     *
     * This approach can also be used to handle Counter64, string-
     * and OID-based watched scalars (although variable-sized writeable
     * objects will need some more specialised initialisation).
     */
    DEBUGMSGTL(("rs232Number",
                "Initializing rs232Number scalar integer.  Default value = %d\n",
                rs232Number));
    reg = netsnmp_create_handler_registration(
             "rs232Number", NULL,
              rs232Number_oid, OID_LENGTH(rs232Number_oid),
              HANDLER_CAN_RONLY);
    netsnmp_init_watcher_info(&rs232Number_winfo, &rs232Number, sizeof(long),
			      ASN_INTEGER, WATCHER_FIXED_SIZE);
if (netsnmp_register_watched_scalar( reg, &rs232Number_winfo ) < 0 ) {
        snmp_log( LOG_ERR, "Failed to register watched rs232Number" );
    }


  DEBUGMSGTL(("rs232Number",
              "Done initalizing rs232Number module\n"));
}
