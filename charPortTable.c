/*
 * Note: this file originally auto-generated by mib2c using
 *  $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "charPortTable.h"

/* create a new row in the (unsorted) table */
struct charPortTable_entry *
charPortTable_createEntry(long  charPortIndex);
/* remove a row from the table */
void charPortTable_removeEntry( struct charPortTable_entry *entry );


/* Typical data structure for a row entry */
struct charPortTable_entry {
    /* Index values */
    long charPortIndex;

    /* Column values */
    char charPortName;
    char old_charPortName;
    long charPortType;
    long charPortReset;
    long old_charPortReset;
    long charPortAdminStatus;
    long old_charPortAdminStatus;
    long charPortOperStatus;
    u_long charPortLastChange;
    long charPortInFlowType;
    long old_charPortInFlowType;
    long charPortOutFlowType;
    long old_charPortOutFlowType;
    long charPortInFlowState;
    long charPortOutFlowState;
    u_long charPortInCharacters;
    u_long charPortOutCharacters;
    long charPortAdminOrigin;
    long old_charPortAdminOrigin;
    long charPortSessionMaximum;
    long old_charPortSessionMaximum;
    u_long charPortSessionNumber;
    long charPortSessionIndex;

    /* Illustrate using a simple linked list */
    int   valid;
    struct charPortTable_entry *next;
};


/** Initializes the charPortTable module */
void
init_charPortTable(void)
{
  /* here we initialize all the tables we're planning on supporting */
    initialize_table_charPortTable();
}


/** Initialize the charPortTable table by defining its contents and how it's structured */
void
initialize_table_charPortTable(void)
{
    const oid charPortTable_oid[] = {1,3,6,1,2,1,19,2};
    const size_t charPortTable_oid_len   = OID_LENGTH(charPortTable_oid);
    netsnmp_handler_registration    *reg;
    netsnmp_iterator_info           *iinfo;
    netsnmp_table_registration_info *table_info;

    DEBUGMSGTL(("charPortTable:init", "initializing table charPortTable\n"));

    reg = netsnmp_create_handler_registration(
              "charPortTable",     charPortTable_handler,
              charPortTable_oid, charPortTable_oid_len,
              HANDLER_CAN_RWRITE
              );

    table_info = SNMP_MALLOC_TYPEDEF( netsnmp_table_registration_info );
    netsnmp_table_helper_add_indexes(table_info,
                           ASN_INTEGER,  /* index: charPortIndex */
                           0);
    table_info->min_column = COLUMN_CHARPORTINDEX;
    table_info->max_column = COLUMN_CHARPORTSESSIONINDEX;
    
    iinfo = SNMP_MALLOC_TYPEDEF( netsnmp_iterator_info );
    iinfo->get_first_data_point = charPortTable_get_first_data_point;
    iinfo->get_next_data_point  = charPortTable_get_next_data_point;
    iinfo->table_reginfo        = table_info;
    
    netsnmp_register_table_iterator( reg, iinfo );

    /* Initialise the contents of the table here */
    struct charPortTable_entry *entry;
    //PortIndex 1
    entry = charPortTable_createEntry(1);
    entry->charPortOperStatus = PORT_FUNC_UP;
    entry->charPortInFlowType = PORT_FLOW_TYPE_NONE;
    entry->charPortOutFlowType = PORT_FLOW_TYPE_NONE;
    //PortIndex 2
    entry = charPortTable_createEntry(2);
    entry->charPortOperStatus = PORT_FUNC_UP;
    entry->charPortInFlowType = PORT_FLOW_TYPE_NONE;
    entry->charPortOutFlowType = PORT_FLOW_TYPE_NONE;
    //PortIndex 3
    entry = charPortTable_createEntry(3);
    entry->charPortOperStatus = PORT_FUNC_UP;
    entry->charPortInFlowType = PORT_FLOW_TYPE_NONE;
    entry->charPortOutFlowType = PORT_FLOW_TYPE_NONE;
    //PortIndex 4
    entry = charPortTable_createEntry(4);
    entry->charPortOperStatus = PORT_FUNC_UP;
    entry->charPortInFlowType = PORT_FLOW_TYPE_NONE;
    entry->charPortOutFlowType = PORT_FLOW_TYPE_NONE;

}


struct charPortTable_entry  *charPortTable_head;

/* create a new row in the (unsorted) table */
struct charPortTable_entry *
charPortTable_createEntry(long  charPortIndex) {
    struct charPortTable_entry *entry;

    entry = SNMP_MALLOC_TYPEDEF(struct charPortTable_entry);
    if (!entry)
        return NULL;

    entry->charPortIndex = charPortIndex;
    entry->next = charPortTable_head;
    charPortTable_head = entry;
    return entry;
}

/* remove a row from the table */
void
charPortTable_removeEntry( struct charPortTable_entry *entry ) {
    struct charPortTable_entry *ptr, *prev;

    if (!entry)
        return;    /* Nothing to remove */

    for ( ptr  = charPortTable_head, prev = NULL;
          ptr != NULL;
          prev = ptr, ptr = ptr->next ) {
        if ( ptr == entry )
            break;
    }
    if ( !ptr )
        return;    /* Can't find it */

    if ( prev == NULL )
        charPortTable_head = ptr->next;
    else
        prev->next = ptr->next;

    SNMP_FREE( entry );   /* XXX - release any other internal resources */
}


/* Example iterator hook routines - using 'get_next' to do most of the work */
netsnmp_variable_list *
charPortTable_get_first_data_point(void **my_loop_context,
                          void **my_data_context,
                          netsnmp_variable_list *put_index_data,
                          netsnmp_iterator_info *mydata)
{
    *my_loop_context = charPortTable_head;
    return charPortTable_get_next_data_point(my_loop_context, my_data_context,
                                    put_index_data,  mydata );
}

