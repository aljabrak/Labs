/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/*
 *---------main_edma1_useBios.c---------
 * This program uses the timers to trigger EDMA events. These events in turn 
 * trigger linked EDMA parameter tables to fill a ping pong buffer structure. 
 * Set a breakpoint on swiProcessFunc(int arg). Then open two memory windows. 
 * Use ping as the address for one memory window and pong for the other. Then 
 * run the application. You'll note that the program bounces between the ping 
 * and pong buffers filling each with a value that comes from the source. 
 * (Note: This example runs with CACHE enable).
 */ 

#include <std.h>
#include <swi.h>
#include <log.h>
#include <clk.h>

#include <csl.h>
#include <csl_cache.h>
#include <csl_edma.h>
#include <csl_timer.h>
#include <csl_irq.h>

/*----------------------------------------------------------------------------*/

/* declare DSP/BIOS objects created with the configuration tool */
extern far SWI_Obj SwiMain;
extern far LOG_Obj LogMain;
extern far SWI_Obj swiProcess;
extern far LOG_Obj trace;

/* Pick which EDMA transfer completion interrupt we want to use */
#define TCCINTNUM   10

/* define some constants */
#define BUFF_SZ  256              /* ping-pong buffer sizes in # of ints  */
#define FCPU     150000000        /* CPU clock frequency                  */
#define SRATE    8000             /* data sample rate (simulated w/timer  */
#define TPRD     (FCPU/(4*SRATE)) /* timer period                         */

/* Create the buffers. We want to align the buffers to be cache friendly */
/* by aligning them on an L2 cache line boundary.                        */
#pragma DATA_ALIGN(ping,128);
#pragma DATA_ALIGN(pong,128);
#pragma DATA_ALIGN(outbuff,128);
int ping[BUFF_SZ];
int pong[BUFF_SZ];
int outbuff[BUFF_SZ];

/* These two variables serve as the data sources for this example. */
/* Also want to align these on a cache line boundary since they    */
/* sources of EDMA transfers.                                      */
#pragma DATA_ALIGN(ping_data,128);
#pragma DATA_ALIGN(pong_data,128);
static int ping_data;
static int pong_data;

/* global variable used to track the ping-pong'ing */
static int pingpong = 0;

/* declare some CSL objects */
TIMER_Handle hTimer;   /* Handle for the timer device                 */
EDMA_Handle hEdma;     /* Handle for the EDMA channel                 */
EDMA_Handle hEdmaPing; /* Handle for the ping EDMA reload parameters  */
EDMA_Handle hEdmaPong; /* Handle for the pong EDMA reload parameters  */
EDMA_Config cfgEdma;   /* EDMA configuration structure                */

/* Create the EDMA configuration structure for ping transfers */
EDMA_Config cfgEdmaPing = {  
  EDMA_OPT_RMK(
    EDMA_OPT_PRI_LOW,
    EDMA_OPT_ESIZE_32BIT,
    EDMA_OPT_2DS_NO,
    EDMA_OPT_SUM_NONE,
    EDMA_OPT_2DD_NO,
    EDMA_OPT_DUM_INC,
    EDMA_OPT_TCINT_YES,
    EDMA_OPT_TCC_OF(TCCINTNUM),
    EDMA_OPT_LINK_YES,
    EDMA_OPT_FS_NO
  ),
  EDMA_SRC_OF(&ping_data),
  EDMA_CNT_OF(BUFF_SZ),
  EDMA_DST_OF(ping),
  EDMA_IDX_OF(0x00000004),
  EDMA_RLD_OF(0x00000000)
};                         

