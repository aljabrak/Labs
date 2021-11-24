/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 06-11-03 (barracuda-m10)" */
/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... main.c
* DATE CREATED.. 01/11/2000
* LAST MODIFIED. 09/26/2000
\******************************************************************************/
#include <std.h>  
#include <swi.h>
#include <log.h>

#include <csl.h>
#include <csl_dma.h>
#include <csl_irq.h>

/*----------------------------------------------------------------------------*/
extern far SWI_Obj SwiMain;  
extern far LOG_Obj LogMain;

void SwiMainFunc();
void DmaIsr();

static int Example1();
static int Example2();
static int Example3();
static int Example4();
static DMA_Handle hDma; 

#define BUFFSZ 1024
static Uint32 BuffA[BUFFSZ/sizeof(Uint32)];
static Uint32 BuffB[BUFFSZ/sizeof(Uint32)];
static volatile int Complete;

/*----------------------------------------------------------------------------*/
void main() { 
  
  /* Initialize the chip support library */
  CSL_init();

  LOG_printf(&LogMain,"<DMA1>");
  
  SWI_post(&SwiMain);
}

/*----------------------------------------------------------------------------*/
void SwiMainFunc() {

  int success = 1;
  
  /* Call the various examples */  
  if (1) success = success && Example1();
  if (1) success = success && Example2();
  if (1) success = success && Example3();
  if (1) success = success && Example4();
  
  LOG_printf(&LogMain,"success=%d",success);
  LOG_printf(&LogMain,"<DONE>");
}

/*----------------------------------------------------------------------------*/
int Example1() {

  int success = TRUE;
  Uint32 PriCtl,SecCtl,SrcAddr,DstAddr,XfrCnt; 
  int x;

  LOG_printf(&LogMain,"Example1");

  /* Initialize the buffers */
  for (x=0; x<BUFFSZ/sizeof(Uint32); x++) {
    BuffA[x] = x;
    BuffB[x] = 0x00000000;
  }
  
  /* Let's use the DMA to perform a simple data copy from */
  /* one buffer to another.                               */
  
  /* To start, we need to open up a DMA channel. Let's use */
  /* DMA channel 2 and also reset it upon opening.         */ 
  hDma = DMA_open(DMA_CHA2,DMA_OPEN_RESET); 
  
  /* Generate discrete DMA parameters using 'make' macros */
  PriCtl  = DMA_PRICTL_RMK(
    DMA_PRICTL_DSTRLD_NONE,
    DMA_PRICTL_SRCRLD_NONE,
    DMA_PRICTL_EMOD_NOHALT,
    DMA_PRICTL_FS_DISABLE,
    DMA_PRICTL_TCINT_DISABLE,
    DMA_PRICTL_PRI_DMA,
    DMA_PRICTL_WSYNC_NONE,
    DMA_PRICTL_RSYNC_NONE,
    DMA_PRICTL_INDEX_NA,
    DMA_PRICTL_CNTRLD_NA,
    DMA_PRICTL_SPLIT_DISABLE,
    DMA_PRICTL_ESIZE_32BIT,
    DMA_PRICTL_DSTDIR_INC,
    DMA_PRICTL_SRCDIR_INC,
    DMA_PRICTL_START_STOP
  );
  SecCtl  = 0x00000000;
  SrcAddr = (Uint32)BuffA;
  DstAddr = (Uint32)BuffB;
  XfrCnt  = DMA_XFRCNT_RMK(
    DMA_XFRCNT_FRMCNT_OF(0),
    DMA_XFRCNT_ELECNT_OF(BUFFSZ/sizeof(Uint32))
  );
  
  /* Configure up the DMA channel */
  DMA_configArgs(hDma,PriCtl,SecCtl,SrcAddr,DstAddr,XfrCnt);
  
  /* Start the DMA operation */
  DMA_start(hDma);
  
  /* Wait until the DMA completes */
  DMA_wait(hDma);

  /* All done with this channel so let's close it */
  DMA_close(hDma);

  /* Verify the results */
  for (x=0; x<BUFFSZ/sizeof(Uint32); x++) {
    if (BuffA[x] != BuffB[x]) {success = FALSE; break;}
  }

  return success;
}

/*----------------------------------------------------------------------------*/
int Example2() {

  int success = TRUE;
  int x;

  LOG_printf(&LogMain,"Example2");

  /* Initialize the buffers */
  for (x=0; x<BUFFSZ/sizeof(Uint32); x++) {
    BuffA[x] = x;
    BuffB[x] = 0x00000000;
  }
  
  /* Let's use the DMA to perform a simple data copy from    */
  /* one buffer to another. Instead of using the the make    */
  /* macros to generate the DMA parameters, they are hand    */
  /* coded. Also notice the prictl parameter is configured   */
  /* to start the DMA right away.                            */
  
  /* open up a DMA channel */
  hDma = DMA_open(DMA_CHAANY,DMA_OPEN_RESET);
  
  /* Perform the DMA operation */
  DMA_configArgs(hDma,
    /* prictl */ 0x01000051,              
    /* secctl */ 0x00000000,              
    /* src    */ (Uint32)BuffA,           
    /* dst    */ (Uint32)BuffB,           
    /* xfrcnt */ BUFFSZ/sizeof(Uint32)    
  );
    
  /* Wait until the DMA completes */
  DMA_wait(hDma);

  /* close the DMA channel */
  DMA_close(hDma);
  
  /* Verify the results */
  for (x=0; x<BUFFSZ/sizeof(Uint32); x++) {
    if (BuffA[x] != BuffB[x]) {success = FALSE; break;}
  }

  return success;
}

