/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_pci.h
* DATE CREATED.. Mon 06/12/2000
* LAST MODIFIED. 02/12/2002  PCI_intClear()
*                04/20/2001  (C64x compatibility)
*				 06/20/2003  TRCTL enhancement
*
\******************************************************************************/
#ifndef _CSL_PCI_H_
#define _CSL_PCI_H_

#include <csl_chip.h>
#include <csl_stdinc.h>
#include <csl_irq.h>
#include <csl_pcihal.h>

#if (PCI_SUPPORT)
/****************************************\
* PCI scope and inline control macros
\****************************************/
#ifdef __cplusplus
#define CSLAPI extern "C" far
#else
#define CSLAPI extern far
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _PCI_MOD_
  #define IDECL extern far
  #define USEDEFS
  #define IDEF
#else
  #ifdef  _INLINE
    #define IDECL static inline
    #define USEDEFS
    #define IDEF  static inline
  #else
    #define IDECL extern far
  #endif
#endif

/****************************************\
* PCI global macro declarations
\****************************************/
#define PCI_EVENT_CNT   11

/* eventPci  definitions */
#define PCI_EVT_DMAHALTED    12
#define PCI_EVT_PRST         11
#define PCI_EVT_EERDY	      9
#define PCI_EVT_CFGERR	      8
#define PCI_EVT_CFGDONE	      7
#define PCI_EVT_MASTEROK      6
#define PCI_EVT_PWRHL         5
#define PCI_EVT_PWRLH         4
#define PCI_EVT_HOSTSW	      3
#define PCI_EVT_PCIMASTER     2
#define PCI_EVT_PCITARGET     1
#define PCI_EVT_PWRMGMT	      0


/* mode StarttXfr definitions */
#define	PCI_WRITE	 0x1u
#define PCI_READ_PREF    0x2u
#define	PCI_READ_NOPREF  0x3u

/* EEPROM sizes */
 #define PCI_EEPROM_NONE     0x00000000u
 #define PCI_EEPROM_4K       0x00000011u
#if (!C64_SUPPORT)
 #define PCI_EEPROM_1K       0x00000001u
 #define PCI_EEPROM_2K       0x00000010u
 #define PCI_EEPROM_16K      0x00000100u
#endif

/****************************************\
* PCI global typedef declarations
\****************************************/
#if(!C64_SUPPORT)
typedef struct {
   Uint32 dspma;
   Uint32 pcima;
   Uint32 pcimc;
} PCI_ConfigXfr;
#else
typedef struct {
   Uint32 dspma;
   Uint32 pcima;
   Uint32 pcimc;
   Uint32 trctl;
} PCI_ConfigXfr;
#endif

/****************************************\
* PCI global variable declarations
\****************************************/
extern far Uint32 _PCI_maskTable[13];



/*_PCI_maskTable[PCI_EVT_PWRMGMT]= _PCI_PCIIEN_PWRMGMT_MASK;
_PCI_maskTable[PCI_EVT_PCITARGET]= _PCI_PCIIEN_PCITARGET_MASK;
_PCI_maskTable[PCI_EVT_PCIMASTER]= _PCI_PCIIEN_PCIMASTER_MASK;
_PCI_maskTable[PCI_EVT_HOSTSW]= _PCI_PCIIEN_PWRLH_MASK;
_PCI_maskTable[PCI_EVT_PWRLH]= _PCI_PCIIEN_PWRLH_MASK;
_PCI_maskTable[PCI_EVT_PWRHL]= _PCI_PCIIEN_PWRHL_MASK;
_PCI_maskTable[PCI_EVT_MASTEROK]= _PCI_PCIIEN_MASTEROK_MASK;
_PCI_maskTable[PCI_EVT_CFGDONE]= _PCI_PCIIEN_CFGDONE_MASK;
_PCI_maskTable[PCI_EVT_CFGERR]= _PCI_PCIIEN_CFGERR_MASK;
_PCI_maskTable[PCI_EVT_EERDY]=  _PCI_PCIIEN_EERDY_MASK;
_PCI_maskTable[PCI_EVT_PRST]= _PCI_PCIIEN_PRST_MASK;
_PCI_maskTable[PCI_EVT_DMAHALTED]= _PCI_PCIIS_DMAHALTED_MASK;
 */

