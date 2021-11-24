/*********************************************************************
 *          (C) COPYRIGHT TEXAS INSTRUMENTS, INC. 2000-2002 				  *
 * FlashBurn 67x Target Code header
 */

/* Change Log:
 */

#ifndef __fbtc67h__
#define __fbtc67h__

	/* Comm. Protocol Version in force when this
	 * FBTC was created. Add 1 if the protocol
	 * changes, even if this software did not change.
	 * For Protocol Version ID, see the Exchange
	 * Communications Protocol document.
	 * This is in the C file instead of the header
	 * file 'cause the header file is used by other
	 * C files, which could compromise encapsulation.
	 * v1 - original version
	 * v2 - added the Query Edit Flash Permission command.
	 * v3 - added the Query Max Data Block Size command
	 *      and redesigned to eliminate RTDX comm..
	 */
#define COMMPROTOCOLVERSION  3

    /*********************
     * Version ID of this FBTC.
	 * Major.Minor 0.0 to 65535.65535
	 * (thus if major = 1, minor = 20, then
	 * version is 00001.00001
	 *
	 * MUST BE EDITED FOR ANY NEW RELEASE!
     *********************
     */
#define FBTCVersionMajor   00001
#define FBTCVersionMinor   00000

	/* This is the response to send when
	 * host queries for Edit Flash Permission.
	 * Set this to 0 or 1 to indicate whether
	 * this FBTC allows editing individual flash
	 * memory locations.
	 */
#define EDITFLASHPERMIT  0

#define BYTESPERMAU	       1

#define CMDSIZEBYTES	   2
#define ARGSIZEBYTES	  30
#define MAXDATABYTES	2048

#define CMDINDEX			0
#define ARGINDEX			(CMDINDEX + CMDSIZEBYTES)
#define DATAINDEX			(ARGINDEX + ARGSIZEBYTES)

#define CMDOK              0x0
#define UNEXP_DATA_LENGTH  0x1
#define ILL_DATA_VAL       0x2       
#define CMD_NOT_DONE       0x3


/* Global Prototypes
 */
void doMessageProc(void);


/* ----------------------------------
 * Special Message Store/fetch funcs.
 * ----------------------------------
 */

/* Stores val into the message command bytes
 */
void StoreCmd(u16 val);
u16 GetCmd(void);

/* Stores val into the message argument bytes
 * at argindex.
 * Argindex is 0-15.
 */
void StoreArg(int argindex, u16 val);

/* Returns an arg value from arg index 0-15
 */
u16  GetArgVal(int index);

/* Returns a pointer to the data block
 */ 
u8 *GetData(void);



/* Send a long value to Host
 * Formats a response message and sends it
 */
void SendI4ToHost(u16 cmd, long val); 

/* Send a u16 value to Host
 * Formats a response message and sends it
 */
void SendI2ToHost(u16 cmd, u16 val); 

/* Send a byte value to Host
 * Formats a response message and sends it
 */
void SendI1ToHost(u16 cmd, u8 val);

#endif

