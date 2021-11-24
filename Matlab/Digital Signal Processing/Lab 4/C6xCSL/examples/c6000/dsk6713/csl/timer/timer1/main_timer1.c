/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------main_timer1.c---------
 * This example uses a timer to generate interrupt at a specific period.
 * The timer event handler increments the event count and prints in stdout.
 */
#include <stdio.h>

#include <csl.h>
#include <csl_timer.h>
#include <csl_irq.h>

#define TIMER_CNT  20  /* Maximum count value */
/*----------------------------------------------------------------------------*/

void TimerEventHandler(void);
extern far void vectors();

static TIMER_Handle hTimer1;
static Uint32 TimerEventId;
static int cnt = 0;  

/*----------------------------------------------------------------------------*/
static Uint32 TimerControl = TIMER_CTL_RMK( /* Timer control register (CTL)*/
  TIMER_CTL_INVINP_NO, /* TINP inverter control(INVINP). Only affects operation
					      if CLKSRC =0.
                           TIMER_CTL_INVINP_NO  - Uninverted TINP drives timer
                           TIMER_CTL_INVINP_YES - inverted TINP drives timer */
  
  TIMER_CTL_CLKSRC_CPUOVR4,/* Timer input clock source (CLKSRC)
						   TIMER_CTL_CLKSRC_CPUOVR4 - CPU clock /4           */
						   	
  TIMER_CTL_CP_PULSE, /* Clock/pulse mode(CP)
					       TIMER_CTL_CP_PULSE - Pulse mode.TSTAT is active one 
						        CPU clock after the timer reaches the timer
								period.PWID determines when it goes inactive.*/
					    
  TIMER_CTL_HLD_YES, /* Hold(HLD). Counter may be read or written regardless of 
					    HLD value.
						   TIMER_CTL_HLD_YES - Counter is disabled and held in
						        current value.
						   TIMER_CTL_HLD_NO - COunter is allowed to count.   */
						   
  TIMER_CTL_GO_NO, /* Go bit(GO). Resets and starts the timer counter.
				           TIMER_CTL_GO_NO - No effects on the timer.
						   TIMER_CTL_GO_YES - if HLD =1, the counter register
						        is zeroed and begins counting on next clock. */
  TIMER_CTL_PWID_ONE, /* Pulse width(PWID). Only used in pulse mode.
					       TIMER_CTL_PWID_ONE - TSTAT goes inactive one timer 
						        input clock cycle after the timer counter value
								equals the timer period value.
                           TIMER_CTL_PWID_TWO -  TSTAT goes inactive one timer 
						        input clock cycle after the timer counter value
								equals the timer period value.               */

  TIMER_CTL_DATOUT_0, /* Data output (DATOUT).
					       TIMER_CTL_DATOUT_0 - If FUNC  =0,the DATOUT is
						        driven on TOUT. 
                           TIMER_CTL_DATOUT_1 - If FUNC =1,The DATOUT is driven
						        on TOUT after inversion by INVOUT.           */

  TIMER_CTL_INVOUT_NO, /* TOUT inverter control (INVOUT) 
					       TIMER_CTL_INVOUT_NO - Uninverted TSTAT drives TOUT
						   TIMER_CTL_INVOUT_YES - Inverted TSTAT drives TOUT.*/
  TIMER_CTL_FUNC_GPIO /* Function of TOUT pin(FUNC).
					       TIMER_CTL_FUNC_GPIO - TOU is a general purpose 
						        output pin
                           TIMER_CTL_FUNC_TOUT - TOUT is a timer output pin  */
					        
);                 



/*----------------------------------------------------------------------------*/
void main() {

  /* Initialize the chip support library, must when using CSL */
  CSL_init(); 
  
  /* Open TIMER1 device, and reset them to power-on default state */
  hTimer1 = TIMER_open(TIMER_DEV1, TIMER_OPEN_RESET);
  
  /* Obtain the event ID for the timer device */
  TimerEventId = TIMER_getEventId(hTimer1);
  
  IRQ_setVecs(vectors);     /* point to the IRQ vector table	*/
  IRQ_globalEnable();       /* Globally enable interrupts       */ 
  IRQ_nmiEnable();          /* Enable NMI interrupt             */   
  
  /* Map TIMER events to physical interrupt number */      
  IRQ_map(TimerEventId, 14);
    
  /* Reset the timer events */
  IRQ_reset(TimerEventId);
    
  /* Configure the timer devices */
  TIMER_configArgs(hTimer1,
    TimerControl, /* use predefined control value  */
    0x00100000,   /* set period                    */
    0x00000000    /* start count value at zero     */
  );

  /* Enable the timer events(events are disabled while resetting) */
  IRQ_enable(TimerEventId);
  
  /* Start the timers */
  TIMER_start(hTimer1);

  while(cnt <= TIMER_CNT); /* waiting for interrupt*/
  
}
/*----------------------------------------------------------------------*/

/************************************************************************\
 name:      TimerEventHandler

 purpose:   Function called from TIMER1 ISR. Just increments the count by
  			one each time it enters this function. Exit from the program
  			after certain count value is reached.
            
 inputs:    void

 returns:   void
\************************************************************************/
void TimerEventHandler(void) {

  
  /* process timer event here */
  cnt++;  
  
  /* Exit from the program when certain count is reached */
  if (cnt > TIMER_CNT)
  {   
      TIMER_pause(hTimer1);
      TIMER_close(hTimer1);
      printf("\nTEST PASSED\n");
      exit(0);
  }
  printf("\n Count : %3d ",cnt);
  
}

/************************************************************************\
 name:      Interrupt Service Routine c_int14

 purpose:   ISR to service TIMERINT1.
            vecs.asm must be modified to include
            c_int14 entry.
            
 inputs:    n/a

 returns:   n/a
\************************************************************************/
interrupt void    
c_int14(void)    
{
    TimerEventHandler();
    return;
} /* end c_int14 */
