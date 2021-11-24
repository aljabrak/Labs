/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_aic23_write.c ========
 *  DSK6713_AIC23_write() implementation
 */

#include <dsk6713.h>
#include <dsk6713_aic23.h>

/*
 *  ======== DSK6713_AIC23_write ========
 *  Write a 32-bit value to the codec
 */
Int16 DSK6713_AIC23_write(DSK6713_AIC23_CodecHandle hCodec, Uint32 val)
{
    /* If McBSP not ready for new data, return false */
    if (!MCBSP_xrdy(DSK6713_AIC23_DATAHANDLE)) {
        return (FALSE);
    }

    /* Write 16 bit data value to DXR */
    MCBSP_write(DSK6713_AIC23_DATAHANDLE, val);

    /* Short delay for McBSP state machine to update */
    asm(" nop");
    asm(" nop");
    asm(" nop");
    asm(" nop");
    asm(" nop");
    asm(" nop");
    asm(" nop");
    asm(" nop");

    return(TRUE);
}
