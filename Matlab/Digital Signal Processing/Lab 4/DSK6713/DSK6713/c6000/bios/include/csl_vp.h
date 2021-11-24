/******************************************************************************\
*           Copyright (C) 1999-2002 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_vp.h
* DATE CREATED.. 02/22/2002 
* LAST MODIFIED. 05/09/2002
*
\******************************************************************************/
#ifndef _CSL_VP_H_
#define _CSL_VP_H_

#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_vphal.h>


#if (VP_SUPPORT)
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

#ifdef  _VP_MOD_
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

/* VP_open() flags */
#define VP_OPEN_RESET     (0x00000001)

/* device identifiers for VP_open() */
#define VP_DEV0    (0)
#if (_VP_PORT_CNT == 3)
  #define VP_DEV1  (1)
  #define VP_DEV2  (2)
#endif

/* device identifiers for VP_open() */
#define VP_PORT0    VP_DEV0
#if (_VP_PORT_CNT == 2)
  #define VP_PORT1    VP_DEV1
  #define VP_PORT2    VP_DEV2
#endif

/******************************************************************************\
* global typedef declarations
\******************************************************************************/
/* device handle object */
#if (CHIP_DM642)
 typedef struct {
  Uint32 allocated;
  Uint32 eventId;
  volatile Uint32 *baseAddr;
  Uint32 ysrcaAddr;
  Uint32 cbsrcaAddr;
  Uint32 crsrcaAddr;
  Uint32 ydstaAddr;
  Uint32 cbdstAddr;
  Uint32 crdstAddr;
  Uint32 ysrcbAddr;
  Uint32 cbsrcbAddr;
  Uint32 crsrcbAddr;
  Uint32 ydstbAddr;
 } VP_Obj, *VP_Handle;
#else
 typedef struct {
  Uint32 allocated;
  Uint32 eventId;
  volatile Uint32 *baseAddr;
  Uint32 ysrcaAddr;
  Uint32 cbsrcaAddr;
  Uint32 crsrcaAddr;
  Uint32 ydstaAddr;
  Uint32 cbdstAddr;
  Uint32 crdstAddr;
 } VP_Obj, *VP_Handle;
#endif

/* device configuration structure */
typedef struct {
	Uint32 vpctl;
	Uint32 vpie;
	Uint32 vpis;
} VP_ConfigPort;

#if (CHIP_DM642)
 typedef struct {
	Uint32 vcactl; 
	Uint32 vcastrt1; 
	Uint32 vcastop1; 
	Uint32 vcastrt2; 
	Uint32 vcastop2; 
	Uint32 vcavint; 
	Uint32 vcathrld; 
	Uint32 vcaevtct; 
	Uint32 vcbctl; 
	Uint32 vcbstrt1; 
	Uint32 vcbstop1; 
	Uint32 vcbstrt2; 
	Uint32 vcbstop2; 
	Uint32 vcbvint; 
	Uint32 vcbthrld; 
	Uint32 vcbevtct; 
	Uint32 tsictl; 
	Uint32 tsiclkinitl; 
	Uint32 tsiclkinitm;
	Uint32 tsistcmpl; 
	Uint32 tsistcmpm;
	Uint32 tsistmskl; 
	Uint32 tsistmskm;
	Uint32 tsiticks; 
 } VP_ConfigCapture;
#else
 typedef struct {
	Uint32 vcactl; 
	Uint32 vcastrt1; 
	Uint32 vcastop1; 
	Uint32 vcastrt2; 
	Uint32 vcastop2; 
	Uint32 vcavint; 
	Uint32 vcathrld; 
	Uint32 vcaevtct; 
	Uint32 tsictl; 
	Uint32 tsiclkinitl; 
	Uint32 tsiclkinitm;
	Uint32 tsistcmpl; 
	Uint32 tsistcmpm;
	Uint32 tsistmskl; 
	Uint32 tsistmskm;
	Uint32 tsiticks; 
 } VP_ConfigCapture;
#endif

typedef struct {
	Uint32 vcactl; 
	Uint32 vcastrt1; 
	Uint32 vcastop1; 
	Uint32 vcastrt2; 
	Uint32 vcastop2; 
	Uint32 vcavint; 
	Uint32 vcathrld; 
	Uint32 vcaevtct; 
} VP_ConfigCaptureChA;

#if (CHIP_DM642)
 typedef struct {
	Uint32 vcbctl; 
	Uint32 vcbstrt1; 
	Uint32 vcbstop1; 
	Uint32 vcbstrt2; 
	Uint32 vcbstop2; 
	Uint32 vcbvint; 
	Uint32 vcbthrld; 
	Uint32 vcbevtct; 
 } VP_ConfigCaptureChB;
#endif

typedef struct {
	Uint32 vcactl; 
	Uint32 tsictl; 
	Uint32 tsiclkinitl; 
	Uint32 tsiclkinitm;
	Uint32 tsistcmpl; 
	Uint32 tsistcmpm;
	Uint32 tsistmskl; 
	Uint32 tsistmskm;
	Uint32 tsiticks; 
} VP_ConfigCaptureTSI;

typedef struct {
	Uint32 vdctl; 
	Uint32 vdfrmsz; 
	Uint32 vdhblnk;
	Uint32 vdvblks1; 
	Uint32 vdvblke1;
	Uint32 vdvblks2; 
	Uint32 vdvblke2;
	Uint32 vdimoff1; 
	Uint32 vdimgsz1; 
	Uint32 vdimoff2; 
	Uint32 vdimgsz2; 
	Uint32 vdfldt1; 
	Uint32 vdfldt2; 
	Uint32 vdthrld; 
	Uint32 vdhsync;
	Uint32 vdvsyns1; 
	Uint32 vdvsyne1; 
	Uint32 vdvsyns2; 
	Uint32 vdvsyne2; 
	Uint32 vdreload; 
	Uint32 vddispevt;
	Uint32 vdclip;
	Uint32 vddefval;
	Uint32 vdvint; 
	Uint32 vdfbit; 
	Uint32 vdvbit1; 
	Uint32 vdvbit2; 
} VP_ConfigDisplay;

typedef struct {
	Uint32 pfunc; 
	Uint32 pdir;
	Uint32 pdout;
	Uint32 pdset;
	Uint32 pdclr;
	Uint32 pien;
	Uint32 pipol;
	Uint32 piclr;
} VP_ConfigGpio;

typedef struct {
	VP_ConfigPort       *port;
	VP_ConfigCapture    *capture;
	VP_ConfigDisplay    *display;
	VP_ConfigGpio       *gpio;
} VP_Config;

/******************************************************************************\
* global variable declarations
\******************************************************************************/

/******************************************************************************\
* global function declarations
\******************************************************************************/
CSLAPI void VP_reset(VP_Handle hVp);
CSLAPI void VP_resetAll();

