/*
 *  Copyright 2001 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  U.S. Patent Nos. 5,283,900  5,392,448
 */
/* "@(#) DSP/BIOS 4.50.2 03-27-01 (barracuda-i02)" */
/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_legacy.h
* DATE CREATED.. 04/24/2000 
* LAST MODIFIED. 10/30/2001 - 
                           EMIF_GBLCTL_NOHOLD_0 => EMIF_GBLCTL_NOHOLD_DISABLE
                           EMIF_GBLCTL_NOHOLD_1 => EMIF_GBLCTL_NOHOLD_ENABLE
                           MCBSP : Baseaddr => baseaddr
\******************************************************************************/
#ifndef _CSL_LEGACY_H_
#define _CSL_LEGACY_H_

#include <csl_legacyhal.h>

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

#ifdef  _LEGACY_MOD_
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

#if (CACHE_SUPPORT)
  #define CACHE_64KSRAM        CACHE_64KSRAM 
  #define CACHE_0KCACHE        CACHE_0KCACHE 
  #define CACHE_48KSRAM        CACHE_48KSRAM 
  #define CACHE_16KCACHE       CACHE_16KCACHE
  #define CACHE_32KSRAM        CACHE_32KSRAM 
  #define CACHE_32KCACHE       CACHE_32KCACHE
  #define CACHE_16KSRAM        CACHE_16KSRAM 
  #define CACHE_48KCACHE       CACHE_48KCACHE
  #define CACHE_0KSRAM         CACHE_0KSRAM  
  #define CACHE_64KCACHE       CACHE_64KCACHE
  #define CACHE_L2MODE         CACHE_L2Mode 
  #define CACHE_L2ALL          CACHE_L2ALL
  #define CACHE_L1PALL         CACHE_L1PALL
  #define CACHE_L1DALL         CACHE_L1DALL
  #define CACHE_REGION         CACHE_Region
  #define CACHE_PCCMAPPED      CACHE_PCC_MAPPED
  #define CACHE_PCCENABLE      CACHE_PCC_ENABLE
  #define CACHE_PCCFREEZE      CACHE_PCC_FREEZE
  #define CACHE_PCCBYPASS      CACHE_PCC_BYPASS 
  #define CACHE_PCC            CACHE_Pcc 
  #define CACHE_Reset          CACHE_reset
  #define CACHE_SetL2Mode      CACHE_setL2Mode
  #define CACHE_GetL2Mode      CACHE_getL2Mode
  #define CACHE_SetPccMode     CACHE_setPccMode
  #define CACHE_GetL2SramSize  CACHE_getL2SramSize
  //#define CACHE_Init           CACHE_init
  #define CACHE_Init()
  #define CACHE_EnableCaching  CACHE_enableCaching

  #define CACHE_Flush(r,a,w)      CACHE_flush(r,(void*)(a),w)
  #define CACHE_Clean(r,a,w)      CACHE_clean(r,(void*)(a),w)
  #define CACHE_Invalidate(r,a,w) CACHE_invalidate(r,(void*)(a),w)

#endif /* CACHE_SUPPORT */

#if (1)
  //#define CHIP_Init            CHIP_init 
  #define CHIP_Init()              
  #define CHIP_GetCpuId        CHIP_getCpuId
  #define CHIP_GetRevId        CHIP_getRevId
  #define CHIP_GetEndian       CHIP_getEndian
  #define CHIP_GetMapMode      CHIP_getMapMode 
#endif

#if (1)
  #define CSL_Init             CSL_init      
  #define CSLINIT_Init         CSLINIT_init      
  #define CSLLIB_Init          CSLLIB_init
#endif

#if (DAT_SUPPORT)
  #define DAT_Open             DAT_open  
  #define DAT_Close            DAT_close     
  #define DAT_Copy             DAT_copy   
  #define DAT_Fill             DAT_fill    
  #define DAT_Wait             DAT_wait  
  #define DAT_Copy2D           DAT_copy2d   
  //#define DAT_Init             DAT_init 
  #define DAT_Init()
  #define _DAT_Open            _DAT_open  
  #define _DAT_Close           _DAT_close     
  #define _DAT_Copy            _DAT_copy   
  #define _DAT_Fill            _DAT_fill    
  #define _DAT_Wait            _DAT_wait  
  #define _DAT_Copy2D          _DAT_copy2d   
  #define _DAT_Init            _DAT_init 
#endif /* DAT_SUPPORT */

#if (DMA_SUPPORT)
  #define DMA_PRIVATE_OBJ      DMA_PrivateObj
  #define DMA_HANDLE           DMA_Handle
  #define DMA_CONFIG           DMA_Config
  #define DMA_GBL              DMA_Gbl
  #define DMA_HCHA0            _DMA_hCha0
  #define DMA_HCHA1            _DMA_hCha1
  #define DMA_HCHA2            _DMA_hCha2
  #define DMA_HCHA3            _DMA_hCha3
  #define DMA_GBL_PRIVATE      DMA_gblPrivate 
  #define DMA_Reset            DMA_reset           
  #define DMA_Open             DMA_open            
  #define DMA_Close            DMA_close           
  #define DMA_ConfigA          DMA_config           
  #define DMA_ConfigB          DMA_configArgs           
  #define DMA_AllocGlobalReg   DMA_allocGlobalReg           
  #define DMA_FreeGlobalReg    DMA_freeGlobalReg           
  //#define DMA_Init             DMA_init           
  #define DMA_Init()
  #define DMA_GetEventId       DMA_getEventId           
  #define DMA_GetStatus        DMA_getStatus           
  #define DMA_Start            DMA_start           
  #define DMA_Stop             DMA_stop           
  #define DMA_Pause            DMA_pause           
  #define DMA_AutoStart        DMA_autoStart           
  #define DMA_Wait             DMA_wait           
  #define DMA_SetAuxCtl        DMA_setAuxCtl           
  #define DMA_GetGlobalReg     DMA_getGlobalReg           
  #define DMA_SetGlobalReg     DMA_setGlobalReg           

