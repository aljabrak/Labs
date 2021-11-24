/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_flash_write.c ========
 *  DSK6713_FLASH_write() implementation
 */

#include <std.h>
#include <csl.h>

#include <dsk6713.h>
#include <dsk6713_flash.h>

/* Write data to a data range in Flash */
void DSK6713_FLASH_write(Uint32 src, Uint32 dst, Uint32 length)
{
    volatile Uint8 *psrc, *pdst;
    Uint32 i;

    /* Establish source and destination */
    psrc = (Uint8 *)src;
    pdst = (Uint8 *)dst;
    for (i = 0; i < length; i++)
    {
        // Program one 8-bit word
        *((volatile Uint8 *)DSK6713_FLASH_CTL555) = 0xaa;
        *((volatile Uint8 *)DSK6713_FLASH_CTL2AA) = 0x55;
        *((volatile Uint8 *)DSK6713_FLASH_CTL555) = 0xa0;
        *pdst = *psrc;

        // Wait for operation to complete
        while(1)
            if (*pdst == *psrc)
                break;

        pdst++;
        psrc++;
    }

    /* Put back in read mode */
    *((volatile Uint16 *)DSK6713_FLASH_BASE) = 0xf0;
}
