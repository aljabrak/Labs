/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== mutex.c ========
 */

#include <std.h>

#include <clk.h>
#include <log.h>
#include <tsk.h>
#include <sem.h>

#include "mutexcfg.h"

Void    mutex1();
Void    mutex2();

LgUns   tsk1count = 0;
LgUns   tsk2count = 0;
LgUns   maincount = 0;

/*
 *  ======== main ========
 */
Void main()
{ 
     /* Does nothing */
}

/*
 *  ======== mutex1 ========
 */
Void mutex1()
{ 
    LgUns tempvar;
    LgUns time;

    for (;;) {
        LOG_printf(&trace, "\n  Running mutex1 function");
        if (SEM_count(&sem) == 0) {
            LOG_printf(&trace, "Sem blocked in mutex1");
        }
        SEM_pend(&sem, SYS_FOREVER); 
        tempvar = maincount;
        time = CLK_getltime();
        /* wait for two system ticks to pass */
        while (CLK_getltime() <= (time + 1)) {
             ;
        }
        tsk1count++;
        maincount = ++tempvar;
        /* combine hex values to display LgUns */
#ifdef _28_
        LOG_printf(&trace, "mutex1: loop 0x%04x%04x;", (Arg)(tsk1count >> 16), (Arg)(tsk1count & 0xffff));
        LOG_printf(&trace, "              total count = 0x%04x%04x", (Arg)(maincount >> 16), (Arg)(maincount & 0xffff)); 
#else
        LOG_printf(&trace, "mutex1: loop 0x%04x%04x;", (Int)(tsk1count >> 16), (Int)(tsk1count & 0xffff));
        LOG_printf(&trace, "              total count = 0x%04x%04x", (Int)(maincount >> 16), (Int)(maincount & 0xffff)); 
#endif

        SEM_post(&sem);
        TSK_sleep(1);
    }
}

/*
 *  ======== mutex2 ========
 */
Void mutex2()
{
    LgUns tempvar;

    for (;;) {
        LOG_printf(&trace, "\n  Running mutex2 function");
        if (SEM_count(&sem) == 0) {
            LOG_printf(&trace, "Sem blocked in mutex2");
        }
        SEM_pend(&sem, SYS_FOREVER);
        tempvar = maincount;
        tsk2count++;
        maincount = ++tempvar;
        /* combine hex values to display LgUns */
#ifdef _28_
        LOG_printf(&trace, "mutex2: loop 0x%04x%04x;", (Arg)(tsk2count >> 16), (Arg)(tsk2count & 0xffff));
        LOG_printf(&trace, "              total count = 0x%04x%04x", (Arg)(maincount >> 16), (Arg)(maincount & 0xffff));
#else
        LOG_printf(&trace, "mutex2: loop 0x%04x%04x;", (Int)(tsk2count >> 16), (Int)(tsk2count & 0xffff));
        LOG_printf(&trace, "              total count = 0x%04x%04x", (Int)(maincount >> 16), (Int)(maincount & 0xffff));
#endif
        SEM_post(&sem);
        TSK_sleep(1);
    }
}
