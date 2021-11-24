/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------main_mcbsp1.c---------
 *
 * mcbsp1 Example configures the serial port for digital loopback mode.
 * We then use the CPU to write/read from the port. In loopback mode, we 
 * should read back the same value as written, which is checked for in a loop
 */
#include <stdio.h>
#include <csl.h>
#include <csl_mcbsp.h>

//---------Global data definition---------

/* create a MCBSP config structure for digital loopback mode */
static MCBSP_Config ConfigLoopback =
{
	MCBSP_SPCR_RMK 	//Serial Port Control Register (SPCR)
	(        
		MCBSP_SPCR_FREE_YES, 		// Serial clock free running mode(FREE) 
		MCBSP_SPCR_SOFT_YES, 		// Serial clock emulation mode(SOFT)
		MCBSP_SPCR_FRST_YES, 		// Frame sync generator reset(FRST)
		MCBSP_SPCR_GRST_YES, 		// Sample rate generator reset(GRST)
		MCBSP_SPCR_XINTM_XRDY, 		// Transmit interrupt mode(XINTM) 
		MCBSP_SPCR_XSYNCERR_NO,		// Transmit synchronization error  
		MCBSP_SPCR_XRST_YES, 		// Transmitter reset(XRST) 
		MCBSP_SPCR_DLB_ON,   		// Digital loopback(DLB) mode 
		MCBSP_SPCR_RJUST_RZF,		// Receive data sign-extension and
		 							//   justification mode(RJUST)
		MCBSP_SPCR_CLKSTP_DISABLE, 	// Clock stop(CLKSTP) mode
		MCBSP_SPCR_DXENA_OFF, 		// DX Enabler(DXENA) -Extra delay for
									//   DX turn-on time.
		MCBSP_SPCR_RINTM_RRDY, 		// Receive interrupt(RINT) mode
		MCBSP_SPCR_RSYNCERR_NO, 	// Receive synchronization error(RSYNCERR)
		MCBSP_SPCR_RRST_YES 		// Receiver reset(RRST)
	),
    
	MCBSP_RCR_RMK	// Receive Control Register (RCR)
	(  
		MCBSP_RCR_RPHASE_SINGLE, 	// Receive phases 
		MCBSP_RCR_RFRLEN2_OF(0), 	// Receive frame length 
									//   in phase 2(RFRLEN2) 
		MCBSP_RCR_RWDLEN2_8BIT,		// Receive element length 
									//   in phase 2(RWDLEN2)  
		MCBSP_RCR_RCOMPAND_MSB,		// Receive companding mode (RCOMPAND)  
		MCBSP_RCR_RFIG_YES, 		// Receive frame ignore(RFIG)
		MCBSP_RCR_RDATDLY_0BIT,		// Receive data delay(RDATDLY)
		MCBSP_RCR_RFRLEN1_OF(0), 	// Receive frame length 
									//   in phase 1(RFRLEN1)
		MCBSP_RCR_RWDLEN1_32BIT,	// Receive element length 
									//   in phase 1(RWDLEN1)
		MCBSP_RCR_RWDREVRS_DISABLE	// Receive 32-bit bit reversal 
									//   feature.(RWDREVRS)
	),
	MCBSP_XCR_RMK	//Transmit Control Register (XCR)
	(            
		MCBSP_XCR_XPHASE_SINGLE,	// Transmit phases
		MCBSP_XCR_XFRLEN2_OF(0),	// Transmit frame length 
									//   in phase 2(XFRLEN2) 
		MCBSP_XCR_XWDLEN2_8BIT, 	// Transmit element length
		 							//   in phase 2
		MCBSP_XCR_XCOMPAND_MSB, 	// Transmit companding mode(XCOMPAND)
		MCBSP_XCR_XFIG_YES, 		// Transmit frame ignore(XFIG)
		MCBSP_XCR_XDATDLY_0BIT, 	// Transmit data delay(XDATDLY)
		MCBSP_XCR_XFRLEN1_OF(0), 	// Transmit frame length 
									//   in phase 1(XFRLEN1)
		MCBSP_XCR_XWDLEN1_32BIT, 	// Transmit element length 
									//   in phase 1(XWDLEN1)
		MCBSP_XCR_XWDREVRS_DISABLE 	// Transmit 32-bit bit reversal feature
	),
	MCBSP_SRGR_RMK	//serial port sample rate generator register(SRGR)
	( 
		MCBSP_SRGR_GSYNC_FREE,		// Sample rate generator clock 
									//   synchronization(GSYNC).
		MCBSP_SRGR_CLKSP_RISING,	// CLKS polarity clock edge select(CLKSP)
		MCBSP_SRGR_CLKSM_INTERNAL,	// MCBSP sample rate generator clock
		 							//   mode(CLKSM)
		MCBSP_SRGR_FSGM_DXR2XSR,	// Sample rate generator transmit frame
			 						//   synchronization
		MCBSP_SRGR_FPER_OF(63),		// Frame period(FPER)
		MCBSP_SRGR_FWID_OF(31),		// Frame width(FWID)
		MCBSP_SRGR_CLKGDV_OF(15)	// Sample rate generator clock
			 						//   divider(CLKGDV)
	),
	MCBSP_MCR_DEFAULT, 				// Using default value of MCR register
	MCBSP_RCERE0_DEFAULT,			// Using default value of RCERE registers
	MCBSP_RCERE1_DEFAULT,
	MCBSP_RCERE2_DEFAULT,
	MCBSP_RCERE3_DEFAULT,
	MCBSP_XCERE0_DEFAULT,			// Using default value of XCERE registers
	MCBSP_XCERE1_DEFAULT,
	MCBSP_XCERE2_DEFAULT,
	MCBSP_XCERE3_DEFAULT,
	MCBSP_PCR_RMK	//serial port pin control register(PCR)
	(   
		MCBSP_PCR_XIOEN_SP, 		// Transmitter in general-purpose I/O mode
		MCBSP_PCR_RIOEN_SP, 		// Receiver in general-purpose I/O mode
		MCBSP_PCR_FSXM_INTERNAL, 	// Transmit frame synchronization mode
		MCBSP_PCR_FSRM_EXTERNAL, 	// Receive frame synchronization mode
		MCBSP_PCR_CLKXM_OUTPUT, 	// Transmitter clock mode (CLKXM)
		MCBSP_PCR_CLKRM_INPUT, 		// Receiver clock mode (CLKRM)
		MCBSP_PCR_CLKSSTAT_0, 		// CLKS pin status(CLKSSTAT)
		MCBSP_PCR_DXSTAT_0,   		// DX pin status(DXSTAT)
		MCBSP_PCR_FSXP_ACTIVEHIGH, 	// Transmit frame synchronization polarity(FSXP)
		MCBSP_PCR_FSRP_ACTIVEHIGH, 	// Receive frame synchronization polarity(FSRP)
		MCBSP_PCR_CLKXP_RISING, 	// Transmit clock polarity(CLKXP)
		MCBSP_PCR_CLKRP_FALLING 	// Receive clock polarity(CLKRP)
	)
};

