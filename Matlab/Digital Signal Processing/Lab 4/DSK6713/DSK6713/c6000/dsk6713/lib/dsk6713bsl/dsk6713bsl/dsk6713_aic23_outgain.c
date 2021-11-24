/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_aic23_setfreq.c ========
 *  DSK6713_AIC23_setFreq() implementation
 */

#include <dsk6713.h>
#include <dsk6713_aic23.h>

/*
 *  ======== DSK6713_AIC23_outGain ========
 *  Set the output gain on the codec
 */
void DSK6713_AIC23_outGain(DSK6713_AIC23_CodecHandle hCodec, Uint16 outGain)
{
    /* Write to codec registers (left and right) */
    DSK6713_AIC23_rset(hCodec, DSK6713_AIC23_LEFTHPVOL,
        (DSK6713_AIC23_rget(hCodec, DSK6713_AIC23_LEFTHPVOL) & 0xff80) | (outGain & 0x7f));
    DSK6713_AIC23_rset(hCodec, DSK6713_AIC23_RIGHTHPVOL,
        (DSK6713_AIC23_rget(hCodec, DSK6713_AIC23_RIGHTHPVOL) & 0xff80) | (outGain & 0x7f));
}

