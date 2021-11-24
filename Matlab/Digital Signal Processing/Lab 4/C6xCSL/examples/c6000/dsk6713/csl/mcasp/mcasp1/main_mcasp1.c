/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------main_mcasp1.c---------
 * MCASP example to demonstrate DIT transmission for Q31 24-bit data type
 */ 
#include <csl.h>
#include <stdio.h>
#include "mcasp1.h"


/**********************************************************************/
/* Define data sections                                               */
/**********************************************************************/
/* for this particular example, setup more src data than needed for
   McASP transmitter. See function SetupSrcLocation for details */
#pragma DATA_SECTION(srcData, "Int_Dat")
Uint32  srcData[TOTAL_RCV_DATA*NUM_RCV_SERIALIZER];

#pragma DATA_SECTION(dstData, "Int_Dat")
Uint32  dstData[TOTAL_RCV_DATA*NUM_RCV_SERIALIZER];

/**********************************************************************/
/* Global variables for interrupt-serviced testcases                  */
/**********************************************************************/
volatile Uint32 xmtDone;
volatile Uint32 rcvDone;

/**********************************************************************/
/* Global Handle                                                      */
/**********************************************************************/
EDMA_Handle hEdmaAXEVT;
EDMA_Handle hEdmaAREVT;
EDMA_Handle hEdmaNull;

MCASP_Handle hMcasp;


/*----------------------------------------------------------------------------*/

/**********************************************************************/
/* Main                                                               */
/**********************************************************************/
void main() {


    int i,port;
    int error = 0;     
    
    /* Configuration for DEVCFG register */

    CHIP_Config devCfgReg = 
     {

          CHIP_DEVCFG_RMK(
               CHIP_DEVCFG_EKSRC_ECLKIN,
               CHIP_DEVCFG_TOUT1SEL_MCASPPIN,
               CHIP_DEVCFG_TOUT0SEL_MCASPPIN,
               CHIP_DEVCFG_MCBSP0DIS_1,
               CHIP_DEVCFG_MCBSP1DIS_1)
               
     };
  
    
    CSL_init();         

    /*---------------------------------------------------------------*/
    /* Initialization                                                */
    /*---------------------------------------------------------------*/     
    /* Sets GIE = 0 and NMIE = 1.  Also disables all interrupts, */
    /* clears all interrupt flags. */

    IRQ_globalDisable(); /* GIE=0 */
    CHIP_FSET(CSR, PGIE, CHIP_CSR_PGIE_DEFAULT);
	
	for (i = 4; i < 16; ++i)
	{
		IRQ_reset(i);
	}	
    
    /* Programs the DEVCFG register so that the muxed pins on the 
            C6713 device functions as MCASP pins.
     */  
 
    CHIP_config(&devCfgReg);

    port =0 ;      
    
    /* clear global variable (test pass/fail info) */ 
    xmtDone = 0;
    rcvDone = 0;
     
    /*---------------------------------------------------------------*/
    /* Initialization                                                */
    /*---------------------------------------------------------------*/       

    /* Setup Source Data */
    /* See function for details on how data is setup for this particular
       example.(mcasp_data.c) */
    SetupSrcLocations((Uint32)srcData, TOTAL_XMT_DATA*NUM_XMT_SERIALIZER, NUM_XMT_SERIALIZER);

    /* Clear Destination Location */
    ClearMem((Uint32)dstData, TOTAL_RCV_DATA*NUM_RCV_SERIALIZER);
    
    hMcasp = MCASP_open(port, MCASP_OPEN_RESET);
    
    /* Initialize MCASP device */
    /* See function for details on how MCASP is setup for this particular
       example.(mcasp_periph.c) */
    
    InitMcasp(port);  
    
    /* Setup EDMA and enable channels to service MCASP */     
    /* See function for details in mcasp_periph.c */
    
    SetupEdma(port);
    
    /* Sets up interrupts to service EDMA transfers */
    /* See function for details in mcasp_interrupt.c */
    
    SetInterruptsEdma();
    
    /* Wake up the Receiver by taking serializer and state machine
            out of reset */
    /* See function for details in mcasp_periph.c */        
    
    WakeRcvXmt(port);
    
    /*Enable internal frame sync of the frame sync master
       This step can be stepped if external frame sync is used. */
    
    MCASP_enableFsync(hMcasp, MCASP_XMT);
    while(!MCASP_FGETH(hMcasp,GBLCTL, XFRST));
     
    while(!(rcvDone & xmtDone));
    
    MCASP_resetRcv(hMcasp);
    
    while ((MCASP_RGETH(hMcasp, GBLCTL) & 0x1F) != 0);
    
    MCASP_resetXmt(hMcasp);
     
    while ((MCASP_RGETH(hMcasp, GBLCTL) & 0x1F00) != 0);

    /*---------------------------------------------------------------*/
    /* Check results                                                 */
    /*---------------------------------------------------------------*/          
    error += CheckTransfer((Uint32)srcData, (Uint32)dstData, TOTAL_RCV_DATA*NUM_RCV_SERIALIZER);

    /*---------------------------------------------------------------*/
    /* Clean up: Reset periperhals and close handles                 */
    /*---------------------------------------------------------------*/   

    /* McASP */    
    MCASP_reset(hMcasp);
    MCASP_close(hMcasp);     
    
    /* EDMA */     
    EDMA_reset(hEdmaAXEVT);
    EDMA_close(hEdmaAXEVT);
    EDMA_reset(hEdmaAREVT);
    EDMA_close(hEdmaAREVT);
    EDMA_reset(hEdmaNull);
    EDMA_close(hEdmaNull);
    
    /* Interrupts */
    IRQ_globalDisable();
        
    if (error) {
      	printf("\nTEST FAILED\n");
    	}
        else {
        printf("\nTEST PASSED\n");
        
    }
    
}


/******************************************************************************\
* End of main.c
\******************************************************************************/

