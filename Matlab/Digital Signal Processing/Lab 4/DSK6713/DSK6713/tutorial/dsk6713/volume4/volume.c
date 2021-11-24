/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/***************************************************************************/
/*                                                                         */
/*     V O L U M E . C                                                     */
/*                                                                         */
/*     Audio gain processing using CLK ISR as data source, a software      */
/*     interrupt for processing routine, and a periodic function to        */ 
/*     control load changes.                                               */
/*                                                                         */
/***************************************************************************/

#include <std.h>

#include <log.h>
#include <swi.h>
#include <clk.h>
#include <sts.h>
#include <trc.h>
#include <rtdx.h>

#include "volumecfg.h"

#include "volume.h"

/* Global declarations */
Int inp_buffer[BUFSIZE];       /* processing data buffers */
Int out_buffer[BUFSIZE];

Int gain = MINGAIN;             /* volume control variable */
Uns processingLoad = BASELOAD;  /* processing routine load value */

/*
 * RTDX channels
 *
 * NOTE: This is a C macro that initializes an RTDX channel structure.
 */
RTDX_CreateInputChannel(control_channel);

/* Functions */
extern Void load(Uns loadValue);

Int processing(Int *input, Int *output);
Void dataIO(Void);
Void loadchange(Void);

/* The following global declarations are used for cpu load calibration */

Float  startupLoad = 0.0;   /* initial cpu load when the processingLoad is 0 */
Int startupLoadDone = 0;    /* flag to indicate that startupLoad is calculated */
/*LgUns mips; (defined in volume.h) mips = (actual cpu mips) / 100 */
/*Uns sliderMaxValue;(defined in volume.h)  maximum slider position */
Uns numberOfSwiPosts;       /* no. of times processing_SWI runs in 1 sec */
Uns swiMailbox;             /* mailbox value of processing_SWI */ 
Void  startupLoadCalc();          /* calculates startup load */                 
LgUns getLoadFactor(Int control); /* calibrates the cpu load */


/*
 * ======== main ========
 */
Void main()
{
  
    LOG_printf(&trace,"volume example started\n" );
    LOG_printf(&trace, "cpu load calibration works after 6 secs\n");
    
    RTDX_enableInput(&control_channel);
    
    /*
     * start the one-shot PRD object which  runs after 6 secs (magic value) from
     * DSP/BIOS startup to calculate startup cpu load. This is due to startupload
     * is stabilized only after 5 to 6 seconds from BIOS startup.
     */
    PRD_start(&calcStartupLoad); 
 
    /* fall into DSP/BIOS idle loop */
    return;
}

/*
 *  ======== processing ========
 *
 * FUNCTION: Called from processing_SWI to apply signal processing
 *           transform to input signal.
 *
 * PARAMETERS: address of input and output buffers.
 *
 * RETURN VALUE: TRUE.
 */
Int processing(Int *input, Int *output)
{
    Int size = BUFSIZE;

    while(size--){
        *output++ = *input++ * gain;
    }

    /* enable performance instrumentation only if TRC_USER0 is set */
    if (TRC_query(TRC_USER0) == 0) {
        STS_set(&processingLoad_STS, CLK_gethtime());
    }
    /* additional processing load */
    load(processingLoad);
    if (TRC_query(TRC_USER0) == 0) {    
        STS_delta(&processingLoad_STS, CLK_gethtime());
    }
    
    return(TRUE);
}

/*
 *  ======== dataIO ========
 *
 * FUNCTION: Called from timer ISR to fake a periodic hardware interrupt that
 *           reads in the input signal and outputs the processed signal.
 *
 * PARAMETERS: none.
 *
 * RETURN VALUE: none.
 */
Void dataIO() 
{
    SWI_dec(&processing_SWI);   /* post processing_SWI software interrupt */   
}

/*
 *  ======== loadchange ========
 *
 * FUNCTION: Called from loadchange_PRD to periodically update the load value.
 *
 * PARAMETERS: none.
 *
 * RETURN VALUE: none.
 */
Void loadchange()
{
    static Int control = MINCONTROL;

    /* Read new load control when host sends it */
    if (!RTDX_channelBusy(&control_channel)) {
        RTDX_readNB(&control_channel, &control, sizeof(control));
        if ((control < MINCONTROL) || (control > MAXCONTROL)) {
            LOG_printf(&trace,"Control value out of range");
        }
        else {
            if(control) {
                processingLoad = getLoadFactor(control);
            }    
            else {
                processingLoad =  control;
            }    
            LOG_printf(&trace,"Load value = %d", control);
        }
    }
}


