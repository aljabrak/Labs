/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_flash_read.c ========
 *  DSK6713_FLASH_read() implementation
 */

#include <std.h>
#include <csl.h>

#include <dsk6713.h>
#include <dsk6713_flash.h>

/* Read data from a data range in Flash */
void DSK6713_FLASH_read(Uint32 src, Uint32 dst, Uint32 length)
{
    Uint8 *psrc, *pdst;
    Uint32 i;

    /* Establish source and destination */
    psrc = (Uint8 *)src;
    pdst = (Uint8 *)dst;
    for (i = 0; i < length; i++)
    {
        *pdst++ = *psrc++;
    }
}
