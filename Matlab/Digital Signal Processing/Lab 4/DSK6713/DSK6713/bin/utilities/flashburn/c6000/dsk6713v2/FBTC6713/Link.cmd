/***********************************
* FILENAME: $RCSfile: Link.cmd,v $
* VERSION : $Revision: 1.3 $
* DATE    : $Date: 2001/04/19 18:57:05 $
* Copyright (c) 2001 Texas Instruments Incorporated
*
* Description: 
*	Simple Linker Control File for TEB6416 FlashBurn FBTC.
*   This was heisted from some examples I found.
*/

-c
-heap  0x2000
-stack 0x4000

/* Memory Map
 */

MEMORY
{
	PMEM:	o = 00000000h	l = 00010000h
	BMEM:	o = 80000000h	l = 00010000h
}


SECTIONS
{
    .text   >  PMEM
    .far    >  PMEM
    .stack  >  PMEM
    .bss    >  PMEM
    .cinit  >  PMEM
    .pinit  >  PMEM
    .cio    >  PMEM
    .const  >  PMEM
    .data   >  PMEM
    .switch >  PMEM
    .sysmem >  PMEM
}
