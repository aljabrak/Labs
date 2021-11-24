/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------main_edma1.c---------
 *
 * This program uses the timer to trigger EDMA events. These events in turn 
 * trigger linked EDMA parameter tables to fill a ping pong buffer structure.
 * On running the program you'll note that the program bounces between the ping 
 * and pong buffers filling each with a value that comes from the source.  
 * (Note: This example runs with CACHE enable).
 *
 * Click on View->Memory to view following locations:
 * &ping_data, &pong_data, ping, pong and outbuff
 * By putting breakpoint at the closing brace of ISR, correct DMA transfers
 * can be viewed in the memory window. 
 */

#include <stdio.h>

#include <csl.h>
#include <csl_cache.h>
#include <csl_edma.h>
#include <csl_timer.h>
#include <csl_irq.h>

//---------Global constants---------

//Pick which EDMA transfer completion interrupt we want to use
#define TCCINTNUM   	10

//Ping-pong buffer sizes in no. of ints
#define BUFF_SZ      	256

//CPU clock frequency
#define FCPU         	500000000

//Data sample rate (simulated w/timer
#define SRATE        	8000

//Timer period
#define TPRD         	(FCPU/(4*SRATE)) 

//Transfer count
#define TRANSFER_CNT 	20

//---------Global data definition---------

//Create the buffers. We want to align the buffers to be cache friendly
//  by aligning them on an L2 cache line boundary.
#pragma DATA_SECTION(ping, ".buffers");
#pragma DATA_SECTION(pong, ".buffers");
#pragma DATA_SECTION(outbuff, ".buffers");

#pragma DATA_ALIGN(ping,128);
#pragma DATA_ALIGN(pong,128);
#pragma DATA_ALIGN(outbuff,128);
int ping[BUFF_SZ];
int pong[BUFF_SZ];
int outbuff[BUFF_SZ];

//These two variables serve as the data sources for this example.
//Also want to align these on a cache line boundary since they
//  sources of EDMA transfers.
#pragma DATA_SECTION(ping_data, ".buffers");
#pragma DATA_SECTION(pong_data, ".buffers");

#pragma DATA_ALIGN(ping_data,128);
#pragma DATA_ALIGN(pong_data,128);
static int ping_data;
static int pong_data;

//Global variable used to track the ping-pong'ing
static int pingpong = 0;

volatile int transferCount = 0;

//Declare the CSL objects
TIMER_Handle hTimer;   //Handle for the timer device               
EDMA_Handle hEdma;     //Handle for the EDMA channel               
EDMA_Handle hEdmaPing; //Handle for the ping EDMA reload parameters
EDMA_Handle hEdmaPong; //Handle for the pong EDMA reload parameters
EDMA_Config cfgEdma;   //EDMA configuration structure              

//Create the EDMA configuration structure for ping transfers
EDMA_Config cfgEdmaPing =
{  
    //Making Options parameter register - EDMA_OPT
    EDMA_OPT_RMK
    (          
		EDMA_OPT_PRI_LOW,
   		EDMA_OPT_ESIZE_32BIT,
   		EDMA_OPT_2DS_NO,
   		EDMA_OPT_SUM_NONE,
   		EDMA_OPT_2DD_NO,
   		EDMA_OPT_DUM_INC,
   		EDMA_OPT_TCINT_YES,
   		EDMA_OPT_TCC_OF(TCCINTNUM),
    	EDMA_OPT_TCCM_OF(TCCINTNUM >> 4),
    	EDMA_OPT_ATCINT_NO,
    	EDMA_OPT_ATCC_OF(0),
    	EDMA_OPT_PDTS_DISABLE,
    	EDMA_OPT_PDTD_DISABLE,
        EDMA_OPT_LINK_YES,
    	EDMA_OPT_FS_NO
    ),
    EDMA_SRC_OF(&ping_data),//Source address register 
    EDMA_CNT_OF(BUFF_SZ),   //Transfer count parameter
    EDMA_DST_OF(ping),      //Destination address parameter
    EDMA_IDX_OF(0x00000004),//Index parameter
    EDMA_RLD_OF(0x00000000) //Count reload/link parameter
};                         

