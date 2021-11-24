/*********************************************************************
 *          (C) COPYRIGHT TEXAS INSTRUMENTS, INC. 2000-2002
 * FlashBurn Programming Functions
 *     for FBTC6713
 */

/*
 */

#include <stdio.h>
#include "type.h"
#include "c6713dsk.h"
#include "FBTC6713.h"
#include "FBCmd.h"



	/* Local prototype
	 */
static GetFlashBuf(u8 *dest, u8 *flashsrc, u16 nBytes);

	/* Used by the checksum calc functions
	 */
static volatile unsigned long cksum = 0;

    /* flashstart/next are used to track
     * where we are in a "flat" Flash memory.
     * Paging, etc. are handled by helper
     * funcs.
     */  
static volatile u8 *flashstart = (volatile u8 *)FLASH_START;
static volatile u8 *flashnext  = (volatile u8 *)FLASH_START;

	/* These are "override" values, in case the
	 * Host has sent new flash base addr and size.
     * flashbaseov is 0xffffffff normally, but changes
     * if Host sends the Change FLASHSTART Address command.
     * Thus if it's not 0xffffffff, then it should be used
     * instead of the FLASH_START value. 
	 */
static volatile u8 *flashbaseov = (u8 *)0xffffffffUL;
static unsigned long flashsizeov =  0xffffffffUL;


/* Set and get the flash base address
 */
void SetFlashBase(unsigned long val)
{
	flashbaseov = (volatile u8 *)val;
}

volatile u8 *GetFlashBase(void)
{
	return flashbaseov != (volatile u8 *)0xffffffffL ?
	                      flashbaseov :
	                      (volatile u8 *)FLASH_START;
}

/* Set and get the flash size
 */
void SetFlashSize(unsigned long val)
{
	flashsizeov = val;
}

unsigned long GetFlashSize(void)
{
	return flashsizeov != 0xffffffffL ? flashsizeov : FLASH_SIZE;
}

void InitFlash(void)
{
	flashstart = GetFlashBase();
	flashnext = flashstart;
}

void SetFlashAddr(u8 *addr)
{
	flashstart = (volatile u8 *)addr;
	flashnext = flashstart;
}


volatile u8 *GetNextFlashAddr(void)
{
	return flashnext;
}


/* Burns flash data, starting at flashnext.
 * This embodies the burning algorithm for the
 * AMD29LV400B flash memory used on 6713 DSK
 */
void BurnFlash(u8 *data, u16 nBytes)
{
	u16 timeout;
	u8 c;

	while(nBytes--)		
	{
		/* Prep AMD
		 * 4MBit (256K X 16) Flash Memory
		 * for writing a byte.  Only low byte is written.
		 */	
		*(volatile char *)FLASH_ADR1 = (char)FLASH_KEY1;
		*(volatile char *)FLASH_ADR2 = (char)FLASH_KEY2;
		*(volatile char *)FLASH_ADR1 = (char)FLASH_KEY3;
	
		*flashnext = *data;
		
		/* Spin here 'til programming completes
		 */
		c = *data++;
		timeout = 0;
		do timeout += 1;
		while(*flashnext != c && timeout < (u16)0xffff);
		
		flashnext++;
	}
    
}


/* The Flash Erase function uses
 * the AMD algorithm to erase the
 * entire chip.
 */

void EraseFlash(void)
{
			
	/* Code to erase AMD29LV400B
	 * 4MBit (256K X 8) Flash Memory
	 */
	*(volatile char *)FLASH_ADR1 = (char)FLASH_KEY1;
	*(volatile char *)FLASH_ADR2 = (char)FLASH_KEY2;
	*(volatile char *)FLASH_ADR1 = (char)FLASH_KEY4;

	*(volatile char *)FLASH_ADR1 = (char)FLASH_KEY1;
	*(volatile char *)FLASH_ADR2 = (char)FLASH_KEY2;
	*(volatile char *)FLASH_ADR1 = (char)FLASH_KEY5;
	
	/* Spin here 'til erasing completes
	 */
	while((GetFlashVal(FLASH_START) & 0x80) == 0x00)
        ;/* Do Nothing!*/	
		
	return;
}

void CKSSet(u16 val)
{
	cksum = val;
}
	
u16 CKSGet(void)
{
	return (u16)cksum;
}
		
u16 CKSAccumBuf(unsigned char *buf, unsigned int len)
{   
	while(len-- > 0)
	{
		cksum += *buf++;
		if(cksum > (unsigned long)0x0000ffff)
		{
			cksum += 1;
			cksum &= (unsigned long)0x0000ffff;
		} 
	}
	
	return (u16)cksum;
}


u8 GetFlashVal(unsigned long addr)
{
    /* Set External Flash for byte-addressability */
    *(unsigned volatile int *)EMIF_CE1 = CE1_8; /* EMIF CE1 control, 8bit async */
	return *(u8 *)addr ;
}

void SendFlashBufToHost(u16 cmd, unsigned long addr, u16 bytecount)
{
    u8 *pflash = (u8 *)addr;
    u16 n = bytecount > 256 ? 256 : bytecount;

	StoreCmd(cmd);     
	StoreArg(0, bytecount);	
    
	GetFlashBuf(GetData(), pflash, n);
}

static GetFlashBuf(u8 *dest, u8 *flashsrc, u16 nBytes)
{
    /* Set External Flash for byte-addressability */
    *(unsigned volatile int *)EMIF_CE1 = CE1_8; /* EMIF CE1 control, 8bit async */
	memcpy(dest, flashsrc, nBytes);
}
