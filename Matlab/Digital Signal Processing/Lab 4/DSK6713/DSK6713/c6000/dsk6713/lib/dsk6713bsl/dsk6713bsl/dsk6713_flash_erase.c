/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_flash_erase.c ========
 *  DSK6713_FLASH_erase() implementation
 */

#include <std.h>
#include <csl.h>

#include <dsk6713.h>
#include <dsk6713_flash.h>

#define DSK6713_FLASH_SECTORS       11

/* Constant table containing end address of each sector */
static Uint32 sector_end[DSK6713_FLASH_SECTORS] = {
    DSK6713_FLASH_BASE + 0x007fff, /* Sector 0  */
    DSK6713_FLASH_BASE + 0x00ffff, /* Sector 1  */
    DSK6713_FLASH_BASE + 0x017fff, /* Sector 2  */
    DSK6713_FLASH_BASE + 0x01ffff, /* Sector 3  */
    DSK6713_FLASH_BASE + 0x027fff, /* Sector 4  */
    DSK6713_FLASH_BASE + 0x02ffff, /* Sector 5  */
    DSK6713_FLASH_BASE + 0x037fff, /* Sector 6  */
    DSK6713_FLASH_BASE + 0x039fff, /* Sector 7  */
    DSK6713_FLASH_BASE + 0x03bfff, /* Sector 8  */
    DSK6713_FLASH_BASE + 0x03dfff, /* Sector 9  */
    DSK6713_FLASH_BASE + 0x03ffff  /* Sector 10 */
};


/* Erase a segment of Flash memory */
void DSK6713_FLASH_erase(Uint32 start, Uint32 length)
{
    Int16 i;
    volatile Uint8 *pdata;
    Uint32 sector_base, end;

    /* Calculate extents of range to erase */
    end = start + length - 1;

    /* Walk through each sector, erase any sectors within range */
    sector_base = DSK6713_FLASH_BASE;
    for (i = 0; i < DSK6713_FLASH_SECTORS; i++)
    {
        if ((start <= sector_base) && (sector_end[i] <= end))
        {
            /* Start sector erase sequence */
            *((volatile Uint8 *)DSK6713_FLASH_CTL555) = 0xaa;
            *((volatile Uint8 *)DSK6713_FLASH_CTL2AA) = 0x55;
            *((volatile Uint8 *)DSK6713_FLASH_CTL555) = 0x80;
            *((volatile Uint8 *)DSK6713_FLASH_CTL555) = 0xaa;
            *((volatile Uint8 *)DSK6713_FLASH_CTL2AA) = 0x55;

            /* Start erase at sector address */
            pdata = (volatile Uint8 *)sector_base;
            *pdata = 0x30;

            /* Wait for erase to complete */
            while (1)
                if (*pdata & 0x80)
                    break;

            /* Put back in read mode */
            *((volatile Uint8 *)DSK6713_FLASH_BASE) = 0xf0;
        }

        /* Advance to next sector */
        sector_base = sector_end[i] + 1;
    }
}