/* Create the EDMA configuration structure for pong transfers */
EDMA_Config cfgEdmaPong = {
  EDMA_OPT_RMK(
    EDMA_OPT_PRI_LOW,
    EDMA_OPT_ESIZE_32BIT,
    EDMA_OPT_2DS_NO,
    EDMA_OPT_SUM_NONE,
    EDMA_OPT_2DD_NO,
    EDMA_OPT_DUM_INC,
    EDMA_OPT_TCINT_YES,
    EDMA_OPT_TCC_OF(TCCINTNUM),
    EDMA_OPT_LINK_YES,
    EDMA_OPT_FS_NO
  ),
  EDMA_SRC_OF(&pong_data),
  EDMA_CNT_OF(BUFF_SZ),
  EDMA_DST_OF(pong),
  EDMA_IDX_OF(0x00000004),
  EDMA_RLD_OF(0x00000000)
};                         
 
    
/*----------------------------------------------------------------------------*/
void main(){

  /* initialize the CSL library */
  CSL_init();

  /* initialize the input source data */
  ping_data=0x00000000;
  pong_data=0x80000000;
  
  /* Since these variables are the source of an EDMA transfer, we     */
  /* need to do write back since we just wrote to them. */
  CACHE_wbL2(&ping_data, 4, CACHE_WAIT);
  CACHE_wbL2(&pong_data, 4, CACHE_WAIT);

  /* Let's disable/clear related interrupts just in case they are pending */
  /* fram a previous run of the program.                                  */  
  IRQ_reset(IRQ_EVT_EDMAINT);
  EDMA_intDisable(TCCINTNUM);
  EDMA_intClear(TCCINTNUM);
  
  /* Although not required, let's clear all of the EDMA parameter RAM. */
  /* This makes it easier to view the RAM and see the changes as we    */
  /* configure it.                                                     */
  EDMA_clearPram(0x00000000);
   
  /* Let's open up a timer device, we'll use this to simulate input events */
  /* at a gien sample rate.                                                */
  hTimer = TIMER_open(TIMER_DEV1, TIMER_OPEN_RESET);

  /* Lets open up the EDMA channel associated with timer #1. */
  hEdma = EDMA_open(EDMA_CHA_TINT1, EDMA_OPEN_RESET);

  /* We also need two EDMA reload parameter sets so let's allocate them */
  /* here. Notice the -1, this means allocate any availale tale.        */
  hEdmaPing = EDMA_allocTable(-1);
  hEdmaPong = EDMA_allocTable(-1);

  /* Let's copy the ping reload configuration structure to an */
  /* intermediate configuration structure.                    */
  cfgEdma = cfgEdmaPing;
  
  /* Let's initialize the link fields of the configuration structures */
  cfgEdmaPing.rld = EDMA_RLD_RMK(0,hEdmaPing);
  cfgEdmaPong.rld = EDMA_RLD_RMK(0,hEdmaPong);
  cfgEdma.rld     = EDMA_RLD_RMK(0,hEdmaPong);

  /* Now let's program up the EDMA channel with the configuration structure */
  EDMA_config(hEdma, &cfgEdma);   
  
  /* Let's also configure the reload parameter tables in the EDMA PRAM */
  /* with the values in the configuration structures.                  */
  EDMA_config(hEdmaPing, &cfgEdmaPing);
  EDMA_config(hEdmaPong, &cfgEdmaPong);   

  /* Configure up the timer. */
  TIMER_configArgs(hTimer, 
    TIMER_CTL_OF(0x00000200), 
    TIMER_PRD_OF(TPRD), 
    TIMER_CNT_OF(0)
  );   

  /* Enable the related interrupts */
  IRQ_enable(IRQ_EVT_EDMAINT);
  EDMA_intEnable(TCCINTNUM);        
  
  /* Enable the EDMA channel */
  EDMA_enableChannel(hEdma);   
  
  /* Finally, enable the timer which will drive everything. */
  TIMER_start(hTimer);
}

/*----------------------------------------------------------------------------*/
void swiProcessFunc(int arg){

  int *inbuff;
  int x;

  if (pingpong){

    /* If pingpong is 0, then we own the ping input buffer */
    inbuff = ping;
    LOG_printf(&trace,"Ping");
    
  }else{

    /* If pingpong is 1, then we own the pong input buffer */
    inbuff = pong;
    LOG_printf(&trace,"Pong");

  }  

  /* Now let's process the input buffer, for simplicity, we'll */
  /* just copy it to the output buffer.                        */
  for (x=0; x<BUFF_SZ; x++) {
    outbuff[x] = inbuff[x];
  }

  /* If this example is enhanced to actually do something with the  */
  /* output buffer such as DMA it somewhere, you will want to write back */
  CACHE_wbL2(outbuff, BUFF_SZ * 4, CACHE_WAIT);
  
  /* Since we're done processing the input buffer, write back and invalidate */
  /* it from cache to ensure we read a fresh version the next time.         */
  CACHE_wbInvL2(inbuff, BUFF_SZ * 4, CACHE_WAIT);
}

/*----------------------------------------------------------------------------*/
void hwiEdmaIsr(int arg){
  
  /* Clear the pending interrupt from the EDMA interrupt pending register */
  EDMA_intClear(TCCINTNUM);
  
  /* Perform ping-pong */
  pingpong = (pingpong + 1) & 1;

  /* Based on if we ping'ed or pong'ed, we need to set the EDMA channel */
  /* link address for the NEXT frame.                                   */
  
  if (pingpong){
    /* Currently doing pong so setup next frame for ping */                     
  
    /* Modify the input data source, this just simulates */
    /* the input data changing.                          */
    ping_data++;

    /* Rememer to write back this variable out of the cache */
    /* since it's the source of an EDMA transfer       */
    CACHE_wbL2(&ping_data, 4, CACHE_WAIT);

    /* Now filling pong so set link to ping */
    EDMA_link(hEdma,hEdmaPing);
    
  }else{
    /* Currently doing ping so setup next frame for pong */                     
  
    /* Modify the output data source, this just simulates */
    /* the input data changing.                           */
    pong_data++;
    
    /* Rememer to flush this variable out of the cache */
    /* since it's the source of an EDMA transfer       */
    CACHE_wbL2(&pong_data, 4, CACHE_WAIT);

    /* Now filling ping so set link to pong */
    EDMA_link(hEdma,hEdmaPong);
    
  }  
 
  /* Notify the app that we just ping-pong'ed */
  SWI_post(&swiProcess);
}
