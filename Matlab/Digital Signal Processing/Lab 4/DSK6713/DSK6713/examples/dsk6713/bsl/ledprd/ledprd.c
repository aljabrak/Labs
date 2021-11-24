/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== ledprd.c ========
 *
 *  This example blinks LED #0 at a rate of about 4 times per second using
 *  the LED module of the the 6713 DSK Board Support Library.  The example
 *  also reads the state of DIP switch #3 and lights LED #3 if the switch
 *  is depressed or turns it off if the switch is not depressed.
 *
 *  When the program is run, DSP/BIOS initializes itself and calls the main()
 *  function.  Main() initializes the BSL then exits and returns control back
 *  to DSP/BIOS.  The real work is done inside blinkLED0() which is a DSP/BIOS
 *  periodic thread that is run every 125ms.
 *
 *  A second thread named blinkLED1() is also included that blinks LED #1
 *  asynchronously with blinkLED0() to demonstrate DSP/BIOS multitasking.
 *  It is not enabled by default but can be added by creating a new periodic
 *  thread entry for it in the DSP/BIOS scheduler.
 *
 *  Please see the 6713 DSK help file under Software/Examples for more
 *  detailed information.
 */

/*
 *  DSP/BIOS is configured using the DSP/BIOS configuration tool.  Settings
 *  for this example are stored in a configuration file called ledprd.cdb.  At
 *  compile time, Code Composer will auto-generate DSP/BIOS related files
 *  based on these settings.  A header file called ledprdcfg.h contains the
 *  results of the autogeneration and must be included for proper operation.
 *  The name of the file is taken from ledprd.cdb and adding cfg.h.
 */
#include "ledprdcfg.h"

/*
 *  The 6713 DSK Board Support Library is divided into several modules, each
 *  of which has its own include file.  The file dsk6713.h must be included
 *  in every program that uses the BSL.  This example also includes
 *  dsk6713_led.h and dsk6713_dip.h because it uses the LED and DIP modules.
 */
#include "dsk6713.h"
#include "dsk6713_led.h"
#include "dsk6713_dip.h"


/*
 *  blinkLED0() - Blink LED #0 and set LED #3 based on the state of DIP switch
 *                #3.  If the switch is down, the LED is turned on.  If the
 *                switch is up, the LED is turned off.
 *
 *                blinkLED0 is a periodic thread that is called every 200ms
 *                from the DSP/BIOS scheduler.  It is configured in the
 *                DSP/BIOS configuration file (ledprd.cdb) under Scheduling
 *                --> PRD --> PRD_blinkLED0.  Right click PRD_blinkLED0 and
 *                select Properties to view its settings.
 */

void blinkLED0()
{
    /* Toggle LED #0 */
    DSK6713_LED_toggle(0);

    /* Check DIP switch #3 and light LED #3 accordingly, 0 = switch pressed */
    if (DSK6713_DIP_get(3) == 0)
        /* Switch pressed, turn LED #3 on */
        DSK6713_LED_on(3);
    else
        /* Switch pressed, turn LED #3 off */
        DSK6713_LED_off(3);
}


/*
 *  blinkLED1() - Blink LED #1.
 *
 *                blinkLED1 is a periodic thread that can be called from the
 *                DSP/BIOS scheduler.  By default, it is not active.  To make
 *                it active, create a new PRD entry called PRD_blinkLED1 in
 *                the DSP/BIOS configuration file (ledprd.cdb) under
 *                Scheduling --> PRD.  Right click PRD_blinkLED1 and select
 *                properties to configure it.  Change the function field to
 *                _blinkLED1 and the period field to 100 to make blinkLED1()
 */

void blinkLED1()
{
    /* Toggle LED #1 */
    DSK6713_LED_toggle(1);
}


/*
 *  main() - Initialize BSL then drop into DSP/BIOS idle loop
 */

void main()
{
    /* Initialize the board support library, must be first BSL call */
    DSK6713_init();

    /* Initialize the LED and DIP switch modules of the BSL */
    DSK6713_LED_init();
    DSK6713_DIP_init();
}
