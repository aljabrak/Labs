/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_dip.c ========
 *  DIP Switch module
 */

#include <csl.h>

#include <dsk6713.h>
#include <dsk6713_dip.h>

void DSK6713_DIP_init()
{
}

Uint32 DSK6713_DIP_get(Uint32 dipNum)
{
    /* Check bounds for dipNum */
    if (dipNum >= 4)
        return (Uint32)-1;

    /* Read DIP switch */
    if ((DSK6713_rget(DSK6713_USER_REG) & (0x10 << dipNum)) == 0)
        return 0;
    else
        return 1;
}

