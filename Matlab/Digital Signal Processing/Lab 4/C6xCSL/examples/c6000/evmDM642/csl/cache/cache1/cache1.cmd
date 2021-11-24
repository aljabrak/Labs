/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------cache1.cmd---------
 *
 */
MEMORY
{
  L2_12: o = 00000000h l = 00030000h /*Upto 192K segment - always SRAM     */
  L2_3:  o = 00030000h l = 00008000h /*32K segment: TaskA-SRAM, TaskB-Cache*/
  L2_4:  o = 00038000h l = 00008000h /*32K segment: always cache           */
  CE0:   o = 80000000h l = 00100000h /* external memory                    */
}

SECTIONS
{
    .cinit      >       L2_12
    .text       >       L2_12
    .stack      >       L2_12
    .bss        >       L2_12
    .const      >       L2_12
    .data       >       L2_12
    .far        >       L2_12
    .switch     >       L2_12
    .sysmem     >       L2_12
    .tables     >       L2_12
    .cio        >       L2_12

    .sramStateA > 		L2_3
    
    .external   >       CE0
}                             
