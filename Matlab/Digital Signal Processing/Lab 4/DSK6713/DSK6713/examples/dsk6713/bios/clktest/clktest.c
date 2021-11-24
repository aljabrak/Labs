/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== clktest.c =======
 *  In this example, a task goes to sleep # number of ticks and 
 *  prints the time after it wakes up.
 *
 */

#include <std.h>

#include <log.h>
#include <clk.h>
#include <tsk.h>

#include "clktestcfg.h"

/*
 *  ======== main ========
 */
Void main()
{
    LOG_printf(&trace, "clktest example started.\n");
}

Void taskFxn(Arg value_arg)
{
    Int value = ArgToInt (value_arg); 
    Uns ticks;
#ifdef _28_ 
    LOG_printf(&trace, "The time in task is: %d ticks", (Arg)TSK_time());
#else 
    LOG_printf(&trace, "The time in task is: %d ticks", (Int)TSK_time());
#endif

    ticks = (value * CLK_countspms()) / CLK_getprd();

#ifdef _28_
    LOG_printf(&trace, "task going to sleep for %d ticks... ", (Arg)ticks);
#else
    LOG_printf(&trace, "task going to sleep for %d ticks... ", ticks);
#endif

    TSK_sleep(ticks);

#ifdef _28_
    LOG_printf(&trace, "...awake! Time is: %d ticks", (Arg)TSK_time());
#else
    LOG_printf(&trace, "...awake! Time is: %d ticks", (Int)TSK_time());
#endif
}
    
