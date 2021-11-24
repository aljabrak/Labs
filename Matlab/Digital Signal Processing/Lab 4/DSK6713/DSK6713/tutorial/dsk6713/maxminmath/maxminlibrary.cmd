/*
 *  Copyright 1998 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 */
/*
 *  ======== volume.cmd ========
 *
 */


MEMORY 
{
   IPRAM       : origin = 0x0,         len = 0x10000
   IDRAM       : origin = 0x80000000,  len = 0x10000
}

SECTIONS
{
        .vectors > IPRAM
        .text    > IPRAM

        .bss     > IDRAM
        .cinit   > IDRAM
        .const   > IDRAM
        .far     > IDRAM
        .stack   > IDRAM
        .cio     > IDRAM
        .sysmem  > IDRAM
}
