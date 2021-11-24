/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------main_mcbsp2.c---------
 *
 * mcbsp2 Example configures the serial port for digital loopback mode and
 * EDMA to transfer data for receive and transmit events.
 * In loopback mode, we should read back the same value as written, 
 * which is verified at the end.
 */
#include <stdio.h>
#include <csl.h>
#include <csl_mcbsp.h>
#include <csl_edma.h>
#include <csl_irq.h>

//---------Global constants---------
#define PASS			0
#define FAIL			1

//EDMA interrupt pin
#define INTNUM_EDMA		8

//McBSP0 transmit interrupt pin
#define	INTNUM_XMT0		10

//McBsp0 receive interrupt pin
#define INTNUM_RCV0		11

//No of frames per direction (implies 64 frames)
#define FRM_CNT			64

//No of elements per frame (implies 32 elements)
#define ELE_CNT			32

#define FILL_PATTERN	0x01010101
#define XFER_CNT        (FRM_CNT * ELE_CNT)

//For every 48 McBSP clocks, one frame sync is sent
#define FRM_PER			47

//No divide-down on the internal clock source : AUXCLK = CPUCLK/4
#define CLKGDV1			0

/*
 * NOTE : 
 * Assuming the CPU clock of 600 MHz, the effective McBSP bit frequency
 *                                       600/4
 *        in Mbits/sec (per stream) = ------------ * 32 bits
 *                                     (FRM_PER+1)
 *
 * If FRM_PER = 47, CPU = 600 MHz, McBSP transfer rate = 100 Mbits/sec
 * If FRM_PER = 47, CPU = 500 MHz, McBSP transfer rate = 83.3 Mbits/sec
 * If FRM_PER = 47, CPU = 400 MHz, McBSP transfer rate = 66.7 Mbits/sec
 *
 * The above transfer rates are applicable only when one McBSP is 
 * operating at a time. If two McBSPs are operating simulatenously
 * then the transfer rates will be half of the rates shown above.
 */

//---------Global data definition---------

#pragma DATA_SECTION(srcMcbsp0, ".internalData");
Uint32 srcMcbsp0[XFER_CNT];

#pragma DATA_SECTION (dstMcbsp0, ".internalData");
Uint32 dstMcbsp0[XFER_CNT]; 

EDMA_Handle hEdmaXmt = NULL;
EDMA_Handle hEdmaRcv = NULL;
MCBSP_Handle hMcbsp = NULL;

//Transfer complete codes for McBSP0
Uint32 tccMcbspXmt0 = 0, tccMcbspRcv0 = 0;

//McBsp error flags
Uint8 mcbsp0TxSyncError = 0;
Uint8 mcbsp0RxSyncError = 0;

//Flag to indicate McBSP-EDMA complete
Uint8 mcbspEDMAdone = 0;

//---------Function prototypes---------

//Address of interrupt vectors table 
extern far void vectors();

void setupMcbspXmtEdma(Uint32 src, Uint32 dst, Uint32 channel, Uint32 tcc);
void setupMcbspRcvEdma(Uint32 src, Uint32 dst, Uint32 channel, Uint32 tcc);
void initMcbsp(MCBSP_Handle hMcbsp1);
void wakeMcbsp(MCBSP_Handle hMcbsp1);
void mcbspCloseAll(void);