#if (0)
  #define DMA_GBL_ADDRRLDB    0x00000001u
  #define DMA_GBL_ADDRRLDC    0x00000002u
  #define DMA_GBL_ADDRRLDD    0x00000003u
  #define DMA_GBL_INDEXA      0x00000004u
  #define DMA_GBL_INDEXB      0x00000005u
  #define DMA_GBL_CNTRLDA     0x00000008u
  #define DMA_GBL_CNTRLDB     0x00000009u
  #define DMA_GBL_SPLITA      0x0000000Du
  #define DMA_GBL_SPLITB      0x0000000Eu
  #define DMA_GBL_SPLITC      0x0000000Fu

  #define _DMA_GBLREG_CNT     16
  #define _DMA_GBLREG_MASK    (_DMA_GBLREG_CNT-1)
#endif

  #define DMA_MK_AUXCTL(chpri,auxpri) ((Uint32)(\
      HFIELD_SHIFT(HDMA_AUXCTL_CHPRI,chpri)|\
      HFIELD_SHIFT(HDMA_AUXCTL_AUXPRI,auxpri)\
    )\
  )

  #define DMA_MK_PRICTL(start,srcdir,dstdir,esize,split,cntrld,\
    index,rsync,wsync,pri,tcint,fs,emod,srcrld,dstrld) ((UINT32)(\
      HFIELD_SHIFT(HDMA_PRICTL_START,start)|\
      HFIELD_SHIFT(HDMA_PRICTL_SRCDIR,srcdir)|\
      HFIELD_SHIFT(HDMA_PRICTL_DSTDIR,dstdir)|\
      HFIELD_SHIFT(HDMA_PRICTL_ESIZE,esize)|\
      HFIELD_SHIFT(HDMA_PRICTL_SPLIT,split)|\
      HFIELD_SHIFT(HDMA_PRICTL_CNTRLD,cntrld)|\
      HFIELD_SHIFT(HDMA_PRICTL_INDEX,index)|\
      HFIELD_SHIFT(HDMA_PRICTL_RSYNC,rsync)|\
      HFIELD_SHIFT(HDMA_PRICTL_WSYNC,wsync)|\
      HFIELD_SHIFT(HDMA_PRICTL_PRI,pri)|\
      HFIELD_SHIFT(HDMA_PRICTL_TCINT,tcint)|\
      HFIELD_SHIFT(HDMA_PRICTL_FS,fs)|\
      HFIELD_SHIFT(HDMA_PRICTL_EMOD,emod)|\
      HFIELD_SHIFT(HDMA_PRICTL_SRCRLD,srcrld)|\
      HFIELD_SHIFT(HDMA_PRICTL_DSTRLD,dstrld)\
    )\
  )

  #define DMA_MK_SECCTL(sxie,frameie,lastie,blockie,rdropie,wdropie,\
    dmacen,fsig,rspol,wspol) ((UINT32)(\
      HFIELD_SHIFT(HDMA_SECCTL_SXIE,sxie)|\
      HFIELD_SHIFT(HDMA_SECCTL_FRAMEIE,frameie)|\
      HFIELD_SHIFT(HDMA_SECCTL_LASTIE,lastie)|\
      HFIELD_SHIFT(HDMA_SECCTL_BLOCKIE,blockie)|\
      HFIELD_SHIFT(HDMA_SECCTL_RDROPIE,rdropie)|\
      HFIELD_SHIFT(HDMA_SECCTL_WDROPIE,wdropie)|\
      HFIELD_SHIFT(HDMA_SECCTL_DMACEN,dmacen)|\
      HFIELD_SHIFT(HDMA_SECCTL_FSIG,fsig)|\
      HFIELD_SHIFT(HDMA_SECCTL_RSPOL,rspol)|\
      HFIELD_SHIFT(HDMA_SECCTL_WSPOL,wspol)\
    )\
  )

  #define DMA_MK_SRC(src) ((Uint32)(\
      HFIELD_SHIFT(HDMA_SRC_SRC,src)\
    )\
  )

  #define DMA_MK_DST(dst) ((Uint32)(\
      HFIELD_SHIFT(HDMA_DST_DST,dst)\
    )\
  )

  #define DMA_MK_XFRCNT(elecnt,frmcnt) ((Uint32)(\
      HFIELD_SHIFT(HDMA_XFRCNT_ELECNT,elecnt)|\
      HFIELD_SHIFT(HDMA_XFRCNT_FRMCNT,frmcnt)\
    )\
  )

  #define DMA_MK_GBLCNT(elecnt,frmcnt) ((Uint32)(\
      HFIELD_SHIFT(HDMA_GBLCNT_ELECNT,elecnt)|\
      HFIELD_SHIFT(HDMA_GBLCNT_FRMCNT,frmcnt)\
    )\
  )

  #define DMA_MK_GBLIDX(eleidx,frmidx) ((Uint32)(\
      HFIELD_SHIFT(HDMA_GBLIDX_ELEIDX,eleidx)|\
      HFIELD_SHIFT(HDMA_GBLIDX_FRMIDX,frmidx)\
    )\
  )

  #define DMA_MK_GBLADDR(gbladdr) ((Uint32)(\
      HFIELD_SHIFT(HDMA_GBLADDR_GBLADDR,gbladdr)\
    )\
  )
#endif /* DMA_SUPPORT */