/****************************************\
* PCI global function declarations
\****************************************/
extern far Uint32 _PCI_eepromEnableWrite();
extern far Uint32 PCI_eepromWrite(Uint32 eeaddr,Uint16 eedata);
extern far Uint32 PCI_eepromWriteAll(Uint16 eedata);
extern far Uint16 PCI_eepromRead(Uint32 eeaddr);
extern far Uint32 PCI_eepromErase(Uint32 eeaddr);
extern far Uint32 PCI_eepromEraseAll();
/****************************************\
* PCI inline function declarations
\****************************************/

/* Master transfer functions */
IDECL void   PCI_xfrStart(Uint32 modeXfr);
IDECL void   PCI_xfrFlush();      // Field START=00  - flush current Transaction
IDECL int    PCI_xfrTest();   // test if the transfer is done - wait the Start field back to 00 */
IDECL void   PCI_xfrByteCntSet(Uint16 nbbyte); // set field CNT - # of bytes to be transfered

/* Halt function (HALT register ) */
#if (!C64_SUPPORT)
IDECL void   PCI_xfrHalt();
IDECL void   PCI_xfrEnable();
#endif


IDECL Uint32 PCI_curDspAddrGet();
IDECL Uint32 PCI_curPciAddrGet();
IDECL Uint32 PCI_curByteCntGet();
#if(!C64_SUPPORT)
IDECL void PCI_xfrConfig(PCI_ConfigXfr *config);
IDECL void PCI_xfrConfigArgs(Uint32 dspma, Uint32 pcima, Uint32 pcimc);
IDECL void PCI_xfrGetConfig(PCI_ConfigXfr *config);
#else
IDECL void PCI_xfrConfig(PCI_ConfigXfr *config);
IDECL void PCI_xfrConfigArgs(Uint32 dspma, Uint32 pcima, Uint32 pcimc , Uint32 trctl);
IDECL void PCI_xfrGetConfig(PCI_ConfigXfr *config);
#endif
/* PCI Interrupt Enable/Reporting functions */
IDECL void   PCI_intEnable(Uint32 eventPci);
IDECL void   PCI_intDisable(Uint32 eventPci);
IDECL Uint32 PCI_intTest(Uint32 eventPci);
IDECL void   PCI_intClear(Uint32 eventPci);

IDECL void PCI_dspIntReqSet();
IDECL void PCI_dspIntReqClear();

/* DSP EEPROM interface functions */
IDECL Uint32 PCI_eepromSize();      /*  reads fieds EESZ of EECTL reg   */
IDECL Uint32 PCI_eepromTest();    /* returns success if EESZ != 0 - EEPROM present */
IDECL Uint32 PCI_eepromIsAutoCfg();  /* reads the EEAI bit status of EECTL- AutoCfgEnable  */

/* Power Management functions */
#if (!C64_SUPPORT)
IDECL void PCI_pwrStatUpdate();
IDECL Uint32 PCI_pwrStatTest();
#endif