/*----------------------------------------------------------------------------*/
int Example3() {

  int success = TRUE;
  int x;
  DMA_Config ConfigStruct = {
    /* prictl */ 0x01000051,              
    /* secctl */ 0x00000000,              
    /* src    */ (Uint32)BuffA,           
    /* dst    */ (Uint32)BuffB,           
    /* xfrcnt */ BUFFSZ/sizeof(Uint32)    
  };  

  LOG_printf(&LogMain,"Example3");

  /* Initialize the buffers */
  for (x=0; x<BUFFSZ/sizeof(Uint32); x++) {
    BuffA[x] = x;
    BuffB[x] = 0x00000000;
  }
  
  /* Let's use the DMA to perform a simple data copy from    */
  /* one buffer to another. Instead of using the the make    */
  /* macros to generate the DMA parameters, they are hand    */
  /* coded. Also notice the prictl parameter is configured   */
  /* to start the DMA right away.                            */
  
  /* open up a DMA channel */
  hDma = DMA_open(DMA_CHAANY,DMA_OPEN_RESET);
  
  /* Perform the DMA operation using configuration structure */
  DMA_config(hDma,&ConfigStruct);
    
  /* Wait until the DMA completes */
  DMA_wait(hDma);

  /* close the DMA channel */
  DMA_close(hDma);
  
  /* Verify the results */
  for (x=0; x<BUFFSZ/sizeof(Uint32); x++) {
    if (BuffA[x] != BuffB[x]) {success = FALSE; break;}
  }

  return success;
}

/*----------------------------------------------------------------------------*/
int Example4() {

  int success = TRUE;
  Uint32 PriCtl,SecCtl,SrcAddr,DstAddr,XfrCnt; 
  int x;

  LOG_printf(&LogMain,"Example4");

  /* Initialize the buffers */
  for (x=0; x<BUFFSZ/sizeof(Uint32); x++) {
    BuffA[x] = x;
    BuffB[x] = 0x00000000;
  }
  
  /* Let's use the DMA to perform a simple data copy from */
  /* one buffer to another.                               */
  
  /* To start, we need to open up a DMA channel. Let's use */
  /* DMA channel 3 and also reset it upon opening.         */ 
  hDma = DMA_open(DMA_CHA3,DMA_OPEN_RESET); 
  
  /* Enable the DMA completion interrupt */
  IRQ_enable(DMA_getEventId(hDma));
  
  /* Generate discrete DMA parameters using 'make' macros */
  PriCtl  = DMA_PRICTL_RMK(
    DMA_PRICTL_DSTRLD_NONE,
    DMA_PRICTL_SRCRLD_NONE,
    DMA_PRICTL_EMOD_NOHALT,
    DMA_PRICTL_FS_DISABLE,
    DMA_PRICTL_TCINT_ENABLE,
    DMA_PRICTL_PRI_DMA,
    DMA_PRICTL_WSYNC_NONE,
    DMA_PRICTL_RSYNC_NONE,
    DMA_PRICTL_INDEX_NA,
    DMA_PRICTL_CNTRLD_NA,
    DMA_PRICTL_SPLIT_DISABLE,
    DMA_PRICTL_ESIZE_32BIT,
    DMA_PRICTL_DSTDIR_INC,
    DMA_PRICTL_SRCDIR_INC,
    DMA_PRICTL_START_STOP
  );
  SecCtl  = 0x00000080;
  SrcAddr = (Uint32)BuffA;
  DstAddr = (Uint32)BuffB;
  XfrCnt  = DMA_XFRCNT_RMK(
    DMA_XFRCNT_FRMCNT_OF(0),
    DMA_XFRCNT_ELECNT_OF(BUFFSZ/sizeof(Uint32))
  );
  
  /* Configure up the DMA channel */
  DMA_configArgs(hDma,PriCtl,SecCtl,SrcAddr,DstAddr,XfrCnt);
  
  /* Clear completion flag */
  Complete = FALSE;
  
  /* Start the DMA operation */
  DMA_start(hDma);
  
  /* Wait until the DMA completes */
  while (!Complete);

  /* All done with this channel so let's close it */
  DMA_close(hDma);

  /* Verify the results */
  for (x=0; x<BUFFSZ/sizeof(Uint32); x++) {
    if (BuffA[x] != BuffB[x]) {success = FALSE; break;}
  }

  return success;
}

/*----------------------------------------------------------------------------*/
void DmaIsr() {
  DMA_CLEAR_CONDITION(hDma, DMA_SECCTL_FRAMECOND);
  Complete = TRUE;
}

/*----------------------------------------------------------------------------*/

/******************************************************************************\
* End of main.c
\******************************************************************************/