//---------main routine---------
void main()
{
	MCBSP_Handle hMcbsp;  
	volatile Uint32 x,y;
	int success = 1;
    
	//Initialize CSL
	CSL_init();

	//Open up serial port 1
	hMcbsp = MCBSP_open(MCBSP_DEV1, MCBSP_OPEN_RESET);
  
	//Configure McBSP for digital loopback, 32bit mode
	//  and setup the sample rate generator to allow self clocking
	MCBSP_config(hMcbsp, &ConfigLoopback);

	//Enable McBSP in steps
	MCBSP_start(hMcbsp, MCBSP_RCV_START | 
						MCBSP_XMIT_START |
   					 	MCBSP_SRGR_START | 
   					 	MCBSP_SRGR_FRAMESYNC,
   			    MCBSP_SRGR_DEFAULT_DELAY);

	//Loop for a while writing values out to the port
	//  then reading them back in. This should take a few seconds
	for (y=0; y<0x00080000; y++)
	{  
		//Wait until the transmitter is ready for a sample, then write to it
		while (!MCBSP_xrdy(hMcbsp));                       
		MCBSP_write(hMcbsp,y);
  
		//Wait until the value is received, then read it
		while (!MCBSP_rrdy(hMcbsp));           
		x = MCBSP_read(hMcbsp);
    
		//Check transmitted and received values to make sure they match
		if (x != y)
		{
			success = 0;
			printf("\nTEST FAILED\n");
			break;
		} 
	}
  
	//Close the port
	MCBSP_close(hMcbsp);
	
	if(success)  
		printf("\nTEST PASSED\n");
}
