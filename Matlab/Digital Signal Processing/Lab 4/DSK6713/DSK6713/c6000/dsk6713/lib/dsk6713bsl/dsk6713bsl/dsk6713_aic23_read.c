/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_aic23_read.c ========
 *  DSK6713_AIC23_read() implementation
 */

#include <dsk6713.h>
#include <dsk6713_aic23.h>

/*
 *  ======== DSK6713_AIC23_read ========
 *  Read a 32-bit value from the codec
 */
Int16 DSK6713_AIC23_read(DSK6713_AIC23_CodecHandle hCodec, Uint32 *val)
{
    /* If McBSP doesn't have new data available, return false */
    if (!MCBSP_rrdy(DSK6713_AIC23_DATAHANDLE)) {
        return (FALSE);
    }

    /* Read the data */
    *val = MCBSP_read(DSK6713_AIC23_DATAHANDLE);
    return (TRUE);
}
