/*
 * Note: this file originally auto-generated by mib2c using
 *  $
 */
#ifndef RS232ASYNCPORTTABLE_H
#define RS232ASYNCPORTTABLE_H

/* function declarations */
void init_rs232AsyncPortTable(void);
void initialize_table_rs232AsyncPortTable(void);
Netsnmp_Node_Handler rs232AsyncPortTable_handler;
Netsnmp_First_Data_Point  rs232AsyncPortTable_get_first_data_point;
Netsnmp_Next_Data_Point   rs232AsyncPortTable_get_next_data_point;

/* column number definitions for table rs232AsyncPortTable */
#define COLUMN_RS232ASYNCPORTINDEX		1
#define COLUMN_RS232ASYNCPORTBITS		2
#define COLUMN_RS232ASYNCPORTSTOPBITS		3
#define COLUMN_RS232ASYNCPORTPARITY		4
#define COLUMN_RS232ASYNCPORTAUTOBAUD		5
#define COLUMN_RS232ASYNCPORTPARITYERRS		6
#define COLUMN_RS232ASYNCPORTFRAMINGERRS	7
#define COLUMN_RS232ASYNCPORTOVERRUNERRS	8


/*RS232 Character Bits definitions*/
#define RS232_CHARACTER_7BITS                   7
#define RS232_CHARACTER_8BITS                   8

/*RS232 Stop Bits definitions*/
#define RS232_STOP_1BITS                        1
#define RS232_STOP_2BITS                        2

/*RS232 Polarity definitions*/
#define RS232_POLARITY_NONE                     1
#define RS232_POLARITY_ODD                      2
#define RS232_POLARITY_EVEN                     3

#endif /* RS232ASYNCPORTTABLE_H */