CSLAPI VP_Handle VP_open(int devNum, Uint32 flags);
CSLAPI void VP_close(VP_Handle hVp);

CSLAPI Uint32 VP_getPins(VP_Handle hVp);
CSLAPI void VP_setPins(VP_Handle hVp, Uint32 val);
CSLAPI void VP_clearPins(VP_Handle hVp, Uint32 val);
CSLAPI void VP_resetCaptureChA(VP_Handle hVp);
#if (CHIP_DM642)
  CSLAPI void VP_resetCaptureChB(VP_Handle hVp);
#endif
CSLAPI void VP_resetDisplay(VP_Handle hVp);

/******************************************************************************\
* inline function declarations
\******************************************************************************/
IDECL Uint32 VP_getYsrcaAddr(VP_Handle hVp); 
IDECL Uint32 VP_getCbsrcaAddr(VP_Handle hVp); 
IDECL Uint32 VP_getCrsrcaAddr(VP_Handle hVp); 
IDECL Uint32 VP_getYdstaAddr(VP_Handle hVp); 
IDECL Uint32 VP_getCbdstAddr(VP_Handle hVp); 
IDECL Uint32 VP_getCrdstAddr(VP_Handle hVp); 
#if (CHIP_DM642)
  IDECL Uint32 VP_getYsrcbAddr(VP_Handle hVp); 
  IDECL Uint32 VP_getCbsrcbAddr(VP_Handle hVp); 
  IDECL Uint32 VP_getCrsrcbAddr(VP_Handle hVp); 
  IDECL Uint32 VP_getYdstbAddr(VP_Handle hVp); 
#endif
IDECL Uint32 VP_getEventId(VP_Handle hVp);

/******************************************************************************/
IDECL void VP_config(VP_Handle hVp, VP_Config *config);
IDECL void VP_configPort(VP_Handle hVp, VP_ConfigPort *config);
IDECL void VP_configCapture(VP_Handle hVp, VP_ConfigCapture *config);
IDECL void VP_configCaptureChA(VP_Handle hVp, VP_ConfigCaptureChA *config);
#if (CHIP_DM642)
  IDECL void VP_configCaptureChB(VP_Handle hVp, VP_ConfigCaptureChB *config);
#endif
IDECL void VP_configCaptureTSI(VP_Handle hVp, VP_ConfigCaptureTSI *config);
IDECL void VP_configDisplay(VP_Handle hVp, VP_ConfigDisplay *config);
IDECL void VP_configGpio(VP_Handle hVp, VP_ConfigGpio *config);
IDECL void VP_getConfig(VP_Handle hVp, VP_Config *config);

