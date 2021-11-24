/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------mcasp1.h---------
 */

#include <csl.h>
#include <csl_edma.h>
#include <csl_mcasp.h>
#include <csl_mcasphal.h>
#include <csl_irq.h>
#include <csl_chip.h>
#include <csl_chiphal.h>


/**********************************************************************/
/* Example-specific Definitions                                       */
/**********************************************************************/
#define SCRATCHSIZE   0x300   /* Amount of memory set aside for source patterns */
 
#define FILL_CONST    0   /* Used for memory fill functions */
#define FILL_INC      1
#define FILL_DEC      2

#define SHIFT_NONE           0
#define SHIFT_LEFT           1
#define SHIFT_RIGHT_SIGNED   2
#define SHIFT_RIGHT_ZERO     3

#define PASS          0   /* Used as test return flags */
#define ERROR_TEST    1
#define ERROR_FILL    2

#define NUM_XMT_SERIALIZER   4
#define NUM_RCV_SERIALIZER   4
#define NUM_TDM_SLOT         32
#define NUM_XTDM_SLOT        16  /* only count the active even slots */
#define NUM_RTDM_SLOT        32  /* receives all slots--active and inactive */
#define TOTAL_XMT_DATA       NUM_XTDM_SLOT*3   /* transfer a total of 5 TDM frames per pin */
#define TOTAL_RCV_DATA       NUM_RTDM_SLOT*3   /* receives a total of 5 TDM frames per pin */


/**********************************************************************/
/* Functions Definition                                               */
/**********************************************************************/
/* Prototypes defined in mcasp_data.c */
Uint32 FillMem( Uint32 start_location, Uint32 length, Uint32 fill_value, Uint8 fill_type );
Uint32 ClearMem( Uint32 start_location, Uint32 length );
void SetupSrcLocations(Uint32 desired_src_space, Uint32 length, Uint32 serializer);
Uint32 CheckTransfer(Uint32 desired_src_space, Uint32 desired_dst_space, Uint32 length );
Uint32 ProcessMem( Uint32 start_location, Uint32 length, Uint8 shift_type, Uint8 shift_amount );

/* Prototypes defined in mcasp_interrupt.c */
interrupt void c_int08(void);
void SetInterruptsEdma(void);
void setXmtDone1();
void setXmtDone2();
void setRcvDone1();
void setRcvDone2();

/* Prototypes defined in mcasp_periph.c */
void InitMcasp(int port);
void SetupEdma(int port);
void WakeRcvXmt(int port);


/**********************************************************************/
/* Global variables defined in mcasp_main.c                           */
/**********************************************************************/
/* Reserve MORE src space than the number of data transmitted. 
   See function SetupSrcLocation for details */
   
extern Uint32  srcData[TOTAL_RCV_DATA*NUM_RCV_SERIALIZER];
extern Uint32  dstData[TOTAL_RCV_DATA*NUM_RCV_SERIALIZER];

extern volatile Uint32 xmtDone;
extern volatile Uint32 rcvDone;

extern MCASP_Handle hMcasp;
extern EDMA_Handle hEdmaAXEVT;
extern EDMA_Handle hEdmaAREVT;
extern EDMA_Handle hEdmaNull;