/****************************************\
* PCI inline function definitions
\****************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void PCI_xfrStart(Uint32 modeXfr) {
   PCI_FSET(PCIMC,START,modeXfr) ;
}
/*----------------------------------------------------------------------------*/
#if (!C64_SUPPORT)
IDEF void PCI_xfrHalt(){
  PCI_FSET(HALT,HALT,1);
}
/*----------------------------------------------------------------------------*/
IDEF void PCI_xfrEnable(){
  PCI_FSET(HALT,HALT,0);
}
#endif /* !C64_SUPPORT */
/*----------------------------------------------------------------------------*/
IDEF void PCI_xfrFlush(){
  PCI_FSET(PCIMC,START,0);
}
/*----------------------------------------------------------------------------*/
IDEF int PCI_xfrTest(){
  return PCI_FGET(PCIMC,START);
}
/*----------------------------------------------------------------------------*/
IDEF void PCI_xfrByteCntSet(Uint16 nbbyte){
  PCI_FSET(PCIMC,CNT,nbbyte);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 PCI_curDspAddrGet() {
  return PCI_FGET(CDSPA,CDSPA);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 PCI_curPciAddrGet() {
  return PCI_FGET(CPCIA,CPCIA);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 PCI_curByteCntGet() {
  return PCI_FGET(CCNT,CCNT);
}
/*----------------------------------------------------------------------------*/
#if(!C64_SUPPORT)
IDEF void PCI_xfrConfig(PCI_ConfigXfr *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *) _PCI_BASE1_GLOBAL;
  register int x0,x1,x2;

  gie = IRQ_globalDisable();

  x0 = config->dspma;
  x1 = config->pcima;
  x2 = config->pcimc;

  base[_PCI_PCIMC_OFFSET] = 0x00000000;
  base[_PCI_DSPMA_OFFSET] = x0;
  base[_PCI_PCIMA_OFFSET] = x1;
  base[_PCI_PCIMC_OFFSET] = x2;

  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void PCI_xfrConfigArgs(Uint32 dspma,Uint32 pcima,Uint32 pcimc) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *) _PCI_BASE1_GLOBAL;

  gie = IRQ_globalDisable();

  base[_PCI_PCIMC_OFFSET] = 0x00000000u;
  base[_PCI_DSPMA_OFFSET] = dspma;
  base[_PCI_PCIMA_OFFSET] = pcima;
  base[_PCI_PCIMC_OFFSET] = pcimc;

 IRQ_globalRestore(gie);
}

/*----------------------------------------------------------------------------*/
IDEF void PCI_xfrGetConfig(PCI_ConfigXfr *config) {

  Uint32 gie;
  volatile Uint32 *base = (volatile Uint32 *) _PCI_BASE1_GLOBAL;
  volatile PCI_ConfigXfr *cfg = (volatile PCI_ConfigXfr*)config;
  register int x0,x1,x2;

  gie = IRQ_globalDisable();

  x0 = base[_PCI_DSPMA_OFFSET];
  x1 = base[_PCI_PCIMA_OFFSET];
  x2 = base[_PCI_PCIMC_OFFSET];

  cfg->dspma = x0;
  cfg->pcima = x1;
  cfg->pcimc = x2;

  IRQ_globalRestore(gie);
}
#else
IDEF void PCI_xfrConfig(PCI_ConfigXfr *config) {

  Uint32 gie;
  volatile Uint32 *base1 = (volatile Uint32 *) _PCI_BASE1_GLOBAL;
  volatile Uint32 *base2 = (volatile Uint32 *) _PCI_BASE3_GLOBAL;

  register int x0,x1,x2,x3;

  gie = IRQ_globalDisable();

  x0 = config->dspma;
  x1 = config->pcima;
  x2 = config->pcimc;
  x3 = config->trctl;

  base1[_PCI_PCIMC_OFFSET] = 0x00000000;
  base1[_PCI_DSPMA_OFFSET] = x0;
  base1[_PCI_PCIMA_OFFSET] = x1;
  base1[_PCI_PCIMC_OFFSET] = x2;
  base2[_PCI_TRCTL_OFFSET] = x3;


  IRQ_globalRestore(gie);
}
/*----------------------------------------------------------------------------*/
IDEF void PCI_xfrConfigArgs(Uint32 dspma,Uint32 pcima,Uint32 pcimc,Uint32 trctl) {

  Uint32 gie;
  volatile Uint32 *base1 = (volatile Uint32 *) _PCI_BASE1_GLOBAL;
  volatile Uint32 *base2 = (volatile Uint32 *) _PCI_BASE3_GLOBAL;

  gie = IRQ_globalDisable();

  base1[_PCI_PCIMC_OFFSET] = 0x00000000u;
  base1[_PCI_DSPMA_OFFSET] = dspma;
  base1[_PCI_PCIMA_OFFSET] = pcima;
  base1[_PCI_PCIMC_OFFSET] = pcimc;
  base2[_PCI_TRCTL_OFFSET] = trctl;

 IRQ_globalRestore(gie);
}

/*----------------------------------------------------------------------------*/
IDEF void PCI_xfrGetConfig(PCI_ConfigXfr *config) {

  Uint32 gie;
  volatile Uint32 *base1 = (volatile Uint32 *) _PCI_BASE1_GLOBAL;
  volatile Uint32 *base2 = (volatile Uint32 *) _PCI_BASE3_GLOBAL;
  volatile PCI_ConfigXfr *cfg = (volatile PCI_ConfigXfr*)config;
  register int x0,x1,x2,x3;

  gie = IRQ_globalDisable();

  x0 = base1[_PCI_DSPMA_OFFSET];
  x1 = base1[_PCI_PCIMA_OFFSET];
  x2 = base1[_PCI_PCIMC_OFFSET];
  x3 = base2[_PCI_TRCTL_OFFSET];

  cfg->dspma = x0;
  cfg->pcima = x1;
  cfg->pcimc = x2;
  cfg->trctl = x3;

  IRQ_globalRestore(gie);
}
#endif
/*----------------------------------------------------------------------------*/
IDEF void PCI_intEnable(Uint32 eventPci) {
  volatile Uint32 value ;
  value=  PCI_RGET(PCIIEN);
  /* Set bit of eventPCi */
  PCI_RSET(PCIIEN,(value | _PCI_maskTable[eventPci]));
}
/*----------------------------------------------------------------------------*/
IDEF void PCI_intDisable(Uint32 eventPci) {
   volatile Uint32 value;
   value =( PCI_RGET(PCIIEN) &= ~_PCI_maskTable[eventPci]);            /* Set the opposite mask of eventPci    */
  PCI_RSET(PCIIEN,value);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 PCI_intTest(Uint32 eventPci) {
    return ( ( PCI_RGET(PCIIS) & _PCI_maskTable[eventPci]) >> eventPci );
}
/*----------------------------------------------------------------------------*/
IDEF void  PCI_intClear(Uint32 eventPci) {
    PCI_RSET(PCIIS, PCI_RGET(PCIIS) & _PCI_maskTable[eventPci]) ;
}
/*----------------------------------------------------------------------------*/
IDEF void PCI_dspIntReqSet(){
 PCI_FSET(RSTSRC,INTREQ,1);
}
/*----------------------------------------------------------------------------*/
IDEF void PCI_dspIntReqClear(){
 PCI_FSET(RSTSRC,INTRST,1);
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 PCI_eepromSize(){
  return (PCI_FGET(EECTL,EESZ));
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 PCI_eepromTest(){
  volatile Uint32 test = 0;
   if ( (PCI_FGET(EECTL,EESZ) != 0))
    {
     test = 1;
    }
   return test;
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 PCI_eepromIsAutoCfg() {
  return((Uint32) PCI_FGET(EECTL,EEAI));
}
/*----------------------------------------------------------------------------*/
#if (!C64_SUPPORT)
IDEF void PCI_pwrStatUpdate() {
    PCI_FSET(PMDCSR,CURSTATE,PCI_FGET(PMDCSR,REQSTATE));   /* update value  */
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 PCI_pwrStatTest() {
    volatile Uint32 status;
      status= PCI_FGET(PCIIS,PWRMGMT) | (PCI_FGET(PMDCSR,D2WARMONWKP)<<1) \
              | ((PCI_FGET(PMDCSR,D3WARMONWKP)<<1) + 1);
     return( status );
}
#endif /* !C64_SUPPORT */

/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */

#endif /* PCI_SUPPORT */
#endif /* _PCI_H_ */
/******************************************************************************\
* End of csl_pci.h
\******************************************************************************/

