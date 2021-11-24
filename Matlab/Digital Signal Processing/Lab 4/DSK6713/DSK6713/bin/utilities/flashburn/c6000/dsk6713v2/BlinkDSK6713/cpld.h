/*H***************************************************************************
*
* $Archive::                                                                $
* $Revision::                                                               $
* $Date::                                                                   $
* $Author::                                                                 $
*
* DESCRIPTION:
*
* USAGE/LIMITATIONS:
*
* NOTES:
*   
*
*H***************************************************************************/

#ifndef cpld_h
#define cpld_h

/*---- compilation control switches ----------------------------------------*/

/*****************************************************************************
* INCLUDE FILES (minimize nesting of header files)
*****************************************************************************/

/*---- system and platform files -------------------------------------------*/

/*---- program files -------------------------------------------------------*/

/*****************************************************************************
* FILE CONTENT
*****************************************************************************/

/*****************************************************************************
* FUNCTIONAL AREA DETAIL
*****************************************************************************/

/*---- context -------------------------------------------------------------*/
#define LED_NONE                 0x00
#define LED_0                    0x01
#define LED_1                    0x02
#define LED_2                    0x04
#define LED_3                    0x08
#define LED_ALL                  0x0F

#define LED_AVAILABLE               4

#define SWITCH_0                 0x01
#define SWITCH_1                 0x02
#define SWITCH_2                 0x04
#define SWITCH_3                 0x08
#define SWITCH_ALL               0x0F
#define SWITCH_AVAILABLE            4

#define DC_REG_CNTL0             0x01
#define DC_REG_CNTL1             0x02
#define DC_REG_NU0               0x04
#define DC_REG_RESET             0x08
#define DC_REG_STAT0             0x10
#define DC_REG_STAT1             0x20
#define DC_REG_NU1               0x40
#define DC_REG_DETECT            0x80

#define MISC_REG_LIL_ENDIAN      0x01
#define MISC_REG_ROM_BOOT        0x02
#define MISC_REG_UTOPIA_EN       0x04
#define MISC_REG_CNTL_EN         0x08
#define MISC_REG_NU0             0x10
#define MISC_REG_NU1             0x20
#define MISC_REG_NU2             0x40
#define MISC_REG_CODEC_MT_RDY    0x80

/*---- data descriptions ---------------------------------------------------*/

typedef struct _board_version
{
	int BoardVersion;
	int FpgaVersion;
} BOARD_VERSION;

/*---- global function prototypes ------------------------------------------*/
#ifdef GLOBAL
    #undef GLOBAL
#endif
#ifdef cpld_c
   #define GLOBAL 
#else
   #define GLOBAL extern
#endif

GLOBAL void    CPLD_Version( BOARD_VERSION * pVersion );
GLOBAL int     CPLD_LedOn(  int LedMask );
GLOBAL int     CPLD_LedOff( int LedMask );
GLOBAL int     CPLD_ReadSwitch( void );
GLOBAL int     CPLD_ReadMisc( void );
GLOBAL int     CPLD_ReadDc( void );
GLOBAL int     CPLD_WriteDc( int DcReg );
GLOBAL int     CPLD_IsCodecReady( void );
GLOBAL int     CPLD_WriteCodecMode( int ModeVal );

#endif /* cpld_h  --------- END OF FILE ------------------------------------*/

