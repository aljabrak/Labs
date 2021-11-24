/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== tsktest.c =======
 *  In this example, 3 tasks have been created with the Configuration
 *  Tool.  Each task has a computation loop consisting of a LOG_printf()
 *  followed by a TSK_yield().  This causes a round robin scheduling for
 *  these tasks of equal priority.
 */

#include <std.h>

#include <log.h>
#include <tsk.h>

#include "tsktestcfg.h"

#define NLOOPS  5

Void task(Arg id_arg);  /* Function for tasks created with Config Tool */ 

/*
 *  ======== main ========
 */
Void main()
{
}

/*
 *  ======== task ========
 */
Void task(Arg id_arg)
{
    Int     id = ArgToInt (id_arg);
    Int     i;
    
    for (i = 0; i < NLOOPS ; i++) {
#ifdef _28_        
        LOG_printf(&trace, "Loop %d: Task %d Working", (Arg)i, (Arg)id);
#else
        LOG_printf(&trace, "Loop %d: Task %d Working", i, id);
#endif
        TSK_yield();
    }
#ifdef _28_    
    LOG_printf(&trace, "Task %d DONE", (Arg)id);
#else
    LOG_printf(&trace, "Task %d DONE", id);
#endif
}
