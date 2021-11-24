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
#include <csl_dat.h>

void SwiMainFunc(int arg0, int arg1);

extern far SWI_Obj SwiMain;
extern far LOG_Obj LogMain;

/*----------------------------------------------------------------------------*/
#pragma DATA_ALIGN(BuffA,4);
#pragma DATA_ALIGN(BuffB,4);
#pragma DATA_ALIGN(BuffC,4);

#define BUFFSZ 4096
static Uint8 BuffA[BUFFSZ];
static Uint8 BuffB[BUFFSZ];
static Uint8 BuffC[BUFFSZ];

static int Test1D();
static int Test2D();

/*----------------------------------------------------------------------------*/
void main() {

  /* Initialize the chip support library, required */
  CSL_init();
  
  LOG_printf(&LogMain,"<DAT>");

  /* Post main SWI to run */
  SWI_post(&SwiMain); 
  
} /* exit main and start schedular */ 

/*----------------------------------------------------------------------------*/
void SwiMainFunc(int arg0, int arg1) {

  int success = TRUE;
  
  LOG_printf(&LogMain,"SwiMainFunc");
  
  LOG_printf(&LogMain,"Test1D");
  success = success && Test1D();

  LOG_printf(&LogMain,"Test2D");
  success = success && Test2D();
  
  LOG_printf(&LogMain,"Success = %d",success);
  LOG_printf(&LogMain,"<DONE>");
}

/*----------------------------------------------------------------------------*/
int Test1D() {

  Uint32 FillValue,XfrId,x,y;
  int success = TRUE;
  
  /* Before using the DAT module, we have to open it. This          */
  /* allocates a DMA channel for exclusive use by the DAT module.   */
  /* For this example, we will chose any available DMA channel. You */
  /* could just as well denote a specific channel.                  */
  DAT_open(DAT_CHAANY, DAT_PRI_HIGH, DAT_OPEN_2D);
  
  /* lets do a loop to ensure we do a tremendous number of transfers */
  for (y=0; y<32; y++) {

    FillValue = 0x00C0FFEE;                    /* Set the fill value         */
    XfrId = DAT_fill(BuffA,BUFFSZ,&FillValue); /* Perform the fill operation */
    DAT_wait(XfrId);                           /* Wait for completion        */
  
    FillValue = 0x12345678;                    /* Set the fill value         */
    XfrId = DAT_fill(BuffB,BUFFSZ,&FillValue); /* Perform the fill operation */
    DAT_wait(XfrId);                           /* Wait for completion        */
    
    FillValue = 0xFFFFFFFF;                    /* Set the fill value         */
    XfrId = DAT_fill(BuffC,BUFFSZ,&FillValue); /* Perform the fill operation */
    DAT_wait(XfrId);                           /* Wait for completion        */
  
    /* You will notice in the fill operations above that we waited for    */
    /* completion between them. This is because we pass the address       */
    /* of the FillValue variable to the function and this address is      */
    /* used as the source address of the DMA transfer. If the FillValue   */
    /* is modified in the middle of a fill operation, the fill will       */
    /* proceed using the new fill value instead of finishing up using     */
    /* original fill value. To prevent this, you must either wait until   */
    /* the previous fill completes or use different fill value variables. */
    
    /* You may want to view the buffers to verify the fill operations.  */
    /* Now that the buffers are initialized, let's swap buffers A and B */
    /* using buffer C as a temporary swap buffer.                       */
  
    XfrId = DAT_copy(BuffB,BuffC,BUFFSZ);  /* copy B -> C         */
    XfrId = DAT_copy(BuffA,BuffB,BUFFSZ);  /* copy A -> B         */
    XfrId = DAT_copy(BuffC,BuffA,BUFFSZ);  /* copy C -> A         */
    DAT_wait(XfrId);                       /* Wait for completion */

    /* Now let's do a special series of copy operations that */
    /* weave the two buffers together.                       */
    for (x=0; x<BUFFSZ; x+=2) {
      XfrId = DAT_copy(BuffA,BuffB,x+1);
      XfrId = DAT_copy(BuffB,BuffA,x+2);
    }                                                          
  
    /* Wait until the last copy operation completes before continuing. */
    DAT_wait(XfrId);
  
    /* Verification loop. If all of the above operations passed, */
    /* this loop will exit with 'success' to set 1.              */
    for (x=0; x<BUFFSZ; x+=4) {
      if (*(Uint32*)(&BuffA[x]) != 0x0034FF78) {success=FALSE; break;}  
      if (*(Uint32*)(&BuffB[x]) != 0x0034FF78) {success=FALSE; break;}
    }    
  }
  
  /* We're all done with the DAT module so we'll */
  /* close it. This frees up the DMA channel.    */
  DAT_close();

  return success;
}

/*----------------------------------------------------------------------------*/
int Test2D() {

  Uint32 XfrId,x,i,j,y;
  int   success = TRUE;
  
  /* Before using the DAT module, we have to open it. This          */
  /* allocates a DMA channel for exclusive use by the DAT module.   */
  /* For this example, we will chose any available DMA channel. You */
  /* could just as well denote a specific channel.                  */
  DAT_open(DAT_CHAANY, DAT_PRI_HIGH, DAT_OPEN_2D);
  
  /* lets do a loop to ensure we do a tremendous number of transfers */
  for (y=0; y<32; y++) {

    /* Initialize Buffers */
    for (x=0; x<BUFFSZ; x+=4) {
      *(Uint32*)(&BuffA[x]) = x>>2;
      *(Uint32*)(&BuffB[x]) = 0xFFFFFFFF;
    }    
  
    /* Loop for different block sizes */
    for (x=8; x>0; x--) {
  
      /* series of 1D to 2D copies */
      for (j=0; j<4; j++) {
        for (i=0; i<4; i++) {
          DAT_copy2d(DAT_1D2D,BuffA+(x*x*(i+4*j)),BuffB+(4*x*x*j+x*i),x,x,4*x);
        }
      }
    
      /* series of 2D to 2D copies */
      for (j=0; j<4; j++) {
        for (i=0; i<4; i++) {
          DAT_copy2d(DAT_2D2D,BuffB+(4*x*x*j+x*i),BuffA+(4*x*x*j+x*i),x,x,4*x);
        }
      }
    
      /* series of 2D to 1D copies */
      for (j=0; j<4; j++) {
        for (i=0; i<4; i++) {
          DAT_copy2d(DAT_2D1D,BuffA+(4*x*x*j+x*i),BuffB+(x*x*(i+4*j)),x,x,4*x);
        }
      } 
    
      /* copy B back to A */
      XfrId = DAT_copy(BuffB,BuffA,4*x*x*4);
    }
  
    /* wait for final transfer to complete before checking results */
    DAT_wait(XfrId);
  
    /* Check results */
    for (x=0; x<BUFFSZ; x+=4) {
      if (*(Uint32*)(&BuffA[x]) != x>>2) {success = FALSE; break;}
    }    
  }

  /* We're all done with the DAT module so we'll */
  /* close it. This frees up the DMA channel.    */
  DAT_close();

  return success;
}

/*----------------------------------------------------------------------------*/

/******************************************************************************\
* End of main.c
\******************************************************************************/