#if (EDMA_SUPPORT)
  #define EDMA_HANDLE          EDMA_Handle
  #define EDMA_CONFIG          EDMA_Config
  #define EDMA_Reset           EDMA_reset
  #define EDMA_Open            EDMA_open
  #define EDMA_Close           EDMA_close
  #define EDMA_AllocTable      EDMA_allocTable
  #define EDMA_FreeTable       EDMA_freeTable
  #define EDMA_ConfigA         EDMA_config
  #define EDMA_ConfigB         EDMA_configArgs
  //#define EDMA_Init            EDMA_init              
  #define EDMA_Init() 
  #define EDMA_GetScratchAddr  EDMA_getScratchAddr              
  #define EDMA_GetScratchSize  EDMA_getScratchSize              
  #define EDMA_GetPriQStatus   EDMA_getPriQStatus              
  #define EDMA_EnableChannel   EDMA_enableChannel    
  #define EDMA_DisableChannel  EDMA_disableChannel              
  #define EDMA_SetChannel      EDMA_setChannel              
  #define EDMA_GetChannel      EDMA_getChannel              
  #define EDMA_ClearChannel    EDMA_clearChannel              
  #define EDMA_GetTableAddress EDMA_getTableAddress              

  #if (0)
    #define EDMA_CCER            HEDMA_CCER
    #define EDMA_CIPR            HEDMA_CIPR
    #define EDMA_CIER            HEDMA_CIER
  #endif

  #define EDMA_MK_OPT(fs,link,tcc,tcint,dum,d2d,sum,s2d,esize,pri)\
    ((Uint32)( \
      HFIELD_SHIFT(HEDMA_OPT_FS,fs)| \
      HFIELD_SHIFT(HEDMA_OPT_LINK,link)| \
      HFIELD_SHIFT(HEDMA_OPT_TCC,tcc)| \
      HFIELD_SHIFT(HEDMA_OPT_TCINT,tcint)| \
      HFIELD_SHIFT(HEDMA_OPT_DUM,dum)| \
      HFIELD_SHIFT(HEDMA_OPT_2DD,d2d)| \
      HFIELD_SHIFT(HEDMA_OPT_SUM,sum)| \
      HFIELD_SHIFT(HEDMA_OPT_2DS,s2d)| \
      HFIELD_SHIFT(HEDMA_OPT_ESIZE,esize)| \
      HFIELD_SHIFT(HEDMA_OPT_PRI,pri) \
    ) \
  )

  #define EDMA_MK_SRC(src) \
    ((Uint32)(\
      HFIELD_SHIFT(HEDMA_SRC_SRC,src)\
    )\
  )

  #define EDMA_MK_CNT(elecnt,frmcnt)\
    ((Uint32)(\
      HFIELD_SHIFT(HEDMA_CNT_ELECNT,elecnt)|\
      HFIELD_SHIFT(HEDMA_CNT_FRMCNT,frmcnt)\
    )\
  )

  #define EDMA_MK_DST(dst) \
    ((Uint32)(\
      HFIELD_SHIFT(HEDMA_DST_DST,dst)\
    )\
  )

  #define EDMA_MK_IDX(eleidx,frmidx)\
    ((Uint32)(\
      HFIELD_SHIFT(HEDMA_IDX_ELEIDX,eleidx)|\
      HFIELD_SHIFT(HEDMA_IDX_FRMIDX,frmidx)\
    )\
  )

  #define EDMA_MK_RLD(link,elerld)\
    ((Uint32)(\
      HFIELD_SHIFT(HEDMA_RLD_LINK,link)|\
      HFIELD_SHIFT(HEDMA_RLD_ELERLD,elerld)\
    )\
  )
#endif /* EDMA_SUPPORT */


#if (EMIF_SUPPORT)
 /* 3 following functions are declared later on */
  // EMIF_CONFIG           
  // EMIF_ConfigA          
  // EMIF_ConfigB         
  
  //#define EMIF_Init            EMIF_init
  #define EMIF_Init()
  
  #define EMIF_GBLCTL_RBTR8_NA             (0x00000000)
  #define EMIF_GBLCTL_SSCRT_NA             (0x00000000)
  #define EMIF_GBLCTL_CLK2EN_NA            (0x00000000)
  #define EMIF_GBLCTL_SSCEN_NA             (0x00000000)
  #define EMIF_GBLCTL_SDCEN_NA             (0x00000000)
  #define EMIF_CECTL_TA_NA                 (0x00000000)
  #define EMIF_SDCTL_SDWID_NA              (0x00000000)
  #define EMIF_SDCTL_SDCSZ_NA              (0x00000000)
  #define EMIF_SDCTL_SDRSZ_NA              (0x00000000)
  #define EMIF_SDCTL_SDBSZ_NA              (0x00000000)
  #define EMIF_SDTIM_XRFR_NA               (0x00000000)
  #define EMIF_SDEXT_NA                    (0x00000000)

