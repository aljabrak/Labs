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
  L2_SRAM : o = 00000000h l = 00038000h /* always SRAM     				*/
  L2_CACHE: o = 00038000h l = 00008000h /* 32K segment: always cache	*/
  CE0_EXT : o = 80000000h l = 00100000h /* external memory				*/
}

SECTIONS
{
    .cinit      >       L2_SRAM
    .text       >       L2_SRAM
    .stack      >       L2_SRAM
    .bss        >       L2_SRAM
    .const      >       L2_SRAM
    .data       >       L2_SRAM
    .far        >       L2_SRAM
    .switch     >       L2_SRAM
    .sysmem     >       L2_SRAM
    .tables     >       L2_SRAM
    .cio        >       L2_SRAM
    .buffers	>		CE0_EXT
}                             
