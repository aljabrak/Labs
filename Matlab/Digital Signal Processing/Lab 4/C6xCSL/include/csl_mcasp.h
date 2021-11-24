/******************************************************************************\
*           Copyright (C) 1999-2002 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_mcasp.h
* DATE CREATED.. 08/10/2001 
* LAST MODIFIED. 02/25/2002  _write32, write32Cfg, read32, read32Cfg
*                02/14/2002  _getRbufAddrCfg()/_getXbufAddrCfg()
*                            MCASP_XBUFx / MCASP_RBUFx macros
*               
\******************************************************************************/
#ifndef _CSL_MCASP_H_
#define _CSL_MCASP_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_mcasphal.h>


#if (MCASP_SUPPORT)
/******************************************************************************\
* scope and inline control macros
\******************************************************************************/

#ifdef __cplusplus
#define CSLAPI extern "C" far
#else
#define CSLAPI extern far
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _MCASP_MOD_
  #define IDECL CSLAPI
  #define USEDEFS
  #define IDEF
#else
  #ifdef  _INLINE
    #define IDECL static inline
    #define USEDEFS
    #define IDEF  static inline
  #else
    #define IDECL CSLAPI
  #endif
#endif

/******************************************************************************\
* global macro declarations
\******************************************************************************/

/* MCASP_open() flags */
#define MCASP_OPEN_RESET     (0x00000001)


/* device identifiers for MCASP_open() */
#define MCASP_DEV0           (0) 
#if (_MCASP_PORT_CNT == 2)
  #define MCASP_DEV1         (1)
#endif


/* device identifiers for MCASP_open() */
#define MCASP_PORT0    MCASP_DEV0
#if (_MCASP_PORT_CNT == 2)
  #define MCASP_PORT1    MCASP_DEV1
#endif

/* select DIT vs. TDM mode */
#define  MCASP_XMT_DIT     1
#define  MCASP_XMT_TDM     0

/* direction = (transmitter only) MCASP_XMT or (receiver only) MCASP_RCV  */
/*             or (both) MCASP_RCVXMT / MCASP_XMTRCV */
#define MCASP_RCV       1
#define MCASP_XMT    	2
#define MCASP_RCVXMT	3
#define MCASP_XMTRCV	3

/* Mode for clk */
#define MCASP_CLK_ASYNC       1
#define MCASP_CLK_SYNC        0


/* define DSP representation */
//#define MCASP_DSP_INTEGER   0
//#define MCASP_DSP_Q31       1

/* define Mode BURST or TDM for format*/
#define MCASP_MODE_BURST    0
#define MCASP_MODE_TDM      1

/* define Mode MSB/LSB first */
#define MCASP_FORMAT_LSB    0
#define MCASP_FORMAT_MSB    1

/* define Align  */
#define MCASP_FORMAT_LEFT   0
#define MCASP_FORMAT_RIGHT  1
      

/* Address Incrementation */
#define MCASP_XBUF_BUFSIZE 4
#define MCASP_RBUF_BUFSIZE 4

#define MCASP_DITCSR_NUMCHANNELS 6
#define MCASP_DITCSR_BUFSIZE 4
#define MCASP_DITCSR_RIGHT_OFFSET (MCASP_DITCSR_BUFSIZE*MCASP_DITCSR_NUMCHANNELS)

#define MCASP_DITUDR_NUMCHANNELS 6
#define MCASP_DITUDR_BUFSIZE 4
#define MCASP_DITUDR_RIGHT_OFFSET (MCASP_DITUDR_BUFSIZE*MCASP_DITUDR_NUMCHANNELS)

/* Status clear */
#define MCASP_RSTAT_ROVRN       0
#define MCASP_RSTAT_RSYNCERR    1
#define MCASP_RSTAT_RCKFAIL     2
#define MCASP_RSTAT_REVENSLOT   3 
#define MCASP_RSTAT_RLAST       4
#define MCASP_RSTAT_RDATA       5
#define MCASP_RSTAT_RSTAFRM     6
#define MCASP_RSTAT_RDMAERR     7
#define MCASP_RSTAT_RERR        8

#define MCASP_XSTAT_XUNDRN      0
#define MCASP_XSTAT_XSYNCERR    1
#define MCASP_XSTAT_XCKFAIL     2
#define MCASP_XSTAT_XEVENSLOT   3 
#define MCASP_XSTAT_XLAST       4
#define MCASP_XSTAT_XDATA       5
#define MCASP_XSTAT_XSTAFRM     6
#define MCASP_XSTAT_XDMAERR     7
#define MCASP_XSTAT_XERR        8


#define MCASP_XBUF0              0
#define MCASP_XBUF1              1
#define MCASP_XBUF2              2 
#define MCASP_XBUF3              3
/* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define MCASP_XBUF4              4
  #define MCASP_XBUF5              5
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6)
  #define MCASP_XBUF6              6
  #define MCASP_XBUF7              7
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define MCASP_XBUF8              8
  #define MCASP_XBUF9              9
  #define MCASP_XBUF10             10
  #define MCASP_XBUF11             11 
  #define MCASP_XBUF12             12
  #define MCASP_XBUF13             13
  #define MCASP_XBUF14             14
  #define MCASP_XBUF15             15
#endif /* _MCASP_CHANNEL_CNT == 16 */

#define MCASP_RBUF0              0
#define MCASP_RBUF1              1
#define MCASP_RBUF2              2 
#define MCASP_RBUF3              3
/* Fields for _MCASP_CHANNEL_CNT == 4 end here*/

#if (_MCASP_CHANNEL_CNT > 4)
  #define MCASP_RBUF4              4
  #define MCASP_RBUF5              5
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT > 6)
  #define MCASP_RBUF6              6
  #define MCASP_RBUF7              7
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 16)
  #define MCASP_RBUF8              8
  #define MCASP_RBUF9              9
  #define MCASP_RBUF10             10
  #define MCASP_RBUF11             11 
  #define MCASP_RBUF12             12
  #define MCASP_RBUF13             13
  #define MCASP_RBUF14             14
  #define MCASP_RBUF15             15
#endif /* _MCASP_CHANNEL_CNT == 16 */

/******************************************************************************\
* global typedef declarations
\******************************************************************************/

typedef enum {
  MCASP_DSP_INTEGER = 0,
  MCASP_DSP_Q31     = 1 
} MCASP_Dsprep;


/* device handle object */
typedef struct {
  Uint32 allocated;
  Uint32 xmtEventId;
  Uint32 rcvEventId;   
  volatile Uint32 *baseAddr;
  Uint32 xbufAddr;
  Uint32 xbufAddrCfg;
  Uint32 rbufAddr;
  Uint32 rbufAddrCfg;
  Uint32 ditcsrAddr;
  Uint32 ditudrAddr;
} MCASP_Obj, *MCASP_Handle;

/* device configuration structure */

typedef struct {
	Uint32 pfunc; 
	Uint32 pdir; 
	Uint32 ditctl;
	Uint32 dlbctl; 
	Uint32 amute;
} MCASP_ConfigGbl;

typedef struct {
	Uint32 rmask;
	Uint32 rfmt; 
	Uint32 afsrctl; 
	Uint32 aclkrctl; 
	Uint32 ahclkrctl; 
	Uint32 rtdm; 
	Uint32 rintctl; 
	Uint32 rclkchk;
} MCASP_ConfigRcv;

typedef struct {
	Uint32 xmask; 
	Uint32 xfmt; 
	Uint32 afsxctl; 
	Uint32 aclkxctl;
	Uint32 ahclkxctl; 
	Uint32 xtdm;
	Uint32 xintctl; 
	Uint32 xclkchk;
} MCASP_ConfigXmt;

#if (_MCASP_CHANNEL_CNT == 16) 
typedef struct { 
	Uint32 srctl0; 
	Uint32 srctl1; 
	Uint32 srctl2; 
	Uint32 srctl3; 
	Uint32 srctl4; 
	Uint32 srctl5; 
	Uint32 srctl6; 
	Uint32 srctl7; 
	Uint32 srctl8; 
	Uint32 srctl9; 
	Uint32 srctl10; 
	Uint32 srctl11; 
	Uint32 srctl12; 
	Uint32 srctl13; 
	Uint32 srctl14; 
	Uint32 srctl15;
} MCASP_ConfigSrctl;

#endif /* _MCASP_CHANNEL_CNT == 16 */

#if (_MCASP_CHANNEL_CNT == 8)

typedef struct { 
	Uint32 srctl0; 
	Uint32 srctl1; 
	Uint32 srctl2; 
	Uint32 srctl3; 
	Uint32 srctl4; 
	Uint32 srctl5; 
	Uint32 srctl6; 
	Uint32 srctl7; 
} MCASP_ConfigSrctl;

#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 6) 
typedef struct { 
        Uint32 srctl0; 
        Uint32 srctl1; 
        Uint32 srctl2; 
        Uint32 srctl3; 
        Uint32 srctl4; 
        Uint32 srctl5; 
} MCASP_ConfigSrctl;
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT == 4) 
typedef struct { 
        Uint32 srctl0; 
        Uint32 srctl1; 
        Uint32 srctl2; 
        Uint32 srctl3; 
} MCASP_ConfigSrctl;
#endif /* _MCASP_CHANNEL_CNT == 4 */

typedef struct {
	MCASP_ConfigGbl	*global;
	MCASP_ConfigRcv	*receive;
	MCASP_ConfigXmt	*transmit;
	MCASP_ConfigSrctl	*srctl;
} MCASP_Config;


/* Parameter Clock Control : ACLKXCTL - ACLKRCTL   */
typedef struct {
   Uint32 syncmode;    /* Async 0 /1 : ACLKXCTL */
   Uint32 xclksrc;     /* Xmt clock source      */
   Uint32 xclkpol;     /* Xmt clock polarity    */
   Uint32 xclkdiv;     /* Xmt clock div         */  
   Uint32 rclksrc;     /* Rcv clock source      */
   Uint32 rclkpol;     /* Rcv clock polarity    */
   Uint32 rclkdiv;     /* Rcv clock div         */  
}MCASP_SetupClk;   


