/*********************************************************************
 *          (C) COPYRIGHT TEXAS INSTRUMENTS, INC. 2000-2002
 * FBTC6713.c -- main() function: Low level FlashBurn Communications
 *             protocol for 6713
 ********************************************************************/

/* Change Log:
 *
 */

#include "type.h"
#include <stdio.h>      /* C_I/O */
 
#include "c6713dsk.h"
#include "FBTC6713.h"
#include "FBCmd.h"


/* -------------
 * Globals
 * -------------
 */
/* The message must be global; Host will use
 * its address for sending and receiving
 * messages.
 * This program reads what's in the message block
 * and processes it. When done processing,
 * this program will store any response data back
 * into the same block.
 */
u8 theMessage[CMDSIZEBYTES+ARGSIZEBYTES+MAXDATABYTES] = {0}; // exchange messages with Host

/* This function must be global; Host will
 * set a breakpoint on it.
 * When this program hits the breakpoint,
 * host will detect the halt and process
 * any response info that may be in the message
 * block. When Host wants to send a message
 * to this FBTC, it will store
 * the message into the global message block
 * and start this FBTC running.
 */
void doMessageProc();  // Message Exchange routine


/* -------------
 * Local statics
 * -------------
 */
	/* This is the Status Word described
	 * in the Comm. Protocol Spec.
	 */	
static u16 m_ProtocolStatusWord = 0;



#pragma FUNC_NEVER_RETURNS(main);

void main()
{    
    /* User comfort message. Runs much faster
     * and leaner with no printfs anywhere.
     */
//	printf("Target FBTC Running\n");

	InitFlash();

	/* Runs forever, 'cause
	 * there's no need for me to halt.
	 *
	 */
	for(;;)
	{
		// When this returns, the Host has sent a message
		// (by writing it into theMessage struct).
		doMessageProc();
		
		doCommand();

	}
}


/* Global Funcs to send messages to Host.
 */

/* This do-nothing function is here to
 * define a global symbol. The Host app.
 * will set a breakpoint at this loc.
 * When this program steps off the
 * breakpoint (returns from this func),
 * that means that the Host has filled
 * the global message block (at theMessage)
 * with a command and data to process.
 * This prog. will process the message,
 * write any response data back into
 * the message block, and then come back
 * here and hit the breakpoint.
 */
void doMessageProc()
{
	/* Optimizer will want to delete
	 * this function, since it doesn't
	 * appear to do anything useful.
	 * Assigning a value to a volatile
	 * forces optimizer to keep this code. 
	 */ 
	volatile int FoolTheOptimizer = 0;
}

/* ------------------------
 * Global Utility Functions
 * ------------------------
 */ 

u16 GetProtocolStatusWord(void)
{
	return m_ProtocolStatusWord;
}


	/* Comm. Protocol Version in force when this
	 * FBTC was created. Add 1 if the protocol
	 * changes, even if this software did not change.
	 * For Protocol Version ID, see the Exchange
	 * Communications Protocol document.
	 * This is in the C file instead of the header
	 * file 'cause the header file is used by other
	 * C files, which could compromise encapsulation.
	 */

u16 GetProtocolVersionID(void)
{
	return (u16)COMMPROTOCOLVERSION;
}



/* -------------------------
 * Utility Status Word funcs
 * -------------------------
 */

	/* Set the 4 status bits
	 */
void SetErrorBits(u16 x)
{
    m_ProtocolStatusWord &= ~(0x000f);
    m_ProtocolStatusWord |= ((x) & 0x000f);
}

/* Stores val into the message command bytes
 */
void StoreCmd(u16 val)
{
	theMessage[0] = val >> 8;
	theMessage[1] =  val & 0x00ff;
}

u16 GetCmd(void)
{
	return ((u16)theMessage[0] << 8) |
	       (u16)theMessage[1];
}

/* Stores val into the message argument bytes
 * at argindex.
 * Argindex is 0-15.
 */
void StoreArg(int argindex, u16 val)
{
	int myindex = ARGINDEX + argindex * 2;
	theMessage[myindex++] = val >> 8;
	theMessage[myindex]   = val & 0x00ff;
}

/* Returns an arg value from arg index 0-15
 */
u16  GetArgVal(int index)
{
	int myindex = ARGINDEX + index * 2;
	return ((u16)theMessage[myindex] << 8) |
	       (u16)theMessage[myindex+1];
}

u8 *GetMessage(void)
{
	return &theMessage[0];
}

u8 *GetData(void)
{
	return &theMessage[DATAINDEX];
}




void SendI4ToHost(u16 cmd, long val)
{
	StoreCmd(cmd);
	StoreArg(0, (u16)(val >> 16));
	StoreArg(1, (u16)(val & 0x0000ffff));
}


void SendI2ToHost(u16 cmd, u16 val)
{
	StoreCmd(cmd);
	StoreArg(0, val);
}

void SendI1ToHost(u16 cmd, u8 val)
{

	StoreCmd(cmd);
	theMessage[ARGINDEX] = val;
}

