/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== lattest.c =======
 *  In this example, a  task created with the configuration tool goes in
 *  a loop forever in which it spends parts of the time doing atomic
 *  operations. The task goes to sleep periodically to allow some idle
 *  time. This example illustrates how to measure the interrupt latency using
 *  an HWI monitor (see the configuration template). It is not intendended to
 *  measure the operating system worst case interrupt latency.
 *
 */

#include <std.h>

#include <que.h>
#include <log.h>
#include <mem.h>
#include <trc.h>
#include <tsk.h>

#include "lattestcfg.h"

#define LOOPS 10000
#define SLEEP 1

/*
   The SLEEP value defined in lattest.c will affect the
   time that RTA use to run its data exchange functions. 
   For some targets, if SLEEP is set to 1 (too low for them), 
   the RTA updates does not occur in real time (but the updates 
   occur once the program is halted). For those targets, 
   this symptom can be avoided by increasing the SLEEP value. 
   In case of the 54xx targets, setting SLEEP to 2,
   rebuilding the program, will make the RTA updates to happen 
   (need to wait for a few seconds after the run button is clicked)
   in real time when the rebuilt program runs."
*/

/*
 *  ======== main ========
 */
Void main(Arg Loops_arg)
{
    LOG_printf(&trace, "lattest example started.\n");

    TRC_enable(TRC_STSHWI | TRC_GBLTARG | TRC_GBLHOST);
}

Void taskFxn(Arg loops_arg)
{
    Void *elem;
    Int i;
    Int loops = ArgToInt (loops_arg);

    elem = (Void *)MEM_alloc(0, sizeof(QUE_Elem), 0);
    
    for ( ; ; ) {
        /* Do some atomic operations for a while. */
        for (i = 0; i < loops; i++) {
            QUE_put(&dummyQue, elem);
            elem = QUE_get(&dummyQue);
        }

        TSK_sleep(SLEEP);
    }
}