//Create the EDMA configuration structure for pong transfers
EDMA_Config cfgEdmaPong = 
{
    //Making Options parameter register - EDMA_OPT
    EDMA_OPT_RMK
    (      
		EDMA_OPT_PRI_LOW,        
		EDMA_OPT_ESIZE_32BIT,
    	EDMA_OPT_2DS_NO,     
    	EDMA_OPT_SUM_NONE,
    	EDMA_OPT_2DD_NO,    
    	EDMA_OPT_DUM_INC,
    	EDMA_OPT_TCINT_YES, 
    	EDMA_OPT_TCC_OF(TCCINTNUM),
    	EDMA_OPT_TCCM_OF(TCCINTNUM >> 4),
    	EDMA_OPT_ATCINT_NO,
    	EDMA_OPT_ATCC_OF(0),
    	EDMA_OPT_PDTS_DISABLE,
    	EDMA_OPT_PDTD_DISABLE,
        EDMA_OPT_LINK_YES,
    	EDMA_OPT_FS_NO
    ),
    EDMA_SRC_OF(&pong_data),//Source address register 
    EDMA_CNT_OF(BUFF_SZ),   //Transfer count parameter
    EDMA_DST_OF(pong),      //Destination address parameter
    EDMA_IDX_OF(0x00000004),//Index parameter
    EDMA_RLD_OF(0x00000000) //Count reload/link parameter
};                         

//---------Function prototypes---------
extern far void vectors();
void setupInterrupts(void);

//Function used to stop EDMA
void stopEdma(void); 
    
//---------main routine---------
void main()
{
    //Initialise CSL
    CSL_init();

    CACHE_enableCaching(CACHE_EMIFA_CE00);
	
    //Configure L2 for 32K Cache mode
    CACHE_setL2Mode(CACHE_32KCACHE);	
	
    //Initialize the input source data
    ping_data=0x00000000;
    pong_data=0x80000000;
  
    //Since these variables are the source of an EDMA transfer, we
    //  need to flush them out of the cache since we just wrote to them.
    CACHE_wbInvL2(&ping_data, 4, CACHE_WAIT);
    CACHE_wbInvL2(&pong_data, 4, CACHE_WAIT);

    //Let's disable/clear related interrupts just in case they are pending
    //  from a previous run of the program.
    setupInterrupts();
    
    //Although not required, let's clear all of the EDMA parameter RAM.
    //This makes it easier to view the RAM and see the changes as we
    //  configure it.
    EDMA_clearPram(0x00000000);
   
  	//Let's open up a timer device, we'll use this to simulate input events
  	//  at a given sample rate.
  	hTimer = TIMER_open(TIMER_DEV1, TIMER_OPEN_RESET);

  	//Lets open up the EDMA channel associated with timer #1.
  	hEdma = EDMA_open(EDMA_CHA_TINT1, EDMA_OPEN_RESET);
  
  	//We also need two EDMA reload parameter sets so let's allocate them
  	//  here. Notice the -1, this means allocate any availale table.
  	hEdmaPing = EDMA_allocTable(-1);
  	hEdmaPong = EDMA_allocTable(-1);

  	//Let's copy the ping reload configuration structure to an
  	//  intermediate configuration structure.
  	cfgEdma = cfgEdmaPing;
  
  	//Let's initialize the link fields of the configuration structures
  	cfgEdmaPing.rld = EDMA_RLD_RMK(0,hEdmaPing);
  	cfgEdmaPong.rld = EDMA_RLD_RMK(0,hEdmaPong);
  	cfgEdma.rld     = EDMA_RLD_RMK(0,hEdmaPong);

  	//Now let's program up the EDMA channel with the configuration structure
  	EDMA_config(hEdma, &cfgEdma);
  
  	//Let's also configure the reload parameter tables in the EDMA PRAM
  	//  with the values in the configuration structures.
  	EDMA_config(hEdmaPing, &cfgEdmaPing);
  	EDMA_config(hEdmaPong, &cfgEdmaPong);   

  	//Configure up the timer
  	TIMER_configArgs(	hTimer, 
    					TIMER_CTL_OF(0x00000200), 
    					TIMER_PRD_OF(TPRD), //Timer period
    					TIMER_CNT_OF(0)
  					);   

  	//Enable the related interrupts
  	IRQ_enable(IRQ_EVT_EDMAINT);
  	EDMA_intDisable(TCCINTNUM);
  	EDMA_intClear(TCCINTNUM);  
  	EDMA_intEnable(TCCINTNUM);        
  
  	//Enable the EDMA channel
  	EDMA_enableChannel(hEdma);   
  
  	//Finally, enable the timer which will drive everything
  	TIMER_start(hTimer);
	
	//Waiting for interrupts
  	while(transferCount <= TRANSFER_CNT); 
}

