/*****************************************************************************\
*           Copyright (C) 1999-2003 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_mdiohal.h
* DATE CREATED.. 02/08/2002
* LAST MODIFIED. 03/05/2003
*------------------------------------------------------------------------------
* REGISTERS/PARAMETERS
*
* VERSION           - Module Version Register
* CONTROL           - Module Control Register
* ALIVE             - PHY "Alive" Indication Register
* LINK              - PHY Link Status Register
* LINKINTRAW        - Link Status Change Interrupt Register
* LINKINTMASKED     - Link Status Change Interrupt Register (Masked)
* USERINTRAW        - User Command Complete Interrupt
* USERINTMASKED     - User Command Complete Interrupt (Masked)
* USERINTMASKSET    - Enable User Command Complete Interrupt Mask
* USERINTMASKCLEAR  - Disable User Command Complete Interrupt Mask
* USERACCESS0       - User Access Register 0
* USERPHYSEL0       - User PHY Select Register 0
* USERACCESS1       - User Access Register 1
* USERPHYSEL1       - User PHY Select Register 1
*
*\******************************************************************************/
#ifndef _CSL_MDIOHAL_H
#define _CSL_MDIOHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>

#if (MDIO_SUPPORT)

/******************************************************************************\
* MDIO Register section
\******************************************************************************/

#define _MDIO_BASE_ADDR   0x01c83800u


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

/* ----------------- */
/* FIELD MAKE MACROS */
/* ----------------- */

