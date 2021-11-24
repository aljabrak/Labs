/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------mcasp1.cmd---------
 *
 */

MEMORY 
{   
   IDRAM       : origin = 0x80000000,  len = 0x020000
   IPRAM       : origin = 0x80020000,  len = 0x040000
}

SECTIONS
{
        .vectors > IDRAM
        .text    > IPRAM
        .bss     > IPRAM
        .cinit   > IDRAM
        .const   > IDRAM
        .far     > IDRAM
        .stack   > IPRAM
        .cio     > IDRAM
        .sysmem  > IDRAM
}