netsnmp_variable_list *
charPortTable_get_next_data_point(void **my_loop_context,
                          void **my_data_context,
                          netsnmp_variable_list *put_index_data,
                          netsnmp_iterator_info *mydata)
{
    struct charPortTable_entry *entry = (struct charPortTable_entry *)*my_loop_context;
    netsnmp_variable_list *idx = put_index_data;

    if ( entry ) {
        snmp_set_var_typed_integer( idx, ASN_INTEGER, entry->charPortIndex );
        idx = idx->next_variable;
        *my_data_context = (void *)entry;
        *my_loop_context = (void *)entry->next;
        return put_index_data;
    } else {
        return NULL;
    }
}


/** handles requests for the charPortTable table */
int
charPortTable_handler(
    netsnmp_mib_handler               *handler,
    netsnmp_handler_registration      *reginfo,
    netsnmp_agent_request_info        *reqinfo,
    netsnmp_request_info              *requests) {

    int ret = 0;
    netsnmp_request_info       *request;
    netsnmp_table_request_info *table_info;
    struct charPortTable_entry          *table_entry;

    DEBUGMSGTL(("charPortTable:handler", "Processing request (%d)\n", reqinfo->mode));

    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request=requests; request; request=request->next) {
            table_entry = (struct charPortTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
    
            switch (table_info->colnum) {
            case COLUMN_CHARPORTOPERSTATUS:
                if ( !table_entry ) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer( request->requestvb, ASN_INTEGER,
                                            table_entry->charPortOperStatus);
                break;
            case COLUMN_CHARPORTINFLOWTYPE:
                if ( !table_entry ) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer( request->requestvb, ASN_INTEGER,
                                            table_entry->charPortInFlowType);
                break;
            case COLUMN_CHARPORTOUTFLOWTYPE:
                if ( !table_entry ) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer( request->requestvb, ASN_INTEGER,
                                            table_entry->charPortOutFlowType);
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_NOSUCHOBJECT);
                break;
            }
        }
        break;

        /*
         * Write-support
         */
    case MODE_SET_RESERVE1:
        for (request=requests; request; request=request->next) {
            table_entry = (struct charPortTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
    
            switch (table_info->colnum) {
            case COLUMN_CHARPORTINFLOWTYPE:
                //Check if the table entry is valid
                if ( !table_entry ) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                /* or possibly 'netsnmp_check_vb_int_range' */
                ret = netsnmp_check_vb_int( request->requestvb );
                if ( ret != SNMP_ERR_NOERROR ) {
                    netsnmp_set_request_error( reqinfo, request, ret );
                    return SNMP_ERR_NOERROR;
                }
                else if (*request->requestvb->val.integer == PORT_FLOW_TYPE_NONE ||
                         *request->requestvb->val.integer == PORT_FLOW_TYPE_SW ||
                         *request->requestvb->val.integer == PORT_FLOW_TYPE_CTSRTS)
                {
                    //Value fulfill the requirement
                }
                else
                {
                    ret = SNMP_ERR_WRONGVALUE;
                    netsnmp_set_request_error( reqinfo, request, ret );
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_CHARPORTOUTFLOWTYPE:
                //Check if the table entry is valid
                if ( !table_entry ) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                /* or possibly 'netsnmp_check_vb_int_range' */
                ret = netsnmp_check_vb_int( request->requestvb );
                if ( ret != SNMP_ERR_NOERROR ) {
                    netsnmp_set_request_error( reqinfo, request, ret );
                    return SNMP_ERR_NOERROR;
                }
                else if (*request->requestvb->val.integer == PORT_FLOW_TYPE_NONE ||
                         *request->requestvb->val.integer == PORT_FLOW_TYPE_SW ||
                         *request->requestvb->val.integer == PORT_FLOW_TYPE_CTSRTS)
                {
                    //Value fulfill the requirement
                }
                else
                {
                    ret = SNMP_ERR_WRONGVALUE;
                    netsnmp_set_request_error( reqinfo, request, ret );
                    return SNMP_ERR_NOERROR;
                }
                break;
            default:
                netsnmp_set_request_error( reqinfo, request,
                                           SNMP_ERR_NOTWRITABLE );
                return SNMP_ERR_NOERROR;
            }
        }
        break;

    case MODE_SET_RESERVE2:
        break;

    case MODE_SET_FREE:
        break;

    case MODE_SET_ACTION:
        for (request=requests; request; request=request->next) {
            table_entry = (struct charPortTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
    
            switch (table_info->colnum) {
            case COLUMN_CHARPORTINFLOWTYPE:
                table_entry->old_charPortInFlowType = table_entry->charPortInFlowType;
                table_entry->charPortInFlowType     = *request->requestvb->val.integer;
                break;
            case COLUMN_CHARPORTOUTFLOWTYPE:
                table_entry->old_charPortOutFlowType = table_entry->charPortOutFlowType;
                table_entry->charPortOutFlowType     = *request->requestvb->val.integer;
                break;
            }
        }
        break;

    case MODE_SET_UNDO:
        for (request=requests; request; request=request->next) {
            table_entry = (struct charPortTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
    
            switch (table_info->colnum) {
            case COLUMN_CHARPORTINFLOWTYPE:
                table_entry->charPortInFlowType     = table_entry->old_charPortInFlowType;
                table_entry->old_charPortInFlowType = 0;
                break;
            case COLUMN_CHARPORTOUTFLOWTYPE:
                table_entry->charPortOutFlowType     = table_entry->old_charPortOutFlowType;
                table_entry->old_charPortOutFlowType = 0;
                break;
            }
        }
        break;

    case MODE_SET_COMMIT:
        break;
    }
    return SNMP_ERR_NOERROR;
}