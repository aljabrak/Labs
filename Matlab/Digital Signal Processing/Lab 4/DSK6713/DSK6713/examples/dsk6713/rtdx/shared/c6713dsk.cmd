/*************************************************************************
* $RCSfile: c6713dsk.cmd,v $
* $Revision: 1.3 $
* $Date: 2000/12/16 06:25:41 $
* Copyright (c) 1997 Texas Instruments Incorporated
*
* Description: 
*	Sample Linker Control File for C6713 DSK target boards.
*
* Usage:  
*	lnk6x <obj files...>    -o <out file> -m <map file> lcf.cmd
*	cl6x  <src files...> -z -o <out file> -m <map file> lcf.cmd
*************************************************************************/
-c
-heap  0x1000
-stack 0x1000
-u __vectors
-u _auto_init

_HWI_Cache_Control = 0;

/* RTDX Interrupt Mask
   - This symbol defines those interrupts which are clients of RTDX
     (ie - interrupts which call RTDX functions.
   - RTDX will apply this mask to the IER before excuting code in 
     RTDX critical sections temporarily disabling those interrupts for 
     a few cycles.
   - Any interrupt handlers which call RTDX_read/write functions should 
     be added to the mask to prevent corruption of the RTDX global state
     variables by simulataneous access from multiple RTDX clients.
*/     
_RTDX_interrupt_mask = ~0x000001808;

MEMORY
{
	VECS:	o=00000000h	l=00000200h		/* interrupt vectors */
	PMEM:	o=00000200h	l=0000FE00h 	/* Internal RAM (L2) mem	*/
	BMEM:	o=80000000h	l=01000000h 	/* CE0, SDRAM, 16 MBytes	*/

}

SECTIONS
{
    .intvecs	>	0h
    .text		>	BMEM
    .rtdx_text	>	BMEM
    .far		>	BMEM
    .stack		>	BMEM
    .bss		>	BMEM
    .cinit		>	BMEM
    .pinit		>	PMEM
    .cio		>	BMEM
    .const		>	BMEM
    .data		>	BMEM
    .rtdx_data	>	BMEM
    .switch		>	BMEM
    .sysmem		>	BMEM
}