// User Supplied Value
#define MDIO_FMK(REG,FIELD,x)\
  ((x<<_MDIO_##REG##_##FIELD##_SHIFT)&_MDIO_##REG##_##FIELD##_MASK)

// Symbolic Value Name
#define MDIO_FMKS(REG,FIELD,SYM)\
  ((MDIO_##REG##_##FIELD##_##SYM<<_MDIO_##REG##_##FIELD##_SHIFT)\
  &_MDIO_##REG##_##FIELD##_MASK)

// MAC Index Flag Flag
#define MDIO_FMKMIF(MACINDEX)    (1u<<(MACINDEX))


/* -------------------------------- */
/* RAW REGISTER/FIELD ACCESS MACROS */
/* -------------------------------- */

#define MDIO_ADDR(REG)\
    _MDIO_##REG##_ADDR

#define MDIO_REG(REG)\
    *(volatile Uint32*)(_MDIO_##REG##_ADDR)

// Standard Registers
#define MDIO_RGET(REG)\
    (*(volatile Uint32*)(_MDIO_##REG##_ADDR))

#define MDIO_RSET(REG,x)\
    (*(volatile Uint32*)(_MDIO_##REG##_ADDR)=(x))

#define MDIO_FGET(REG,FIELD)\
    ((MDIO_RGET(REG)&_MDIO_##REG##_##FIELD##_MASK)\
    >>_MDIO_##REG##_##FIELD##_SHIFT)

#define MDIO_FSET(REG,FIELD,x)\
    MDIO_RSET(REG,(MDIO_RGET(REG)&~_MDIO_##REG##_##FIELD##_MASK)|\
    MDIO_FMK(REG,FIELD,x))

#define MDIO_FSETS(REG,FIELD,SYM)\
    MDIO_RSET(REG,(MDIO_RGET(REG)&~_MDIO_##REG##_##FIELD##_MASK)|\
    MDIO_FMKS(REG,FIELD,SYM))



/******************************************************************************\
* _____________________
* |                   |
* |  VERSION          |
* |___________________|
*
* TXIDVER           - TX Identification and Version Register
*
* FIELDS (msb -> lsb)
* (r)   MODID       - Module Id
* (r)   REVMAJ      - Major Revision
* (r)   REVMIN      - Minor Revision
*
* MACROS SUPPORTED
*  MDIO_FMK     y
*  MDIO_FMKS    .
*  MDIO_FMKMIF  .
*  MDIO_ADDR    y
*  MDIO_REG     y
*  MDIO_RGET    y
*  MDIO_RSET    y
*  MDIO_FGET    y
*  MDIO_FSET    y
*  MDIO_FSETS   .
*
\******************************************************************************/
#define _MDIO_VERSION_ADDR                      (_MDIO_BASE_ADDR+0x0000u)

#define MDIO_VERSION                            MDIO_REG(VERSION)

#define _MDIO_VERSION_MODID_MASK                0xFFFF0000u
#define _MDIO_VERSION_MODID_SHIFT               16u
#define  MDIO_VERSION_MODID_DEFAULT		0x00000007u	

#define _MDIO_VERSION_REVMAJ_MASK               0x0000FF00u
#define _MDIO_VERSION_REVMAJ_SHIFT              8u
#define  MDIO_VERSION_REVMAJ_DEFAULT		0x00000000u	

#define _MDIO_VERSION_REVMIN_MASK               0x000000FFu
#define _MDIO_VERSION_REVMIN_SHIFT              0u
#define	 MDIO_VERSION_REVMIN_DEFAULT		0x00000000u	



/******************************************************************************\
* _____________________
* |                   |
* |    CONTROL        |
* |___________________|
*
* CONTROL           - MDIO Control Register
*
* FIELDS (msb -> lsb)
* (r)   IDLE        - MDIO State Machine Idle
* (rw)  ENABLE      - Enable Control
* (rw)  PREAMBLE    - Preamble Disable
* (rwc) FAULT       - Fault Indicator
* (rw)  FAULTENB    - Fault Detect Enable
* (rw)  INTTESTENB  - Link Test Enable
* (rw)  CLKDIV      - Clock Divider
*
*
* MACROS SUPPORTED
*  MDIO_FMK     y
*  MDIO_FMKS    y
*  MDIO_FMKMIF  .
*  MDIO_ADDR    y
*  MDIO_REG     y
*  MDIO_RGET    y
*  MDIO_RSET    y
*  MDIO_FGET    y
*  MDIO_FSET    y
*  MDIO_FSETS   y
*
\******************************************************************************/
#define _MDIO_CONTROL_ADDR                      (_MDIO_BASE_ADDR+0x0004u)

#define MDIO_CONTROL                            MDIO_REG(TXCONTROL)

#define _MDIO_CONTROL_IDLE_MASK                 0x80000000u
#define _MDIO_CONTROL_IDLE_SHIFT                31u
#define  MDIO_CONTROL_IDLE_DEFAULT		0x00000001u	
#define MDIO_CONTROL_IDLE_YES                   1u
#define MDIO_CONTROL_IDLE_NO                    0u

#define _MDIO_CONTROL_ENABLE_MASK               0x40000000u
#define _MDIO_CONTROL_ENABLE_SHIFT              30u
#define  MDIO_CONTROL_ENABLE_DEFAULT		0x00000000u	
#define MDIO_CONTROL_ENABLE_YES                 1u
#define MDIO_CONTROL_ENABLE_NO                  0u

#define _MDIO_CONTROL_PREAMBLE_MASK             0x00100000u
#define _MDIO_CONTROL_PREAMBLE_SHIFT            20u
#define  MDIO_CONTROL_PREAMBLE_DEFAULT		0x00000000u	
#define MDIO_CONTROL_PREAMBLE_DISABLED          1u
#define MDIO_CONTROL_PREAMBLE_ENABLED           0u

#define _MDIO_CONTROL_FAULT_MASK                0x00080000u
#define _MDIO_CONTROL_FAULT_SHIFT               19u
#define  MDIO_CONTROL_FAULT_DEFAULT		0x00000000u	
#define MDIO_CONTROL_FAULT_YES                  1u
#define MDIO_CONTROL_FAULT_NO                   0u

#define _MDIO_CONTROL_FAULTENB_MASK             0x00040000u
#define _MDIO_CONTROL_FAULTENB_SHIFT            18u
#define  MDIO_CONTROL_FAULTENB_DEFAULT		0x00000000u	
#define MDIO_CONTROL_FAULTENB_YES               1u
#define MDIO_CONTROL_FAULTENB_NO                0u

#define _MDIO_CONTROL_INTTESTENB_MASK           0x00020000u
#define _MDIO_CONTROL_INTTESTENB_SHIFT          17u
#define  MDIO_CONTROL_INTTESTENB_DEFAULT	0x00000000u	
#define MDIO_CONTROL_INTTESTENB_YES             1u
#define MDIO_CONTROL_INTTESTENB_NO              0u

#define _MDIO_CONTROL_CLKDIV_MASK               0x000000FFu
#define _MDIO_CONTROL_CLKDIV_SHIFT              0u
#define  MDIO_CONTROL_CLKDIV_DEFAULT		0x000000FFu	



/******************************************************************************\
* _____________________
* |                   |
* |   ALIVE           |
* |   LINK            |
* |___________________|
*
* ALIVE             - PHY "Alive" Indication Register
* LINK              - PHY Link Status Register
*
* FIELDS (msb -> lsb)
*  PHY Index Flags (0-31) (use MDIO_FMKMIF)
*
* MACROS SUPPORTED
*  MDIO_FMK     .
*  MDIO_FMKS    .
*  MDIO_FMKMIF  y
*  MDIO_ADDR    y
*  MDIO_REG     y
*  MDIO_RGET    y
*  MDIO_RSET    y
*  MDIO_FGET    .
*  MDIO_FSET    .
*  MDIO_FSETS   .
*
\******************************************************************************/
#define _MDIO_ALIVE_ADDR                        (_MDIO_BASE_ADDR+0x0008u)
#define _MDIO_LINK_ADDR                         (_MDIO_BASE_ADDR+0x000Cu)

#define MDIO_ALIVE                              MDIO_REG(ALIVE)
#define MDIO_LINK                               MDIO_REG(LINK)



/******************************************************************************\
* _____________________
* |                   |
* | LINKINTRAW        |
* | LINKINTMASKED     |
* | USERINTRAW        |
* | USERINTMASKED     |
* | USERINTMASKSET    |
* | USERINTMASKCLEAR  |
* |___________________|
*
* LINKINTRAW        - Link Status Change Interrupt Register
* LINKINTMASKED     - Link Status Change Interrupt Register (Masked)
* USERINTRAW        - User Command Complete Interrupt
* USERINTMASKED     - User Command Complete Interrupt (Masked)
* USERINTMASKSET    - Enable User Command Complete Interrupt Mask
* USERINTMASKCLEAR  - Disable User Command Complete Interrupt Mask
*
* FIELDS (msb -> lsb)
*       MAC0        - Mac 0 Flag (yes/no)
*       MAC1        - Mac 1 Flag (yes/no)
*
* MACROS SUPPORTED
*  MDIO_FMK     y
*  MDIO_FMKS    y
*  MDIO_FMKMIF  .
*  MDIO_ADDR    y
*  MDIO_REG     y
*  MDIO_RGET    y
*  MDIO_RSET    y
*  MDIO_FGET    y
*  MDIO_FSET    y
*  MDIO_FSETS   .
*
\******************************************************************************/
#define _MDIO_LINKINTRAW_ADDR                   (_MDIO_BASE_ADDR+0x0010u)
#define _MDIO_LINKINTMASKED_ADDR                (_MDIO_BASE_ADDR+0x0014u)
#define _MDIO_USERINTRAW_ADDR                   (_MDIO_BASE_ADDR+0x0020u)
#define _MDIO_USERINTMASKED_ADDR                (_MDIO_BASE_ADDR+0x0024u)
#define _MDIO_USERINTMASKSET_ADDR               (_MDIO_BASE_ADDR+0x0028u)
#define _MDIO_USERINTMASKCLEAR_ADDR             (_MDIO_BASE_ADDR+0x002Cu)

#define MDIO_LINKINTRAW                         MDIO_REG(LINKINT)
#define MDIO_LINKINTMASKED                      MDIO_REG(LINKINTMASKED)
#define MDIO_USERINTRAW                         MDIO_REG(USERINTRAW)
#define MDIO_USERINTMASKED                      MDIO_REG(USERINTMASKED)
#define MDIO_USERINTMASKSET                     MDIO_REG(USERINTMASKSET)
#define MDIO_USERINTMASKCLEAR                   MDIO_REG(USERINTMASKCLEAR)

#define _MDIO_LINKINTRAW_MAC0_MASK              0x00000001u
#define _MDIO_LINKINTRAW_MAC0_SHIFT             0u
#define  MDIO_LINKINTRAW_MAC0_DEFAULT		0x00000000u	
#define _MDIO_LINKINTRAW_MAC1_MASK              0x00000002u
#define _MDIO_LINKINTRAW_MAC1_SHIFT             1u
#define  MDIO_LINKINTRAW_MAC1_DEFAULT		0x00000000u	

#define MDIO_LINKINTRAW_MAC0_YES                1u
#define MDIO_LINKINTRAW_MAC0_NO                 0u
#define MDIO_LINKINTRAW_MAC1_YES                1u
#define MDIO_LINKINTRAW_MAC1_NO                 0u

#define _MDIO_LINKINTMASKED_MAC0_MASK           0x00000001u
#define _MDIO_LINKINTMASKED_MAC0_SHIFT          0u
#define  MDIO_LINKINTMASKED_MAC0_DEFAULT	0x00000000u	
#define _MDIO_LINKINTMASKED_MAC1_MASK           0x00000002u
#define _MDIO_LINKINTMASKED_MAC1_SHIFT          1u
#define  MDIO_LINKINTMASKED_MAC1_DEFAULT	0x00000000u	

#define MDIO_LINKINTMASKED_MAC0_YES             1u
#define MDIO_LINKINTMASKED_MAC0_NO              0u
#define MDIO_LINKINTMASKED_MAC1_YES             1u
#define MDIO_LINKINTMASKED_MAC1_NO              0u

#define _MDIO_USERINTRAW_MAC0_MASK              0x00000001u
#define _MDIO_USERINTRAW_MAC0_SHIFT             0u
#define  MDIO_USERINTRAW_MAC0_DEFAULT		0x00000000u	
#define _MDIO_USERINTRAW_MAC1_MASK              0x00000002u
#define _MDIO_USERINTRAW_MAC1_SHIFT             1u
#define	 MDIO_USERINTRAW_MAC1_DEFAULT		0x00000000u	

#define MDIO_USERINTRAW_MAC0_YES                1u
#define MDIO_USERINTRAW_MAC0_NO                 0u
#define MDIO_USERINTRAW_MAC1_YES                1u
#define MDIO_USERINTRAW_MAC1_NO                 0u

#define _MDIO_USERINTMASKED_MAC0_MASK           0x00000001u
#define _MDIO_USERINTMASKED_MAC0_SHIFT          0u
#define  MDIO_USERINTMASKED_MAC0_DEFAULT	0x00000000u
#define _MDIO_USERINTMASKED_MAC1_MASK           0x00000002u
#define _MDIO_USERINTMASKED_MAC1_SHIFT          1u
#define  MDIO_USERINTMASKED_MAC1_DEFAULT	0x00000000u	

#define MDIO_USERINTMASKED_MAC0_YES             1u
#define MDIO_USERINTMASKED_MAC0_NO              0u
#define MDIO_USERINTMASKED_MAC1_YES             1u
#define MDIO_USERINTMASKED_MAC1_NO              0u

#define _MDIO_USERINTMASKSET_MAC0_MASK          0x00000001u
#define _MDIO_USERINTMASKSET_MAC0_SHIFT         0u
#define  MDIO_USERINTMASKSET_MAC0_DEFAULT	0x00000000u
#define _MDIO_USERINTMASKSET_MAC1_MASK          0x00000002u
#define _MDIO_USERINTMASKSET_MAC1_SHIFT         1u
#define  MDIO_USERINTMASKSET_MAC1_DEFAULT	0x00000000u	

#define MDIO_USERINTMASKSET_MAC0_YES            1u
#define MDIO_USERINTMASKSET_MAC0_NO             0u
#define MDIO_USERINTMASKSET_MAC1_YES            1u
#define MDIO_USERINTMASKSET_MAC1_NO             0u

#define _MDIO_USERINTMASKCLEAR_MAC0_MASK        0x00000001u
#define _MDIO_USERINTMASKCLEAR_MAC0_SHIFT       0u
#define  MDIO_USERINTMASKCLEAR_MAC0_DEFAULT	0x00000000u	
#define _MDIO_USERINTMASKCLEAR_MAC1_MASK        0x00000002u
#define _MDIO_USERINTMASKCLEAR_MAC1_SHIFT       1u
#define  MDIO_USERINTMASKCLEAR_MAC1_DEFAULT	0x00000000u	

#define MDIO_USERINTMASKCLEAR_MAC0_YES          1u
#define MDIO_USERINTMASKCLEAR_MAC0_NO           0u
#define MDIO_USERINTMASKCLEAR_MAC1_YES          1u
#define MDIO_USERINTMASKCLEAR_MAC1_NO           0u



/******************************************************************************\
* _____________________
* |                   |
* |   USERACCESS0     |
* |   USERACCESS1     |
* |___________________|
*
* USERACCESS0       - User Access Register 0
* USERACCESS1       - User Access Register 1
*
* FIELDS (msb -> lsb)
* (rws) GO          - Go Bit
* (rw)  WRITE       - Write Enable
* (r)   ACK         - Acknowledge
* (rw)  REGADR      - PHY Register Address
* (rw)  PHYADR      - PHY Device Address
* (rw)  DATA        - User Data to Read/Write
*
* MACROS SUPPORTED
*  MDIO_FMK     y
*  MDIO_FMKS    .
*  MDIO_FMKMIF  .
*  MDIO_ADDR    y
*  MDIO_REG     y
*  MDIO_RGET    y
*  MDIO_RSET    y
*  MDIO_FGET    y
*  MDIO_FSET    y
*  MDIO_FSETS   .
*
\******************************************************************************/
#define _MDIO_USERACCESS0_ADDR                  (_MDIO_BASE_ADDR+0x0080u)
#define _MDIO_USERACCESS1_ADDR                  (_MDIO_BASE_ADDR+0x0088u)

#define  MDIO_USERACCESS0                       MDIO_REG(USERACCESS0)
#define  MDIO_USERACCESS1                       MDIO_REG(USERACCESS1)

#define _MDIO_USERACCESS0_GO_MASK               0x80000000u
#define _MDIO_USERACCESS0_GO_SHIFT              31u
#define  MDIO_USERACCESS0_GO_DEFAULT		0x00000000u
#define _MDIO_USERACCESS0_WRITE_MASK            0x40000000u
#define _MDIO_USERACCESS0_WRITE_SHIFT           30u
#define  MDIO_USERACCESS0_WRITE_DEFAULT		0x00000000u
#define _MDIO_USERACCESS0_ACK_MASK              0x20000000u
#define _MDIO_USERACCESS0_ACK_SHIFT             29u
#define  MDIO_USERACCESS0_ACK_DEFAULT		0x00000000u
#define _MDIO_USERACCESS0_REGADR_MASK           0x03E00000u
#define _MDIO_USERACCESS0_REGADR_SHIFT          21u
#define  MDIO_USERACCESS0_REGADR_DEFAULT	0x00000000u
#define _MDIO_USERACCESS0_PHYADR_MASK           0x001F0000u
#define _MDIO_USERACCESS0_PHYADR_SHIFT          16u
#define  MDIO_USERACCESS0_PHYADR_DEFAULT	0x00000000u
#define _MDIO_USERACCESS0_DATA_MASK             0x0000FFFFu
#define _MDIO_USERACCESS0_DATA_SHIFT            0u
#define  MDIO_USERACCESS0_DATA_DEFAULT		0x00000000u

#define _MDIO_USERACCESS1_GO_MASK               0x80000000u
#define _MDIO_USERACCESS1_GO_SHIFT              31u
#define  MDIO_USERACCESS1_GO_DEFAULT		0x00000000u
#define _MDIO_USERACCESS1_WRITE_MASK            0x40000000u
#define _MDIO_USERACCESS1_WRITE_SHIFT           30u
#define  MDIO_USERACCESS1_WRITE_DEFAULT		0x00000000u
#define _MDIO_USERACCESS1_ACK_MASK              0x20000000u
#define _MDIO_USERACCESS1_ACK_SHIFT             29u
#define  MDIO_USERACCESS1_ACK_DEFAULT		0x00000000u
#define _MDIO_USERACCESS1_REGADR_MASK           0x03E00000u
#define _MDIO_USERACCESS1_REGADR_SHIFT          21u
#define  MDIO_USERACCESS1_REGADR_DEFAULT	0x00000000u
#define _MDIO_USERACCESS1_PHYADR_MASK           0x001F0000u
#define _MDIO_USERACCESS1_PHYADR_SHIFT          16u
#define  MDIO_USERACCESS1_PHYADR_DEFAULT	0x00000000u
#define _MDIO_USERACCESS1_DATA_MASK             0x0000FFFFu
#define _MDIO_USERACCESS1_DATA_SHIFT            0u
#define  MDIO_USERACCESS1_DATA_DEFAULT		0x00000000u


/******************************************************************************\
* _____________________
* |                   |
* |   USERPHYSEL0     |
* |   USERPHYSEL1     |
* |___________________|
*
* USERPHYSEL0       - User PHY Select Register 0
* USERPHYSEL1       - User PHY Select Register 1
*
* FIELDS (msb -> lsb)
* (rw)  LINKSEL     - Link Detect Type Selection
* (rw)  LINKINTENB  - Link Interrupt Enable
* (rw)  PHYADDR     - Address (0-31) of Phy to Use
*
* MACROS SUPPORTED
*  MDIO_FMK     y
*  MDIO_FMKS    y
*  MDIO_FMKMIF  .
*  MDIO_ADDR    y
*  MDIO_REG     y
*  MDIO_RGET    y
*  MDIO_RSET    y
*  MDIO_FGET    y
*  MDIO_FSET    y
*  MDIO_FSETS   y
*
\******************************************************************************/
#define _MDIO_USERPHYSEL0_ADDR                  (_MDIO_BASE_ADDR+0x0084u)
#define _MDIO_USERPHYSEL1_ADDR                  (_MDIO_BASE_ADDR+0x008Cu)

#define  MDIO_USERPHYSEL0                       MDIO_REG(USERPHYSEL0)
#define  MDIO_USERPHYSEL1                       MDIO_REG(USERPHYSEL1)

#define _MDIO_USERPHYSEL0_LINKSEL_MASK          0x00000080u
#define _MDIO_USERPHYSEL0_LINKSEL_SHIFT         7u
#define  MDIO_USERPHYSEL0_LINKSEL_DEFAULT	0x00000000u
#define MDIO_USERPHYSEL0_LINKSEL_MLINK          1u
#define MDIO_USERPHYSEL0_LINKSEL_MDIO           0u

#define _MDIO_USERPHYSEL0_LINKINTENB_MASK       0x00000040u
#define _MDIO_USERPHYSEL0_LINKINTENB_SHIFT      6u
#define  MDIO_USERPHYSEL0_LINKINTENB_DEFAULT	0x00000000u
#define MDIO_USERPHYSEL0_LINKINTENB_ENABLE      1u
#define MDIO_USERPHYSEL0_LINKINTENB_DISABLE     0u

#define _MDIO_USERPHYSEL0_PHYADDR_MASK          0x0000001Fu
#define _MDIO_USERPHYSEL0_PHYADDR_SHIFT         0u
#define  MDIO_USERPHYSEL0_PHYADDR_DEFAULT	0x00000000u

#define _MDIO_USERPHYSEL1_LINKSEL_MASK          0x00000080u
#define _MDIO_USERPHYSEL1_LINKSEL_SHIFT         7u
#define  MDIO_USERPHYSEL1_LINKSEL_DEFAULT	0x00000000u
#define MDIO_USERPHYSEL1_LINKSEL_MLINK          1u
#define MDIO_USERPHYSEL1_LINKSEL_MDIO           0u

#define _MDIO_USERPHYSEL1_LINKINTENB_MASK       0x00000040u
#define _MDIO_USERPHYSEL1_LINKINTENB_SHIFT      6u
#define  MDIO_USERPHYSEL1_LINKINTENB_DEFAULT	0x00000000u
#define MDIO_USERPHYSEL1_LINKINTENB_ENABLE      1u
#define MDIO_USERPHYSEL1_LINKINTENB_DISABLE     0u

#define _MDIO_USERPHYSEL1_PHYADDR_MASK          0x0000001Fu
#define _MDIO_USERPHYSEL1_PHYADDR_SHIFT         0u
#define  MDIO_USERPHYSEL1_PHYADDR_DEFAULT	0x00000000u


#endif /* MDIO_SUPPORT */

#endif /* _CSL_MDIOHAL_H_ */
/******************************************************************************\
* End of csl_mdiohal.h
\******************************************************************************/