/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF Uint32 VP_getYsrcaAddr(VP_Handle hVp) {
  return (Uint32)(hVp->ysrcaAddr);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VP_getCbsrcaAddr(VP_Handle hVp) {
  return (Uint32)(hVp->cbsrcaAddr);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VP_getCrsrcaAddr(VP_Handle hVp) {
  return (Uint32)(hVp->crsrcaAddr);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VP_getYdstaAddr(VP_Handle hVp) {
  return (Uint32)(hVp->ydstaAddr);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VP_getCbdstAddr(VP_Handle hVp) {
  return (Uint32)(hVp->cbdstAddr);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 VP_getCrdstAddr(VP_Handle hVp) {
  return (Uint32)(hVp->crdstAddr);
}

#if (CHIP_DM642)
  /*----------------------------------------------------------------------------*/
  IDEF Uint32 VP_getYsrcbAddr(VP_Handle hVp) {
    return (Uint32)(hVp->ysrcbAddr);
  }
  /*----------------------------------------------------------------------------*/
  IDEF Uint32 VP_getCbsrcbAddr(VP_Handle hVp) {
    return (Uint32)(hVp->cbsrcbAddr);
  }
  /*----------------------------------------------------------------------------*/
  IDEF Uint32 VP_getCrsrcbAddr(VP_Handle hVp) {
    return (Uint32)(hVp->crsrcbAddr);
  }
  /*----------------------------------------------------------------------------*/
  IDEF Uint32 VP_getYdstbAddr(VP_Handle hVp) {
    return (Uint32)(hVp->ydstbAddr);
  }
#endif
/*----------------------------------------------------------------------------*/
IDEF Uint32 VP_getEventId(VP_Handle hVp) {
  return (hVp->eventId);
}
/*----------------------------------------------------------------------------*/

#if (CHIP_DM642)
 IDEF void VP_config(VP_Handle hVp, VP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hVp->baseAddr);
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19;
  register int x20,x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36;
  register int x37,x38,x39,x40,x41,x42,x43,x44,x45,x46,x47,x48,x49,x50,x51,x52,x53;
  register int x54,x55,x56,x57,x58,x59,x60,x61;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x0  =  config->port->vpctl;
  x1  =  config->port->vpie;
  x2  =  config->port->vpis;
  x3  =  config->capture->vcastrt1; 
  x4  =  config->capture->vcastop1; 
  x5  =  config->capture->vcastrt2; 
  x6  =  config->capture->vcastop2; 
  x7  =  config->capture->vcavint; 
  x8  =  config->capture->vcathrld; 
  x9  =  config->capture->vcaevtct; 
  x10 =  config->capture->vcbstrt1; 
  x11 =  config->capture->vcbstop1; 
  x12 =  config->capture->vcbstrt2; 
  x13 =  config->capture->vcbstop2; 
  x14 =  config->capture->vcbvint; 
  x15 =  config->capture->vcbthrld;
  x16 =  config->capture->vcbevtct;
  x17 =  config->capture->tsictl; 
  x18 =  config->capture->tsiclkinitl; 
  x19 =  config->capture->tsiclkinitm;
  x20 =  config->capture->tsistcmpl; 
  x21 =  config->capture->tsistcmpm;
  x22 =  config->capture->tsistmskl; 
  x23 =  config->capture->tsistmskm;
  x24 =  config->capture->tsiticks; 
  x25 =  config->display->vdfrmsz; 
  x26 =  config->display->vdhblnk;
  x27 =  config->display->vdvblks1;  
  x28 =  config->display->vdvblke1;
  x29 =  config->display->vdvblks2; 
  x30 =  config->display->vdvblke2;
  x31 =  config->display->vdimoff1; 
  x32 =  config->display->vdimgsz1; 
  x33 =  config->display->vdimoff2; 
  x34 =  config->display->vdimgsz2; 
  x35 =  config->display->vdfldt1; 
  x36 =  config->display->vdfldt2; 
  x37 =  config->display->vdthrld; 
  x38 =  config->display->vdhsync;
  x39 =  config->display->vdvsyns1; 
  x40 =  config->display->vdvsyne1; 
  x41 =  config->display->vdvsyns2; 
  x42 =  config->display->vdvsyne2; 
  x43 =  config->display->vdreload; 
  x44 =  config->display->vddispevt;
  x45 =  config->display->vdclip;
  x46 =  config->display->vddefval;
  x47 =  config->display->vdvint; 
  x48 =  config->display->vdfbit; 
  x49 =  config->display->vdvbit1; 
  x50 =  config->display->vdvbit2; 
  x51 =  config->gpio->pfunc; 
  x52 =  config->gpio->pdir;
  x53 =  config->gpio->pdout;
  x54 =  config->gpio->pdset;
  x55 =  config->gpio->pdclr;
  x56 =  config->gpio->pien;
  x57 =  config->gpio->pipol;
  x58 =  config->gpio->piclr;
  x59 =  config->capture->vcactl; 
  x60 =  config->capture->vcbctl; 
  x61 =  config->display->vdctl; 

  base[_VP_VPCTL_OFFSET]       =    x0;
  base[_VP_VPIE_OFFSET]        =    x1;  
  base[_VP_VPIS_OFFSET]        =    x2;  
  base[_VP_VCASTRT1_OFFSET]    =    x3;  
  base[_VP_VCASTOP1_OFFSET]    =    x4;  
  base[_VP_VCASTRT2_OFFSET]    =    x5;  
  base[_VP_VCASTOP2_OFFSET]    =    x6;  
  base[_VP_VCAVINT_OFFSET]     =    x7;  
  base[_VP_VCATHRLD_OFFSET]    =    x8;  
  base[_VP_VCAEVTCT_OFFSET]    =    x9;  
  base[_VP_VCBSTRT1_OFFSET]    =    x10;  
  base[_VP_VCBSTOP1_OFFSET]    =    x11;  
  base[_VP_VCBSTRT2_OFFSET]    =    x12;  
  base[_VP_VCBSTOP2_OFFSET]    =    x13;  
  base[_VP_VCBVINT_OFFSET]     =    x14;  
  base[_VP_VCBTHRLD_OFFSET]    =    x15;  
  base[_VP_VCBEVTCT_OFFSET]    =    x16;  
  base[_VP_TSICTL_OFFSET]       =    x17;  
  base[_VP_TSICLKINITL_OFFSET]  =    x18;  
  base[_VP_TSICLKINITM_OFFSET]  =    x19;  
  base[_VP_TSISTCMPL_OFFSET]    =    x20;  
  base[_VP_TSISTCMPM_OFFSET]    =    x21;  
  base[_VP_TSISTMSKL_OFFSET]    =    x22;  
  base[_VP_TSISTMSKM_OFFSET]    =    x23;  
  base[_VP_TSITICKS_OFFSET]     =    x24;  
  base[_VP_VDFRMSZ_OFFSET]     =    x25;  
  base[_VP_VDHBLNK_OFFSET]     =    x26;  
  base[_VP_VDVBLKS1_OFFSET]    =    x27;  
  base[_VP_VDVBLKE1_OFFSET]    =    x28;  
  base[_VP_VDVBLKS2_OFFSET]    =    x29;  
  base[_VP_VDVBLKE2_OFFSET]    =    x30;  
  base[_VP_VDIMGOFF1_OFFSET]   =    x31;  
  base[_VP_VDIMGSZ1_OFFSET]    =    x32;  
  base[_VP_VDIMGOFF2_OFFSET]   =    x33;  
  base[_VP_VDIMGSZ2_OFFSET]    =    x34;  
  base[_VP_VDFLDT1_OFFSET]     =    x35;  
  base[_VP_VDFLDT2_OFFSET]     =    x36;  
  base[_VP_VDTHRLD_OFFSET]     =    x37;  
  base[_VP_VDHSYNC_OFFSET]     =    x38;  
  base[_VP_VDVSYNS1_OFFSET]    =    x39;  
  base[_VP_VDVSYNE1_OFFSET]    =    x40;  
  base[_VP_VDVSYNS2_OFFSET]    =    x41;  
  base[_VP_VDVSYNE2_OFFSET]    =    x42;  
  base[_VP_VDRELOAD_OFFSET]    =    x43;  
  base[_VP_VDDISPEVT_OFFSET]   =    x44;  
  base[_VP_VDCLIP_OFFSET]      =    x45;  
  base[_VP_VDDEFVAL_OFFSET]    =    x46;  
  base[_VP_VDVINT_OFFSET]      =    x47;  
  base[_VP_VDFBIT_OFFSET]      =    x48;  
  base[_VP_VDVBIT1_OFFSET]     =    x49;  
  base[_VP_VDVBIT2_OFFSET]     =    x50;  
  base[_VP_PFUNC_OFFSET]       =    x51;  
  base[_VP_PDIR_OFFSET]        =    x52;  
  base[_VP_PDOUT_OFFSET]       =    x53;  
  base[_VP_PDSET_OFFSET]       =    x54;  
  base[_VP_PDCLR_OFFSET]       =    x55;  
  base[_VP_PIEN_OFFSET]        =    x56;  
  base[_VP_PIPOL_OFFSET]       =    x57;  
  base[_VP_PICLR_OFFSET]       =    x58;  
  base[_VP_VCACTL_OFFSET]      =    x59;  
  base[_VP_VCBCTL_OFFSET]      =    x60;  
  base[_VP_VDCTL_OFFSET]       =    x61;  

  IRQ_globalRestore(gie);
 }
#else
 IDEF void VP_config(VP_Handle hVp, VP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hVp->baseAddr);
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19;
  register int x20,x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36;
  register int x37,x38,x39,x40,x41,x42,x43,x44,x45,x46,x47,x48,x49,x50,x51,x52,x53;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x0  =  config->port->vpctl;
  x1  =  config->port->vpie;
  x2  =  config->port->vpis;
  x3  =  config->capture->vcastrt1; 
  x4  =  config->capture->vcastop1; 
  x5  =  config->capture->vcastrt2; 
  x6  =  config->capture->vcastop2; 
  x7  =  config->capture->vcavint; 
  x8  =  config->capture->vcathrld; 
  x9  =  config->capture->vcaevtct; 
  x10 =  config->capture->tsictl; 
  x11 =  config->capture->tsiclkinitl; 
  x12 =  config->capture->tsiclkinitm;
  x13 =  config->capture->tsistcmpl; 
  x14 =  config->capture->tsistcmpm;
  x15 =  config->capture->tsistmskl; 
  x16 =  config->capture->tsistmskm;
  x17 =  config->capture->tsiticks; 
  x18 =  config->display->vdfrmsz; 
  x19 =  config->display->vdhblnk;
  x20 =  config->display->vdvblks1;  
  x21 =  config->display->vdvblke1;
  x22 =  config->display->vdvblks2; 
  x23 =  config->display->vdvblke2;
  x24 =  config->display->vdimoff1; 
  x25 =  config->display->vdimgsz1; 
  x26 =  config->display->vdimoff2; 
  x27 =  config->display->vdimgsz2; 
  x28 =  config->display->vdfldt1; 
  x29 =  config->display->vdfldt2; 
  x30 =  config->display->vdthrld; 
  x31 =  config->display->vdhsync;
  x32 =  config->display->vdvsyns1; 
  x33 =  config->display->vdvsyne1; 
  x34 =  config->display->vdvsyns2; 
  x35 =  config->display->vdvsyne2; 
  x36 =  config->display->vdreload; 
  x37 =  config->display->vddispevt;
  x38 =  config->display->vdclip;
  x39 =  config->display->vddefval;
  x40 =  config->display->vdvint; 
  x41 =  config->display->vdfbit; 
  x42 =  config->display->vdvbit1; 
  x43 =  config->display->vdvbit2; 
  x44 =  config->gpio->pfunc; 
  x45 =  config->gpio->pdir;
  x46 =  config->gpio->pdout;
  x47 =  config->gpio->pdset;
  x48 =  config->gpio->pdclr;
  x49 =  config->gpio->pien;
  x50 =  config->gpio->pipol;
  x51 =  config->gpio->piclr;
  x52 =  config->capture->vcactl; 
  x53 =  config->display->vdctl; 

  base[_VP_VPCTL_OFFSET]        =    x0;
  base[_VP_VPIE_OFFSET]         =    x1;  
  base[_VP_VPIS_OFFSET]         =    x2;  
  base[_VP_VCASTRT1_OFFSET]     =    x3;  
  base[_VP_VCASTOP1_OFFSET]     =    x4;  
  base[_VP_VCASTRT2_OFFSET]     =    x5;  
  base[_VP_VCASTOP2_OFFSET]     =    x6;  
  base[_VP_VCAVINT_OFFSET]      =    x7;  
  base[_VP_VCATHRLD_OFFSET]     =    x8;  
  base[_VP_VCAEVTCT_OFFSET]     =    x9;  
  base[_VP_TSICTL_OFFSET]       =    x10;  
  base[_VP_TSICLKINITL_OFFSET]  =    x11;  
  base[_VP_TSICLKINITM_OFFSET]  =    x12;  
  base[_VP_TSISTCMPL_OFFSET]    =    x13;  
  base[_VP_TSISTCMPM_OFFSET]    =    x14;  
  base[_VP_TSISTMSKL_OFFSET]    =    x15;  
  base[_VP_TSISTMSKM_OFFSET]    =    x16;  
  base[_VP_TSITICKS_OFFSET]     =    x17;  
  base[_VP_VDFRMSZ_OFFSET]      =    x18;  
  base[_VP_VDHBLNK_OFFSET]      =    x19;  
  base[_VP_VDVBLKS1_OFFSET]     =    x20;  
  base[_VP_VDVBLKE1_OFFSET]     =    x21;  
  base[_VP_VDVBLKS2_OFFSET]     =    x22;  
  base[_VP_VDVBLKE2_OFFSET]     =    x23;  
  base[_VP_VDIMGOFF1_OFFSET]    =    x24;  
  base[_VP_VDIMGSZ1_OFFSET]     =    x25;  
  base[_VP_VDIMGOFF2_OFFSET]    =    x26;  
  base[_VP_VDIMGSZ2_OFFSET]     =    x27;  
  base[_VP_VDFLDT1_OFFSET]      =    x28;  
  base[_VP_VDFLDT2_OFFSET]      =    x29;  
  base[_VP_VDTHRLD_OFFSET]      =    x30;  
  base[_VP_VDHSYNC_OFFSET]      =    x31;  
  base[_VP_VDVSYNS1_OFFSET]     =    x32;  
  base[_VP_VDVSYNE1_OFFSET]     =    x33;  
  base[_VP_VDVSYNS2_OFFSET]     =    x34;  
  base[_VP_VDVSYNE2_OFFSET]     =    x35;  
  base[_VP_VDRELOAD_OFFSET]     =    x36;  
  base[_VP_VDDISPEVT_OFFSET]    =    x37;  
  base[_VP_VDCLIP_OFFSET]       =    x38;  
  base[_VP_VDDEFVAL_OFFSET]     =    x39;  
  base[_VP_VDVINT_OFFSET]       =    x40;  
  base[_VP_VDFBIT_OFFSET]       =    x41;  
  base[_VP_VDVBIT1_OFFSET]      =    x42;  
  base[_VP_VDVBIT2_OFFSET]      =    x43;  
  base[_VP_PFUNC_OFFSET]        =    x44;  
  base[_VP_PDIR_OFFSET]         =    x45;  
  base[_VP_PDOUT_OFFSET]        =    x46;  
  base[_VP_PDSET_OFFSET]        =    x47;  
  base[_VP_PDCLR_OFFSET]        =    x48;  
  base[_VP_PIEN_OFFSET]         =    x49;  
  base[_VP_PIPOL_OFFSET]        =    x50;  
  base[_VP_PICLR_OFFSET]        =    x51;  
  base[_VP_VCACTL_OFFSET]       =    x52;  
  base[_VP_VDCTL_OFFSET]        =    x53;  

  IRQ_globalRestore(gie);
 }
#endif
/*----------------------------------------------------------------------------*/
IDEF void VP_configPort(VP_Handle hVp, VP_ConfigPort *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hVp->baseAddr);
  register int x0,x1,x2;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x0  =  config->vpctl;
  x1  =  config->vpie;
  x2  =  config->vpis;

  base[_VP_VPCTL_OFFSET]  =  x0;
  base[_VP_VPIE_OFFSET]   =  x1;
  base[_VP_VPIS_OFFSET]   =  x2;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
#if (CHIP_DM642)
 IDEF void VP_configCapture(VP_Handle hVp, VP_ConfigCapture *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hVp->baseAddr);
  register int x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19;
  register int x20,x21,x22,x23,x24,x25,x26;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x3  =  config->vcastrt1; 
  x4  =  config->vcastop1; 
  x5  =  config->vcastrt2; 
  x6  =  config->vcastop2; 
  x7  =  config->vcavint; 
  x8  =  config->vcathrld; 
  x9  =  config->vcaevtct; 
  x10 =  config->vcbstrt1; 
  x11 =  config->vcbstop1; 
  x12 =  config->vcbstrt2; 
  x13 =  config->vcbstop2; 
  x14 =  config->vcbvint; 
  x15 =  config->vcbthrld; 
  x16 =  config->vcbevtct; 
  x17 =  config->tsictl; 
  x18 =  config->tsiclkinitl; 
  x19 =  config->tsiclkinitm;
  x20 =  config->tsistcmpl; 
  x21 =  config->tsistcmpm;
  x22 =  config->tsistmskl; 
  x23 =  config->tsistmskm;
  x24 =  config->tsiticks; 
  x25 =  config->vcactl; 
  x26 =  config->vcbctl; 

  base[_VP_VCASTRT1_OFFSET]     =    x3;
  base[_VP_VCASTOP1_OFFSET]     =    x4;  
  base[_VP_VCASTRT2_OFFSET]     =    x5;  
  base[_VP_VCASTOP2_OFFSET]     =    x6;  
  base[_VP_VCAVINT_OFFSET]      =    x7;  
  base[_VP_VCATHRLD_OFFSET]     =    x8;  
  base[_VP_VCAEVTCT_OFFSET]     =    x9;  
  base[_VP_VCBSTRT1_OFFSET]     =    x10;  
  base[_VP_VCBSTOP1_OFFSET]     =    x11;  
  base[_VP_VCBSTRT2_OFFSET]     =    x12;  
  base[_VP_VCBSTOP2_OFFSET]     =    x13;  
  base[_VP_VCBVINT_OFFSET]      =    x14;  
  base[_VP_VCBTHRLD_OFFSET]     =    x15;  
  base[_VP_VCBEVTCT_OFFSET]     =    x16;  
  base[_VP_TSICTL_OFFSET]       =    x17;  
  base[_VP_TSICLKINITL_OFFSET]  =    x18;  
  base[_VP_TSICLKINITM_OFFSET]  =    x19;  
  base[_VP_TSISTCMPL_OFFSET]    =    x20;  
  base[_VP_TSISTCMPM_OFFSET]    =    x21;  
  base[_VP_TSISTMSKL_OFFSET]    =    x22;  
  base[_VP_TSISTMSKM_OFFSET]    =    x23;  
  base[_VP_TSITICKS_OFFSET]     =    x24;  
  base[_VP_VCACTL_OFFSET]       =    x25;  
  base[_VP_VCBCTL_OFFSET]       =    x26;  

  IRQ_globalRestore(gie);
 }
#else
 IDEF void VP_configCapture(VP_Handle hVp, VP_ConfigCapture *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hVp->baseAddr);
  register int x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x3  =  config->vcastrt1; 
  x4  =  config->vcastop1; 
  x5  =  config->vcastrt2; 
  x6  =  config->vcastop2; 
  x7  =  config->vcavint; 
  x8  =  config->vcathrld; 
  x9  =  config->vcaevtct; 
  x10 =  config->tsictl; 
  x11 =  config->tsiclkinitl; 
  x12 =  config->tsiclkinitm;
  x13 =  config->tsistcmpl; 
  x14 =  config->tsistcmpm;
  x15 =  config->tsistmskl; 
  x16 =  config->tsistmskm;
  x17 =  config->tsiticks; 
  x18 =  config->vcactl; 

  base[_VP_VCASTRT1_OFFSET]     =    x3;
  base[_VP_VCASTOP1_OFFSET]     =    x4;  
  base[_VP_VCASTRT2_OFFSET]     =    x5;  
  base[_VP_VCASTOP2_OFFSET]     =    x6;  
  base[_VP_VCAVINT_OFFSET]      =    x7;  
  base[_VP_VCATHRLD_OFFSET]     =    x8;  
  base[_VP_VCAEVTCT_OFFSET]     =    x9;  
  base[_VP_TSICTL_OFFSET]       =    x10;  
  base[_VP_TSICLKINITL_OFFSET]  =    x11;  
  base[_VP_TSICLKINITM_OFFSET]  =    x12;  
  base[_VP_TSISTCMPL_OFFSET]    =    x13;  
  base[_VP_TSISTCMPM_OFFSET]    =    x14;  
  base[_VP_TSISTMSKL_OFFSET]    =    x15;  
  base[_VP_TSISTMSKM_OFFSET]    =    x16;  
  base[_VP_TSITICKS_OFFSET]     =    x17;  
  base[_VP_VCACTL_OFFSET]       =    x18;  

  IRQ_globalRestore(gie);
 }
#endif
/*----------------------------------------------------------------------------*/
/* Note: VCACTL is also included in VP_configCaptureTSI();                    */
/*----------------------------------------------------------------------------*/
IDEF void VP_configCaptureChA(VP_Handle hVp, VP_ConfigCaptureChA *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hVp->baseAddr);
  register int x3,x4,x5,x6,x7,x8,x9,x10;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x3  =  config->vcastrt1; 
  x4  =  config->vcastop1; 
  x5  =  config->vcastrt2; 
  x6  =  config->vcastop2; 
  x7  =  config->vcavint; 
  x8  =  config->vcathrld; 
  x9  =  config->vcaevtct; 
  x10 =  config->vcactl; 

  base[_VP_VCASTRT1_OFFSET]    =    x3;
  base[_VP_VCASTOP1_OFFSET]    =    x4;  
  base[_VP_VCASTRT2_OFFSET]    =    x5;  
  base[_VP_VCASTOP2_OFFSET]    =    x6;  
  base[_VP_VCAVINT_OFFSET]     =    x7;  
  base[_VP_VCATHRLD_OFFSET]    =    x8;  
  base[_VP_VCAEVTCT_OFFSET]    =    x9;  
  base[_VP_VCACTL_OFFSET]      =    x10;  

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
/* Note: VCACTL is also included in VP_configCaptureChannelA();               */
/*----------------------------------------------------------------------------*/
IDEF void VP_configCaptureTSI(VP_Handle hVp, VP_ConfigCaptureTSI *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hVp->baseAddr);
  register int x15,x16,x17,x18,x19,x20,x21,x22,x23;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x15 =  config->tsictl; 
  x16 =  config->tsiclkinitl; 
  x17 =  config->tsiclkinitm;
  x18 =  config->tsistcmpl; 
  x19 =  config->tsistcmpm;
  x20 =  config->tsistmskl; 
  x21 =  config->tsistmskm;
  x22 =  config->tsiticks; 
  x23 =  config->vcactl; 

  base[_VP_TSICTL_OFFSET]       =    x15;  
  base[_VP_TSICLKINITL_OFFSET]  =    x16;  
  base[_VP_TSICLKINITM_OFFSET]  =    x17;  
  base[_VP_TSISTCMPL_OFFSET]    =    x18;  
  base[_VP_TSISTCMPM_OFFSET]    =    x19;  
  base[_VP_TSISTMSKL_OFFSET]    =    x20;  
  base[_VP_TSISTMSKM_OFFSET]    =    x21;  
  base[_VP_TSITICKS_OFFSET]     =    x22;  
  base[_VP_VCACTL_OFFSET]      =    x23;  

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
#if (CHIP_DM642)
 IDEF void VP_configCaptureChB(VP_Handle hVp, VP_ConfigCaptureChB *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hVp->baseAddr);
  register int x9,x10,x11,x12,x13,x14,x15,x16;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x9  =  config->vcbstrt1; 
  x10 =  config->vcbstop1; 
  x11 =  config->vcbstrt2; 
  x12 =  config->vcbstop2; 
  x13 =  config->vcbvint; 
  x14 =  config->vcbthrld; 
  x15 =  config->vcbevtct; 
  x16 =  config->vcbctl; 

  base[_VP_VCBSTRT1_OFFSET]    =    x9;  
  base[_VP_VCBSTOP1_OFFSET]    =    x10;  
  base[_VP_VCBSTRT2_OFFSET]    =    x11;  
  base[_VP_VCBSTOP2_OFFSET]    =    x12;  
  base[_VP_VCBVINT_OFFSET]     =    x13;  
  base[_VP_VCBTHRLD_OFFSET]    =    x14;  
  base[_VP_VCBEVTCT_OFFSET]    =    x15;  
  base[_VP_VCBCTL_OFFSET]      =    x16;  

  IRQ_globalRestore(gie);
 }
