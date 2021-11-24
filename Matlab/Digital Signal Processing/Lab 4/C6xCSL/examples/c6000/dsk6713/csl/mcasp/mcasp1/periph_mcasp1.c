/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------peripheral_mcasp1.h---------
 * Contains functions that initialise EDMA and McASP
 */

#include "mcasp1.h"


/************************************************************************\
 name:      SetupEdma()

 purpose:   Setup EDMA and enable channels to service MCASP
            This function opens the EDMA handle but does not close it.           

 inputs:    int port: McASP port being serviced

 returns:   n/a
\************************************************************************/
void SetupEdma(int port)
{
     int edmaChaAXEVT;
     int edmaChaAREVT;
  
     /* Program ESEL registers to select EDMA channels
        used to service McASP */
     if (port == 0) /* McASP0 */
     {
          edmaChaAXEVT = EDMA_map(EDMA_CHA_AXEVT0, 12);
          edmaChaAREVT = EDMA_map(EDMA_CHA_AREVT0, 13);
     }
     else if (port == 1) /* McASP1 */
     {
          edmaChaAXEVT = EDMA_map(EDMA_CHA_AXEVT1, 14);
          edmaChaAREVT = EDMA_map(EDMA_CHA_AREVT1, 15);     
     } 
     
     /* Open EDMA handles */
     hEdmaAXEVT = EDMA_open(edmaChaAXEVT, EDMA_OPEN_RESET);
     hEdmaAREVT = EDMA_open(edmaChaAREVT, EDMA_OPEN_RESET);
     hEdmaNull  = EDMA_allocTable(-1);
     
     /* Configure EDMA parameters */
     
     /* Transmit parameters. See function SetupSrcLocation for 
        details on data structure */
     EDMA_configArgs(
          hEdmaAXEVT,     
          EDMA_OPT_RMK(
               EDMA_OPT_PRI_HIGH,
               EDMA_OPT_ESIZE_32BIT,    /* Element size 32 bits */
               EDMA_OPT_2DS_NO,
               EDMA_OPT_SUM_IDX,
               EDMA_OPT_2DD_NO,
               EDMA_OPT_DUM_NONE,
               EDMA_OPT_TCINT_YES,      /* Enable Transfer Complete Interrupt    */
               EDMA_OPT_TCC_OF(edmaChaAXEVT),
               EDMA_OPT_LINK_YES,       /* Enable linking to NULL table          */
               EDMA_OPT_FS_YES
               ),
           EDMA_SRC_RMK((Uint32)srcData), 	 
           EDMA_CNT_RMK(TOTAL_XMT_DATA-1, NUM_XMT_SERIALIZER), /* no. of elements   */
           EDMA_DST_RMK(MCASP_getXbufAddr(hMcasp)), 
           
           /* for frame index calculation, see function SetupSrcLocations
              description */
           EDMA_IDX_RMK(EDMA_IDX_FRMIDX_OF(2*NUM_XMT_SERIALIZER*4), EDMA_IDX_ELEIDX_OF(4)),
           EDMA_RLD_RMK(NUM_XMT_SERIALIZER,0)
     );

     EDMA_configArgs(
          hEdmaAREVT,     
          EDMA_OPT_RMK(
               EDMA_OPT_PRI_HIGH,
               EDMA_OPT_ESIZE_32BIT,    /* Element size 32 bits */
               EDMA_OPT_2DS_NO,
               EDMA_OPT_SUM_NONE,
               EDMA_OPT_2DD_NO,
               EDMA_OPT_DUM_INC,
               EDMA_OPT_TCINT_YES,      /* Enable Transfer Complete Interrupt    */
               EDMA_OPT_TCC_OF(edmaChaAREVT),
               EDMA_OPT_LINK_YES,       /* Enable linking to NULL table          */
               EDMA_OPT_FS_YES
               ),
           EDMA_SRC_RMK(MCASP_getRbufAddr(hMcasp)), 	 
           EDMA_CNT_RMK(TOTAL_RCV_DATA-1, NUM_RCV_SERIALIZER), /* no. of elements   */
           EDMA_DST_RMK((Uint32)dstData), 
           EDMA_IDX_RMK(EDMA_IDX_FRMIDX_DEFAULT, EDMA_IDX_ELEIDX_DEFAULT),
           EDMA_RLD_RMK(NUM_XMT_SERIALIZER,0)
     );      
      			
	 /* Link transfers to Null */		
     EDMA_link(hEdmaAXEVT, hEdmaNull);
     EDMA_link(hEdmaAREVT, hEdmaNull);

     EDMA_intHook(12, setXmtDone1);
     EDMA_intHook(13, setRcvDone1);
     EDMA_intHook(14, setXmtDone2);
     EDMA_intHook(15, setRcvDone2);

                    
     /* Enable EDMA interrupts */
     EDMA_intDisable(edmaChaAXEVT);         	
     EDMA_intDisable(edmaChaAREVT); 
     EDMA_intClear(edmaChaAXEVT);
     EDMA_intClear(edmaChaAREVT);
     EDMA_intEnable(edmaChaAXEVT);	
     EDMA_intEnable(edmaChaAREVT);	

     /* enable EDMA channels */  
     EDMA_enableChannel(hEdmaAXEVT);
     EDMA_enableChannel(hEdmaAREVT);

}