void processbuff(int arg)
{
	int *inbuff;
	int x;
  	printf("\n %2d -",transferCount); 
  	if (pingpong)
  	{
  		//If pingpong is 0, then we own the ping input buffer
    	inbuff = ping;
    	printf(" Ping ");
  	}
  	else
  	{
  		//If pingpong is 1, then we own the pong input buffer
    	inbuff = pong;
    	printf(" Pong " );
  	}  
  
  	transferCount++;
  	
  	//Now let's process the input buffer, for simplicity, we'll
  	//  just copy it to the output buffer.
  	for (x=0; x<BUFF_SZ; x++)
  		outbuff[x] = inbuff[x];
  
  	//If this example is enhanced to actually do something with the
  	//  output buffer such as DMA it somewhere, you will want to flush
  	//  it out of the cache first.
   	CACHE_wbInvL2(outbuff, (BUFF_SZ << 2), CACHE_WAIT);
 
  	//Since we're done processing the input buffer, clean it from cache,
  	//  this invalidates it from cache to ensure we read a fresh version
  	//  the next time.
   	CACHE_wbInvL2(inbuff, (BUFF_SZ << 2), CACHE_WAIT);
}

// Function to sets up interrupts to service EDMA transfers
void setupInterrupts(void)
{
	//Point to the IRQ vector table
    IRQ_setVecs(vectors);
    IRQ_nmiEnable();
    IRQ_globalEnable();
    IRQ_map(IRQ_EVT_EDMAINT, 8);
    IRQ_reset(IRQ_EVT_EDMAINT);
}

//Interrupt Service Routine c_int08 : ISR to service EDMAINT. 
//vecs_edma1.asm must be modified to include c_int08 entry.
interrupt void    
c_int08(void)    
{
  	//Clear the pending interrupt from the EDMA interrupt pending register
  	EDMA_intClear(TCCINTNUM);
  
  	//Perform ping-pong
  	pingpong = (pingpong + 1) & 1;

    //Exit from the program if certain no of transfres are done
    if (transferCount >= TRANSFER_CNT)
    {
		TIMER_pause(hTimer);
      	stopEdma();
      	TIMER_close(hTimer);
      	printf ("\nDone.....");
      	exit(0);    
    }
  
  	//Based on if we ping'ed or pong'ed, we need to set the EDMA channel
  	//  link address for the NEXT frame.
	if (pingpong)
	{
    	//Currently doing pong so setup next frame for ping  
    	//Modify the input data source, this just simulates
    	//  the input data changing.
    	ping_data++;

    	//Rememer to flush this variable out of the cache
    	//  since it's the source of an EDMA transfer
    	CACHE_wbInvL2(&ping_data, 4, CACHE_WAIT);
    
    	//Now filling pong so set link to ping
    	EDMA_link(hEdma,hEdmaPing);
  	}
  	else
  	{
    	//Currently doing ping so setup next frame for pong
    	//Modify the output data source, this just simulates
    	//  the input data changing.
    	pong_data++;
    
    	//Rememer to flush this variable out of the cache
    	//  since it's the source of an EDMA transfer    
    	CACHE_wbInvL2(&pong_data, 4, CACHE_WAIT);
    	 
    	//Now filling ping so set link to pong
        EDMA_link(hEdma,hEdmaPong);
  	}  
  	processbuff(0);
  	return;
}

//Stops the EDMA service.
void stopEdma(void)
{
    //Disable interrupts, close EDMA channel before exit of the program
    IRQ_disable(IRQ_EVT_EDMAINT);
    EDMA_RSET(CCER,0x00000000);
    EDMA_disableChannel(hEdma);
    EDMA_intDisable(TCCINTNUM);
    EDMA_intClear(TCCINTNUM);

 	EDMA_close(hEdma);
 	EDMA_resetAll();
 	EDMA_RSET(CIPR,0xFFFFFFFF);
 	EDMA_RSET(ECR,0xFFFFFFFF);
}