/* added for reported bug SDSsq22603*/
  #define EMIF_GBLCTL_NOHOLD_0       EMIF_GBLCTL_NOHOLD_DISABLE
  #define EMIF_GBLCTL_NOHOLD_1       EMIF_GBLCTL_NOHOLD_ENABLE


  #define  EMIF_CECTL_TA_OF(x)         _VALUEOF(x)
  #define  EMIF_SDEXT_OF(x)            _VALUEOF(x)

  #define EMIF_MK_GBLCTL(rbtr8,sscrt,clk2en,clk1en,sscen,sdcen,nohold)\
    ((Uint32)( \
      HFIELD_SHIFT(HEMIF_GBLCTL_RBTR8,rbtr8)|\
      HFIELD_SHIFT(HEMIF_GBLCTL_SSCRT,sscrt)|\
      HFIELD_SHIFT(HEMIF_GBLCTL_CLK2EN,clk2en)|\
      HFIELD_SHIFT(HEMIF_GBLCTL_CLK1EN,clk1en)|\
      HFIELD_SHIFT(HEMIF_GBLCTL_SSCEN,sscen)|\
      HFIELD_SHIFT(HEMIF_GBLCTL_SDCEN,sdcen)|\
      HFIELD_SHIFT(HEMIF_GBLCTL_NOHOLD,nohold)|\
      0x00003000 \
    )\
  )

  #define EMIF_MK_CECTL(rdhld,mtype,rdstrb,ta,rdsetup,wrhld,wrstrb,wrsetup)\
    ((Uint32)( \
      HFIELD_SHIFT(HEMIF_CECTL_RDHLD,rdhld)|\
      HFIELD_SHIFT(HEMIF_CECTL_WRHLDMSB,(wrhld>>2))|\
      HFIELD_SHIFT(HEMIF_CECTL_MTYPE,mtype)|\
      HFIELD_SHIFT(HEMIF_CECTL_RDSTRB,rdstrb)|\
      HFIELD_SHIFT(HEMIF_CECTL_TA,ta)|\
      HFIELD_SHIFT(HEMIF_CECTL_RDSETUP,rdsetup)|\
      HFIELD_SHIFT(HEMIF_CECTL_WRHLD,wrhld)|\
      HFIELD_SHIFT(HEMIF_CECTL_WRSTRB,wrstrb)|\
      HFIELD_SHIFT(HEMIF_CECTL_WRSETUP,wrsetup)\
    )\
  )

  #define EMIF_MK_SDCTL(trc,trp,trcd,init,rfen,sdwid,sdcsz,sdrsz,sdbsz)\
    ((Uint32)( \
      HFIELD_SHIFT(HEMIF_SDCTL_TRC,trc)|\
      HFIELD_SHIFT(HEMIF_SDCTL_TRP,trp)|\
      HFIELD_SHIFT(HEMIF_SDCTL_TRCD,trcd)|\
      HFIELD_SHIFT(HEMIF_SDCTL_INIT,init)|\
      HFIELD_SHIFT(HEMIF_SDCTL_RFEN,rfen)|\
      HFIELD_SHIFT(HEMIF_SDCTL_SDWID,sdwid)|\
      HFIELD_SHIFT(HEMIF_SDCTL_SDCSZ,sdcsz)|\
      HFIELD_SHIFT(HEMIF_SDCTL_SDRSZ,sdrsz)|\
      HFIELD_SHIFT(HEMIF_SDCTL_SDBSZ,sdbsz)\
    )\
  )

  #define EMIF_MK_SDTIM(period,xrfr)\
    ((Uint32)( \
      HFIELD_SHIFT(HEMIF_SDTIM_PERIOD,period)|\
      HFIELD_SHIFT(HEMIF_SDTIM_XRFR,xrfr)\
    )\
  )

  #define EMIF_MK_SDEXT(tcl,tras,trrd,twr,thzp,rd2rd,rd2deac,rd2wr,\
    r2wdqm,wr2wr,wr2deac,wr2rd) ((Uint32)( \
      HFIELD_SHIFT(HEMIF_SDEXT_TCL,tcl)|\
      HFIELD_SHIFT(HEMIF_SDEXT_TRAS,tras)|\
      HFIELD_SHIFT(HEMIF_SDEXT_TRRD,trrd)|\
      HFIELD_SHIFT(HEMIF_SDEXT_TWR,twr)|\
      HFIELD_SHIFT(HEMIF_SDEXT_THZP,thzp)|\
      HFIELD_SHIFT(HEMIF_SDEXT_RD2RD,rd2rd)|\
      HFIELD_SHIFT(HEMIF_SDEXT_RD2DEAC,rd2deac)|\
      HFIELD_SHIFT(HEMIF_SDEXT_RD2WR,rd2wr)|\
      HFIELD_SHIFT(HEMIF_SDEXT_R2WDQM,r2wdqm)|\
      HFIELD_SHIFT(HEMIF_SDEXT_WR2WR,wr2wr)|\
      HFIELD_SHIFT(HEMIF_SDEXT_WR2DEAC,wr2deac)|\
      HFIELD_SHIFT(HEMIF_SDEXT_WR2RD,wr2rd)\
    )\
  )
#endif /* EMIF_SUPPORT */


#if  (GPIO_SUPPORT && C64_SUPPORT)

#define GPIO_config(config)    GPIO_config(_hGpioDev0,config);
#define GPIO_configArgs( gpgc, gpen,  gpdir, gpval, gphm,  gplm,  gppol)\
        GPIO_configArgs(_hGpioDev0, gpgc, gpen,  gpdir, gpval,   gphm,  gplm,  gppol)
#define GPIO_getConfig(config)  GPIO_getConfig(_hGpioDev0,config)


#define GPIO_pinEnable(pinId)  GPIO_pinEnable(_hGpioDev0,pinId)

#define GPIO_pinDisable(pinId) GPIO_pinDisable(_hGpioDev0, pinId)
#define GPIO_pinDirection(pinId,direction) GPIO_pinDirection(_hGpioDev0,pinId,direction)


#define GPIO_pinRead( pinId) GPIO_pinRead(_hGpioDev0, pinId)
#define GPIO_read( pinMask) GPIO_read(_hGpioDev0, pinMask)

/* For output Pins */
#define GPIO_pinWrite( pinId,  val) GPIO_pinWrite(_hGpioDev0, pinId,  val)
#define GPIO_write( pinMask,  val)  GPIO_write(_hGpioDev0, pinMask,  val)


