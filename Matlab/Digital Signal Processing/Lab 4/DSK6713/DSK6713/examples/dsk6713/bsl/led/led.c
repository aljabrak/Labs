/*
 *  Copyright 2003 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== led.c ========
 *
 *  This example blinks LED #0 at a rate of about 2.5 times per second using
 *  the LED module of the the DSK6713 Board Support Library.  The example
 *  also reads the state of DIP switch #3 and lights LED #3 if the switch
 *  is depressed or turns it off if the switch is not depressed.
 *
 *  The purpose of this example is to demonstrate basic BSL usage as well
 *  as provide a project base for your own code.
 *
 *  Please see the DSK6713 help file for more detailed information.
 */

/*
 *  DSP/BIOS is configured using the DSP/BIOS configuration tool.  Settings
 *  for this example are stored in a configuration file called led.cdb.  At
 *  compile time, Code Composer will auto-generate DSP/BIOS related files
 *  based on these settings.  A header file called ledcfg.h contains the
 *  results of the autogeneration and must be included for proper operation.
 *  The name of the file is taken from led.cdb and adding cfg.h.
 */
#include "ledcfg.h"

/*
 *  The Board Support Library is divided into several modules, each
 *  of which has its own include file.  The file dsk6713.h must be included
 *  in every program that uses the BSL.  This example also includes
 *  dsk6713_led.h and dsk6713_dip.h because it uses the LED and DIP modules.
 */
#include "dsk6713.h"
#include "dsk6713_led.h"
#include "dsk6713_dip.h"


/*
 *  main() - Main code routine, initializes BSL and runs LED application
 */

/*
 *  EXTRA: Pressing DIP switch #3 changes LED #3 from off to on.
 */

void main()
{
    /* Initialize the board support library, must be first BSL call */
    DSK6713_init();

    /* Initialize the LED and DIP switch modules of the BSL */
    DSK6713_LED_init();
    DSK6713_DIP_init();

    while(1)
    {
        /* Toggle LED #0 */
        DSK6713_LED_toggle(0);

        /* Check DIP switch #3 and light LED #3 accordingly, 0 = switch pressed */
        if (DSK6713_DIP_get(3) == 0)
            /* Switch pressed, turn LED #3 on */
            DSK6713_LED_on(3);
        else
            /* Switch not pressed, turn LED #3 off */
            DSK6713_LED_off(3);

        /* Spin in a software delay loop for about 200ms */
        DSK6713_waitusec(200000);
    }
}