/************************************************************************\
 name:      InitMcasp

 purpose:   Initialize MCASP in these steps:
 
            1. Open handle and reset MCASP to default values
               (done before entering this function)

            2. Configure all registers except GBLCTL
            2a. PWRDEMU
            2b. Receiver registers RMASK, RFMT, AFSRCTL, ACLKRCTL, 
                AHCLKRCTL, RTDM, RINTCTL, RCLKCHK
                Be sure all clocks are set to use internal clock source
                if external serial clocks are not running. This is
                for proper synchronization of the GBLCTL register.
            2c. Transmitter registers XMASK, XFMT, AFSXCTL, ACLKXCTL, 
                AHCLKXCTL, XTDM, XINTCTL, XCLKCHK
                Be sure all clocks are set to use internal clock source
                if external serial clocks are not running. This is
                for proper synchronization of the GBLCTL register.
            2d. Serializer registers
            2e. PFUNC, PDIR, DITCTL, DLBCTL, AMUTE. Note that PDIR should
                only be programmed AFTER the clocks/frames are setup 
                in the steps above. Because the moment you configure a clk 
                pin as an output in PDIR, the clock pin starts toggling.
                Therefore you want to make sure step 2b is completed first
                so that the clocks toggle at the proper rate.
            
            3. Start serial clocks
               NOTE THAT this step can be skipped if external serial clocks
               are used and they are RUNNING.
            3a. Take internal serial clk dividers out of reset by setting 
                bits RCLKRST, RHCLKRST, XCLKRST, and XHCLKRST in GBLCTL.
                All other bits in the GBLCTL register should be held at 0.
            3b. Read back from GBLCTL register to ensure step 3a is 
                completed errorfully.

            NOTE: Prior to any GBLCTL register writing, presence of the 
            rx and tx clock is a must.
            
            NOTE THAT THIS FUNCTION DOES NOT CLOSE THE 
            MCASP CSL MODULE!

 inputs:    
            int port                    : McASP port #

 returns:   n/a
\************************************************************************/
void InitMcasp(int port)
{

    MCASP_SetupClk clkSetup;
    MCASP_SetupHclk hClkSetup;
    MCASP_SetupFsync fsyncSetup;
    MCASP_SetupFormat formatSetup;
    
    
     /*---------------------------------------------------------------*/
     /* Define structures for later use                               */
     /*---------------------------------------------------------------*/
     MCASP_ConfigRcv rcvRegs =  
     {
          0x000FFFFF,
          MCASP_RFMT_RMK(
               MCASP_RFMT_RDATDLY_0BIT,
               MCASP_RFMT_RRVRS_LSBFIRST,
               MCASP_RFMT_RPAD_RPBIT,
               MCASP_RFMT_RPBIT_OF(19),
               MCASP_RFMT_RSSZ_32BITS,
               MCASP_RFMT_RBUSEL_DAT,
               MCASP_RFMT_RROT_12BITS),
          MCASP_AFSRCTL_RMK( 
               MCASP_AFSRCTL_RMOD_OF(NUM_TDM_SLOT),  
               MCASP_AFSRCTL_FRWID_BIT,
               MCASP_AFSRCTL_FSRM_INTERNAL,
               MCASP_AFSRCTL_FSRP_ACTIVEHIGH),
          MCASP_ACLKRCTL_RMK( 
               MCASP_ACLKRCTL_CLKRP_FALLING,
               MCASP_ACLKRCTL_CLKRM_INTERNAL,
               MCASP_ACLKRCTL_CLKRDIV_OF(0)),
          MCASP_AHCLKRCTL_RMK(
               MCASP_AHCLKRCTL_HCLKRM_INTERNAL,
               MCASP_AHCLKRCTL_HCLKRP_FALLING,
               MCASP_AHCLKRCTL_HCLKRDIV_OF(20)),
          0xFFFFFFFF,     
          MCASP_RINTCTL_RMK(
               MCASP_RINTCTL_RSTAFRM_DISABLE,
               MCASP_RINTCTL_RDATA_DISABLE,
               MCASP_RINTCTL_RLAST_DISABLE,
               MCASP_RINTCTL_RDMAERR_DISABLE,
               MCASP_RINTCTL_RCKFAIL_DISABLE,
               MCASP_RINTCTL_RSYNCERR_DISABLE,
               MCASP_RINTCTL_ROVRN_DISABLE),
          MCASP_RCLKCHK_DEFAULT         
     }; 

     MCASP_ConfigXmt xmtRegs =  
     {
          0xFFFFF000,
          MCASP_XFMT_RMK(
               MCASP_XFMT_XDATDLY_0BIT,
               MCASP_XFMT_XRVRS_LSBFIRST,
               MCASP_XFMT_XPAD_XPBIT,
               MCASP_XFMT_XPBIT_OF(31),
               MCASP_XFMT_XSSZ_32BITS,
               MCASP_XFMT_XBUSEL_DAT,
               MCASP_XFMT_XROT_NONE),
          MCASP_AFSXCTL_RMK( 
               MCASP_AFSXCTL_XMOD_OF(NUM_TDM_SLOT) ,  
               MCASP_AFSXCTL_FXWID_BIT,
               MCASP_AFSXCTL_FSXM_INTERNAL,
               MCASP_AFSXCTL_FSXP_ACTIVEHIGH),
          MCASP_ACLKXCTL_RMK( 
               MCASP_ACLKXCTL_CLKXP_RISING,
               MCASP_ACLKXCTL_ASYNC_SYNC,
               MCASP_ACLKXCTL_CLKXM_INTERNAL,
               MCASP_ACLKXCTL_CLKXDIV_OF(0)),
          MCASP_AHCLKXCTL_RMK(
               MCASP_AHCLKXCTL_HCLKXM_INTERNAL,
               MCASP_AHCLKXCTL_HCLKXP_FALLING,
               MCASP_AHCLKXCTL_HCLKXDIV_OF(20)),
          0x55555555,     
          MCASP_XINTCTL_RMK(
               MCASP_XINTCTL_XSTAFRM_DISABLE,
               MCASP_XINTCTL_XDATA_DISABLE,
               MCASP_XINTCTL_XLAST_DISABLE,
               MCASP_XINTCTL_XDMAERR_DISABLE,
               MCASP_XINTCTL_XCKFAIL_DISABLE,
               MCASP_XINTCTL_XSYNCERR_DISABLE,
               MCASP_XINTCTL_XUNDRN_DISABLE),
          MCASP_XCLKCHK_DEFAULT         
     }; 




     MCASP_ConfigSrctl srctlRegs =
     {
          MCASP_SRCTL_RMK(
               MCASP_SRCTL_DISMOD_LOW,
               MCASP_SRCTL_SRMOD_XMT),  /* SRCTL0 */
          MCASP_SRCTL_RMK(
               MCASP_SRCTL_DISMOD_LOW,
               MCASP_SRCTL_SRMOD_RCV),  /* SRCTL1 */
          MCASP_SRCTL_RMK(
               MCASP_SRCTL_DISMOD_LOW,
               MCASP_SRCTL_SRMOD_XMT),  /* SRCTL2 */
          MCASP_SRCTL_RMK(
               MCASP_SRCTL_DISMOD_LOW,
               MCASP_SRCTL_SRMOD_RCV),  /* SRCTL3 */
          MCASP_SRCTL_RMK(
               MCASP_SRCTL_DISMOD_LOW,
               MCASP_SRCTL_SRMOD_XMT),  /* SRCTL4 */
          MCASP_SRCTL_RMK(
               MCASP_SRCTL_DISMOD_LOW,
               MCASP_SRCTL_SRMOD_RCV),  /* SRCTL5 */
          MCASP_SRCTL_RMK(
               MCASP_SRCTL_DISMOD_LOW,
               MCASP_SRCTL_SRMOD_XMT),  /* SRCTL6 */
          MCASP_SRCTL_RMK(
               MCASP_SRCTL_DISMOD_LOW,
               MCASP_SRCTL_SRMOD_RCV),  /* SRCTL7 */
     }; 

     MCASP_ConfigGbl globalRegs =
     {
          MCASP_PFUNC_RMK(
               MCASP_PFUNC_AFSR_MCASP,
               MCASP_PFUNC_AHCLKR_MCASP,
               MCASP_PFUNC_ACLKR_MCASP,
               MCASP_PFUNC_AFSX_MCASP,
               MCASP_PFUNC_AHCLKX_MCASP,
               MCASP_PFUNC_ACLKX_MCASP,
               MCASP_PFUNC_AMUTE_DEFAULT,
               MCASP_PFUNC_AXR7_MCASP,
               MCASP_PFUNC_AXR6_MCASP,
               MCASP_PFUNC_AXR5_MCASP,
               MCASP_PFUNC_AXR4_MCASP,
               MCASP_PFUNC_AXR3_MCASP,              
               MCASP_PFUNC_AXR2_MCASP,              
               MCASP_PFUNC_AXR1_MCASP,              
               MCASP_PFUNC_AXR0_MCASP),              
          MCASP_PDIR_RMK(
               MCASP_PDIR_AFSR_OUT,
               MCASP_PDIR_AHCLKR_OUT,
               MCASP_PDIR_ACLKR_OUT,
               MCASP_PDIR_AFSX_OUT,
               MCASP_PDIR_AHCLKX_OUT,
               MCASP_PDIR_ACLKX_OUT,               
               MCASP_PDIR_AMUTE_DEFAULT,
               MCASP_PDIR_AXR7_IN,
               MCASP_PDIR_AXR6_OUT,             
               MCASP_PDIR_AXR5_IN,             
               MCASP_PDIR_AXR4_OUT,             
               MCASP_PDIR_AXR3_IN,             
               MCASP_PDIR_AXR2_OUT,             
               MCASP_PDIR_AXR1_IN,             
               MCASP_PDIR_AXR0_OUT),                       
          MCASP_DITCTL_DEFAULT,
          MCASP_DLBCTL_RMK(
               MCASP_DLBCTL_MODE_XMTCLK, 
               MCASP_DLBCTL_ORD_XMTEVEN, 
               MCASP_DLBCTL_DLBEN_ENABLE),
          MCASP_AMUTE_DEFAULT     
     }; 

     /*---------------------------------------------------------------*/
     /* 2. Configure all registers except GBLCTL                      */
     /*---------------------------------------------------------------*/  
     // Step 2a: Leave PWRDEMU at default.
     
     // Step 2b: Receiver registers
     
    clkSetup.syncmode = MCASP_ACLKXCTL_ASYNC_ASYNC;
    clkSetup.xclkdiv = MCASP_ACLKXCTL_CLKXDIV_OF(0xA);
    clkSetup.xclkpol = MCASP_ACLKXCTL_CLKXP_RISING;
    clkSetup.xclksrc = MCASP_ACLKXCTL_CLKXM_INTERNAL;

    
    clkSetup.rclkdiv = MCASP_ACLKRCTL_CLKRDIV_OF(0xB);
    clkSetup.rclkpol = MCASP_ACLKRCTL_CLKRP_FALLING;
    clkSetup.rclksrc = MCASP_ACLKRCTL_CLKRM_INTERNAL;
    
    MCASP_setupClk (hMcasp, &clkSetup, MCASP_RCV);
    
    clkSetup.xclkdiv = MCASP_ACLKXCTL_CLKXDIV_OF(0x12);
    clkSetup.xclkpol = MCASP_ACLKXCTL_CLKXP_FALLING;
    clkSetup.xclksrc = MCASP_ACLKXCTL_CLKXM_INTERNAL;
    MCASP_setupClk (hMcasp, &clkSetup, MCASP_XMT);
     
     
     
    hClkSetup.rhclkdiv = MCASP_AHCLKRCTL_HCLKRDIV_OF(0xFFF);
    hClkSetup.rhclkpol = MCASP_AHCLKRCTL_HCLKRP_FALLING;
    hClkSetup.rhclksrc = MCASP_AHCLKRCTL_HCLKRM_INTERNAL;
    hClkSetup.xhclkdiv = MCASP_AHCLKXCTL_HCLKXDIV_OF(0xF01);    
    hClkSetup.xhclkpol = MCASP_AHCLKXCTL_HCLKXP_FALLING;
    hClkSetup.xhclksrc = MCASP_AHCLKXCTL_HCLKXM_INTERNAL;
    
    MCASP_setupHclk (hMcasp, &hClkSetup, MCASP_XMTRCV);    
     
    hClkSetup.rhclkdiv = MCASP_AHCLKRCTL_HCLKRDIV_OF(0x020);
    hClkSetup.rhclkpol = MCASP_AHCLKRCTL_HCLKRP_RISING;
    hClkSetup.rhclksrc = MCASP_AHCLKRCTL_HCLKRM_INTERNAL;    
    
    MCASP_setupHclk (hMcasp, &hClkSetup, MCASP_RCV); 
    
    hClkSetup.xhclkdiv = MCASP_AHCLKXCTL_HCLKXDIV_OF(0x04E);    
    hClkSetup.xhclkpol = MCASP_AHCLKXCTL_HCLKXP_RISING;
    hClkSetup.xhclksrc = MCASP_AHCLKXCTL_HCLKXM_INTERNAL;
    MCASP_setupHclk (hMcasp, &hClkSetup, MCASP_XMT);
     
    
    fsyncSetup.rmode = MCASP_AFSRCTL_RMOD_BURST;
    
    fsyncSetup.frwid = MCASP_AFSRCTL_FRWID_BIT;
    fsyncSetup.rfspol = MCASP_AFSRCTL_FSRP_ACTIVEHIGH;
    fsyncSetup.rfssrc = MCASP_AFSRCTL_FSRM_INTERNAL;
    fsyncSetup.rslotsize = MCASP_AFSRCTL_RMOD_OF(0x10);
    fsyncSetup.rmode = 1;
    fsyncSetup.fxwid = MCASP_AFSXCTL_FXWID_BIT;
    fsyncSetup.xfspol = MCASP_AFSXCTL_FSXP_ACTIVEHIGH;
    fsyncSetup.xfssrc = MCASP_AFSXCTL_FSXM_INTERNAL;
    fsyncSetup.xslotsize = MCASP_AFSXCTL_XMOD_OF(0x1F);
    fsyncSetup.xmode = 1;
    
    MCASP_setupFsync (hMcasp, &fsyncSetup, MCASP_XMTRCV);  
    
    fsyncSetup.frwid = MCASP_AFSRCTL_FRWID_WORD;
    fsyncSetup.rfspol = MCASP_AFSRCTL_FSRP_ACTIVELOW;
    fsyncSetup.rfssrc = MCASP_AFSRCTL_FSRM_INTERNAL;
    fsyncSetup.rslotsize = MCASP_AFSRCTL_RMOD_OF(0x10F);
    fsyncSetup.rmode = 1;
    
    MCASP_setupFsync (hMcasp, &fsyncSetup, MCASP_RCV);    

    fsyncSetup.fxwid = MCASP_AFSXCTL_FXWID_WORD;
    fsyncSetup.xfspol = MCASP_AFSXCTL_FSXP_ACTIVELOW;
    fsyncSetup.xfssrc = MCASP_AFSXCTL_FSXM_INTERNAL;
    fsyncSetup.xslotsize = MCASP_AFSXCTL_XMOD_OF(0x1FF);
    fsyncSetup.xmode = 1;
    MCASP_setupFsync (hMcasp, &fsyncSetup, MCASP_XMT); 
    

    formatSetup.ralign = MCASP_FORMAT_RIGHT;
    formatSetup.rbusel = MCASP_RFMT_RBUSEL_CFG;
    formatSetup.rdelay = MCASP_RFMT_RDATDLY_2BIT;
    formatSetup.rdsprep = MCASP_DSP_Q31;
    formatSetup.rorder = MCASP_FORMAT_MSB;
    formatSetup.rslotsize = 24;
    formatSetup.rwordsize = 20;
    formatSetup.rpad = MCASP_RFMT_RPAD_RPBIT;
    formatSetup.rpbit = MCASP_RFMT_RPBIT_OF(1);
    
    formatSetup.xalign = MCASP_FORMAT_RIGHT;
    formatSetup.xbusel = MCASP_XFMT_XBUSEL_DAT;
    formatSetup.xdelay = MCASP_XFMT_XDATDLY_1BIT;
    formatSetup.xdsprep = MCASP_DSP_Q31;
    formatSetup.xorder = MCASP_FORMAT_MSB;
    formatSetup.xslotsize = 32;
    formatSetup.xwordsize = 16;
    formatSetup.xpad = MCASP_XFMT_XPAD_XPBIT;
    formatSetup.xpbit = MCASP_XFMT_XPBIT_OF(2);
    
    MCASP_setupFormat(hMcasp, &formatSetup, MCASP_XMTRCV);
     
    
    // Set up DIT transmission for Q31 24-bit data type  
    
    MCASP_configDit(hMcasp,(MCASP_Dsprep)1,24); 

	 
	MCASP_configRcv(hMcasp, &rcvRegs);  
	 
	// Step 2c: Transmitter registers
	MCASP_configXmt(hMcasp, &xmtRegs);        	 

    // Step 2d: Serializer registers
	MCASP_configSrctl(hMcasp, &srctlRegs);  
	 
	// Step 2e: PFUNC, PDIR, DITCTL, DLBCTL, AMUTE.
	MCASP_configGbl(hMcasp, &globalRegs);   
     
     
    /*---------------------------------------------------------------*/
    /* 3. Start Serial Clocks                                        */
    /*---------------------------------------------------------------*/  
     
    // Step 3a: Take clk dividers out of reset
    // Step 3b: Read back GBLCTL to make sure the clock resets are written to errorfully          
     
    MCASP_enableHclk(hMcasp, MCASP_XMTRCV);
    while(!(  MCASP_FGETH(hMcasp, GBLCTL,XHCLKRST)));
     
    MCASP_enableClk(hMcasp, MCASP_XMTRCV);
    while(!(  MCASP_FGETH(hMcasp, GBLCTL,XCLKRST)));

     
} /* end of InitMcasp() */




