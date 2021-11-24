/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------mcbsp2.cmd---------
 *
 */
MEMORY
{
  L2 : o = 00000000h l = 00040000h /* all SRAM     		*/
  CE0: o = 80000000h l = 00100000h /* external memory   */
}

SECTIONS
{
    .cinit      >       L2
    .text       >       L2
    .stack      >       L2
    .bss        >       L2
    .const      >       L2
    .data       >       L2
    .far        >       L2
    .switch     >       L2
    .sysmem     >       L2
    .tables     >       L2
    .cio        >       L2
    
	.internalData >		L2
	
    .external   >       CE0
}                             
