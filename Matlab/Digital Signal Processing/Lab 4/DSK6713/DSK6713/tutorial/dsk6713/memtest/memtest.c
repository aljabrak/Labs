/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== memtest.c ========
 *  This program allocates and frees memory from
 *  different memory segments.
 */
 
#include <std.h>

#include <log.h>
#include <mem.h>

#include "memtestcfg.h"


#define NALLOCS 2       /* # of allocations from each segment */
#define BUFSIZE 128     /* size of allocations */

extern Int SEG0;

static Void printmem(Int segid);

/*
 *  ======== main ========
 */
Void main()
{
    LOG_printf(&trace, "memtest example started.\n");
}

/*
 *  ======== initTask ========
 */
Void initTask()
{
    Int i;
    Ptr ram[NALLOCS];

    LOG_printf(&trace, "before allocating ...");

    /* print initial memory status */
    printmem(SEG0);

    LOG_printf(&trace, "allocating ...");

    /* allocate some memory from each segment */
    for (i = 0; i < NALLOCS; i++) {
        ram[i] = MEM_alloc(SEG0, BUFSIZE, 0);
#ifdef _28_
        LOG_printf(&trace, "seg %d: ptr = %p", (Arg)SEG0, (Arg)ram[i]);
#else
        LOG_printf(&trace, "seg %d: ptr = %p", SEG0, ram[i]);
#endif
    }

    LOG_printf(&trace, "after allocating ...");

    /* print memory status */
    printmem(SEG0);

    /* free memory */
    for (i = 0; i < NALLOCS; i++) {
        MEM_free(SEG0, ram[i], BUFSIZE);
    }

    LOG_printf(&trace, "after freeing ...");

    /* print memory status */
    printmem(SEG0);

    LOG_printf(&trace, "Test Complete");
}

/*
 *  ======== printmem ========
 */
static Void printmem(Int segid)
{
    MEM_Stat    statbuf;

    MEM_stat(segid, &statbuf);

#ifdef _28_
    LOG_printf(&trace, "seg %d: O 0x%x", (Arg)segid,(Arg)statbuf.size);
    LOG_printf(&trace, "\tU 0x%x\tA 0x%x", (Arg)statbuf.used,(Arg)statbuf.length);
#else
    LOG_printf(&trace, "seg %d: O 0x%x", segid, statbuf.size);
    LOG_printf(&trace, "\tU 0x%x\tA 0x%x", statbuf.used, statbuf.length);
#endif
}