#endif
/*----------------------------------------------------------------------------*/
IDEF void VP_configDisplay(VP_Handle hVp, VP_ConfigDisplay *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hVp->baseAddr);
  register int x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36,x37,x38;
  register int x39,x40,x41,x42,x43,x44,x45,x46,x47,x48,x49,x50,x51;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */

  x25 =  config->vdfrmsz; 
  x26 =  config->vdhblnk;
  x27 =  config->vdvblks1;  
  x28 =  config->vdvblke1;
  x29 =  config->vdvblks2; 
  x30 =  config->vdvblke2;
  x31 =  config->vdimoff1; 
  x32 =  config->vdimgsz1; 
  x33 =  config->vdimoff2; 
  x34 =  config->vdimgsz2; 
  x35 =  config->vdfldt1; 
  x36 =  config->vdfldt2; 
  x37 =  config->vdthrld; 
  x38 =  config->vdhsync;
  x39 =  config->vdvsyns1; 
  x40 =  config->vdvsyne1; 
  x41 =  config->vdvsyns2; 
  x42 =  config->vdvsyne2; 
  x43 =  config->vdreload; 
  x44 =  config->vddispevt;
  x45 =  config->vdclip;
  x46 =  config->vddefval;
  x47 =  config->vdvint;
  x48 =  config->vdfbit; 
  x49 =  config->vdvbit1; 
  x50 =  config->vdvbit2; 
  x51 =  config->vdctl; 

  base[_VP_VDFRMSZ_OFFSET]   =    x25;
  base[_VP_VDHBLNK_OFFSET]   =    x26;  
  base[_VP_VDVBLKS1_OFFSET]  =    x27;  
  base[_VP_VDVBLKE1_OFFSET]  =    x28;  
  base[_VP_VDVBLKS2_OFFSET]  =    x29;  
  base[_VP_VDVBLKE2_OFFSET]  =    x30;  
  base[_VP_VDIMGOFF1_OFFSET] =    x31;  
  base[_VP_VDIMGSZ1_OFFSET]  =    x32;  
  base[_VP_VDIMGOFF2_OFFSET] =    x33;  
  base[_VP_VDIMGSZ2_OFFSET]  =    x34;  
  base[_VP_VDFLDT1_OFFSET]   =    x35;  
  base[_VP_VDFLDT2_OFFSET]   =    x36;  
  base[_VP_VDTHRLD_OFFSET]   =    x37;  
  base[_VP_VDHSYNC_OFFSET]   =    x38;  
  base[_VP_VDVSYNS1_OFFSET]  =    x39;  
  base[_VP_VDVSYNE1_OFFSET]  =    x40;  
  base[_VP_VDVSYNS2_OFFSET]  =    x41;  
  base[_VP_VDVSYNE2_OFFSET]  =    x42;  
  base[_VP_VDRELOAD_OFFSET]  =    x43;  
  base[_VP_VDDISPEVT_OFFSET] =    x44;  
  base[_VP_VDCLIP_OFFSET]    =    x45;  
  base[_VP_VDDEFVAL_OFFSET]  =    x46;  
  base[_VP_VDVINT_OFFSET]    =    x47;  
  base[_VP_VDFBIT_OFFSET]    =    x48;  
  base[_VP_VDVBIT1_OFFSET]   =    x49;  
  base[_VP_VDVBIT2_OFFSET]   =    x50;  
  base[_VP_VDCTL_OFFSET]     =    x51;  

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void VP_configGpio(VP_Handle hVp, VP_ConfigGpio *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hVp->baseAddr);
  register int x49,x50,x51,x52,x53,x54,x55,x56;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
  x49 =  config->pfunc; 
  x50 =  config->pdir;
  x51 =  config->pdout;
  x52 =  config->pdset;
  x53 =  config->pdclr;
  x54 =  config->pien;
  x55 =  config->pipol;
  x56 =  config->piclr;

  base[_VP_PFUNC_OFFSET]  =    x49;
  base[_VP_PDIR_OFFSET]   =    x50;
  base[_VP_PDOUT_OFFSET]  =    x51;
  base[_VP_PDSET_OFFSET]  =    x52;
  base[_VP_PDCLR_OFFSET]  =    x53;
  base[_VP_PIEN_OFFSET]   =    x54;
  base[_VP_PIPOL_OFFSET]  =    x55;
  base[_VP_PICLR_OFFSET]  =    x56;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