//---------main routine---------
void main(void)
{
	Uint32 i, val0 = 0;
    Uint32 mcbsp0_xmt_addr = 0;
    Uint32 mcbsp0_rcv_addr = 0;

    //Initialize CSL
    CSL_init();

    //Fill the src buffer based on the FILL_PATTERN
    for (i=0; i<XFER_CNT; i++)
    {
    	val0 += FILL_PATTERN;
    	
    	//Set up src buffer
        srcMcbsp0[i] = val0;
        
        //Corrupt dst buffer
        dstMcbsp0[i] = 0xDEADBEEF;
	}

	
	//---------Configure MCBSP0 in DLB mode---------
	
	//Open MCBSP0
	hMcbsp = MCBSP_open(MCBSP_DEV0, MCBSP_OPEN_RESET);
	if(hMcbsp == INV)
	{
		printf("\nTEST FAILED\n");
		exit(1);
	}	

	//Get MCBSP0 DXR address to use as EDMA destination for transmit event
	mcbsp0_xmt_addr = MCBSP_getXmtAddr(hMcbsp);
	
	//Get MCBSP0 DRR address to use as EDMA source for receive event
	mcbsp0_rcv_addr = MCBSP_getRcvAddr(hMcbsp);
	
	//Initialize McBSP
    initMcbsp(hMcbsp);

	//---------Setup McBSP interrupts---------
	
    //Cleanup interrupts
	IRQ_resetAll();
  	IRQ_globalDisable();
	IRQ_nmiDisable();	  
	  
	//Map McBSP transmit and receive interrupts
  	IRQ_map(IRQ_EVT_XINT0, INTNUM_XMT0);
  	IRQ_map(IRQ_EVT_RINT0, INTNUM_RCV0);	  
  	  
  	//Enable McBSP interrupts
    IRQ_enable(IRQ_EVT_XINT0);
    IRQ_enable(IRQ_EVT_RINT0);
      	  
	//---------Setup McBSP-EDMA channels---------
	  		
  	//Cleanup all EDMA channels
  	EDMA_resetAll();
  	    
    //Allocate transfer complete codes for McBSP0 Xmt and Rcv
    tccMcbspXmt0 = EDMA_intAlloc(-1);
    tccMcbspRcv0 = EDMA_intAlloc(-1);

	//Setup McBSP0-EDMA channels
	setupMcbspXmtEdma (	(Uint32)srcMcbsp0, 
							mcbsp0_xmt_addr, 
							EDMA_CHA_XEVT0, 
							tccMcbspXmt0
						);
    setupMcbspRcvEdma (	mcbsp0_rcv_addr, 
    						(Uint32)dstMcbsp0, 
    						EDMA_CHA_REVT0, 
    						tccMcbspRcv0
						);

	//Enable McBSP-EDMA channels
	EDMA_enableChannel(hEdmaXmt);
	EDMA_enableChannel(hEdmaRcv);
	
	//---------Enable EDMA interrupts for McBSP0---------
    IRQ_map(IRQ_EVT_EDMAINT, INTNUM_EDMA);
    EDMA_intClear(tccMcbspRcv0);
    EDMA_intEnable(tccMcbspRcv0);
    IRQ_enable(IRQ_EVT_EDMAINT);

	//Setup Interrupt vector table
    IRQ_setVecs(vectors);
    IRQ_globalEnable();
    IRQ_nmiEnable();

	//Start McBSP
	wakeMcbsp(hMcbsp); 

    //Wait for McBSP transfers to complete
    while(!mcbspEDMAdone)
    {
    	if(	mcbsp0TxSyncError || 
    		mcbsp0RxSyncError || 
    	  	(MCBSP_FGETH(hMcbsp, SPCR, RFULL) == MCBSP_SPCR_RFULL_YES)
    	  )
    	{
			//Release all resources
    		mcbspCloseAll();
	   		printf("\nTEST FAILED\n");	
	   		exit(-1);
    	}
	}
    
	//Release all resources used in this example
	mcbspCloseAll();
     
	//Validate McBsp transfers
	if(!memcmp(srcMcbsp0, dstMcbsp0, XFER_CNT * 4 /*in bytes*/))
		printf("\nTEST PASSED\n");
	else
		printf("\nTEST FAILED\n");
}

//Function to setup EDMA for McBSP transmitter
void setupMcbspXmtEdma(Uint32 src, Uint32 dst, Uint32 channel, Uint32 tcc) 
{
    int opt, cnt, idx, rld_lnk;

	//Open McBsp Xmt EDMA channel
    hEdmaXmt = EDMA_open(channel, EDMA_OPEN_RESET);
	if(hEdmaXmt == EDMA_HINV)
	{
		printf("\nTEST FAILED\n");
		mcbspCloseAll();
		exit(-1);
	}
	
    //Set up EDMA channel to transfer from DMEM to DXR1
    opt = 	EDMA_OPT_RMK
    	  	(
				EDMA_OPT_PRI_URGENT,	// Urgent priority
				EDMA_OPT_ESIZE_32BIT,	// Element size 32 bits
            	EDMA_OPT_2DS_NO,		// 1D source
            	EDMA_OPT_SUM_INC,		// Auto increment for source
            	EDMA_OPT_2DD_NO,		// 1D destination
            	EDMA_OPT_DUM_NONE,		// No update for McBSP side
            	EDMA_OPT_TCINT_YES,		// Enable transfer complete interrupt
            	EDMA_OPT_TCC_OF
            	 (tcc & 0xF),			// Lower four bits of TCC
            	EDMA_OPT_TCCM_OF
            	 (((tcc & 0x30) >> 4)),	// Higher two bits of TCC
            	EDMA_OPT_ATCINT_NO,		// No alternate xfer complete int
            	EDMA_OPT_ATCC_OF(0),	// No alternate xfer complete code
            	EDMA_OPT_PDTS_DISABLE,	// disable PDT mode for source
            	EDMA_OPT_PDTD_DISABLE,	// disable PDT mode for destination
            	EDMA_OPT_LINK_YES,		// Enable linking
            	EDMA_OPT_FS_NO			// Element synchronized
            );       
	cnt = (Uint32) (((FRM_CNT - 1) << 16) | ELE_CNT); 
	rld_lnk = (ELE_CNT << 16 | 0);
   	idx = 0;

   	EDMA_configArgs(hEdmaXmt, opt, src, cnt, dst, idx, rld_lnk);

	//Link with null table for termination
   	EDMA_link(hEdmaXmt, EDMA_hNull); 
}

