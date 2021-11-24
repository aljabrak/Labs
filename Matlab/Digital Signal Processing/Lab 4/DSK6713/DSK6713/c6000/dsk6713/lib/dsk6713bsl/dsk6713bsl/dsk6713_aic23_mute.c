/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_aic23_mute.c ========
 *  DSK6713_AIC23_mute() implementation
 */

#include <dsk6713.h>
#include <dsk6713_aic23.h>

/*
 *  ======== DSK6713_AIC23_mute ========
 *  Enable/disable codec mute mode
 */
void DSK6713_AIC23_mute(DSK6713_AIC23_CodecHandle hCodec, Int16 mode)
{
    int regval;

    /* Enable mute if mode is true */
    regval = (mode) ? 0x08 : 0x00;

    /* Write to codec registers (left and right) */
    DSK6713_AIC23_rset(hCodec, DSK6713_AIC23_DIGPATH,
        (DSK6713_AIC23_rget(hCodec, DSK6713_AIC23_DIGPATH) & 0xfff7) | regval);
}