/*
 *  ======== startupLoadCalc ========
 *
 * FUNCTION: Called from periodic object calcStartupLoad to calculate the
 *           startup cpu load.
 *
 * PARAMETERS: none.
 *
 * RETURN VALUE: none.
 */

Void startupLoadCalc()
{
    LgInt max, num, acc;    /* max, num, acc fields of STS Object              */
    Float swiDuration;      /* time gap in ms between two successive SWI posts */
    LgUns countPerMilliSec; /* no. of high resultion ticks in 1 ms             */
    LgUns prdRegValue;      /* value of the periodic register value            */
    Float milliSecPerInt;   /* no. of milli seconds for interrupt              */
 
     /*
      * Read BIOS object IDL_busyObj STS object to get the statistics
      * num : no. of times the DSP/BIOS idle loop is run in 1 second.
      * max : minimum no. of timer ticks taken for one idle loop execution.
      * acc : total no. of timer ticks elapsed in 1 second.
      * Note that the duration of timer ticks (i.e 1 second) depends upon the
      * refresh rate specified in the RTA panel properties. However startup cpu 
      * load calculation is not effected by this duration.
      */ 
    
#if defined(_54_) /* Handle specific implementation for 54x */
    Int maxh, maxl, numh, numl, acch, accl;
    
    maxh = IDL_busyObj.maxh;
    maxl = IDL_busyObj.maxl;
    numh = IDL_busyObj.numh;
    numl = IDL_busyObj.numl;
    acch = IDL_busyObj.acch;
    accl = IDL_busyObj.accl;
   
    max = maxh;
    max = (max << 16) | (0x0000ffff & maxl);
    num = numh;
    num = (num << 16) | (0x0000ffff & numl);    
    acc = acch;
    acc = (acc << 16) | (0x0000ffff & accl);
#else
    max = IDL_busyObj.max;    
    num = IDL_busyObj.num;   
    acc = IDL_busyObj.acc;           
#endif
    
    /* calculate startup cpu load using  num, acc and max */
    
    startupLoad = (num * max * PERCENT) / acc; /* gives idleload%  */
    
    if (startupLoad < 0) {/* since STS maintains -ve numbers for max/acc field */
         startupLoad *= -1;
    }     
    
    startupLoad = PERCENT - startupLoad ; /* cpuload% =  100 - idleload% */
    
    /*set flag to indicate that startup cpu load is calculated*/
    startupLoadDone = 1; 
        
    /* get the high resolution timer ticks per 1 ms */    
    countPerMilliSec = CLK_countspms();
    
    /* get the periodic register value */
    prdRegValue = CLK_getprd();
    
    /*
     * calculate no. of ms for interrupt. 1 interrupt = periodic register value
     * times the high resolution timer tick. 1.0/countPerMilliSec gives time
     * in ms for 1 high resolution timer tick. hence no.of ms for interrupt = 
     * periodic register value * time for one high resulution tick in ms 
     */
    milliSecPerInt = prdRegValue * 1.0 / countPerMilliSec;
    
    /* get the swi initial mailbox value  */
    swiMailbox  = processing_SWI.initkey;
    
    /* 
     * calculate time gap in ms between two successive swi posts.
     * since swi mailbox is decremented at every interrupt, time taken before
     * the swi is posted = time for interrupt  * swi mailbox
     */
    swiDuration =  swiMailbox * milliSecPerInt;
    
    /* calculate number of times swi can be posted in 1 s(1000 ms) */
    numberOfSwiPosts = 1000 / swiDuration; /* 1000 ms / swiDuration */
}

/*
 *  ======== getLoadFactor ========
 *
 * FUNCTION: Called from loadchange to calibrate the cpu load.
 *
 * PARAMETERS: slider position.
 *
 * RETURN VALUE: actual no. of NOPs supplied to the load function.
 */
 
LgUns getLoadFactor(Int control)
{
    Float expectedLoad;
    LgUns loadCycles;
    
    expectedLoad = control * PERCENT / sliderMaxValue;
    
    /* 
     * calibrate only if expected cpu load is more than startup cpu load 
     * and startup cpu load is calculated.
     * expectedload = startupload + (loadcycles * numberOfSwiPosts) / mips.
     * because load function runs numberOfSwiPosts times in 1 second
     * and it executes loadcycles nops each time it is run.
     */
    if ( (expectedLoad > startupLoad) && startupLoadDone) {
        loadCycles = (mips * (expectedLoad - startupLoad)) / numberOfSwiPosts;
    }   
    else { 
        loadCycles = 0;
    }   
    
    return loadCycles / MULTIPLYFACTOR;
}