//Function to setup EDMA for McBSP receiver
void setupMcbspRcvEdma(Uint32 src, Uint32 dst, Uint32 channel, Uint32 tcc) 
{
	int opt, cnt, idx, rld_lnk;

	//Open McBsp Rcv EDMA channel
    hEdmaRcv = EDMA_open(channel, EDMA_OPEN_RESET);
	if(hEdmaRcv == EDMA_HINV)
	{
		printf("\nTEST FAILED\n");
		mcbspCloseAll();
		exit(-1);
	}

	//Set up EDMA channel to transfer from DMEM to DXR1
	opt = 	EDMA_OPT_RMK
   			(
   				EDMA_OPT_PRI_URGENT,	// Urgent priority
            	EDMA_OPT_ESIZE_32BIT,   // Element size 32 bits
            	EDMA_OPT_2DS_NO,        // 1D source
            	EDMA_OPT_SUM_NONE,      // No update for McBSP side
            	EDMA_OPT_2DD_NO,        // 1D destination
            	EDMA_OPT_DUM_INC,       // auto increment for destination
            	EDMA_OPT_TCINT_YES,     // Enable transfer complete interrupt
            	EDMA_OPT_TCC_OF
            	 (tcc & 0xF), 			// Lower four bits of TCC
            	EDMA_OPT_TCCM_OF
            	 (((tcc & 0x30) >> 4)), // Higher two bits of TCC
            	EDMA_OPT_ATCINT_NO,     // No alternate xfer complete int
            	EDMA_OPT_ATCC_OF(0),    // No alternate xfer complete code
            	EDMA_OPT_PDTS_DISABLE,  // disable PDT mode for source
            	EDMA_OPT_PDTD_DISABLE,  // disable PDT mode for destination
            	EDMA_OPT_LINK_YES,      // Enable linking
            	EDMA_OPT_FS_NO			// Element synchronized
            );

	cnt = (Uint32) (((FRM_CNT - 1) << 16) | ELE_CNT); 
   	rld_lnk = (ELE_CNT << 16 | 0);
   	idx = 0;

   	EDMA_configArgs(hEdmaRcv, opt, src, cnt, dst, idx, rld_lnk);

	//Link with null table for termination
   	EDMA_link(hEdmaRcv, EDMA_hNull);
}

