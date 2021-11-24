/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== tone.c ========
 *
 *  This example uses the AIC23 codec module of the 6713 DSK Board Support
 *  Library to generate a 1KHz sine wave on the audio outputs for 5 seconds.
 *  The sine wave data is pre-calculated in an array called sinetable.  The
 *  codec operates at 48KHz by default.  Since the sine wave table has 48
 *  entries per period, each pass through the inner loop takes 1 millisecond.
 *  5000 passes through the inner loop takes 5 seconds.
 *
 *  Please see the 6713 DSK help file under Software/Examples for more
 *  detailed information.
 */

/*
 *  DSP/BIOS is configured using the DSP/BIOS configuration tool.  Settings
 *  for this example are stored in a configuration file called tone.cdb.  At
 *  compile time, Code Composer will auto-generate DSP/BIOS related files
 *  based on these settings.  A header file called tonecfg.h contains the
 *  results of the autogeneration and must be included for proper operation.
 *  The name of the file is taken from tone.cdb and adding cfg.h.
 */
#include "tonecfg.h"

/*
 *  The 6713 DSK Board Support Library is divided into several modules, each
 *  of which has its own include file.  The file dsk6713.h must be included
 *  in every program that uses the BSL.  This example also includes
 *  dsk6713_aic23.h because it uses the AIC23 codec module.
 */
#include "dsk6713.h"
#include "dsk6713_aic23.h"

/* Length of sine wave table */
#define SINE_TABLE_SIZE   48

/* Codec configuration settings */
DSK6713_AIC23_Config config = { \
    0x0017,  /* 0 DSK6713_AIC23_LEFTINVOL  Left line input channel volume */ \
    0x0017,  /* 1 DSK6713_AIC23_RIGHTINVOL Right line input channel volume */\
    0x00d8,  /* 2 DSK6713_AIC23_LEFTHPVOL  Left channel headphone volume */  \
    0x00d8,  /* 3 DSK6713_AIC23_RIGHTHPVOL Right channel headphone volume */ \
    0x0011,  /* 4 DSK6713_AIC23_ANAPATH    Analog audio path control */      \
    0x0000,  /* 5 DSK6713_AIC23_DIGPATH    Digital audio path control */     \
    0x0000,  /* 6 DSK6713_AIC23_POWERDOWN  Power down control */             \
    0x0043,  /* 7 DSK6713_AIC23_DIGIF      Digital audio interface format */ \
    0x0081,  /* 8 DSK6713_AIC23_SAMPLERATE Sample rate control */            \
    0x0001   /* 9 DSK6713_AIC23_DIGACT     Digital interface activation */   \
};

/* Pre-generated sine wave data, 16-bit signed samples */
Int16 sinetable[SINE_TABLE_SIZE] = {
    0x0000, 0x10b4, 0x2120, 0x30fb, 0x3fff, 0x4dea, 0x5a81, 0x658b,
    0x6ed8, 0x763f, 0x7ba1, 0x7ee5, 0x7ffd, 0x7ee5, 0x7ba1, 0x76ef,
    0x6ed8, 0x658b, 0x5a81, 0x4dea, 0x3fff, 0x30fb, 0x2120, 0x10b4,
    0x0000, 0xef4c, 0xdee0, 0xcf06, 0xc002, 0xb216, 0xa57f, 0x9a75,
    0x9128, 0x89c1, 0x845f, 0x811b, 0x8002, 0x811b, 0x845f, 0x89c1,
    0x9128, 0x9a76, 0xa57f, 0xb216, 0xc002, 0xcf06, 0xdee0, 0xef4c
};


/*
 *  main() - Main code routine, initializes BSL and generates tone
 */

void main()
{
    DSK6713_AIC23_CodecHandle hCodec;
    Int16 msec, sample;

    /* Initialize the board support library, must be called first */
    DSK6713_init();

    /* Start the codec */
    hCodec = DSK6713_AIC23_openCodec(0, &config);

    /* Generate a 1KHz sine wave for 5 seconds */
    for (msec = 0; msec < 5000; msec++)
    {
        for (sample = 0; sample < SINE_TABLE_SIZE; sample++)
        {
            /* Send a sample to the left channel */
            while (!DSK6713_AIC23_write(hCodec, sinetable[sample]));

            /* Send a sample to the right channel */
            while (!DSK6713_AIC23_write(hCodec, sinetable[sample]));
        }
    }

    /* Close the codec */
    DSK6713_AIC23_closeCodec(hCodec);
}