/* For input Pins */
#define GPIO_deltaHighGet( pinId) GPIO_deltaHighGet(_hGpioDev0, pinId)
#define GPIO_deltaHighClear( pinId) GPIO_deltaHighClear(_hGpioDev0, pinId)
#define GPIO_deltaLowGet( pinId) GPIO_deltaLowGet(_hGpioDev0, pinId)
#define GPIO_deltaLowClear( pinId) GPIO_deltaLowClear(_hGpioDev0, pinId)

#define GPIO_maskHighSet( pinId) GPIO_maskHighSet(_hGpioDev0, pinId)
#define GPIO_maskHighClear( pinId) GPIO_maskHighClear(_hGpioDev0, pinId)
#define GPIO_maskLowSet( pinId) GPIO_maskLowSet(_hGpioDev0, pinId)
#define GPIO_maskLowClear( pinId) GPIO_maskLowClear(_hGpioDev0, pinId)

/* Pass Through Mode */
#define GPIO_intPolarity(signal,polarity) GPIO_intPolarity(_hGpioDev0, signal,  polarity)

#endif



#if (HPI_SUPPORT)
  //#define HPI_Init             HPI_init      
  #define HPI_Init()
  #define HPI_GetEventId       HPI_getEventId      
  #define HPI_GetHwob          HPI_getHwob      
  #define HPI_GetDspint        HPI_getDspint      
  #define HPI_GetHint          HPI_getHint      
  #define HPI_GetHrdy          HPI_getHrdy      
  #define HPI_GetFetch         HPI_getFetch      
  #define HPI_SetDspint        HPI_setDspint      
  #define HPI_SetHint          HPI_setHint      
#endif /* HPI_SUPPORT */

#if (IRQ_SUPPORT)
  #define IntMask              intMask         
  #define IRQ_EVENT            IRQ_Event         
  #define IRQ_EventTable       IRQ_eventTable         
  #define IRQ_IntTable         IRQ_intTable         
  //#define IRQ_Init             IRQ_init  
  #define IRQ_Init()                  
  #define IRQ_Map              IRQ_map         
  #define IRQ_Enable           IRQ_enable         
  #define IRQ_Disable          IRQ_disable         
  #define IRQ_Set              IRQ_set         
  #define IRQ_Clear            IRQ_clear         
  #define IRQ_Test             IRQ_test         
  #define IRQ_DisableGie       IRQ_globalDisable
  #define IRQ_RestoreGie       IRQ_globalRestore
#endif /* IRQ_SUPPORT */

