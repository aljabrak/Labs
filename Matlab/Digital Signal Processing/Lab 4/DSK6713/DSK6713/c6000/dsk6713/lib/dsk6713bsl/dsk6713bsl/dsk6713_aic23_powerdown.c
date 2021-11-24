/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_aic23_powerDown.c ========
 *  DSK6713_AIC23_powerDown() implementation
 */

#include <dsk6713.h>
#include <dsk6713_aic23.h>

/*
 *  ======== DSK6713_AIC23_powerDown ========
 *  Enable/disable powerdown modes for the DAC and ADC codec subsections
 */
void DSK6713_AIC23_powerDown(DSK6713_AIC23_CodecHandle hCodec, Uint16 sect)
{
    /* Write to codec register */
    DSK6713_AIC23_rset(hCodec, DSK6713_AIC23_POWERDOWN,
        (DSK6713_AIC23_rget(hCodec, DSK6713_AIC23_POWERDOWN) & 0xff00) | (sect & 0xff));
}