//Function to initialize McBSP for DLB mode
void initMcbsp(MCBSP_Handle handle)
{
   	Uint32 spcr, pcr, srgr, xcr, rcr, mcr;
   	Uint32 rcere0, rcere1, rcere2, rcere3;
   	Uint32 xcere0, xcere1, xcere2, xcere3;

   	spcr = 	MCBSP_SPCR_RMK
   			(
   				MCBSP_SPCR_FREE_DEFAULT,
				MCBSP_SPCR_SOFT_DEFAULT,
				MCBSP_SPCR_FRST_YES,
            	MCBSP_SPCR_GRST_YES,
            	MCBSP_SPCR_XINTM_XSYNCERR,
            	MCBSP_SPCR_XSYNCERR_DEFAULT,
            	MCBSP_SPCR_XRST_YES,
            	MCBSP_SPCR_DLB_ON,
            	MCBSP_SPCR_RJUST_RZF,
            	MCBSP_SPCR_CLKSTP_DISABLE,
            	MCBSP_SPCR_DXENA_OFF,
            	MCBSP_SPCR_RINTM_RSYNCERR,
            	MCBSP_SPCR_RSYNCERR_DEFAULT,
            	MCBSP_SPCR_RRST_YES
            ); 

   	pcr = 	MCBSP_PCR_RMK
			(
   				MCBSP_PCR_XIOEN_SP,
            	MCBSP_PCR_RIOEN_SP,
            	MCBSP_PCR_FSXM_INTERNAL, 
            	MCBSP_PCR_FSRM_EXTERNAL,
            	MCBSP_PCR_CLKXM_OUTPUT,
            	MCBSP_PCR_CLKRM_INPUT,
            	MCBSP_PCR_CLKSSTAT_DEFAULT,
            	MCBSP_PCR_DXSTAT_DEFAULT,
            	MCBSP_PCR_FSXP_ACTIVEHIGH,
            	MCBSP_PCR_FSRP_ACTIVEHIGH,
            	MCBSP_PCR_CLKXP_RISING,
            	MCBSP_PCR_CLKRP_FALLING
			);

   	srgr = 	MCBSP_SRGR_RMK
   			(
   				MCBSP_SRGR_GSYNC_DEFAULT,
            	MCBSP_SRGR_CLKSP_DEFAULT,
            	MCBSP_SRGR_CLKSM_INTERNAL,
            	MCBSP_SRGR_FSGM_FSG,
            	MCBSP_SRGR_FPER_OF(FRM_PER),
            	MCBSP_SRGR_FWID_DEFAULT,
            	MCBSP_SRGR_CLKGDV_OF(CLKGDV1)
            );

   	xcr  = 	MCBSP_XCR_RMK
   			(
   				MCBSP_XCR_XPHASE_SINGLE,
            	MCBSP_XCR_XFRLEN2_DEFAULT,
            	MCBSP_XCR_XWDLEN2_DEFAULT,
            	MCBSP_XCR_XCOMPAND_MSB,
            	MCBSP_XCR_XFIG_DEFAULT,
            	MCBSP_XCR_XDATDLY_0BIT,
            	MCBSP_XCR_XFRLEN1_OF(0),
            	MCBSP_XCR_XWDLEN1_32BIT,
            	MCBSP_XCR_XWDREVRS_DEFAULT
            );

   	rcr  = 	MCBSP_RCR_RMK
   			(
    			MCBSP_RCR_RPHASE_SINGLE,
            	MCBSP_RCR_RFRLEN2_DEFAULT,
            	MCBSP_RCR_RWDLEN2_DEFAULT,
            	MCBSP_RCR_RCOMPAND_MSB,
            	MCBSP_RCR_RFIG_DEFAULT,
            	MCBSP_RCR_RDATDLY_0BIT,
            	MCBSP_RCR_RFRLEN1_OF(0),
            	MCBSP_RCR_RWDLEN1_32BIT,
            	MCBSP_RCR_RWDREVRS_DEFAULT
            );

   	mcr = MCBSP_MCR_DEFAULT;

   	rcere0 = MCBSP_RCERE0_DEFAULT;
   	xcere0 = MCBSP_XCERE0_DEFAULT;
   	rcere1 = MCBSP_RCERE1_DEFAULT;
   	xcere1 = MCBSP_XCERE1_DEFAULT;
   	rcere2 = MCBSP_RCERE2_DEFAULT;
   	xcere2 = MCBSP_XCERE2_DEFAULT;
   	rcere3 = MCBSP_RCERE3_DEFAULT;
   	xcere3 = MCBSP_XCERE3_DEFAULT;

   	MCBSP_configArgs(handle, spcr, rcr, xcr, srgr, mcr, rcere0, rcere1,
   		 				rcere2, rcere3, xcere0, xcere1, xcere2, xcere3, pcr);

   	//Enable sample rate generator and frame sync
   	MCBSP_enableSrgr(handle);
   	MCBSP_enableFsync(handle);
}


//Function to initiate McBSP transfers
void wakeMcbsp(MCBSP_Handle handle)
{
   	MCBSP_enableXmt(handle);
   	MCBSP_enableRcv(handle);
} 

//ISR to check for all McBsp Xmt errors
interrupt void mcbsp0XmtIsr()
{
	//Check for Transmit sync error
  	if(MCBSP_FGETH(hMcbsp, SPCR, XSYNCERR) == MCBSP_SPCR_XSYNCERR_YES)
    	mcbsp0TxSyncError = 1;
}

//ISR to check for all McBsp Rcv errors
interrupt void mcbsp0RcvIsr()
{
  	//Check for Receive sync error
  	if(MCBSP_FGETH(hMcbsp, SPCR, RSYNCERR) == MCBSP_SPCR_RSYNCERR_YES) 
     	mcbsp0RxSyncError = 1;
}

//ISR for McBSP-EDMA complete interrupt
interrupt void edmaIsr()
{
	if(EDMA_intTest(tccMcbspRcv0))
	{
		EDMA_intClear(tccMcbspRcv0);
		mcbspEDMAdone = 1;
	}
}

//Function to clos and free all resources used so far
void mcbspCloseAll(void)
{
  	//Disable McBSP interrupts
    IRQ_disable(IRQ_EVT_XINT0);
    IRQ_disable(IRQ_EVT_RINT0);
    
    //Disable EDMA interrupts for McBSP0
    EDMA_intClear(tccMcbspRcv0);
    EDMA_intDisable(tccMcbspRcv0);
    IRQ_disable(IRQ_EVT_EDMAINT);
    
    //Close McBSP
    MCBSP_close(hMcbsp);

	//Free all TCCs
	EDMA_intFree(tccMcbspXmt0);
	EDMA_intFree(tccMcbspRcv0);

	//Close all EDMA channels
    EDMA_close(hEdmaXmt);
    EDMA_close(hEdmaRcv);
}
