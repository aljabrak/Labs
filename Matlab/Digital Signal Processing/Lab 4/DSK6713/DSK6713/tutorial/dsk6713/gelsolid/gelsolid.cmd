/*
 *  Copyright 1998 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 */
/*
 *  ======== hello.cmd ========
 *
 */


MEMORY 
{
   SDRAM       : origin = 0x80000000,  len = 0x400000
}

SECTIONS
{
        .vectors > SDRAM
        .text    > SDRAM

        .bss     > SDRAM
        .cinit   > SDRAM
        .const   > SDRAM
        .far     > SDRAM
        .stack   > SDRAM
        .cio     > SDRAM
        .sysmem  > SDRAM
}
