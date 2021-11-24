/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/*
 *---------main_timer2_useBios.c---------
 *
 * This example uses two timers and programs them to generate interrupts
 * at different periods and jump to dummy SWI's. For this purpose, BIOS CLK manager
 * is disabled using configuration tool. Execution graph will show various events.
 */
#include <std.h>
#include <swi.h>

#include <csl.h>
#include <csl_timer.h>
#include <csl_irq.h>
#include "timer2_useBioscfg.h"

/*----------------------------------------------------------------------------*/
void TimerEventHandler(int Arg);

static TIMER_Handle hTimer1, hTimer2;
static Uint32 TimerEventId1,TimerEventId2;

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

extern far SWI_Obj SwiMain;
extern far SWI_Obj SwiIsr1;
extern far SWI_Obj SwiIsr2;

/*----------------------------------------------------------------------------*/
void main() {

  /* Initialize the chip support library, required */
  CSL_init(); 

  LOG_printf(&LogEvent,"Only the Message Log will update since \n timers are not available to DSP/BIOS");
  LOG_printf(&LogEvent,"Execution Graph will display various events");

  /* post the main SWI */
  SWI_post(&SwiMain);
  
}

/*----------------------------------------------------------------------------*/
void SwiMainFunc(int arg0, int arg1) {

  /* Open up a timer devices, don't care which ones, and reset them to */
  /* power-on default state.                                           */
  hTimer1 = TIMER_open(TIMER_DEVANY, TIMER_OPEN_RESET);
  hTimer2 = TIMER_open(TIMER_DEVANY, TIMER_OPEN_RESET);

  /* Obtain the event IDs for the timer devices */
  TimerEventId1 = TIMER_getEventId(hTimer1);
  TimerEventId2 = TIMER_getEventId(hTimer2);

  /* Enable the timer events */
  IRQ_enable(TimerEventId1);
  IRQ_enable(TimerEventId2);

  /* Configure the timer devices */
  TIMER_configArgs(hTimer1,
    TimerControl, /* use predefined control value  */
    0x00100000,   /* set period                    */
    0x00000000    /* start count value at zero     */
  );

  TIMER_configArgs(hTimer2,
    TimerControl, /* use predefined control value  */
    0x00080000,   /* set period                    */
    0x00000000    /* start count value at zero     */
  );

  /* Start the timers */
  TIMER_start(hTimer1);
  TIMER_start(hTimer2);
}

void SwiIsr1Func(void)
{
	return;
}

void SwiIsr2Func(void)
{
	return;
}

/*----------------------------------------------------------------------------*/
void TimerEventHandler(int Arg) {
  
  static int cnt[2] = {0,0};
  /* process timer event here */
  cnt[Arg]++;
  
  if (Arg) SWI_post(&SwiIsr2);
  else SWI_post(&SwiIsr1);
}