#if (CHIP_DM642)
 IDEF void VP_getConfig(VP_Handle hVp, VP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hVp->baseAddr);
//  volatile VP_Config* cfg = (volatile VP_Config*)config;
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19;
  register int x20,x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36;
  register int x37,x38,x39,x40,x41,x42,x43,x44,x45,x46,x47,x48,x49,x50,x51,x52,x53;
  register int x54,x55,x56,x57,x58,x59,x60,x61;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
	
  x0   =   base[_VP_VPCTL_OFFSET];
  x1   =   base[_VP_VPIE_OFFSET];  
  x2   =   base[_VP_VPIS_OFFSET];  
  x3   =   base[_VP_VCACTL_OFFSET];  
  x4   =   base[_VP_VCASTRT1_OFFSET];  
  x5   =   base[_VP_VCASTOP1_OFFSET];  
  x6   =   base[_VP_VCASTRT2_OFFSET];  
  x7   =   base[_VP_VCASTOP2_OFFSET];  
  x8   =   base[_VP_VCAVINT_OFFSET];  
  x9   =   base[_VP_VCATHRLD_OFFSET];  
  x10  =   base[_VP_VCAEVTCT_OFFSET];  
  x11  =   base[_VP_VCBCTL_OFFSET];  
  x12  =   base[_VP_VCBSTRT1_OFFSET];  
  x13  =   base[_VP_VCBSTOP1_OFFSET];  
  x14  =   base[_VP_VCBSTRT2_OFFSET];  
  x15  =   base[_VP_VCBSTOP2_OFFSET];  
  x16  =   base[_VP_VCBVINT_OFFSET];  
  x17  =   base[_VP_VCBTHRLD_OFFSET];  
  x18  =   base[_VP_VCBEVTCT_OFFSET];  
  x19  =   base[_VP_TSICTL_OFFSET];  
  x20  =   base[_VP_TSICLKINITL_OFFSET];  
  x21  =   base[_VP_TSICLKINITM_OFFSET];  
  x22  =   base[_VP_TSISTCMPL_OFFSET];  
  x23  =   base[_VP_TSISTCMPM_OFFSET];  
  x24  =   base[_VP_TSISTMSKL_OFFSET];  
  x25  =   base[_VP_TSISTMSKM_OFFSET];  
  x26  =   base[_VP_TSITICKS_OFFSET];  
  x27  =   base[_VP_VDCTL_OFFSET];  
  x28  =   base[_VP_VDFRMSZ_OFFSET];  
  x29  =   base[_VP_VDHBLNK_OFFSET];  
  x30  =   base[_VP_VDVBLKS1_OFFSET];  
  x31  =   base[_VP_VDVBLKE1_OFFSET];  
  x32  =   base[_VP_VDVBLKS2_OFFSET];  
  x33  =   base[_VP_VDVBLKE2_OFFSET];  
  x34  =   base[_VP_VDIMGOFF1_OFFSET];  
  x35  =   base[_VP_VDIMGSZ1_OFFSET];  
  x36  =   base[_VP_VDIMGOFF2_OFFSET];  
  x37  =   base[_VP_VDIMGSZ2_OFFSET];  
  x38  =   base[_VP_VDFLDT1_OFFSET];  
  x39  =   base[_VP_VDFLDT2_OFFSET];  
  x40  =   base[_VP_VDTHRLD_OFFSET];  
  x41  =   base[_VP_VDHSYNC_OFFSET];  
  x42  =   base[_VP_VDVSYNS1_OFFSET];  
  x43  =   base[_VP_VDVSYNE1_OFFSET];  
  x44  =   base[_VP_VDVSYNS2_OFFSET];  
  x45  =   base[_VP_VDVSYNE2_OFFSET];  
  x46  =   base[_VP_VDRELOAD_OFFSET];  
  x47  =   base[_VP_VDDISPEVT_OFFSET];  
  x48  =   base[_VP_VDCLIP_OFFSET];  
  x49  =   base[_VP_VDDEFVAL_OFFSET];  
  x50  =   base[_VP_VDVINT_OFFSET];  
  x51  =   base[_VP_VDFBIT_OFFSET];  
  x52  =   base[_VP_VDVBIT1_OFFSET];  
  x53  =   base[_VP_VDVBIT2_OFFSET];  
  x54  =   base[_VP_PFUNC_OFFSET];  
  x55  =   base[_VP_PDIR_OFFSET];  
  x56  =   base[_VP_PDOUT_OFFSET];  
  x57  =   base[_VP_PDSET_OFFSET];  
  x58  =   base[_VP_PDCLR_OFFSET];  
  x59  =   base[_VP_PIEN_OFFSET];  
  x60  =   base[_VP_PIPOL_OFFSET];  
  x61  =   base[_VP_PICLR_OFFSET];  
  
  config->port->vpctl         =  x0;
  config->port->vpie          =  x1;  
  config->port->vpis          =  x2;  
  config->capture->vcactl     =  x3;  
  config->capture->vcastrt1   =  x4;  
  config->capture->vcastop1   =  x5;  
  config->capture->vcastrt2   =  x6;  
  config->capture->vcastop2   =  x7;  
  config->capture->vcavint    =  x8;  
  config->capture->vcathrld   =  x9;  
  config->capture->vcaevtct   =  x10;  
  config->capture->vcbctl     =  x11;  
  config->capture->vcbstrt1   =  x12;  
  config->capture->vcbstop1   =  x13;  
  config->capture->vcbstrt2   =  x14;  
  config->capture->vcbstop2   =  x15;  
  config->capture->vcbvint    =  x16;  
  config->capture->vcbthrld   =  x17;  
  config->capture->vcbevtct   =  x18;  
  config->capture->tsictl      =  x19;  
  config->capture->tsiclkinitl =  x20;  
  config->capture->tsiclkinitm =  x21;  
  config->capture->tsistcmpl   =  x22;  
  config->capture->tsistcmpm   =  x23;  
  config->capture->tsistmskl   =  x24;  
  config->capture->tsistmskm   =  x25;  
  config->capture->tsiticks    =  x26;  
  config->display->vdctl      =  x27;  
  config->display->vdfrmsz    =  x28;  
  config->display->vdhblnk    =  x29;  
  config->display->vdvblks1   =  x30;  
  config->display->vdvblke1   =  x31;  
  config->display->vdvblks2   =  x32;  
  config->display->vdvblke2   =  x33;  
  config->display->vdimoff1   =  x34;  
  config->display->vdimgsz1   =  x35;  
  config->display->vdimoff2   =  x36;  
  config->display->vdimgsz2   =  x37;  
  config->display->vdfldt1    =  x38;  
  config->display->vdfldt2    =  x39;  
  config->display->vdthrld    =  x40;  
  config->display->vdhsync    =  x41;  
  config->display->vdvsyns1   =  x42;  
  config->display->vdvsyne1   =  x43;  
  config->display->vdvsyns2   =  x44;  
  config->display->vdvsyne2   =  x45;  
  config->display->vdreload   =  x46;  
  config->display->vddispevt  =  x47;  
  config->display->vdclip     =  x48;  
  config->display->vddefval   =  x49;  
  config->display->vdvint     =  x50;  
  config->display->vdfbit     =  x51;  
  config->display->vdvbit1    =  x52;  
  config->display->vdvbit2    =  x53;  
  config->gpio->pfunc         =  x54;  
  config->gpio->pdir          =  x55;  
  config->gpio->pdout         =  x56;  
  config->gpio->pdset         =  x57;  
  config->gpio->pdclr         =  x58;  
  config->gpio->pien          =  x59;  
  config->gpio->pipol         =  x60;  
  config->gpio->piclr         =  x61;  
                                 
  IRQ_globalRestore(gie);
 }
