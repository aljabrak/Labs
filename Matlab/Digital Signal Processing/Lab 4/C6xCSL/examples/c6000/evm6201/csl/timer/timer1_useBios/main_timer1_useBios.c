/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 06-11-03 (barracuda-m10)" */
/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... main.c
* DATE CREATED.. 01/11/2000
* LAST MODIFIED. 09/27/2000
\******************************************************************************/
#include <std.h>
#include <swi.h>
#include <log.h>

#include <csl.h>
#include <csl_irq.h>
#include <csl_timer.h>

/*----------------------------------------------------------------------------*/
void TimerEventHandler();

extern far LOG_Obj LogMain;

static TIMER_Handle hTimer;
static Uint32 TimerEventId;

static Uint32 TimerControl = TIMER_CTL_RMK(
  TIMER_CTL_INVINP_NO,
  TIMER_CTL_CLKSRC_CPUOVR4,
  TIMER_CTL_CP_PULSE,
  TIMER_CTL_HLD_YES,
  TIMER_CTL_GO_NO,
  TIMER_CTL_PWID_ONE,
  TIMER_CTL_DATOUT_0,
  TIMER_CTL_INVOUT_NO,
  TIMER_CTL_FUNC_GPIO
);

/*----------------------------------------------------------------------------*/
void main() {

  /* Initialize the chip support library, required */
  CSL_init();

  /* Open up a timer device */
  hTimer = TIMER_open(TIMER_DEV1, TIMER_OPEN_RESET);

  /* Obtain the event ID for the timer device */
  TimerEventId = TIMER_getEventId(hTimer);

  /* Enable the event */
  IRQ_enable(TimerEventId);

  /* Configure the timer device */
  TIMER_configArgs(hTimer,
    TimerControl, /* use predefined control value          */
    0x00010000,   /* set period to 4*0x00010000 CPU cycles */
    0x00000000    /* start count value at zero             */
  );

  /* Start the timer */
  TIMER_start(hTimer);
}

/*----------------------------------------------------------------------------*/
void TimerEventHandler() {
  /* process timer event here */
  static int cnt = 0;
  LOG_printf(&LogMain,"Timer Event #%d",cnt++);
}

/*----------------------------------------------------------------------------*/

/******************************************************************************\
* End of main.c
\******************************************************************************/

