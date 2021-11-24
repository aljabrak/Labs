/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------edma1.cmd---------
 *
 */

MEMORY
{
	L2SRAM  : o = 00000000h		l = 00030000h
	L2CACHE : o = 00030000h		l = 00010000h /* 64K Cache */ 
	EXTERNAL: o = 80000000h		l = 80010000h
}

SECTIONS
{    
    .text   >   L2SRAM
    .stack	>   L2SRAM
    .far	>   L2SRAM
    .switch	>   L2SRAM 
    .tables >   L2SRAM
    .data   >   L2SRAM
    .bss	>   L2SRAM
    .sysmem	>   L2SRAM
    .cinit	>   L2SRAM
    .const	>   L2SRAM
    .cio    >   L2SRAM 
    
    .buffers >  EXTERNAL
}
