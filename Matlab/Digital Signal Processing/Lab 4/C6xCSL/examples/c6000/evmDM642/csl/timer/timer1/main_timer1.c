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

//---------Global constants---------

//Maximum count value
#define TIMER_CNT  20

//---------Global data definition---------
static TIMER_Handle hTimer1;
static Uint32 TimerEventId;
static int cnt = 0;

//Timer control register (CTL)
static Uint32 TimerControl = 
			
	TIMER_CTL_RMK
	(
		TIMER_CTL_SPND_EMUSTOP,
  		TIMER_CTL_INVINP_NO, 		// TINP inverter control(INVINP)
  		TIMER_CTL_CLKSRC_CPUOVR8,	// Timer input clock source (CLKSRC)
		TIMER_CTL_CP_PULSE, 		// Clock/pulse mode(CP)
		TIMER_CTL_HLD_YES, 			// Hold(HLD)
		TIMER_CTL_GO_NO, 			// Go bit(GO)-
									//   resets & starts timer counter
		TIMER_CTL_PWID_ONE, 		// Pulse width(PWID)-
									//   used only in pulse mode
		TIMER_CTL_DATOUT_0, 		// Data output (DATOUT)
		TIMER_CTL_INVOUT_NO, 		// TOUT inverter control (INVOUT) 
		TIMER_CTL_FUNC_GPIO 		// Function of TOUT pin(FUNC)
	);                 

//---------Function prototypes---------
void TimerEventHandler(void);
extern far void vectors();

//---------main routine---------
void main()
{
	TIMER_Config myTimConfig;
	
	//Initialise CSL
	CSL_init(); 
  
	//Open TIMER1 device, and reset it to power-on default state
	hTimer1 = TIMER_open(TIMER_DEV1, TIMER_OPEN_RESET);
  
	//Obtain the event ID for the timer device
	TimerEventId = TIMER_getEventId(hTimer1);
  
	//Point to the IRQ vector table  
	IRQ_setVecs(vectors);
	
	//Globally enable interrupts
	IRQ_globalEnable();
	
	//Enable NMI interrupt
	IRQ_nmiEnable();
  
	//Map TIMER events to physical interrupt number
	IRQ_map(TimerEventId, 14);
    
	//Reset the timer events
	IRQ_reset(TimerEventId);
    
	//---------Configure the timer devices---------
	
	//Start count value at zero
	myTimConfig.cnt = 0x0;
	
	//Use predefined control value  */
	myTimConfig.ctl = TimerControl;
	
	//Set period
	myTimConfig.prd = 0x00100000;
	
	TIMER_config(hTimer1, &myTimConfig);

	//Enable the timer events(events are disabled while resetting)
	IRQ_enable(TimerEventId);
  
	//Start the timers
	TIMER_start(hTimer1);

	//Waiting for interrupt
	while(cnt <= TIMER_CNT); 
}

//---------Subroutine definition---------

//Function called from TIMER1 ISR. Just increments the count by
//  one each time it enters this function. Exit from the program
//  after certain count value is reached.
void TimerEventHandler(void)
{
	//Process timer event here
	cnt++;  
  
	//Exit from the program when certain count is reached
	if (cnt > TIMER_CNT)
	{   
		TIMER_pause(hTimer1);
		TIMER_close(hTimer1);
		printf("\nTEST PASSED\n");
		exit(0);
	}
	printf("\n Count : %3d ",cnt);
}

//ISR to service TIMERINT1. 
//  vecs_timer1.asm must be modified to include c_int14 entry.
interrupt void c_int14(void)    
{
	TimerEventHandler();
	return;
}
