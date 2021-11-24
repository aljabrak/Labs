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

/* Table of supported frequencies */
static Uint16 freqtable[] =
{
    DSK6713_AIC23_FREQ_8KHZ,  0x06,  // 8000 Hz
    DSK6713_AIC23_FREQ_16KHZ, 0x2c,  // 16000 Hz
    DSK6713_AIC23_FREQ_24KHZ, 0x20,  // 24000 Hz
    DSK6713_AIC23_FREQ_32KHZ, 0x0c,  // 32000 Hz
    DSK6713_AIC23_FREQ_44KHZ, 0x11,  // 44100 Hz
    DSK6713_AIC23_FREQ_48KHZ, 0x00,  // 48000 Hz
    DSK6713_AIC23_FREQ_96KHZ, 0x0e,  // 96000 Hz
    0, 0                             // End of table
};

/*
 *  ======== DSK6713_AIC23_setFreq ========
 *  Set the codec sample rate frequency
 */
void DSK6713_AIC23_setFreq(DSK6713_AIC23_CodecHandle hCodec, Uint32 freq)
{
    Uint16 regval, curr;

    /* Calculate codec clock control register setting, assume USB Mode (12MHz) */
    /* regval will contain CLKIN,SR3..SR0,BOSR */
    curr = 0;
    while(1)
    {
        /* Do nothing if frequency doesn't match */
        if (freqtable[curr] == 0)
            return;

        /* Check for match */
        if (freqtable[curr] == freq)
        {
            regval = freqtable[curr + 1];
            break;
        }

        /* Set up for next pair */
        curr += 2;
    }

    /* Write to codec register */
    DSK6713_AIC23_rset(hCodec, DSK6713_AIC23_SAMPLERATE,
        (DSK6713_AIC23_rget(hCodec, DSK6713_AIC23_SAMPLERATE) & 0xff81) | ((regval & 0x3f) << 1));
}
