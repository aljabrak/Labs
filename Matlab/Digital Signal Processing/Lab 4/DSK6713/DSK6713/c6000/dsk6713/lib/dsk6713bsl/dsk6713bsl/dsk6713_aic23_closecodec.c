/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_aic23_closeCodec.c ========
 *  DSK6713_AIC23_closeCodec() implementation
 */

#include <dsk6713.h>
#include <dsk6713_aic23.h>

/*
 *  ======== DSK6713_AIC23_closeCodec ========
 *  Close the codec
 */
void DSK6713_AIC23_closeCodec(DSK6713_AIC23_CodecHandle hCodec)
{
    /* Turn the codec off */
    DSK6713_AIC23_rset(hCodec, DSK6713_AIC23_POWERDOWN, 0xff);

    /* Close McBSPs */
    MCBSP_close(DSK6713_AIC23_CONTROLHANDLE);
    MCBSP_close(DSK6713_AIC23_DATAHANDLE);
}