/* Parameter High- Freq Clock Control : AHCLKXCTL - AHCLKRCTL   */
typedef struct {
   Uint32 xhclksrc;     /* Xmt clock source      */
   Uint32 xhclkpol;     /* Xmt clock polarity    */
   Uint32 xhclkdiv;     /* Xmt clock div         */  
   Uint32 rhclksrc;     /* Rcv clock source      */
   Uint32 rhclkpol;     /* Rcv clock polarity    */
   Uint32 rhclkdiv;     /* Rcv clock div         */  
}MCASP_SetupHclk;   


/* Parameter Frame Sync Control : AFSXCTL - AFSRCTL   */
typedef struct {
   Uint32 xmode;      /* TDM - BURST   : FSXMOD - AFSXCTL reg     */
   Uint32 xslotsize;  /* slots# for TDM: FSXMOD - AFSXCTL reg    */          
   Uint32 xfssrc;     /* Internal/External  AFSXE - AFSXCTL reg   */
   Uint32 xfspol;     /* Xmt clock polarity  FSXPOL - AFSXCTL reg */
   Uint32 fxwid;     /* Xmt Frame Duration  FXWID - AFSXCTL reg */           
   Uint32 rmode;      /* TDM - BURST   FSRMOD - AFSRCTL reg       */
   Uint32 rslotsize;  /* slots# for TDM                           */
   Uint32 rfssrc;     /* Rcv Internal/External AFSRE - AFSRCTL reg */
   Uint32 rfspol;     /* Rcv clock polarity  FSRPOL- AFSRCTL reg   */ 
   Uint32 frwid;     /* Rcv Frame Duration  FRWID - AFSRCTL reg */             
}MCASP_SetupFsync;   

/* Parameters  Data Stream Format: XFMT - RFMT   */
typedef struct {
  Uint32 xbusel;        /* DAT / CFG bus                     */
  MCASP_Dsprep xdsprep;       /* DSP representation :Q31/Integer   */
  Uint32 xslotsize;     /* 8-32bits  TXSSZ field - XFMT reg  */
  Uint32 xwordsize;     /* rotation right                    */
  Uint32 xalign;        /* Left/Right Aligned                */
  Uint32 xpad;          /* Pad value for extra bits          */
  Uint32 xpbit;         /* which bit to pad the extra bits   */
  Uint32 xorder;        /* MSB/LSB XRVRS field  - XFMT reg   */
  Uint32 xdelay;        /*  Bit delay - XFMT reg             */
  Uint32 rbusel;        /* DAT / CFG bus                     */
  MCASP_Dsprep rdsprep;       /* DSP representation :Q31/Integer   */
  Uint32 rslotsize;     /* 8-32bits  RXSSZ                   */
  Uint32 rwordsize;     /* rotation right                    */
  Uint32 ralign;        /* Left/Right Aligned                */
  Uint32 rpad;          /* Pad value for extra bits          */
  Uint32 rpbit;         /* which bit to pad the extra bits   */
  Uint32 rorder;        /* MSB/LSB XRVRS field  - XFMT reg   */
  Uint32 rdelay;        /* FSXDLY Bit delay - XFMT reg       */             
} MCASP_SetupFormat;



 
/******************************************************************************\
* global variable declarations
\******************************************************************************/

/******************************************************************************\
* global function declarations
\******************************************************************************/
CSLAPI void MCASP_reset(MCASP_Handle hMcasp);
CSLAPI void MCASP_resetAll();

CSLAPI MCASP_Handle MCASP_open(int devNum, Uint32 flags);
CSLAPI void MCASP_close(MCASP_Handle hMcasp);
CSLAPI MCASP_Handle MCASP_getHandle(int devNum);

CSLAPI Uint32 MCASP_getPins(MCASP_Handle hMcasp);
CSLAPI void MCASP_setPins(MCASP_Handle hMcasp, Uint32 pins);
CSLAPI void MCASP_clearPins(MCASP_Handle hMcasp, Uint32 pins);

/* direction = (transmitter only) MCASP_XMT - (receiver only) MCASP_RCV - (both) MCASP_RCVXMT */

/* active state machine step 8*/
CSLAPI void MCASP_enableSm(MCASP_Handle hMcasp, Uint32 direction);

/* enable data serializer step 5*/
CSLAPI void MCASP_enableSers(MCASP_Handle hMcasp, Uint32 direction);

/* enable clocks  step 4  */
CSLAPI void MCASP_enableClk(MCASP_Handle hMcasp, Uint32 direction);
CSLAPI void MCASP_enableHclk(MCASP_Handle hMcasp, Uint32 direction);

/* enable frame sync if receiver with internal frame sync */
CSLAPI void MCASP_enableFsync(MCASP_Handle hMcasp, Uint32 direction);


CSLAPI void MCASP_setupClk(MCASP_Handle hMcasp,MCASP_SetupClk *setupclk, Uint32 direction);
CSLAPI void MCASP_setupHclk(MCASP_Handle hMcasp,MCASP_SetupHclk *setuphclk, Uint32 direction);
CSLAPI void MCASP_setupFsync(MCASP_Handle hMcasp,MCASP_SetupFsync *setupfsync, Uint32 direction);
CSLAPI void MCASP_setupFormat(MCASP_Handle hMcasp,MCASP_SetupFormat *setupFormat, Uint32 direction);

/* Configuration of DIT mode */
CSLAPI void MCASP_configDit(MCASP_Handle hMcasp,MCASP_Dsprep dsprep, Uint32 datalen); 

/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL Uint32 MCASP_getXbufAddrCfg(MCASP_Handle hMcasp, Uint32 xbufNum); 
IDECL Uint32 MCASP_getXbufAddr(MCASP_Handle hMcasp);

IDECL Uint32 MCASP_getRbufAddrCfg(MCASP_Handle hMcasp, Uint32 rbufNum); 
IDECL Uint32 MCASP_getRbufAddr(MCASP_Handle hMcasp);

