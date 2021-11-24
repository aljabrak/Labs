/**************************************************************************\
*              Copyright (C) 2002 Texas Instruments Incorporated.
*                             All Rights Reserved
*--------------------------------------------------------------------------
* MODULE NAME... EMU
* FILENAME...... csl_emuhal.h
* DATE CREATED.. 05/12/2003
* LAST MODIFIED. 05/20/2003
* PROJECT....... Chip Support Library
* COMPONENT..... Hardware Abstraction Layer
* PREREQUISITES.
*
*--------------------------------------------------------------------------
* DESCRIPTION:
*        CSL Hardware Abstraction Layer interface for the EMU module
*
*--------------------------------------------------------------------------
* REGISTERS:
*
* DBGSTAT   - DBGSTAT {Debug Status Register}
* MFREG0    - MFREG0 {Miscellaneous Function Register}
\**************************************************************************/

#ifndef _CSL_EMUHAL_H_
#define _CSL_EMUHAL_H_

/**************************************************************************\
* Private Macros and Include files
\**************************************************************************/
#include <csl_stdinchal.h>
#include <csl_chiphal.h>

#if (EMU_SUPPORT)


/**************************************************************************\
* Module level register/field access macros
\**************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */
    #define EMU_FMK(REG, FIELD, x)                                        \
    _PER_FMK(EMU, ##REG, ##FIELD, x)
    #define EMU_FMKS(REG, FIELD, SYM)                                     \
    _PER_FMKS(EMU, ##REG, ##FIELD, ##SYM)

  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */
  #define EMU_ADDR(REG)             _EMU_##REG##_ADDR
    #define EMU_RGET(REG)                                                 \
    _PER_RGET(_EMU_##REG##_ADDR, EMU, ##REG)
    #define EMU_RSET(REG, x)                                              \
    _PER_RSET(_EMU_##REG##_ADDR, EMU, ##REG, x)
  #define EMU_FGET(REG, FLD)        _EMU_##REG##_FGET(##FLD)
  #define EMU_FSET(REG, FLD, x)     _EMU_##REG##_FSET(##FLD, x)
    #define EMU_FSETS(REG, FLD, SYM)                                      \
    _EMU_##REG##_FSETS(##FLD, ##SYM)

  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */
  #define EMU_RGETA(addr, REG)      _PER_RGET(addr, EMU, ##REG)
  #define EMU_RSETA(addr, REG, x)   _PER_RSET(addr, EMU, ##REG,x)
    #define EMU_FGETA(addr, REG, FLD)                                     \
    _PER_FGET(addr, EMU, ##REG,##FLD)
    #define EMU_FSETA(addr, REG, FLD, x)                                  \
    _PER_FSET(addr, EMU, ##REG, ##FLD, x)
    #define EMU_FSETSA(addr, REG, FLD, SYM)                               \
    _PER_FSETS(addr, EMU, ##REG, ##FLD, ##SYM)

  /* ----------------------------------------- */
  /* HANDLE BASED REGISTER/FIELD ACCESS MACROS */
  /* ----------------------------------------- */
    #define EMU_ADDRH(h, REG)                                             \
    ((void *)(&(((EMU_PrivateObj *)h)->baseAddr[_EMU_##REG##_OFFSET])))
    #define EMU_RGETH(h, REG)                                             \
    EMU_RGETA(EMU_ADDRH(h, ##REG), ##REG)
    #define EMU_RSETH(h, REG, x)                                          \
    EMU_RSETA(EMU_ADDRH(h, ##REG), ##REG, x)
    #define EMU_FGETH(h, REG, FIELD)                                      \
    EMU_FGETA(EMU_ADDRH(h, ##REG), ##REG, ##FIELD)
    #define EMU_FSETH(h, REG, FIELD,x)                                    \
    EMU_FSETA(EMU_ADDRH(h, ##REG), ##REG, ##FIELD, x)
    #define EMU_FSETSH(h, REG, FIELD, SYM)                                \
    EMU_FSETSA(EMU_ADDRH(h, ##REG), ##REG, ##FIELD, ##SYM)


/**************************************************************************\
*
* _____________________
* |                   |
* |   D B G S T A T   |
* |___________________|
*
* DBGSTAT - DBGSTAT {Debug Status Register}
*
* FIELDS (msb -> lsb)
*     (r)     DBGMST          Read MFREG0:DBGM state
*     (r)     EALLOWST        Read MFREG0:EALLOW state
\**************************************************************************/

  #define _EMU_DBGSTAT_ADDR         (0x01BC0000)
  #define _EMU_DBGSTAT              (*(Uint32 *)_EMU_DBGSTAT_ADDR)

  #define _EMU_DBGSTAT_DBGMST_MASK  (0x00020000u)
  #define _EMU_DBGSTAT_DBGMST_SHIFT (0x00000011u)

  #define EMU_DBGSTAT_DBGMST_OF(x)  _VALUEOF(x)

    #define _EMU_DBGSTAT_EALLOWST_MASK                                    \
    (0x00010000u)
    #define _EMU_DBGSTAT_EALLOWST_SHIFT                                   \
    (0x00000010u)
    #define EMU_DBGSTAT_EALLOWST_OF(x)                                    \
    _VALUEOF(x)

  #define EMU_DBGSTAT_OF(x)         _VALUEOF(x)


    #define _EMU_DBGSTAT_FGET(FLD)                                        \
    _PER_FGET(_EMU_DBGSTAT_ADDR, EMU, DBGSTAT, ##FLD)
    #define _EMU_DBGSTAT_FSET(FLD, f)                                     \
    _PER_FSET(_EMU_DBGSTAT_ADDR, EMU, DBGSTAT, ##FLD,f)
    #define _EMU_DBGSTAT_FSETS(FLD, SYM)                                  \
    _PER_FSETS(_EMU_DBGSTAT_ADDR, EMU, DBGSTAT, ##FLD, ##SYM)


/**************************************************************************\
*
* _____________________
* |                   |
* |    M F R E G 0    |
* |___________________|
*
* MFREG0 - MFREG0 {Miscellaneous Function Register}
*
* FIELDS (msb -> lsb)
*     (w)     DBGMLD          Load qualifier for the DBGM bit
*     (w)     DBGM            Set a mask to inhibit debug access
*     (w)     ABRTILD         Load qualifier for the ABORTI bit
*     (w)     ABRTI           set the bit to ABORT a lost ISR
*     (w)     EALLOWLD        Load qualifier for the EALLOW bit
*     (w)     EALLOW          Set the bit to allow Emulation access
\**************************************************************************/

  #define _EMU_MFREG0_ADDR          (0x01BC0014)
  #define _EMU_MFREG0               (*(Uint32 *)_EMU_MFREG0_ADDR)

  #define _EMU_MFREG0_DBGMLD_MASK   (0x08000000u)
  #define _EMU_MFREG0_DBGMLD_SHIFT  (0x0000001Bu)
  #define EMU_MFREG0_DBGMLD_OF(x)   _VALUEOF(x)

  #define _EMU_MFREG0_DBGM_MASK     (0x04000000u)
  #define _EMU_MFREG0_DBGM_SHIFT    (0x0000001Au)
  #define EMU_MFREG0_DBGM_OF(x)     _VALUEOF(x)

  #define _EMU_MFREG0_ABRTILD_MASK  (0x00040000u)
  #define _EMU_MFREG0_ABRTILD_SHIFT (0x00000012u)
  #define EMU_MFREG0_ABRTILD_OF(x)  _VALUEOF(x)

  #define _EMU_MFREG0_ABRTI_MASK    (0x00020000u)
  #define _EMU_MFREG0_ABRTI_SHIFT   (0x00000011u)
  #define EMU_MFREG0_ABRTI_OF(x)    _VALUEOF(x)

  #define _EMU_MFREG0_EALLOWLD_MASK (0x00004000u)
    #define _EMU_MFREG0_EALLOWLD_SHIFT                                    \
    (0x0000000Eu)
  #define EMU_MFREG0_EALLOWLD_OF(x) _VALUEOF(x)

  #define _EMU_MFREG0_EALLOW_MASK   (0x00002000u)
  #define _EMU_MFREG0_EALLOW_SHIFT  (0x0000000Du)
  #define EMU_MFREG0_EALLOW_OF(x)   _VALUEOF(x)

  #define EMU_MFREG0_OF(x)          _VALUEOF(x)

  #define EMU_MFREG0_RMK(dbgmld, dbgm, abrtild, abrti, eallowld, eallow) ((Uint32)    (\
                  _PER_FMK(EMU, MFREG0, DBGMLD, dbgmld)                   \
                |_PER_FMK(EMU, MFREG0, DBGM, dbgm)                        \
                |_PER_FMK(EMU, MFREG0, ABRTILD, abrtild)                  \
                |_PER_FMK(EMU, MFREG0, ABRTI, abrti)                      \
                |_PER_FMK(EMU, MFREG0, EALLOWLD, eallowld)                \
                |_PER_FMK(EMU, MFREG0, EALLOW, eallow)                    \
        )                                                                 \
  )

    #define _EMU_MFREG0_FGET(FLD)                                         \
    _PER_FGET(_EMU_MFREG0_ADDR, EMU, MFREG0, ##FLD)
    #define _EMU_MFREG0_FSET(FLD, f)                                      \
    _PER_FSET(_EMU_MFREG0_ADDR, EMU, MFREG0, ##FLD,f)
    #define _EMU_MFREG0_FSETS(FLD, SYM)                                   \
    _PER_FSETS(_EMU_MFREG0_ADDR, EMU, MFREG0, ##FLD, ##SYM)



#endif /* (EMU_SUPPORT) */
#endif /* _CSL_EMUHAL_H_ */

/**************************************************************************\
* End of csl_emuhal.h
\**************************************************************************/