/************************************************************************\
 name:      WakeRcvXmt

 purpose:   Wake up the Receiver by taking serializer and state machine
            out of reset. 
            Wake up the transmitter by:
            1. taking serializer out of reset
            2. verifying that all transmit buffers are serviced
            3. taking state machine out of reset.
            Note that every time the GBLCTL register is written to,
            it must be read back to ensure it was written errorfully.            

 inputs:    int port            : McASP port #

 returns:   n/a
\************************************************************************/
void WakeRcvXmt(int port)
{
     
     /*---------------------------------------------------------------*/
     /* Take serializer out of reset                                  */
     /* Both transmit and receive                                     */
     /*---------------------------------------------------------------*/       

     MCASP_enableSers(hMcasp, MCASP_RCVXMT);
     while(!(MCASP_FGETH(hMcasp,GBLCTL,RSRCLR) & MCASP_FGETH(hMcasp,GBLCTL,XSRCLR)));

     /*---------------------------------------------------------------*/
     /* Verify all transmit buffers are serviced                      */
     /*---------------------------------------------------------------*/  

     while(MCASP_FGETH(hMcasp,XSTAT,XDATA));

     /*---------------------------------------------------------------*/
     /* Take transmit and receive state machine out of reset          */
     /*---------------------------------------------------------------*/       

     MCASP_enableSm(hMcasp, MCASP_RCVXMT);
     while(!(MCASP_FGETH(hMcasp,GBLCTL,RSMRST) & MCASP_FGETH(hMcasp,GBLCTL,XSMRST)));
     
}