#else
 IDEF void VP_getConfig(VP_Handle hVp, VP_Config *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *)(hVp->baseAddr);
//  volatile VP_Config* cfg = (volatile VP_Config*)config;
  register int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19;
  register int x20,x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36;
  register int x37,x38,x39,x40,x41,x42,x43,x44,x45,x46,x47,x48,x49,x50,x51,x52,x53;

  gie = IRQ_globalDisable();

  /* the compiler generates more efficient code if the loads */
  /* and stores are grouped together rather than intermixed  */
	
  x0   =   base[_VP_VPCTL_OFFSET];
  x1   =   base[_VP_VPIE_OFFSET];  
  x2   =   base[_VP_VPIS_OFFSET];  
  x3   =   base[_VP_VCACTL_OFFSET];  
  x4   =   base[_VP_VCASTRT1_OFFSET];  
  x5   =   base[_VP_VCASTOP1_OFFSET];  
  x6   =   base[_VP_VCASTRT2_OFFSET];  
  x7   =   base[_VP_VCASTOP2_OFFSET];  
  x8   =   base[_VP_VCAVINT_OFFSET];  
  x9   =   base[_VP_VCATHRLD_OFFSET];  
  x10  =   base[_VP_VCAEVTCT_OFFSET];  
  x11  =   base[_VP_TSICTL_OFFSET];  
  x12  =   base[_VP_TSICLKINITL_OFFSET];  
  x13  =   base[_VP_TSICLKINITM_OFFSET];  
  x14  =   base[_VP_TSISTCMPL_OFFSET];  
  x15  =   base[_VP_TSISTCMPM_OFFSET];  
  x16  =   base[_VP_TSISTMSKL_OFFSET];  
  x17  =   base[_VP_TSISTMSKM_OFFSET];  
  x18  =   base[_VP_TSITICKS_OFFSET];  
  x19  =   base[_VP_VDCTL_OFFSET];  
  x20  =   base[_VP_VDFRMSZ_OFFSET];  
  x21  =   base[_VP_VDHBLNK_OFFSET];  
  x22  =   base[_VP_VDVBLKS1_OFFSET];  
  x23  =   base[_VP_VDVBLKE1_OFFSET];  
  x24  =   base[_VP_VDVBLKS2_OFFSET];  
  x25  =   base[_VP_VDVBLKE2_OFFSET];  
  x26  =   base[_VP_VDIMGOFF1_OFFSET];  
  x27  =   base[_VP_VDIMGSZ1_OFFSET];  
  x28  =   base[_VP_VDIMGOFF2_OFFSET];  
  x29  =   base[_VP_VDIMGSZ2_OFFSET];  
  x30  =   base[_VP_VDFLDT1_OFFSET];  
  x31  =   base[_VP_VDFLDT2_OFFSET];  
  x32  =   base[_VP_VDTHRLD_OFFSET];  
  x33  =   base[_VP_VDHSYNC_OFFSET];  
  x34  =   base[_VP_VDVSYNS1_OFFSET];  
  x35  =   base[_VP_VDVSYNE1_OFFSET];  
  x36  =   base[_VP_VDVSYNS2_OFFSET];  
  x37  =   base[_VP_VDVSYNE2_OFFSET];  
  x38  =   base[_VP_VDRELOAD_OFFSET];  
  x39  =   base[_VP_VDDISPEVT_OFFSET];  
  x40  =   base[_VP_VDCLIP_OFFSET];  
  x41  =   base[_VP_VDDEFVAL_OFFSET];  
  x42  =   base[_VP_VDVINT_OFFSET];  
  x43  =   base[_VP_VDFBIT_OFFSET];  
  x44  =   base[_VP_VDVBIT1_OFFSET];  
  x45  =   base[_VP_VDVBIT2_OFFSET];  
  x46  =   base[_VP_PFUNC_OFFSET];  
  x47  =   base[_VP_PDIR_OFFSET];  
  x48  =   base[_VP_PDOUT_OFFSET];  
  x49  =   base[_VP_PDSET_OFFSET];  
  x50  =   base[_VP_PDCLR_OFFSET];  
  x51  =   base[_VP_PIEN_OFFSET];  
  x52  =   base[_VP_PIPOL_OFFSET];  
  x53  =   base[_VP_PICLR_OFFSET];  
  
  config->port->vpctl          =  x0;
  config->port->vpie           =  x1;  
  config->port->vpis           =  x2;  
  config->capture->vcactl      =  x3;  
  config->capture->vcastrt1    =  x4;  
  config->capture->vcastop1    =  x5;  
  config->capture->vcastrt2    =  x6;  
  config->capture->vcastop2    =  x7;  
  config->capture->vcavint     =  x8;  
  config->capture->vcathrld    =  x9;  
  config->capture->vcaevtct    =  x10;  
  config->capture->tsictl      =  x11;  
  config->capture->tsiclkinitl =  x12;  
  config->capture->tsiclkinitm =  x13;  
  config->capture->tsistcmpl   =  x14;  
  config->capture->tsistcmpm   =  x15;  
  config->capture->tsistmskl   =  x16;  
  config->capture->tsistmskm   =  x17;  
  config->capture->tsiticks    =  x18;  
  config->display->vdctl       =  x19;  
  config->display->vdfrmsz     =  x20;  
  config->display->vdhblnk     =  x21;  
  config->display->vdvblks1    =  x22;  
  config->display->vdvblke1    =  x23;  
  config->display->vdvblks2    =  x24;  
  config->display->vdvblke2    =  x25;  
  config->display->vdimoff1    =  x26;  
  config->display->vdimgsz1    =  x27;  
  config->display->vdimoff2    =  x28;  
  config->display->vdimgsz2    =  x29;  
  config->display->vdfldt1     =  x30;  
  config->display->vdfldt2     =  x31;  
  config->display->vdthrld     =  x32;  
  config->display->vdhsync     =  x33;  
  config->display->vdvsyns1    =  x34;  
  config->display->vdvsyne1    =  x35;  
  config->display->vdvsyns2    =  x36;  
  config->display->vdvsyne2    =  x37;  
  config->display->vdreload    =  x38;  
  config->display->vddispevt   =  x39;  
  config->display->vdclip      =  x40;  
  config->display->vddefval    =  x41;  
  config->display->vdvint      =  x42;  
  config->display->vdfbit      =  x43;  
  config->display->vdvbit1     =  x44;  
  config->display->vdvbit2     =  x45;  
  config->gpio->pfunc          =  x46;  
  config->gpio->pdir           =  x47;  
  config->gpio->pdout          =  x48;  
  config->gpio->pdset          =  x49;  
  config->gpio->pdclr          =  x50;  
  config->gpio->pien           =  x51;  
  config->gpio->pipol          =  x52;  
  config->gpio->piclr          =  x53;  
                                 
  IRQ_globalRestore(gie);
 }
#endif
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* VP_SUPPORT */
#endif /* _CSL_VP_H_ */
/******************************************************************************\
* End of csl_vp.h
\******************************************************************************/

