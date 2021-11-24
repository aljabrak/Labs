/*********************************************************************
 *          (C) COPYRIGHT TEXAS INSTRUMENTS, INC. 2000-2002
 * FBCmd.c -- Process FlashBurn Target Component commands
 *				for FBTC6713
 */

/* Change Log:
 *
 *
 */

#define DBPRINT 0

#include "type.h"
#include "c6713dsk.h"
#include "FBTC6713.h"
#include "FBCmd.h"
#include <stdio.h>

/* -------------
 * Globals
 * -------------
 */

/* -------------
 * Local statics
 * -------------
 */

/* ----------------
 * Local prototypes
 * ----------------
 */
static void SendVersionID(void);


void doCommand(void)
{
	u16 cmd = GetCmd();
	
        #if DBPRINT == 1
        printf("CMD: %x", cmd);
        #endif
    
    /* Dispatch to a command handler. Handle
     * simple stuff here.
     */
	switch(cmd)
	{
	case 0x0000:      /* NOP */  
		break;
	case 0x0001:      /* QUERY PROTOCOL VERSION */
		SetErrorBits(CMDOK);
		SendI2ToHost(cmd, GetProtocolVersionID());
		break;
	case 0x0002:      /* QUERY STATUS */
        #if DBPRINT == 1
        if(DBPRINT) printf("  Status: %x", GetProtocolStatusWord());
        #endif
		SendI2ToHost(cmd, GetProtocolStatusWord());
		break;
	case 0x0003:      /* ERASE FLASH */
		InitFlash();
		SetErrorBits(CMDOK);
		EraseFlash();
		break;
	case 0x0004:	/* Query FlashStart Addr */
		SendI4ToHost(cmd, (unsigned long)GetFlashBase());
		break;
	case 0x0005:  /* Read 1 Flash loc */
        #if DBPRINT == 1
        if(DBPRINT) printf(" ARGS: %x %x", GetArgVal(0), GetArgVal(1));
		#endif
		SendI1ToHost(cmd, GetFlashVal((unsigned long)GetFlashBase() + ShortsToULong(GetArgVal(0), GetArgVal(1))));
		break;
	case 0x0006:  /* Read a block of flash memory */
        #if DBPRINT == 1
        printf(" ARGS: %x %x %x",
        				GetArgVal(0), GetArgVal(1), GetArgVal(2));
		#endif
        SetErrorBits(CMDOK);
		SendFlashBufToHost(cmd, (unsigned long)GetFlashBase() + ShortsToULong(GetArgVal(0), GetArgVal(1)), GetArgVal(2));
		break;
	case 0x0007:   /* Write data to flash  */
        #if DBPRINT == 1
        printf(" ARGS: %x %x %x",  GetArgVal(0), GetArgVal(1), GetArgVal(2));
		#endif
		SetFlashAddr((u8 *)((unsigned long)GetFlashBase() + ShortsToULong(GetArgVal(0), GetArgVal(1))));
		SetErrorBits(CMDOK);
		BurnFlash(GetData(), GetArgVal(2));		
		break;
	case 0x0008:    /* More data */
        #if DBPRINT == 1
        printf(" ARG: %x",  GetArgVal(0));
		#endif
		SetErrorBits(CMDOK);
		BurnFlash(GetData(), GetArgVal(0));
		break;
	case 0x0009:   /* Respond with current flash data checksum */
        #if DBPRINT == 1
        printf(" ARGS: %x %x %x %x\n",  GetArgVal(0), GetArgVal(1), GetArgVal(2), GetArgVal(3));
		#endif
		SetErrorBits(CMDOK);
		CKSSet(0);
		SendI2ToHost(cmd,
		            (u16)CKSAccumBuf((unsigned char *)((unsigned long)GetFlashBase() + ShortsToULong(GetArgVal(0), GetArgVal(1))),
		                  ShortsToULong(GetArgVal(2), GetArgVal(3))));
		break;
    case 0x000a:   /* Accept User Data
	                * Simply accept & toss data.
                    * I use this for timing tests.
                    * It could contain your own proprietary
                    * commands or data, sort of an escape
                    * sequence.
                    */
        #if DBPRINT == 1
        printf(" ARG: %x",  GetArgVal(0));
        #endif
		SetErrorBits(CMDOK);
		/* (Don't do anything with the data)
		 */
		break;

    case 0x000b:      /* QUERY FLASHSIZE VALUE */
		SetErrorBits(CMDOK);
		SendI4ToHost(cmd, GetFlashSize());
		break;

	case 0x000c:      /* Change FLASH Start Address */
        #if DBPRINT == 1
        printf(" ARGS: %x %x", GetArgVal(0), GetArgVal(1));
        #endif
		SetErrorBits(CMDOK);
		SetFlashBase(ShortsToULong(GetArgVal(0), GetArgVal(1)));
		break;

	case 0x000d:      /* Change Flash Size */
        #if DBPRINT == 1
        printf(" ARGS: %x %x", GetArgVal(0), GetArgVal(1));
		#endif
		SetErrorBits(CMDOK);
		SetFlashSize(ShortsToULong(GetArgVal(0), GetArgVal(1)));
		break;

	case 0x000e:      /* Query FBTC Version ID */
		SetErrorBits(CMDOK);
		SendVersionID();
		break;

	case 0x000f:      /* QUERY EDIT CAPABILITY */
		SetErrorBits(CMDOK);
		SendI2ToHost(cmd, EDITFLASHPERMIT);
		break;

	case 0x0010:      /* QUERY MAX DATA BLOCK SIZE (BYTES)*/
		SetErrorBits(CMDOK);
		SendI2ToHost(cmd, MAXDATABYTES);
		break;

	default:
			#if DBPRINT == 1
			printf(" *** UNKNOWN! ***");
			#endif
		break;
	}
	
	#if DBPRINT == 1
	printf("\n");
	#endif
}


/* Send my version ID back to the Host.
 */
static void SendVersionID()
{
	StoreCmd(0x000e);  /* response to this command */	
	StoreArg(0, FBTCVersionMajor); /* Arg0 */
	StoreArg(1, FBTCVersionMinor); /* Arg1 */
}
