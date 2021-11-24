/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------interrupt_mcasp1.c---------
 */

#include "mcasp1.h"

extern far void vectors();


/************************************************************************\
 name:      SetInterruptsEdma

 purpose:   Sets up interrupts to service EDMA transfers

 inputs:    None

 returns:   n/a
\************************************************************************/
void SetInterruptsEdma(void)
{
     IRQ_setVecs(vectors);     /* point to the IRQ vector table	*/

     IRQ_nmiEnable();
     IRQ_globalEnable();
          
     IRQ_map(IRQ_EVT_EDMAINT, 8);
     IRQ_reset(IRQ_EVT_EDMAINT);

     IRQ_enable(IRQ_EVT_EDMAINT);

} /* end SetInterruptsEdma() */


/************************************************************************\
 name:      Interrupt Service Routine c_int08

 purpose:   ISR to service EDMAINT. vecs.asm must be modified to include
            c_int08 entry.
            
 inputs:    n/a

 returns:   n/a
\************************************************************************/
interrupt void    
c_int08(void)    
{
    EDMA_intDispatcher();
    return;
} /* end c_int08 */


void setXmtDone1()
{
    xmtDone = 1;
}

void setXmtDone2()
{
    xmtDone = 1;
}

void setRcvDone1()
{
    rcvDone = 1;
}

void setRcvDone2()
{
    rcvDone = 1;
}

