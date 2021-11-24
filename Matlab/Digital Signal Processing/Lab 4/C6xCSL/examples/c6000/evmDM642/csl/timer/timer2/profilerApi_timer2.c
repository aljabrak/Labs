/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------profilerApi_timer2.c---------
 * This file defines all the API's of the profiler.
 */
#include "profiler_timer2.h"

TIMER_Handle hTim;
int cpuByTimClk;

//Timer control register (CTL)
static Uint32 TimerControl = 
			
	TIMER_CTL_RMK
	(
		TIMER_CTL_SPND_EMUSTOP,		// Suspend when emulation halt
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

//Function to configure timer for profiler usage
int profile_timConfig(int timDeviceNum, int clkRatio)
{	
	//Return with invalide device number error if it is not
	//  in -1 to 2 range (for C64xx)
	if (timDeviceNum < TIMER_DEVANY || timDeviceNum > TIMER_DEV2)
		return ERR_INVDEVNUM;
		
	//For C64xx timer using internal clk source the ratio is always 8
	if (clkRatio != 8)
		return ERR_INVCLKRATIO;
	
	//Store the ratio to use later
	cpuByTimClk = clkRatio;
	
	//Open the appropriate timer device
	hTim = TIMER_open(timDeviceNum, TIMER_OPEN_RESET);
	
	//Return bad handle error if open fails
	if (hTim == INV)
		return ERR_BADHANDLE;
	
	return 0;	
}

//Function to be used just before the code section to be profiled.
//It starts the profiler operation.
void profile_begin(void)
{
	TIMER_Config myTimConfig;
	
	//If open failed earlier, return without doing anything
	if (hTim == INV)
		return;
	
	//Configure CNT, PRD and CTL registers
	myTimConfig.cnt = 0x0;			//Initialise to 0
	myTimConfig.prd = 0xFFFFFFFF;	//Initialise to maximum possible value
	myTimConfig.ctl = TimerControl;
	
	TIMER_config(hTim, &myTimConfig);
	
	//Start the timer to begin profiling
	TIMER_start(hTim);
}

//Function to be used immediately after the code section to be profiled.
//It stops the profiler operation.
long profile_end(void)
{
	if (hTim != INV)
	{
		//Pause the timer to get the accurate count now
		TIMER_pause(hTim);
		
		//Get this count and multiply by the ratio of CPU to Timer CLK
		//  to return actual CPU cycles taken
		return ((long)(TIMER_getCount(hTim) * cpuByTimClk));
	}
	
	//Return negative value if handle is invalid
	return ((long) -1);	
}

//Function to close the profiler after its usage. To be used before exiting
//  the user program.
void profile_timClose(void)
{
	//If the handle is valid, close the timer device
	if (hTim != INV)
		TIMER_close(hTim);
}
