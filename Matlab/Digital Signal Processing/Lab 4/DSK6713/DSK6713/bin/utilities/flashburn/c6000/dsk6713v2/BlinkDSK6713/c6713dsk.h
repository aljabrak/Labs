/*******************************************************************************
* FILENAME
*   c6416teb.h
*
* DESCRIPTION
*   TEB Header File
*
* NOTES:
*
*******************************************************************************/
#ifndef c6416teb_h
#define c6416teb_h

// Include CSL.  This assumes CSL v2.1 for support of C64xx EMIF A and B.
#include "csl.h"
#include "csl_emifa.h"
#include "csl_emifb.h"
#include "csl_timer.h"
#include "csl_mcbsp.h"
 

// Misc. other definitions for memory test not defined else where
#define INTERNAL_MEM_SIZE  (0x4000)>>2
#define INTERNAL_MEM_START 0x00010000
#define ALL_A			    0xaaaaaaaa
#define ALL_5			    0x55555555
#define ALT_A5			    0xa5a5a5a5
#define ALT_5A			    0x5a5a5a5a

#endif