#if (MCBSP_SUPPORT)

  #define BaseAddr              baseAddr 
  #define MCBSP_PRIVATE_OBJ    MCBSP_PrivateObj        
  #define MCBSP_HANDLE         MCBSP_Handle        
  #define MCBSP_CONFIG         MCBSP_Config        
  #define MCBSP_HDEV0          _MCBSP_hDev0        
  #define MCBSP_HDEV1          _MCBSP_hDev1        
  #define MCBSP_HDEV2          _MCBSP_hDev2        
  #define MCBSP_Reset          MCBSP_reset        
  #define MCBSP_Open           MCBSP_open         
  #define MCBSP_Close          MCBSP_close        
  #define MCBSP_ConfigA        MCBSP_config
  #define MCBSP_ConfigB        MCBSP_configArgs
  #define MCBSP_GetPins        MCBSP_getPins        
  #define MCBSP_SetPins        MCBSP_setPins        
  //#define MCBSP_Init           MCBSP_init         
  #define MCBSP_Init()  
  #define MCBSP_GetXmtAddr     MCBSP_getXmtAddr        
  #define MCBSP_GetRcvAddr     MCBSP_getRcvAddr        
  #define MCBSP_GetXmtEventId  MCBSP_getXmtEventId        
  #define MCBSP_GetRcvEventId  MCBSP_getRcvEventId        
  #define MCBSP_Read           MCBSP_read 
  #define MCBSP_Write          MCBSP_write   
  #define MCBSP_EnableXmt      MCBSP_enableXmt        
  #define MCBSP_EnableRcv      MCBSP_enableRcv        
  #define MCBSP_EnableFsync    MCBSP_enableFsync        
  #define MCBSP_EnableSrgr     MCBSP_enableSrgr        
  #define MCBSP_Xrdy           MCBSP_xrdy         
  #define MCBSP_Rrdy           MCBSP_rrdy         
  #define MCBSP_Xempty         MCBSP_xempty        
  #define MCBSP_Rfull          MCBSP_rfull        
  #define MCBSP_XsyncErr       MCBSP_xsyncerr        
  #define MCBSP_RsyncErr       MCBSP_rsyncerr        

  #define MCBSP_SPCR_DXENA_NA               (0x00000000)
  #define MCBSP_RCR_RWDREVRS_NA             (0x00000000)
  #define MCBSP_RCR_RPHASE2_NA              (0x00000000)
  #define MCBSP_RCR_RPHASE2_NORMAL          (0x00000000)
  #define MCBSP_RCR_RPHASE2_OPPOSITE        (0x00000000)
  #define MCBSP_XCR_XWDREVRS_NA             (0x00000000)
  #define MCBSP_XCR_XPHASE2_NA              (0x00000000)
  #define MCBSP_XCR_XPHASE2_NORMAL          (0x00000000)
  #define MCBSP_XCR_XPHASE2_OPPOSITE        (0x00000000)

  #define MCBSP_DRR_OFFSET   0
  #define MCBSP_DXR_OFFSET   1
  #define MCBSP_SPCR_OFFSET  2
  #define MCBSP_RCR_OFFSET   3
  #define MCBSP_XCR_OFFSET   4
  #define MCBSP_SRGR_OFFSET  5
  #define MCBSP_MCR_OFFSET   6
  #define MCBSP_RCER_OFFSET  7
  #define MCBSP_XCER_OFFSET  8
  #define MCBSP_PCR_OFFSET   9

  #define MCBSP_ALLOCATED(hMcbsp) ((hMcbsp)->Allocated)
  #define MCBSP_XMTEVENTID(hMcbsp) ((hMcbsp)->XmtEventId)
  #define MCBSP_RCVEVENTID(hMcbsp) ((hMcbsp)->RcvEventId)
  #define MCBSP_DRR(hMcbsp)  (((hMcbsp)->BaseAddr)[MCBSP_DRR_OFFSET])
  #define MCBSP_DXR(hMcbsp)  (((hMcbsp)->BaseAddr)[MCBSP_DXR_OFFSET])
  #define MCBSP_SPCR(hMcbsp) (((hMcbsp)->BaseAddr)[MCBSP_SPCR_OFFSET])
  #define MCBSP_RCR(hMcbsp)  (((hMcbsp)->BaseAddr)[MCBSP_RCR_OFFSET])
  #define MCBSP_XCR(hMcbsp)  (((hMcbsp)->BaseAddr)[MCBSP_XCR_OFFSET])
  #define MCBSP_SRGR(hMcbsp) (((hMcbsp)->BaseAddr)[MCBSP_SRGR_OFFSET])
  #define MCBSP_MCR(hMcbsp)  (((hMcbsp)->BaseAddr)[MCBSP_MCR_OFFSET])
  #define MCBSP_RCER(hMcbsp) (((hMcbsp)->BaseAddr)[MCBSP_RCER_OFFSET])
  #define MCBSP_XCER(hMcbsp) (((hMcbsp)->BaseAddr)[MCBSP_XCER_OFFSET])
  #define MCBSP_PCR(hMcbsp)  (((hMcbsp)->BaseAddr)[MCBSP_PCR_OFFSET])


  #define MCBSP_MK_SPCR(rrst,rintm,dxena,clkstp,rjust,dlb,xrst,xintm,grst,\
    frst) ((Uint32)( \
      HFIELD_SHIFT(HMCBSP_SPCR_RRST,rrst)| \
      HFIELD_SHIFT(HMCBSP_SPCR_RINTM,rintm)| \
      HFIELD_SHIFT(HMCBSP_SPCR_DXENA,dxena)| \
      HFIELD_SHIFT(HMCBSP_SPCR_CLKSTP,clkstp)| \
      HFIELD_SHIFT(HMCBSP_SPCR_RJUST,rjust)| \
      HFIELD_SHIFT(HMCBSP_SPCR_DLB,dlb)| \
      HFIELD_SHIFT(HMCBSP_SPCR_XRST,xrst)| \
      HFIELD_SHIFT(HMCBSP_SPCR_XINTM,xintm)| \
      HFIELD_SHIFT(HMCBSP_SPCR_GRST,grst)| \
      HFIELD_SHIFT(HMCBSP_SPCR_FRST,frst) \
    ) \
  )


