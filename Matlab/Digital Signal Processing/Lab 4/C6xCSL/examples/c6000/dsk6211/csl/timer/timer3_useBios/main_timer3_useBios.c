/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/*
 *---------main_timer3_useBios.c---------
 *
 * This example uses a timer to generate interrupt at a specific period.
 * The timer ISR increments the event count and prints in message log.
 */
#include <std.h>
#include <swi.h>
#include <log.h>

#include <csl.h>
#include <csl_irq.h>
#include <csl_timer.h>

/*----------------------------------------------------------------------------*/
void TimerEventHandler();
extern far LOG_Obj LogMain;

/*----------------------------------------------------------------------------*/
void main() {

  TIMER_Handle hTimer;
  
  /* Initialize the chip support library, required */
  CSL_init(); 
  
  /* Open up a time device, remember that BIOS is using timer0 for CLK module */
  hTimer = TIMER_open(TIMER_DEV1,TIMER_OPEN_RESET);
  
  /* Configure the timer device */
  TIMER_configArgs(hTimer,0x000002C0,0x00080000,0x00000000);

  /* Enable the timer event, use literal event ID  */
  IRQ_enable(TIMER_getEventId(hTimer));

}

/*----------------------------------------------------------------------------*/
void TimerEventHandler() {
  static int cnt = 0;

  LOG_printf(&LogMain,"Timer Event #%d",cnt++);
}
