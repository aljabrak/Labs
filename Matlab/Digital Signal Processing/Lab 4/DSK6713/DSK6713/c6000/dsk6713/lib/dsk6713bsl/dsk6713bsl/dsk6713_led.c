/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_led.c ========
 *  LED module for the DSK6713
 */

#include <csl.h>

#include "dsk6713.h"
#include "dsk6713_led.h"

static Int16 ledstate;

void DSK6713_LED_init()
{
    /* Turn all LEDs off */
    ledstate = 0;
    DSK6713_rset(DSK6713_USER_REG, ledstate);
}

void DSK6713_LED_off(Uint32 ledNum)
{
    /* Check bounds for ledNum */
    if (ledNum >= 4)
        return;

    /* Clear the LED bit */
    ledstate &= ~(1 << ledNum);
    DSK6713_rset(DSK6713_USER_REG, ledstate);
}

void DSK6713_LED_on(Uint32 ledNum)
{
    /* Check bounds for ledNum */
    if (ledNum >= 4)
        return;

    /* Set the LED bit */
    ledstate |= 1 << ledNum;
    DSK6713_rset(DSK6713_USER_REG, ledstate);
}

void DSK6713_LED_toggle(Uint32 ledNum)
{
    /* Check bounds for ledNum */
    if (ledNum >= 4)
        return;

    /* Toggle the LED bit */
    if ((DSK6713_rget(DSK6713_USER_REG) & (1 << ledNum)) == 0)
        DSK6713_LED_on(ledNum);
    else
        DSK6713_LED_off(ledNum);
}