/******** redefined for CSL 1.2 / 1.23 ************/
  #define _MCBSP_RCR_RPHASE2_MASK      0x00008000u
  #define _MCBSP_RCR_RPHASE2_SHIFT     0x0000000Fu
  #define  MCBSP_RCR_RPHASE2_DEFAULT   0x00000000u
  #define  MCBSP_RCR_RPHASE2_OF(x)     _VALUEOF(x)
  
  #define _MCBSP_XCR_XPHASE2_MASK      0x00008000u
  #define _MCBSP_XCR_XPHASE2_SHIFT     0x0000000Fu
  #define  MCBSP_XCR_XPHASE2_DEFAULT   0x00000000u
  #define  MCBSP_XCR_XPHASE2_OF(x)     _VALUEOF(x)



  #define MCBSP_MK_RCR(rwdrevrs,rwdlen1,rfrlen1,rphase2,rdatdly,rfig,\
    rcompand,rwdlen2,rfrlen2,rphase) ((Uint32)(\
      HFIELD_SHIFT(HMCBSP_RCR_RWDREVRS,rwdrevrs)|\
      HFIELD_SHIFT(HMCBSP_RCR_RWDLEN1,rwdlen1)|\
      HFIELD_SHIFT(HMCBSP_RCR_RFRLEN1,rfrlen1)|\
      HFIELD_SHIFT(HMCBSP_RCR_RPHASE2,rphase2)|\
      HFIELD_SHIFT(HMCBSP_RCR_RDATDLY,rdatdly)|\
      HFIELD_SHIFT(HMCBSP_RCR_RFIG,rfig)|\
      HFIELD_SHIFT(HMCBSP_RCR_RCOMPAND,rcompand)|\
      HFIELD_SHIFT(HMCBSP_RCR_RWDLEN2,rwdlen2)|\
      HFIELD_SHIFT(HMCBSP_RCR_RFRLEN2,rfrlen2)|\
      HFIELD_SHIFT(HMCBSP_RCR_RPHASE,rphase)\
    ) \
  )

  #define MCBSP_MK_XCR(xwdrevrs,xwdlen1,xfrlen1,xphase2,xdatdly,xfig,\
    xcompand,xwdlen2,xfrlen2,xphase) ((Uint32)(\
      HFIELD_SHIFT(HMCBSP_XCR_XWDREVRS,xwdrevrs)|\
      HFIELD_SHIFT(HMCBSP_XCR_XWDLEN1,xwdlen1)|\
      HFIELD_SHIFT(HMCBSP_XCR_XFRLEN1,xfrlen1)|\
      HFIELD_SHIFT(HMCBSP_XCR_XPHASE2,xphase2)|\
      HFIELD_SHIFT(HMCBSP_XCR_XDATDLY,xdatdly)|\
      HFIELD_SHIFT(HMCBSP_XCR_XFIG,xfig)|\
      HFIELD_SHIFT(HMCBSP_XCR_XCOMPAND,xcompand)|\
      HFIELD_SHIFT(HMCBSP_XCR_XWDLEN2,xwdlen2)|\
      HFIELD_SHIFT(HMCBSP_XCR_XFRLEN2,xfrlen2)|\
      HFIELD_SHIFT(HMCBSP_XCR_XPHASE,xphase)\
    ) \
  )

  /* make SRGR register value based on symbolic constants */
  #define MCBSP_MK_SRGR(clkgdv,fwid,fper,fsgm,clksm,clksp,gsync) (\
    (Uint32)(\
      HFIELD_SHIFT(HMCBSP_SRGR_CLKGDV,clkgdv)|\
      HFIELD_SHIFT(HMCBSP_SRGR_FWID,fwid)|\
      HFIELD_SHIFT(HMCBSP_SRGR_FPER,fper)|\
      HFIELD_SHIFT(HMCBSP_SRGR_FSGM,fsgm)|\
      HFIELD_SHIFT(HMCBSP_SRGR_CLKSM,clksm)|\
      HFIELD_SHIFT(HMCBSP_SRGR_CLKSP,clksp)|\
      HFIELD_SHIFT(HMCBSP_SRGR_GSYNC,gsync)\
    )\
  )
  
  #define MCBSP_MK_MCR(rmcm,rpablk,rpbblk,xmcm,xpablk,xpbblk)\
    ((Uint32)(\
      HFIELD_SHIFT(HMCBSP_MCR_RMCM,rmcm)|\
      HFIELD_SHIFT(HMCBSP_MCR_RPABLK,rpablk)|\
      HFIELD_SHIFT(HMCBSP_MCR_RPBBLK,rpbblk)|\
      HFIELD_SHIFT(HMCBSP_MCR_XMCM,xmcm)|\
      HFIELD_SHIFT(HMCBSP_MCR_XPABLK,xpablk)|\
      HFIELD_SHIFT(HMCBSP_MCR_XPBBLK,xpbblk)\
    )\
  )
  
  #define MCBSP_MK_RCER(rcea,rceb) (\
    (Uint32)(\
      (((Uint32)(rcea))&0x0000FFFF)|\
      ((((Uint32)(rceb))<<16)&0xFFFF0000)\
    )\
  )
  
  #define MCBSP_MK_XCER(xcea,xceb) (\
    (Uint32)(\
      (((Uint32)(xcea))&0x0000FFFF)|\
      ((((Uint32)(xceb))<<16)&0xFFFF0000)\
      )\
  )

  #define MCBSP_MK_PCR(clkrp,clkxp,fsrp,fsxp,dxstat,clksstat,clkrm,clkxm,\
    fsrm,fsxm,rioen,xioen) ((Uint32)(\
      HFIELD_SHIFT(HMCBSP_PCR_CLKRP,clkrp)|\
      HFIELD_SHIFT(HMCBSP_PCR_CLKXP,clkxp)|\
      HFIELD_SHIFT(HMCBSP_PCR_FSRP,fsrp)|\
      HFIELD_SHIFT(HMCBSP_PCR_FSXP,fsxp)|\
      HFIELD_SHIFT(HMCBSP_PCR_DXSTAT,dxstat)|\
      HFIELD_SHIFT(HMCBSP_PCR_CLKSSTAT,clksstat)|\
      HFIELD_SHIFT(HMCBSP_PCR_CLKRM,clkrm)|\
      HFIELD_SHIFT(HMCBSP_PCR_CLKXM,clkxm)|\
      HFIELD_SHIFT(HMCBSP_PCR_FSRM,fsrm)|\
      HFIELD_SHIFT(HMCBSP_PCR_FSXM,fsxm)|\
      HFIELD_SHIFT(HMCBSP_PCR_RIOEN,rioen)|\
      HFIELD_SHIFT(HMCBSP_PCR_XIOEN,xioen)\
    )\
  )
#endif /* MCBSP_SUPPORT */

#if (PWR_SUPPORT)
  #define PWR_MODE             PWR_Mode     
  //#define PWR_Init             PWR_init     
  #define PWR_Init() 
  #define PWR_PowerDown        PWR_powerDown    
  #define PWR_ConfigB          PWR_configArgs

  #define PWR_MK_PDCTL(dma,emif,mcbsp0,mcbsp1,mcbsp2) ((Uint32)( \
      HFIELD_SHIFT(HPWR_PDCTL_DMA,dma)|\
      HFIELD_SHIFT(HPWR_PDCTL_EMIF,emif)|\
      HFIELD_SHIFT(HPWR_PDCTL_MCBSP0,mcbsp0)|\
      HFIELD_SHIFT(HPWR_PDCTL_MCBSP1,mcbsp1)|\
      HFIELD_SHIFT(HPWR_PDCTL_MCBSP2,mcbsp2)\
    )\
  )
#endif /* PWR_SUPPORT */


#if (1)
  #define UINT8                Uint8   
  #define UINT16               Uint16   
  #define UINT32               Uint32   
  #define UINT40               Uint40   
  #define INT8                 Int8   
  #define INT16                Int16   
  #define INT32                Int32   
  #define INT40                Int40   
  #define BOOL                 int
  #define HANDLE               Handle   
#endif

