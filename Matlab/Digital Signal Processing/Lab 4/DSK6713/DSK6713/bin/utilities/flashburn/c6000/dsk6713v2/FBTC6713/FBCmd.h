/***********************************************************
 *          (C) COPYRIGHT TEXAS INSTRUMENTS, INC. 2000, 2001
 * FBCmd.h -- Process FlashBurn Target Component commands
 *            for 6713 DSK
 */

/* Change Log:
 */

#ifndef __fbcmd__
#define __fbcmd__


#include "type.h"
#include "fbtc6713.h"


#define ShortsToLong(vHighHalf, vLowHalf)  \
		((long)(((unsigned long)((u16)(vHighHalf)) << 16) | ((unsigned long)((u16)(vLowHalf)))))

#define ShortsToULong(vHighHalf, vLowHalf)  \
		((unsigned long)(((unsigned long)((u16)(vHighHalf)) << 16) | ((unsigned long)((u16)(vLowHalf)))))

/* -----------------------
 * Prototypes from FBCMD.C
 * -----------------------
 */

/* Given the command message,
 * carry out the command and prepare the
 * response.
 */
void doCommand(void);

/* --------------------------
 * Prototypes from FBURNCMD.C
 * --------------------------
 */
	/* Set/Get Flash Memory base address.
	 * The Host may want me to change where
	 * I think the flash memory is, rather
	 * than have me use my hard-coded flash
	 * base address (FLASH_START in header
	 * file c6416TEB.h). It is set in response to a
	 * Set FLASHBASE Address command from Host.
	 */
void SetFlashBase(unsigned long val);
volatile u8 *GetFlashBase(void);

	/* Set/Get Flash Memory size.
	 * The Host may want me to change how big
	 * I think the flash memory is, rather
	 * than have me use my hard-coded flash
	 * size (FLASH_SIZE in header file
	 * c6416teb.h)
	 */
void SetFlashSize(unsigned long val);
unsigned long GetFlashSize(void);

	/* Initialize flash memory pointers
	 * to a known flash memory address
	 */
void InitFlash(void);
	/* Initialize flash memory pointers
	 * to an address
	 */
void SetFlashAddr(u8 *addr);

	/* Burn data into flash memory starting
	 * at current flash memory pointer
	 * (flashnext).
	 */
void BurnFlash(u8 *data, u16 nBytes);

	/* Burn data into flash memory starting
	 * at current flash memory pointer.
	 */
volatile u8 *GetNextFlashAddr(void);

	/* Erase flash memory starting
	 * at current flash memory pointer.
	 * Erase from current start pointer to
	 * end of flash memory.
	 */
void EraseFlash();

	/* Checksum Processing.
	 * A simple modulo-16 additive cksum
	 * which adds the carry bit back into
	 * the accumulator.
	 */
	 /* Initialize to a value */
void CKSSet(u16 val);
	 /* Returns the current value */
u16 CKSGet(void);
	 /* Accumulate a new value */
u16 CKSAccum(unsigned char val);
	 /* Accumulate a buffer */
u16 CKSAccumBuf(unsigned char *buf, unsigned int len);

	/* Return a flash memory byte
	 */
u8 GetFlashVal(unsigned long addr);
	/* Sends a block of flash bytes to host
	 * Limited to 256 bytes.
	 */
void SendFlashBufToHost(u16 cmd, unsigned long addr, u16 bytecount);

#endif