IDECL Uint32 MCASP_getXmtEventId(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_getRcvEventId(MCASP_Handle hMcasp);

IDECL Uint32 MCASP_read32Cfg(MCASP_Handle hMcasp, Uint32 rbufNum);
IDECL void   MCASP_write32Cfg(MCASP_Handle hMcasp, Uint32 xbufNum, Uint32 val);
/* uses EDMA addresses */
IDECL Uint32 MCASP_read32(MCASP_Handle hMcasp);
IDECL void   MCASP_write32(MCASP_Handle hMcasp,Uint32 val);

IDECL Uint32 MCASP_rstat(MCASP_Handle hMcasp);

/******* Not documented ************************/
IDECL Uint32 MCASP_rovrn(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_rsyncerr(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_rckfail(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_revenslot(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_rlast(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_rdata(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_rstafrm(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_rerr(MCASP_Handle hMcasp);

IDECL Uint32 MCASP_xstat(MCASP_Handle hMcasp);
/******* Not documented ************************/
IDECL Uint32 MCASP_xundrn(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_xsyncerr(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_xckfail(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_xevenslot(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_xlast(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_xdata(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_xstafrm(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_xerr(MCASP_Handle hMcasp);

IDECL Uint32 MCASP_getRslotcnt(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_getXslotcnt(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_getRclkcnt(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_getXclkcnt(MCASP_Handle hMcasp);
IDECL Uint32 MCASP_getMutin(MCASP_Handle hMcasp);

/*****************************************************/
IDECL void MCASP_clearRcvStat(MCASP_Handle hMcasp,Uint32 fieldnum);
IDECL void MCASP_clearXmtStat(MCASP_Handle hMcasp,Uint32 fieldnum);

IDECL Uint32 MCASP_getChanStatusAddr(MCASP_Handle hMcasp, Uint32 chSide, Uint32 chNum);
IDECL Uint32 MCASP_getUserDataAddr(MCASP_Handle hMcasp, Uint32 chSide, Uint32 chNum);

IDECL void MCASP_config(MCASP_Handle hMcasp, MCASP_Config *config);
IDECL void MCASP_configGbl(MCASP_Handle hMcasp, MCASP_ConfigGbl *config);
IDECL void MCASP_configRcv(MCASP_Handle hMcasp, MCASP_ConfigRcv *config);
IDECL void MCASP_configXmt(MCASP_Handle hMcasp, MCASP_ConfigXmt *config);
IDECL void MCASP_configSrctl(MCASP_Handle hMcasp, MCASP_ConfigSrctl *config);

/************** Not documented ****************************************/

#if (_MCASP_CHANNEL_CNT == 16)
IDECL void MCASP_configArgs(MCASP_Handle hMcasp, Uint32 pfunc, Uint32 pdir, 
  Uint32 amute, Uint32 dlbctl, Uint32 ditctl, Uint32 rmask, Uint32 rfmt, Uint32 afsrctl,
  Uint32 aclkrctl, Uint32 ahclkrctl, Uint32 rtdm, Uint32 rintctl, Uint32 rclkchk,
  Uint32 xmask, Uint32 xfmt, Uint32 afsxctl, Uint32 aclkxctl, Uint32 ahclkxctl, Uint32 xtdm, 
  Uint32 xintctl, Uint32 xclkchk, Uint32 srctl0, Uint32 srctl1, Uint32 srctl2, Uint32 srctl3, 
  Uint32 srctl4, Uint32 srctl5, Uint32 srctl6, Uint32 srctl7, Uint32 srctl8, Uint32 srctl9, 
  Uint32 srctl10, Uint32 srctl11, Uint32 srctl12, Uint32 srctl13, Uint32 srctl14, Uint32 srctl15  );

#endif /* _MCASP_CHANNEL_CNT == 16 */

#if (_MCASP_CHANNEL_CNT == 8)
IDECL void MCASP_configArgs(MCASP_Handle hMcasp, Uint32 pfunc, Uint32 pdir, 
  Uint32 amute, Uint32 dlbctl, Uint32 ditctl, Uint32 rmask, Uint32 rfmt, Uint32 afsrctl,
  Uint32 aclkrctl, Uint32 ahclkrctl, Uint32 rtdm, Uint32 rintctl, Uint32 rclkchk,
  Uint32 xmask, Uint32 xfmt, Uint32 afsxctl, Uint32 aclkxctl, Uint32 ahclkxctl, Uint32 xtdm, 
  Uint32 xintctl, Uint32 xclkchk, Uint32 srctl0, Uint32 srctl1, Uint32 srctl2, Uint32 srctl3, 
  Uint32 srctl4, Uint32 srctl5, Uint32 srctl6, Uint32 srctl7);
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 6)
IDECL void MCASP_configArgs(MCASP_Handle hMcasp, Uint32 pfunc, Uint32 pdir, 
  Uint32 amute, Uint32 dlbctl, Uint32 ditctl, Uint32 rmask, Uint32 rfmt, Uint32 afsrctl,
  Uint32 aclkrctl, Uint32 ahclkrctl, Uint32 rtdm, Uint32 rintctl, Uint32 rclkchk,
  Uint32 xmask, Uint32 xfmt, Uint32 afsxctl, Uint32 aclkxctl, Uint32 ahclkxctl, Uint32 xtdm, 
  Uint32 xintctl, Uint32 xclkchk, Uint32 srctl0, Uint32 srctl1, Uint32 srctl2, Uint32 srctl3, 
  Uint32 srctl4, Uint32 srctl5);
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT == 4)
IDECL void MCASP_configArgs(MCASP_Handle hMcasp, Uint32 pfunc, Uint32 pdir, 
  Uint32 amute, Uint32 dlbctl, Uint32 ditctl, Uint32 rmask, Uint32 rfmt, Uint32 afsrctl,
  Uint32 aclkrctl, Uint32 ahclkrctl, Uint32 rtdm, Uint32 rintctl, Uint32 rclkchk,
  Uint32 xmask, Uint32 xfmt, Uint32 afsxctl, Uint32 aclkxctl, Uint32 ahclkxctl, Uint32 xtdm, 
  Uint32 xintctl, Uint32 xclkchk, Uint32 srctl0, Uint32 srctl1, Uint32 srctl2, Uint32 srctl3);
#endif /* _MCASP_CHANNEL_CNT == 4 */

/**********************************************************************/

IDECL void MCASP_getConfig(MCASP_Handle hMcasp, MCASP_Config *config);

IDECL void MCASP_resetXmt(MCASP_Handle hMcasp);
IDECL void MCASP_resetRcv(MCASP_Handle hMcasp);

/** read GBLCTL register with the right value **/
IDECL Uint32 MCASP_getGblctl(MCASP_Handle hMcasp, Uint32 direction);


/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getXbufAddr(MCASP_Handle hMcasp) {
  return (Uint32)(hMcasp->xbufAddr);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getXbufAddrCfg(MCASP_Handle hMcasp, Uint32 xbufNum) {
  return (Uint32)(hMcasp->xbufAddrCfg + (xbufNum*MCASP_XBUF_BUFSIZE));
}

/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getRbufAddr(MCASP_Handle hMcasp) {
  return (Uint32)(hMcasp->rbufAddr);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getRbufAddrCfg(MCASP_Handle hMcasp, Uint32 rbufNum) {
  return (Uint32)(hMcasp->rbufAddrCfg + (rbufNum*MCASP_RBUF_BUFSIZE));
}

/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getGblctl(MCASP_Handle hMcasp,Uint32 direction) {
  if (direction == MCASP_XMT) {
  return (MCASP_RGETH(hMcasp,XGBLCTL)& 0x0001F00);
  } else { 
  if (direction == MCASP_RCV) {
  return (MCASP_RGETH(hMcasp,RGBLCTL)& 0x000001F);
  } else {
  return (MCASP_RGETH(hMcasp,GBLCTL));
    }
 }
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getXmtEventId(MCASP_Handle hMcasp) {
  return (hMcasp->xmtEventId);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getRcvEventId(MCASP_Handle hMcasp) {
  return (hMcasp->rcvEventId);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_read32Cfg(MCASP_Handle hMcasp, Uint32 rbufNum) {
  return (*(volatile Uint32 *)(hMcasp->rbufAddrCfg + (rbufNum*MCASP_RBUF_BUFSIZE)));
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_read32(MCASP_Handle hMcasp) {
  return (*(volatile Uint32 *)(hMcasp->rbufAddr));
}
/*----------------------------------------------------------------------------*/
IDEF void MCASP_write32Cfg(MCASP_Handle hMcasp, Uint32 xbufNum, Uint32 val) {
  (*(volatile Uint32 *)(hMcasp->xbufAddrCfg + (xbufNum*MCASP_XBUF_BUFSIZE))) = val;
}
/*----------------------------------------------------------------------------*/
IDEF void MCASP_write32(MCASP_Handle hMcasp, Uint32 val) {
  (*(volatile Uint32 *)(hMcasp->xbufAddr)) = val;
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_rstat(MCASP_Handle hMcasp) {
  return MCASP_RGETH(hMcasp,RSTAT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_rovrn(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,RSTAT,ROVRN);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_rsyncerr(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,RSTAT,RSYNCERR);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_rckfail(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,RSTAT,RCKFAIL);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_revenslot(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,RSTAT,RTDMSLOT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_rlast(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,RSTAT,RLAST);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_rdata(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,RSTAT,RDATA);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_rstafrm(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,RSTAT,RSTAFRM);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_rerr(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,RSTAT,RERR);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_xstat(MCASP_Handle hMcasp) {
  return MCASP_RGETH(hMcasp,XSTAT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_xundrn(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,XSTAT,XUNDRN);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_xsyncerr(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,XSTAT,XSYNCERR);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_xckfail(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,XSTAT,XCKFAIL);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_xevenslot(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,XSTAT,XTDMSLOT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_xlast(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,XSTAT,XLAST);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_xdata(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,XSTAT,XDATA);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_xstafrm(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,XSTAT,XSTAFRM);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_xerr(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,XSTAT,XERR);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getRslotcnt(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,RSLOT,RSLOTCNT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getXslotcnt(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,XSLOT,XSLOTCNT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getRclkcnt(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,RCLKCHK,RCNT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getXclkcnt(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,XCLKCHK,XCNT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getMutin(MCASP_Handle hMcasp) {
  return MCASP_FGETH(hMcasp,AMUTE,INSTAT);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getChanStatusAddr(MCASP_Handle hMcasp, Uint32 chSide, Uint32 chNum) {
  return (Uint32)(hMcasp->ditcsrAddr + (chSide*MCASP_DITCSR_RIGHT_OFFSET)+
  (chNum*MCASP_DITCSR_BUFSIZE));
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 MCASP_getUserDataAddr(MCASP_Handle hMcasp, Uint32 chSide, Uint32 chNum) {
  return (Uint32)(hMcasp->ditudrAddr + (chSide*MCASP_DITUDR_RIGHT_OFFSET)+
  (chNum*MCASP_DITUDR_BUFSIZE));
}
/*----------------------------------------------------------------------------*/
IDEF void MCASP_clearXmtStat(MCASP_Handle hMcasp, Uint32 fieldnum){
    MCASP_RSETH(hMcasp,XSTAT,1<<fieldnum);
}
/*----------------------------------------------------------------------------*/
IDEF void MCASP_clearRcvStat(MCASP_Handle hMcasp, Uint32 fieldnum){
     MCASP_RSETH(hMcasp,RSTAT,1<<fieldnum);
}
/*----------------------------------------------------------------------------*/

IDEF void MCASP_resetRcv(MCASP_Handle hMcasp) {
/* reset State Machine = clear serial buffer = reset frame sync generator 
   reset Clock */
  MCASP_RSETH(hMcasp,GBLCTL, MCASP_RGETH(hMcasp,RGBLCTL) &\
	  MCASP_FMKS(GBLCTL,RSRCLR,CLEAR) \
	| MCASP_FMKS(GBLCTL,RSMRST,RESET) \
	| MCASP_FMKS(GBLCTL,RFRST,RESET) \
	| MCASP_FMKS(GBLCTL,RCLKRST,RESET) \
	| MCASP_FMKS(GBLCTL,RHCLKRST,RESET) \
	);
}
/*----------------------------------------------------------------------------*/
IDEF void MCASP_resetXmt(MCASP_Handle hMcasp) {
/* reset State Machine = clear serial buffer = reset frame sync generator 
   reset Clock */
  MCASP_RSETH(hMcasp,GBLCTL, MCASP_RGETH(hMcasp,XGBLCTL) &\
	  MCASP_FMKS(GBLCTL,XSRCLR,CLEAR) \
	| MCASP_FMKS(GBLCTL,XSMRST,RESET) \
	| MCASP_FMKS(GBLCTL,XFRST,RESET) \
	| MCASP_FMKS(GBLCTL,XCLKRST,RESET) \
	| MCASP_FMKS(GBLCTL,XHCLKRST,RESET) 
	);
}
/*----------------------------------------------------------------------------*/
#if (_MCASP_CHANNEL_CNT == 16)
IDEF void MCASP_config(MCASP_Handle hMcasp, MCASP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19;
  register int x20,x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x0 = config->global->pfunc;
  x1 = config->global->pdir;
  x2 = config->global->amute;
  x3 = config->global->dlbctl;
  x4 = config->global->ditctl;
  x5 = config->receive->rmask;
  x6 = config->receive->rfmt;
  x7 = config->receive->afsrctl;
  x8 = config->receive->aclkrctl;
  x9 = config->receive->ahclkrctl;
  x10 = config->receive->rtdm;
  x11 = config->receive->rintctl;
  x12 = config->receive->rclkchk;
  x13 = config->transmit->xmask;
  x14 = config->transmit->xfmt;
  x15 = config->transmit->afsxctl;
  x16 = config->transmit->aclkxctl;
  x17 = config->transmit->ahclkxctl;
  x18 = config->transmit->xtdm;
  x19 = config->transmit->xintctl;
  x20 = config->transmit->xclkchk;
  x21 = config->srctl->srctl0;
  x22 = config->srctl->srctl1;
  x23 = config->srctl->srctl2;
  x24 = config->srctl->srctl3;
  x25 = config->srctl->srctl4;
  x26 = config->srctl->srctl5;
  x27 = config->srctl->srctl6;
  x28 = config->srctl->srctl7;
  x29 = config->srctl->srctl8;
  x30 = config->srctl->srctl9;
  x31 = config->srctl->srctl10;
  x32 = config->srctl->srctl11;
  x33 = config->srctl->srctl12;
  x34 = config->srctl->srctl13;
  x35 = config->srctl->srctl14;
  x36 = config->srctl->srctl15;

  base[_MCASP_RMASK_OFFSET] = 	x5;
  base[_MCASP_RFMT_OFFSET] = 	x6;
  base[_MCASP_AFSRCTL_OFFSET] = x7;
  base[_MCASP_ACLKRCTL_OFFSET]= x8;
  base[_MCASP_AHCLKRCTL_OFFSET]= x9;
  base[_MCASP_RTDM_OFFSET] = 	x10;
  base[_MCASP_RINTCTL_OFFSET] = x11;
  base[_MCASP_RCLKCHK_OFFSET] = x12;
  base[_MCASP_XMASK_OFFSET] = 	x13;
  base[_MCASP_XFMT_OFFSET] = 	x14;
  base[_MCASP_AFSXCTL_OFFSET] = x15;
  base[_MCASP_ACLKXCTL_OFFSET]= x16;
  base[_MCASP_AHCLKXCTL_OFFSET]= x17;
  base[_MCASP_XTDM_OFFSET] = 	x18;
  base[_MCASP_XINTCTL_OFFSET] = x19;
  base[_MCASP_XCLKCHK_OFFSET] = x20;
  base[_MCASP_SRCTL0_OFFSET] = 	x21;
  base[_MCASP_SRCTL1_OFFSET] = 	x22;
  base[_MCASP_SRCTL2_OFFSET] = 	x23;
  base[_MCASP_SRCTL3_OFFSET] = 	x24;
  base[_MCASP_SRCTL4_OFFSET] = 	x25;
  base[_MCASP_SRCTL5_OFFSET] = 	x26;
  base[_MCASP_SRCTL6_OFFSET] = 	x27;
  base[_MCASP_SRCTL7_OFFSET] = 	x28;
  base[_MCASP_SRCTL8_OFFSET] = 	x29;
  base[_MCASP_SRCTL9_OFFSET] = 	x30;
  base[_MCASP_SRCTL10_OFFSET] = x31;
  base[_MCASP_SRCTL11_OFFSET] = x32;
  base[_MCASP_SRCTL12_OFFSET] = x33;
  base[_MCASP_SRCTL13_OFFSET] = x34;
  base[_MCASP_SRCTL14_OFFSET] = x35;
  base[_MCASP_SRCTL15_OFFSET] = x36;
  base[_MCASP_AMUTE_OFFSET]  = 	x2;
  base[_MCASP_DLBCTL_OFFSET] = 	x3;
  base[_MCASP_DITCTL_OFFSET] =  x4;
  base[_MCASP_PFUNC_OFFSET] = 	x0;
  base[_MCASP_PDIR_OFFSET]  = 	x1;

  IRQ_globalRestore(gie);
}

#endif /* _MCASP_CHANNEL_CNT == 16 */

#if (_MCASP_CHANNEL_CNT == 8)
IDEF void MCASP_config(MCASP_Handle hMcasp, MCASP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19;
  register int x20,x21,x22,x23,x24,x25,x26,x27,x28;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x0 = config->global->pfunc;
  x1 = config->global->pdir;
  x2 = config->global->amute;
  x3 = config->global->dlbctl;
  x4 = config->global->ditctl;
  x5 = config->receive->rmask;
  x6 = config->receive->rfmt;
  x7 = config->receive->afsrctl;
  x8 = config->receive->aclkrctl;
  x9 = config->receive->ahclkrctl;
  x10 = config->receive->rtdm;
  x11 = config->receive->rintctl;
  x12 = config->receive->rclkchk;
  x13 = config->transmit->xmask;
  x14 = config->transmit->xfmt;
  x15 = config->transmit->afsxctl;
  x16 = config->transmit->aclkxctl;
  x17 = config->transmit->ahclkxctl;
  x18 = config->transmit->xtdm;
  x19 = config->transmit->xintctl;
  x20 = config->transmit->xclkchk;
  x21 = config->srctl->srctl0;
  x22 = config->srctl->srctl1;
  x23 = config->srctl->srctl2;
  x24 = config->srctl->srctl3;
  x25 = config->srctl->srctl4;
  x26 = config->srctl->srctl5;
  x27 = config->srctl->srctl6;
  x28 = config->srctl->srctl7;

  base[_MCASP_RMASK_OFFSET] = 	x5;
  base[_MCASP_RFMT_OFFSET] = 	x6;
  base[_MCASP_AFSRCTL_OFFSET] = x7;
  base[_MCASP_ACLKRCTL_OFFSET]= x8;
  base[_MCASP_AHCLKRCTL_OFFSET]= x9;
  base[_MCASP_RTDM_OFFSET] = 	x10;
  base[_MCASP_RINTCTL_OFFSET] = x11;
  base[_MCASP_RCLKCHK_OFFSET] = x12;
  base[_MCASP_XMASK_OFFSET] = 	x13;
  base[_MCASP_XFMT_OFFSET] = 	x14;
  base[_MCASP_AFSXCTL_OFFSET] = x15;
  base[_MCASP_ACLKXCTL_OFFSET]= x16;
  base[_MCASP_AHCLKXCTL_OFFSET]= x17;
  base[_MCASP_XTDM_OFFSET] = 	x18;
  base[_MCASP_XINTCTL_OFFSET] = x19;
  base[_MCASP_XCLKCHK_OFFSET] = x20;
  base[_MCASP_SRCTL0_OFFSET] = 	x21;
  base[_MCASP_SRCTL1_OFFSET] = 	x22;
  base[_MCASP_SRCTL2_OFFSET] = 	x23;
  base[_MCASP_SRCTL3_OFFSET] = 	x24;
  base[_MCASP_SRCTL4_OFFSET] = 	x25;
  base[_MCASP_SRCTL5_OFFSET] = 	x26;
  base[_MCASP_SRCTL6_OFFSET] = 	x27;
  base[_MCASP_SRCTL7_OFFSET] = 	x28;
  base[_MCASP_AMUTE_OFFSET]  = 	x2;
  base[_MCASP_DLBCTL_OFFSET] = 	x3;
  base[_MCASP_DITCTL_OFFSET] =  x4;
  base[_MCASP_PFUNC_OFFSET] = 	x0;
  base[_MCASP_PDIR_OFFSET]  = 	x1;

  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 6)
IDEF void MCASP_config(MCASP_Handle hMcasp, MCASP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19;
  register int x20,x21,x22,x23,x24,x25,x26;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x0 = config->global->pfunc;
  x1 = config->global->pdir;
  x2 = config->global->amute;
  x3 = config->global->dlbctl;
  x4 = config->global->ditctl;
  x5 = config->receive->rmask;
  x6 = config->receive->rfmt;
  x7 = config->receive->afsrctl;
  x8 = config->receive->aclkrctl;
  x9 = config->receive->ahclkrctl;
  x10 = config->receive->rtdm;
  x11 = config->receive->rintctl;
  x12 = config->receive->rclkchk;
  x13 = config->transmit->xmask;
  x14 = config->transmit->xfmt;
  x15 = config->transmit->afsxctl;
  x16 = config->transmit->aclkxctl;
  x17 = config->transmit->ahclkxctl;
  x18 = config->transmit->xtdm;
  x19 = config->transmit->xintctl;
  x20 = config->transmit->xclkchk;
  x21 = config->srctl->srctl0;
  x22 = config->srctl->srctl1;
  x23 = config->srctl->srctl2;
  x24 = config->srctl->srctl3;
  x25 = config->srctl->srctl4;
  x26 = config->srctl->srctl5;

  base[_MCASP_RMASK_OFFSET] = x5;
  base[_MCASP_RFMT_OFFSET] = x6;
  base[_MCASP_AFSRCTL_OFFSET] = x7;
  base[_MCASP_ACLKRCTL_OFFSET]= x8;
  base[_MCASP_AHCLKRCTL_OFFSET]= x9;
  base[_MCASP_RTDM_OFFSET] = x10;
  base[_MCASP_RINTCTL_OFFSET] = x11;
  base[_MCASP_RCLKCHK_OFFSET] = x12;
  base[_MCASP_XMASK_OFFSET] = x13;
  base[_MCASP_XFMT_OFFSET] = x14;
  base[_MCASP_AFSXCTL_OFFSET] = x15;
  base[_MCASP_ACLKXCTL_OFFSET]= x16;
  base[_MCASP_AHCLKXCTL_OFFSET]= x17;
  base[_MCASP_XTDM_OFFSET] = x18;
  base[_MCASP_XINTCTL_OFFSET] = x19;
  base[_MCASP_XCLKCHK_OFFSET] = x20;
  base[_MCASP_SRCTL0_OFFSET] = x21;
  base[_MCASP_SRCTL1_OFFSET] = x22;
  base[_MCASP_SRCTL2_OFFSET] = x23;
  base[_MCASP_SRCTL3_OFFSET] = x24;
  base[_MCASP_SRCTL4_OFFSET] = x25;
  base[_MCASP_SRCTL5_OFFSET] = x26;
  base[_MCASP_AMUTE_OFFSET]  = x2;
  base[_MCASP_DLBCTL_OFFSET] = x3;
  base[_MCASP_DITCTL_OFFSET] =  x4;
  base[_MCASP_PFUNC_OFFSET] = x0;
  base[_MCASP_PDIR_OFFSET]  = x1;

  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT == 4)
IDEF void MCASP_config(MCASP_Handle hMcasp, MCASP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19;
  register int x20,x21,x22,x23,x24;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x0 = config->global->pfunc;
  x1 = config->global->pdir;
  x2 = config->global->amute;
  x3 = config->global->dlbctl;
  x4 = config->global->ditctl;
  x5 = config->receive->rmask;
  x6 = config->receive->rfmt;
  x7 = config->receive->afsrctl;
  x8 = config->receive->aclkrctl;
  x9 = config->receive->ahclkrctl;
  x10 = config->receive->rtdm;
  x11 = config->receive->rintctl;
  x12 = config->receive->rclkchk;
  x13 = config->transmit->xmask;
  x14 = config->transmit->xfmt;
  x15 = config->transmit->afsxctl;
  x16 = config->transmit->aclkxctl;
  x17 = config->transmit->ahclkxctl;
  x18 = config->transmit->xtdm;
  x19 = config->transmit->xintctl;
  x20 = config->transmit->xclkchk;
  x21 = config->srctl->srctl0;
  x22 = config->srctl->srctl1;
  x23 = config->srctl->srctl2;
  x24 = config->srctl->srctl3;

  base[_MCASP_RMASK_OFFSET] = x5;
  base[_MCASP_RFMT_OFFSET] = x6;
  base[_MCASP_AFSRCTL_OFFSET] = x7;
  base[_MCASP_ACLKRCTL_OFFSET]= x8;
  base[_MCASP_AHCLKRCTL_OFFSET]= x9;
  base[_MCASP_RTDM_OFFSET] = x10;
  base[_MCASP_RINTCTL_OFFSET] = x11;
  base[_MCASP_RCLKCHK_OFFSET] = x12;
  base[_MCASP_XMASK_OFFSET] = x13;
  base[_MCASP_XFMT_OFFSET] = x14;
  base[_MCASP_AFSXCTL_OFFSET] = x15;
  base[_MCASP_ACLKXCTL_OFFSET]= x16;
  base[_MCASP_AHCLKXCTL_OFFSET]= x17;
  base[_MCASP_XTDM_OFFSET]    = x18;
  base[_MCASP_XINTCTL_OFFSET] = x19;
  base[_MCASP_XCLKCHK_OFFSET] = x20;
  base[_MCASP_SRCTL0_OFFSET]  = x21;
  base[_MCASP_SRCTL1_OFFSET]  = x22;
  base[_MCASP_SRCTL2_OFFSET]  = x23;
  base[_MCASP_SRCTL3_OFFSET]  = x24;
  base[_MCASP_AMUTE_OFFSET]   = x2;
  base[_MCASP_DLBCTL_OFFSET]  = x3;
  base[_MCASP_DITCTL_OFFSET]  = x4;
  base[_MCASP_PFUNC_OFFSET]   = x0;
  base[_MCASP_PDIR_OFFSET]    = x1;

  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 4 */


/*----------------------------------------------------------------------------*/
IDEF void MCASP_configGbl(MCASP_Handle hMcasp, MCASP_ConfigGbl *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  register int x0,x1,x2,x3,x4;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x0 = config->pfunc;
  x1 = config->pdir;
  x2 = config->amute;
  x3 = config->dlbctl;
  x4 = config->ditctl;

  base[_MCASP_PFUNC_OFFSET] = 	x0;
  base[_MCASP_AMUTE_OFFSET]  = 	x2;
  base[_MCASP_DLBCTL_OFFSET] = 	x3;
  base[_MCASP_DITCTL_OFFSET] = x4;
  base[_MCASP_PDIR_OFFSET]  = 	x1;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void MCASP_configRcv(MCASP_Handle hMcasp, MCASP_ConfigRcv *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  register int x5,x6,x7,x8,x9,x10,x11,x12;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x5 = config->rmask;
  x6 = config->rfmt;
  x7 = config->afsrctl;
  x8 = config->aclkrctl;
  x9 = config->ahclkrctl;
  x10 = config->rtdm;
  x11 = config->rintctl;
  x12 = config->rclkchk;

  base[_MCASP_RMASK_OFFSET] = 	x5;
  base[_MCASP_RFMT_OFFSET] = 	x6;
  base[_MCASP_AFSRCTL_OFFSET] = x7;
  base[_MCASP_ACLKRCTL_OFFSET]= x8;
  base[_MCASP_AHCLKRCTL_OFFSET]= x9;
  base[_MCASP_RTDM_OFFSET] = 	x10;
  base[_MCASP_RINTCTL_OFFSET] = x11;
  base[_MCASP_RCLKCHK_OFFSET] = x12;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void MCASP_configXmt(MCASP_Handle hMcasp, MCASP_ConfigXmt *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  register int x13,x14,x15,x16,x17,x18,x19,x20;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x13 = config->xmask;
  x14 = config->xfmt;
  x15 = config->afsxctl;
  x16 = config->aclkxctl;
  x17 = config->ahclkxctl;
  x18 = config->xtdm;
  x19 = config->xintctl;
  x20 = config->xclkchk;

  base[_MCASP_XMASK_OFFSET] = 	x13;
  base[_MCASP_XFMT_OFFSET] = 	x14;
  base[_MCASP_AFSXCTL_OFFSET] = x15;
  base[_MCASP_ACLKXCTL_OFFSET]= x16;
  base[_MCASP_AHCLKXCTL_OFFSET]= x17;
  base[_MCASP_XTDM_OFFSET] = 	x18;
  base[_MCASP_XINTCTL_OFFSET] = x19;
  base[_MCASP_XCLKCHK_OFFSET] = x20;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
#if (_MCASP_CHANNEL_CNT == 16)	
IDEF void MCASP_configSrctl(MCASP_Handle hMcasp, MCASP_ConfigSrctl *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  register int x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x21 = config->srctl0;
  x22 = config->srctl1;
  x23 = config->srctl2;
  x24 = config->srctl3;
  x25 = config->srctl4;
  x26 = config->srctl5;
  x27 = config->srctl6;
  x28 = config->srctl7;
  x29 = config->srctl8;
  x30 = config->srctl9;
  x31 = config->srctl10;
  x32 = config->srctl11;
  x33 = config->srctl12;
  x34 = config->srctl13;
  x35 = config->srctl14;
  x36 = config->srctl15;

  base[_MCASP_SRCTL0_OFFSET] = 	x21;
  base[_MCASP_SRCTL1_OFFSET] = 	x22;
  base[_MCASP_SRCTL2_OFFSET] = 	x23;
  base[_MCASP_SRCTL3_OFFSET] = 	x24;
  base[_MCASP_SRCTL4_OFFSET] = 	x25;
  base[_MCASP_SRCTL5_OFFSET] = 	x26;
  base[_MCASP_SRCTL6_OFFSET] = 	x27;
  base[_MCASP_SRCTL7_OFFSET] = 	x28;
  base[_MCASP_SRCTL8_OFFSET] = 	x29;
  base[_MCASP_SRCTL9_OFFSET] = 	x30;
  base[_MCASP_SRCTL10_OFFSET] = x31;
  base[_MCASP_SRCTL11_OFFSET] = x32;
  base[_MCASP_SRCTL12_OFFSET] = x33;
  base[_MCASP_SRCTL13_OFFSET] = x34;
  base[_MCASP_SRCTL14_OFFSET] = x35;
  base[_MCASP_SRCTL15_OFFSET] = x36;

  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 16 */

#if (_MCASP_CHANNEL_CNT == 8)
IDEF void MCASP_configSrctl(MCASP_Handle hMcasp, MCASP_ConfigSrctl *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  register int x21,x22,x23,x24,x25,x26,x27,x28;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x21 = config->srctl0;
  x22 = config->srctl1;
  x23 = config->srctl2;
  x24 = config->srctl3;
  x25 = config->srctl4;
  x26 = config->srctl5;
  x27 = config->srctl6;
  x28 = config->srctl7;

  base[_MCASP_SRCTL0_OFFSET] = 	x21;
  base[_MCASP_SRCTL1_OFFSET] = 	x22;
  base[_MCASP_SRCTL2_OFFSET] = 	x23;
  base[_MCASP_SRCTL3_OFFSET] = 	x24;
  base[_MCASP_SRCTL4_OFFSET] = 	x25;
  base[_MCASP_SRCTL5_OFFSET] = 	x26;
  base[_MCASP_SRCTL6_OFFSET] = 	x27;
  base[_MCASP_SRCTL7_OFFSET] = 	x28;

  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 6)
IDEF void MCASP_configSrctl(MCASP_Handle hMcasp, MCASP_ConfigSrctl *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  register int x21,x22,x23,x24,x25,x26;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x21 = config->srctl0;
  x22 = config->srctl1;
  x23 = config->srctl2;
  x24 = config->srctl3;
  x25 = config->srctl4;
  x26 = config->srctl5;

  base[_MCASP_SRCTL0_OFFSET] = x21;
  base[_MCASP_SRCTL1_OFFSET] = x22;
  base[_MCASP_SRCTL2_OFFSET] = x23;
  base[_MCASP_SRCTL3_OFFSET] = x24;
  base[_MCASP_SRCTL4_OFFSET] = x25;
  base[_MCASP_SRCTL5_OFFSET] = x26;

  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT == 4)
IDEF void MCASP_configSrctl(MCASP_Handle hMcasp, MCASP_ConfigSrctl *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  register int x21,x22,x23,x24;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x21 = config->srctl0;
  x22 = config->srctl1;
  x23 = config->srctl2;
  x24 = config->srctl3;

  base[_MCASP_SRCTL0_OFFSET] = x21;
  base[_MCASP_SRCTL1_OFFSET] = x22;
  base[_MCASP_SRCTL2_OFFSET] = x23;
  base[_MCASP_SRCTL3_OFFSET] = x24;

  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 4 */

/*----------------------------------------------------------------------------*/
#if (_MCASP_CHANNEL_CNT == 16)
IDEF void MCASP_configArgs(MCASP_Handle hMcasp, Uint32 pfunc, Uint32 pdir, 
  Uint32 amute, Uint32 dlbctl, Uint32 ditctl, Uint32 rmask, Uint32 rfmt, Uint32 afsrctl,
  Uint32 aclkrctl, Uint32 ahclkrctl, Uint32 rtdm, Uint32 rintctl, Uint32 rclkchk,
  Uint32 xmask, Uint32 xfmt, Uint32 afsxctl, Uint32 aclkxctl, Uint32 ahclkxctl, Uint32 xtdm, 
  Uint32 xintctl, Uint32 xclkchk, Uint32 srctl0, Uint32 srctl1, Uint32 srctl2, Uint32 srctl3, 
  Uint32 srctl4, Uint32 srctl5, Uint32 srctl6, Uint32 srctl7, Uint32 srctl8, Uint32 srctl9, 
  Uint32 srctl10, Uint32 srctl11, Uint32 srctl12, Uint32 srctl13, Uint32 srctl14, Uint32 srctl15  ) 
{

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);

  gie = IRQ_globalDisable();

  base[_MCASP_RMASK_OFFSET] = 	rmask;
  base[_MCASP_RFMT_OFFSET] = 	rfmt;  
  base[_MCASP_AFSRCTL_OFFSET] = afsrctl;  
  base[_MCASP_ACLKRCTL_OFFSET]= aclkrctl;  
  base[_MCASP_AHCLKRCTL_OFFSET]=ahclkrctl;   
  base[_MCASP_RTDM_OFFSET] = 	rtdm;
  base[_MCASP_RINTCTL_OFFSET] = rintctl;   
  base[_MCASP_RCLKCHK_OFFSET] = rclkchk;   
  base[_MCASP_XMASK_OFFSET] = 	xmask;
  base[_MCASP_XFMT_OFFSET] = 	xfmt;   
  base[_MCASP_AFSXCTL_OFFSET] = afsxctl;   
  base[_MCASP_ACLKXCTL_OFFSET]= aclkxctl;   
  base[_MCASP_AHCLKXCTL_OFFSET]=ahclkxctl;    
  base[_MCASP_XTDM_OFFSET] = 	xtdm;   
  base[_MCASP_XINTCTL_OFFSET] = xintctl;   
  base[_MCASP_XCLKCHK_OFFSET] = xclkchk;   
  base[_MCASP_SRCTL0_OFFSET] = 	srctl0;
  base[_MCASP_SRCTL1_OFFSET] = 	srctl1;         
  base[_MCASP_SRCTL2_OFFSET] = 	srctl2;         
  base[_MCASP_SRCTL3_OFFSET] = 	srctl3;         
  base[_MCASP_SRCTL4_OFFSET] = 	srctl4;         
  base[_MCASP_SRCTL5_OFFSET] = 	srctl5;         
  base[_MCASP_SRCTL6_OFFSET] = 	srctl6;         
  base[_MCASP_SRCTL7_OFFSET] = 	srctl7;         
  base[_MCASP_SRCTL8_OFFSET] = 	srctl8;         
  base[_MCASP_SRCTL9_OFFSET] = 	srctl9;         
  base[_MCASP_SRCTL10_OFFSET] = srctl10;         
  base[_MCASP_SRCTL11_OFFSET] = srctl11;         
  base[_MCASP_SRCTL12_OFFSET] = srctl12;         
  base[_MCASP_SRCTL13_OFFSET] = srctl13;         
  base[_MCASP_SRCTL14_OFFSET] = srctl14;         
  base[_MCASP_SRCTL15_OFFSET] = srctl15;         
  base[_MCASP_AMUTE_OFFSET]  = 	amute;  
  base[_MCASP_DLBCTL_OFFSET] = 	dlbctl;  
  base[_MCASP_DITCTL_OFFSET] =  ditctl;  
  base[_MCASP_PFUNC_OFFSET] = 	pfunc;
  base[_MCASP_PDIR_OFFSET]  = 	pdir;  
              
  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 16 */

#if (_MCASP_CHANNEL_CNT == 8)
IDEF void MCASP_configArgs(MCASP_Handle hMcasp, Uint32 pfunc, Uint32 pdir, 
  Uint32 amute, Uint32 dlbctl, Uint32 ditctl, Uint32 rmask, Uint32 rfmt, Uint32 afsrctl,
  Uint32 aclkrctl, Uint32 ahclkrctl, Uint32 rtdm, Uint32 rintctl, Uint32 rclkchk,
  Uint32 xmask, Uint32 xfmt, Uint32 afsxctl, Uint32 aclkxctl, Uint32 ahclkxctl, Uint32 xtdm, 
  Uint32 xintctl, Uint32 xclkchk, Uint32 srctl0, Uint32 srctl1, Uint32 srctl2, Uint32 srctl3, 
  Uint32 srctl4, Uint32 srctl5, Uint32 srctl6, Uint32 srctl7) 
{

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);

  gie = IRQ_globalDisable();

  base[_MCASP_RMASK_OFFSET] = 	rmask;
  base[_MCASP_RFMT_OFFSET] = 	rfmt;  
  base[_MCASP_AFSRCTL_OFFSET] = afsrctl;  
  base[_MCASP_ACLKRCTL_OFFSET]= aclkrctl;  
  base[_MCASP_AHCLKRCTL_OFFSET]=ahclkrctl;   
  base[_MCASP_RTDM_OFFSET] = 	rtdm;
  base[_MCASP_RINTCTL_OFFSET] = rintctl;   
  base[_MCASP_RCLKCHK_OFFSET] = rclkchk;   
  base[_MCASP_XMASK_OFFSET] = 	xmask;
  base[_MCASP_XFMT_OFFSET] = 	xfmt;   
  base[_MCASP_AFSXCTL_OFFSET] = afsxctl;   
  base[_MCASP_ACLKXCTL_OFFSET]= aclkxctl;   
  base[_MCASP_AHCLKXCTL_OFFSET]=ahclkxctl;    
  base[_MCASP_XTDM_OFFSET] = 	xtdm;   
  base[_MCASP_XINTCTL_OFFSET] = xintctl;   
  base[_MCASP_XCLKCHK_OFFSET] = xclkchk;   
  base[_MCASP_SRCTL0_OFFSET] = 	srctl0;
  base[_MCASP_SRCTL1_OFFSET] = 	srctl1;         
  base[_MCASP_SRCTL2_OFFSET] = 	srctl2;         
  base[_MCASP_SRCTL3_OFFSET] = 	srctl3;         
  base[_MCASP_SRCTL4_OFFSET] = 	srctl4;         
  base[_MCASP_SRCTL5_OFFSET] = 	srctl5;         
  base[_MCASP_SRCTL6_OFFSET] = 	srctl6;         
  base[_MCASP_SRCTL7_OFFSET] = 	srctl7;         
  base[_MCASP_AMUTE_OFFSET]  = 	amute;  
  base[_MCASP_DLBCTL_OFFSET] = 	dlbctl;  
  base[_MCASP_DITCTL_OFFSET] =  ditctl;  
  base[_MCASP_PFUNC_OFFSET] = 	pfunc;
  base[_MCASP_PDIR_OFFSET]  = 	pdir;  
              
  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 6)
IDEF void MCASP_configArgs(MCASP_Handle hMcasp, Uint32 pfunc, Uint32 pdir, 
  Uint32 amute, Uint32 dlbctl, Uint32 ditctl, Uint32 rmask, Uint32 rfmt, Uint32 afsrctl,
  Uint32 aclkrctl, Uint32 ahclkrctl, Uint32 rtdm, Uint32 rintctl, Uint32 rclkchk,
  Uint32 xmask, Uint32 xfmt, Uint32 afsxctl, Uint32 aclkxctl, Uint32 ahclkxctl, Uint32 xtdm, 
  Uint32 xintctl, Uint32 xclkchk, Uint32 srctl0, Uint32 srctl1, Uint32 srctl2, Uint32 srctl3, 
  Uint32 srctl4, Uint32 srctl5) 
{

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);

  gie = IRQ_globalDisable();

  base[_MCASP_RMASK_OFFSET] = rmask;
  base[_MCASP_RFMT_OFFSET] = rfmt;  
  base[_MCASP_AFSRCTL_OFFSET] = afsrctl;  
  base[_MCASP_ACLKRCTL_OFFSET]= aclkrctl;  
  base[_MCASP_AHCLKRCTL_OFFSET]= ahclkrctl;   
  base[_MCASP_RTDM_OFFSET] = rtdm;
  base[_MCASP_RINTCTL_OFFSET] = rintctl;   
  base[_MCASP_RCLKCHK_OFFSET] = rclkchk;   
  base[_MCASP_XMASK_OFFSET] = xmask;
  base[_MCASP_XFMT_OFFSET] = xfmt;   
  base[_MCASP_AFSXCTL_OFFSET] = afsxctl;   
  base[_MCASP_ACLKXCTL_OFFSET]= aclkxctl;   
  base[_MCASP_AHCLKXCTL_OFFSET]=ahclkxctl;    
  base[_MCASP_XTDM_OFFSET] = xtdm;   
  base[_MCASP_XINTCTL_OFFSET] = xintctl;   
  base[_MCASP_XCLKCHK_OFFSET] = xclkchk;   
  base[_MCASP_SRCTL0_OFFSET] = srctl0;
  base[_MCASP_SRCTL1_OFFSET] = srctl1;         
  base[_MCASP_SRCTL2_OFFSET] = srctl2;         
  base[_MCASP_SRCTL3_OFFSET] = srctl3;         
  base[_MCASP_SRCTL4_OFFSET] = srctl4;         
  base[_MCASP_SRCTL5_OFFSET] = srctl5;         
  base[_MCASP_AMUTE_OFFSET]  = amute;  
  base[_MCASP_DLBCTL_OFFSET] = dlbctl;  
  base[_MCASP_DITCTL_OFFSET] =  ditctl;  
  base[_MCASP_PFUNC_OFFSET] = pfunc;
  base[_MCASP_PDIR_OFFSET]  = pdir;  
              
  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT == 4)
IDEF void MCASP_configArgs(MCASP_Handle hMcasp, Uint32 pfunc, Uint32 pdir, 
  Uint32 amute, Uint32 dlbctl, Uint32 ditctl, Uint32 rmask, Uint32 rfmt, Uint32 afsrctl,
  Uint32 aclkrctl, Uint32 ahclkrctl, Uint32 rtdm, Uint32 rintctl, Uint32 rclkchk,
  Uint32 xmask, Uint32 xfmt, Uint32 afsxctl, Uint32 aclkxctl, Uint32 ahclkxctl, Uint32 xtdm, 
  Uint32 xintctl, Uint32 xclkchk, Uint32 srctl0, Uint32 srctl1, Uint32 srctl2, Uint32 srctl3) 
{

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);

  gie = IRQ_globalDisable();

  base[_MCASP_RMASK_OFFSET] = rmask;
  base[_MCASP_RFMT_OFFSET] = rfmt;  
  base[_MCASP_AFSRCTL_OFFSET] = afsrctl;  
  base[_MCASP_ACLKRCTL_OFFSET]= aclkrctl;  
  base[_MCASP_AHCLKRCTL_OFFSET]= ahclkrctl;   
  base[_MCASP_RTDM_OFFSET] = rtdm;
  base[_MCASP_RINTCTL_OFFSET] = rintctl;   
  base[_MCASP_RCLKCHK_OFFSET] = rclkchk;   
  base[_MCASP_XMASK_OFFSET] = xmask;
  base[_MCASP_XFMT_OFFSET] = xfmt;   
  base[_MCASP_AFSXCTL_OFFSET] = afsxctl;   
  base[_MCASP_ACLKXCTL_OFFSET]= aclkxctl;   
  base[_MCASP_AHCLKXCTL_OFFSET]=ahclkxctl;    
  base[_MCASP_XTDM_OFFSET] = xtdm;   
  base[_MCASP_XINTCTL_OFFSET] = xintctl;   
  base[_MCASP_XCLKCHK_OFFSET] = xclkchk;   
  base[_MCASP_SRCTL0_OFFSET] = srctl0;
  base[_MCASP_SRCTL1_OFFSET] = srctl1;         
  base[_MCASP_SRCTL2_OFFSET] = srctl2;         
  base[_MCASP_SRCTL3_OFFSET] = srctl3;         
  base[_MCASP_AMUTE_OFFSET]  = amute;  
  base[_MCASP_DLBCTL_OFFSET] = dlbctl;  
  base[_MCASP_DITCTL_OFFSET] =  ditctl;  
  base[_MCASP_PFUNC_OFFSET] = pfunc;
  base[_MCASP_PDIR_OFFSET]  = pdir;  
              
  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 4 */

/*----------------------------------------------------------------------------*/
#if (_MCASP_CHANNEL_CNT == 16)
IDEF void MCASP_getConfig(MCASP_Handle hMcasp, MCASP_Config *config)
{

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  volatile MCASP_Config* cfg = (volatile MCASP_Config*)config;
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19;
  register int x20,x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
	
  x0  = base[_MCASP_PFUNC_OFFSET]; 
  x1  = base[_MCASP_PDIR_OFFSET];  
  x2  = base[_MCASP_AMUTE_OFFSET]; 
  x3  = base[_MCASP_DLBCTL_OFFSET]; 
  x4  = base[_MCASP_DITCTL_OFFSET];
  x5  = base[_MCASP_RMASK_OFFSET]; 
  x6  = base[_MCASP_RFMT_OFFSET]; 
  x7  = base[_MCASP_AFSRCTL_OFFSET]; 
  x8  = base[_MCASP_ACLKRCTL_OFFSET];
  x9  = base[_MCASP_AHCLKRCTL_OFFSET];
  x10 = base[_MCASP_RTDM_OFFSET];  
  x11 = base[_MCASP_RINTCTL_OFFSET]; 
  x12 = base[_MCASP_RCLKCHK_OFFSET]; 
  x13 = base[_MCASP_XMASK_OFFSET]; 
  x14 = base[_MCASP_XFMT_OFFSET]; 
  x15 = base[_MCASP_AFSXCTL_OFFSET]; 
  x16 = base[_MCASP_ACLKXCTL_OFFSET];
  x17 = base[_MCASP_AHCLKXCTL_OFFSET];
  x18 = base[_MCASP_XTDM_OFFSET];  
  x19 = base[_MCASP_XINTCTL_OFFSET]; 
  x20 = base[_MCASP_XCLKCHK_OFFSET]; 
  x21 = base[_MCASP_SRCTL0_OFFSET]; 
  x22 = base[_MCASP_SRCTL1_OFFSET];       
  x23 = base[_MCASP_SRCTL2_OFFSET];       
  x24 = base[_MCASP_SRCTL3_OFFSET];       
  x25 = base[_MCASP_SRCTL4_OFFSET];       
  x26 = base[_MCASP_SRCTL5_OFFSET];       
  x27 = base[_MCASP_SRCTL6_OFFSET];       
  x28 = base[_MCASP_SRCTL7_OFFSET];       
  x29 = base[_MCASP_SRCTL8_OFFSET];       
  x30 = base[_MCASP_SRCTL9_OFFSET];       
  x31 = base[_MCASP_SRCTL10_OFFSET];      
  x32 = base[_MCASP_SRCTL11_OFFSET];      
  x33 = base[_MCASP_SRCTL12_OFFSET];      
  x34 = base[_MCASP_SRCTL13_OFFSET];      
  x35 = base[_MCASP_SRCTL14_OFFSET];      
  x36 = base[_MCASP_SRCTL15_OFFSET];      
  
  cfg->global->pfunc        =  x0;
  cfg->global->pdir         =  x1;     
  cfg->global->amute        =  x2;     
  cfg->global->dlbctl        =  x3;     
  cfg->global->ditctl      =  x4;     
  cfg->receive->rmask       =  x5;
  cfg->receive->rfmt        =  x6;           
  cfg->receive->afsrctl     =  x7;           
  cfg->receive->aclkrctl    =  x8;           
  cfg->receive->ahclkrctl   =  x9;     
  cfg->receive->rtdm        =  x10;
  cfg->receive->rintctl     =  x11;            
  cfg->receive->rclkchk     =  x12;            
  cfg->transmit->xmask      =  x13;            
  cfg->transmit->xfmt       =  x14;            
  cfg->transmit->afsxctl    =  x15;       
  cfg->transmit->aclkxctl   =  x16;            
  cfg->transmit->ahclkxctl  =  x17;            
  cfg->transmit->xtdm       =  x18;            
  cfg->transmit->xintctl    =  x19;            
  cfg->transmit->xclkchk    =  x20;            
  cfg->srctl->srctl0       =  x21;     
  cfg->srctl->srctl1       =  x22;                
  cfg->srctl->srctl2       =  x23;                
  cfg->srctl->srctl3       =  x24;                
  cfg->srctl->srctl4       =  x25;                
  cfg->srctl->srctl5       =  x26;                
  cfg->srctl->srctl6       =  x27;                
  cfg->srctl->srctl7       =  x28;                
  cfg->srctl->srctl8       =  x29;                
  cfg->srctl->srctl9       =  x30;           
  cfg->srctl->srctl10      =  x31;           
  cfg->srctl->srctl11      =  x32;                
  cfg->srctl->srctl12      =  x33;                
  cfg->srctl->srctl13      =  x34;                
  cfg->srctl->srctl14      =  x35;                
  cfg->srctl->srctl15      =  x36;                

  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 16 */

#if (_MCASP_CHANNEL_CNT == 8)
IDEF void MCASP_getConfig(MCASP_Handle hMcasp, MCASP_Config *config)
{

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  volatile MCASP_Config* cfg = (volatile MCASP_Config*)config;
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19;
  register int x20,x21,x22,x23,x24,x25,x26,x27,x28;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
	
  x0  = base[_MCASP_PFUNC_OFFSET]; 
  x1  = base[_MCASP_PDIR_OFFSET];  
  x2  = base[_MCASP_AMUTE_OFFSET]; 
  x3  = base[_MCASP_DLBCTL_OFFSET]; 
  x4  = base[_MCASP_DITCTL_OFFSET];
  x5  = base[_MCASP_RMASK_OFFSET]; 
  x6  = base[_MCASP_RFMT_OFFSET]; 
  x7  = base[_MCASP_AFSRCTL_OFFSET]; 
  x8  = base[_MCASP_ACLKRCTL_OFFSET];
  x9  = base[_MCASP_AHCLKRCTL_OFFSET];
  x10 = base[_MCASP_RTDM_OFFSET];  
  x11 = base[_MCASP_RINTCTL_OFFSET]; 
  x12 = base[_MCASP_RCLKCHK_OFFSET]; 
  x13 = base[_MCASP_XMASK_OFFSET]; 
  x14 = base[_MCASP_XFMT_OFFSET]; 
  x15 = base[_MCASP_AFSXCTL_OFFSET]; 
  x16 = base[_MCASP_ACLKXCTL_OFFSET];
  x17 = base[_MCASP_AHCLKXCTL_OFFSET];
  x18 = base[_MCASP_XTDM_OFFSET];  
  x19 = base[_MCASP_XINTCTL_OFFSET]; 
  x20 = base[_MCASP_XCLKCHK_OFFSET]; 
  x21 = base[_MCASP_SRCTL0_OFFSET]; 
  x22 = base[_MCASP_SRCTL1_OFFSET];       
  x23 = base[_MCASP_SRCTL2_OFFSET];       
  x24 = base[_MCASP_SRCTL3_OFFSET];       
  x25 = base[_MCASP_SRCTL4_OFFSET];       
  x26 = base[_MCASP_SRCTL5_OFFSET];       
  x27 = base[_MCASP_SRCTL6_OFFSET];       
  x28 = base[_MCASP_SRCTL7_OFFSET];       
  
  cfg->global->pfunc        =  x0;
  cfg->global->pdir         =  x1;     
  cfg->global->amute        =  x2;     
  cfg->global->dlbctl       =  x3;     
  cfg->global->ditctl       =  x4;     
  cfg->receive->rmask       =  x5;
  cfg->receive->rfmt        =  x6;           
  cfg->receive->afsrctl     =  x7;           
  cfg->receive->aclkrctl    =  x8;           
  cfg->receive->ahclkrctl   =  x9;     
  cfg->receive->rtdm        =  x10;
  cfg->receive->rintctl     =  x11;            
  cfg->receive->rclkchk     =  x12;            
  cfg->transmit->xmask      =  x13;            
  cfg->transmit->xfmt       =  x14;            
  cfg->transmit->afsxctl    =  x15;       
  cfg->transmit->aclkxctl   =  x16;            
  cfg->transmit->ahclkxctl  =  x17;            
  cfg->transmit->xtdm       =  x18;            
  cfg->transmit->xintctl    =  x19;            
  cfg->transmit->xclkchk    =  x20;            
  cfg->srctl->srctl0        =  x21;     
  cfg->srctl->srctl1        =  x22;                
  cfg->srctl->srctl2        =  x23;                
  cfg->srctl->srctl3        =  x24;                
  cfg->srctl->srctl4        =  x25;                
  cfg->srctl->srctl5        =  x26;                
  cfg->srctl->srctl6        =  x27;                
  cfg->srctl->srctl7        =  x28;                

  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 8 */

#if (_MCASP_CHANNEL_CNT == 6)
IDEF void MCASP_getConfig(MCASP_Handle hMcasp, MCASP_Config *config)
{

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  volatile MCASP_Config* cfg = (volatile MCASP_Config*)config;
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19;
  register int x20,x21,x22,x23,x24,x25,x26;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */

  x0  = base[_MCASP_PFUNC_OFFSET]; 
  x1  = base[_MCASP_PDIR_OFFSET];  
  x2  = base[_MCASP_AMUTE_OFFSET]; 
  x3  = base[_MCASP_DLBCTL_OFFSET]; 
  x4  = base[_MCASP_DITCTL_OFFSET];
  x5  = base[_MCASP_RMASK_OFFSET]; 
  x6  = base[_MCASP_RFMT_OFFSET]; 
  x7  = base[_MCASP_AFSRCTL_OFFSET]; 
  x8  = base[_MCASP_ACLKRCTL_OFFSET];
  x9  = base[_MCASP_AHCLKRCTL_OFFSET];
  x10 = base[_MCASP_RTDM_OFFSET];  
  x11 = base[_MCASP_RINTCTL_OFFSET]; 
  x12 = base[_MCASP_RCLKCHK_OFFSET]; 
  x13 = base[_MCASP_XMASK_OFFSET]; 
  x14 = base[_MCASP_XFMT_OFFSET]; 
  x15 = base[_MCASP_AFSXCTL_OFFSET]; 
  x16 = base[_MCASP_ACLKXCTL_OFFSET];
  x17 = base[_MCASP_AHCLKXCTL_OFFSET];
  x18 = base[_MCASP_XTDM_OFFSET];  
  x19 = base[_MCASP_XINTCTL_OFFSET]; 
  x20 = base[_MCASP_XCLKCHK_OFFSET]; 
  x21 = base[_MCASP_SRCTL0_OFFSET]; 
  x22 = base[_MCASP_SRCTL1_OFFSET];       
  x23 = base[_MCASP_SRCTL2_OFFSET];       
  x24 = base[_MCASP_SRCTL3_OFFSET];       
  x25 = base[_MCASP_SRCTL4_OFFSET];       
  x26 = base[_MCASP_SRCTL5_OFFSET];       
  
  cfg->global->pfunc        =  x0;
  cfg->global->pdir         =  x1;     
  cfg->global->amute        =  x2;     
  cfg->global->dlbctl       =  x3;     
  cfg->global->ditctl       =  x4;     
  cfg->receive->rmask       =  x5;
  cfg->receive->rfmt        =  x6;           
  cfg->receive->afsrctl     =  x7;           
  cfg->receive->aclkrctl    =  x8;           
  cfg->receive->ahclkrctl   =  x9;     
  cfg->receive->rtdm        =  x10;
  cfg->receive->rintctl     =  x11;            
  cfg->receive->rclkchk     =  x12;            
  cfg->transmit->xmask      =  x13;            
  cfg->transmit->xfmt       =  x14;            
  cfg->transmit->afsxctl    =  x15;       
  cfg->transmit->aclkxctl   =  x16;            
  cfg->transmit->ahclkxctl  =  x17;            
  cfg->transmit->xtdm       =  x18;            
  cfg->transmit->xintctl    =  x19;            
  cfg->transmit->xclkchk    =  x20;            
  cfg->srctl->srctl0        =  x21;     
  cfg->srctl->srctl1        =  x22;                
  cfg->srctl->srctl2        =  x23;                
  cfg->srctl->srctl3        =  x24;                
  cfg->srctl->srctl4        =  x25;                
  cfg->srctl->srctl5        =  x26;                

  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 6 */

#if (_MCASP_CHANNEL_CNT == 4)
IDEF void MCASP_getConfig(MCASP_Handle hMcasp, MCASP_Config *config)
{

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hMcasp->baseAddr);
  volatile MCASP_Config* cfg = (volatile MCASP_Config*)config;
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19;
  register int x20,x21,x22,x23,x24;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */

  x0  = base[_MCASP_PFUNC_OFFSET]; 
  x1  = base[_MCASP_PDIR_OFFSET];  
  x2  = base[_MCASP_AMUTE_OFFSET]; 
  x3  = base[_MCASP_DLBCTL_OFFSET]; 
  x4  = base[_MCASP_DITCTL_OFFSET];
  x5  = base[_MCASP_RMASK_OFFSET]; 
  x6  = base[_MCASP_RFMT_OFFSET]; 
  x7  = base[_MCASP_AFSRCTL_OFFSET]; 
  x8  = base[_MCASP_ACLKRCTL_OFFSET];
  x9  = base[_MCASP_AHCLKRCTL_OFFSET];
  x10 = base[_MCASP_RTDM_OFFSET];  
  x11 = base[_MCASP_RINTCTL_OFFSET]; 
  x12 = base[_MCASP_RCLKCHK_OFFSET]; 
  x13 = base[_MCASP_XMASK_OFFSET]; 
  x14 = base[_MCASP_XFMT_OFFSET]; 
  x15 = base[_MCASP_AFSXCTL_OFFSET]; 
  x16 = base[_MCASP_ACLKXCTL_OFFSET];
  x17 = base[_MCASP_AHCLKXCTL_OFFSET];
  x18 = base[_MCASP_XTDM_OFFSET];  
  x19 = base[_MCASP_XINTCTL_OFFSET]; 
  x20 = base[_MCASP_XCLKCHK_OFFSET]; 
  x21 = base[_MCASP_SRCTL0_OFFSET]; 
  x22 = base[_MCASP_SRCTL1_OFFSET];       
  x23 = base[_MCASP_SRCTL2_OFFSET];       
  x24 = base[_MCASP_SRCTL3_OFFSET];       
  
  cfg->global->pfunc        =  x0;
  cfg->global->pdir         =  x1;     
  cfg->global->amute        =  x2;     
  cfg->global->dlbctl       =  x3;     
  cfg->global->ditctl       =  x4;     
  cfg->receive->rmask       =  x5;
  cfg->receive->rfmt        =  x6;           
  cfg->receive->afsrctl     =  x7;           
  cfg->receive->aclkrctl    =  x8;           
  cfg->receive->ahclkrctl   =  x9;     
  cfg->receive->rtdm        =  x10;
  cfg->receive->rintctl     =  x11;            
  cfg->receive->rclkchk     =  x12;            
  cfg->transmit->xmask      =  x13;            
  cfg->transmit->xfmt       =  x14;            
  cfg->transmit->afsxctl    =  x15;       
  cfg->transmit->aclkxctl   =  x16;            
  cfg->transmit->ahclkxctl  =  x17;            
  cfg->transmit->xtdm       =  x18;            
  cfg->transmit->xintctl    =  x19;            
  cfg->transmit->xclkchk    =  x20;            
  cfg->srctl->srctl0        =  x21;     
  cfg->srctl->srctl1        =  x22;                
  cfg->srctl->srctl2        =  x23;                
  cfg->srctl->srctl3        =  x24;                

  IRQ_globalRestore(gie);
}
#endif /* _MCASP_CHANNEL_CNT == 4 */


/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* MCASP_SUPPORT */
#endif /* _CSL_MCASP_H_ */
/******************************************************************************\
* End of csl_mcasp.h
\******************************************************************************/