#if (TIMER_SUPPORT)
  #define TIMER_PRIVATE_OBJ    TIMER_PrivateObj       
  #define TIMER_HANDLE         TIMER_Handle       
  #define TIMER_CONFIG         TIMER_Config       
  #define TIMER_HDEV0          _TIMER_hDev0       
  #define TIMER_HDEV1          _TIMER_hDev1       
  #define TIMER_Reset          TIMER_reset       
  #define TIMER_Open           TIMER_open       
  #define TIMER_Close          TIMER_close       
  #define TIMER_ConfigA        TIMER_config
  #define TIMER_ConfigB        TIMER_configArgs
  //#define TIMER_Init           TIMER_init       
  #define TIMER_Init()
  #define TIMER_GetEventId     TIMER_getEventId       
  #define TIMER_Start          TIMER_start       
  #define TIMER_Pause          TIMER_pause       
  #define TIMER_Resume         TIMER_resume       
  #define TIMER_GetPeriod      TIMER_getPeriod       
  #define TIMER_SetPeriod      TIMER_setPeriod       
  #define TIMER_GetCount       TIMER_getCount       
  #define TIMER_SetCount       TIMER_setCount       
  #define TIMER_GetDatin       TIMER_getDatIn       
  #define TIMER_SetDatout      TIMER_setDatOut       
  #define TIMER_GetTstat       TIMER_getTStat       

  /* make CTL register value based on symbolic constants */
  #define TIMER_MK_CTL(func,invout,datout,pwid,go,hld,cp,clksrc,invinp)\
    ((Uint32)( \
      HFIELD_SHIFT(HTIMER_CTL_FUNC,func)|\
      HFIELD_SHIFT(HTIMER_CTL_INVOUT,invout)|\
      HFIELD_SHIFT(HTIMER_CTL_DATOUT,datout)|\
      HFIELD_SHIFT(HTIMER_CTL_PWID,pwid)|\
      HFIELD_SHIFT(HTIMER_CTL_GO,go)|\
      HFIELD_SHIFT(HTIMER_CTL_HLD,hld)|\
      HFIELD_SHIFT(HTIMER_CTL_CP,cp)|\
      HFIELD_SHIFT(HTIMER_CTL_CLKSRC,clksrc)|\
      HFIELD_SHIFT(HTIMER_CTL_INVINP,invinp)\
    ) \
  )
#endif /* TIMER_SUPPORT */


/******************************************************************************\
* global typedef declarations
\******************************************************************************/

#if (DMA_SUPPORT&&0)
  typedef enum {
    DMA_GBL_ADDRRLD = 0x00,
    DMA_GBL_INDEX   = 0x04,
    DMA_GBL_CNTRLD  = 0x08,
    DMA_GBL_SPLIT   = 0x0C
  } DMA_Gbl;
#endif /* DMA_SUPPORT */

#if (EMIF_SUPPORT)
/* device configuration structure */
typedef struct {
  UINT32 gblctl;
  UINT32 ce0ctl;
  UINT32 ce1ctl;
  UINT32 ce2ctl;
  UINT32 ce3ctl;
  UINT32 sdctl;
  UINT32 sdtim;
  UINT32 sdext;
} EMIF_CONFIG;
#endif /* EMIF_SUPPORT */


/******************************************************************************\
* global variable declarations
\******************************************************************************/
#if (DMA_SUPPORT&&0)
  extern far Uint32 _DMA_gblRegTbl[_DMA_GBLREG_CNT];
#endif /* DMA_SUPPORT */


/******************************************************************************\
* global function declarations
\******************************************************************************/
#if (DMA_SUPPORT&&0)
  CSLAPI Uint32 DMA_allocGlobalReg(DMA_Gbl regType, Uint32 initVal);
  CSLAPI void   DMA_freeGlobalReg(Uint32 regId);
#endif /* DMA_SUPPORT */
  
#if (EMIF_SUPPORT)
  CSLAPI void EMIF_ConfigA(EMIF_CONFIG *Config);
  CSLAPI void EMIF_ConfigB(UINT32 gblctl, UINT32 ce0ctl, UINT32 ce1ctl,
    UINT32 ce2ctl, UINT32 ce3ctl, UINT32 sdctl, UINT32 sdtim, UINT32 sdext);
#endif

/******************************************************************************\
* inline function declarations
\******************************************************************************/
#if (DMA_SUPPORT&&0)
  IDECL Uint32 DMA_getGlobalRegAddr(Uint32 regId);
  IDECL Uint32 DMA_getGlobalReg(Uint32 regId);
  IDECL void   DMA_setGlobalReg(Uint32 regId, Uint32 val);
#endif /* DMA_SUPPORT */


/******************************************************************************\
* inline function definitions
\******************************************************************************/
#ifdef USEDEFS
#if (DMA_SUPPORT&&0)
/*----------------------------------------------------------------------------*/
IDEF Uint32 DMA_getGlobalRegAddr(Uint32 regId) {
  return _DMA_gblRegTbl[regId&_DMA_GBLREG_MASK];
}
/*----------------------------------------------------------------------------*/
IDEF Uint32 DMA_getGlobalReg(Uint32 regId) {
  return REG32(_DMA_gblRegTbl[regId&_DMA_GBLREG_MASK]);
}
/*----------------------------------------------------------------------------*/
IDEF void DMA_setGlobalReg(Uint32 regId, Uint32 val) {
  REG32(_DMA_gblRegTbl[regId&_DMA_GBLREG_MASK])=val;
}
/*----------------------------------------------------------------------------*/
#endif /* DMA_SUPPORT */
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */


#endif /* _CSL_LEGACY_H_ */
/******************************************************************************\
* End of csl_legacy.h
\******************************************************************************/

