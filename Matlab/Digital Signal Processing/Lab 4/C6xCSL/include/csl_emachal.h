/*****************************************************************************\
*           Copyright (C) 1999-2003 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_emachal.h
* DATE CREATED.. 02/04/2002
* LAST MODIFIED. 03/05/2003
*------------------------------------------------------------------------------
* REGISTERS/PARAMETERS
*
* TXIDVER           - TX Identification and Version Register
* TXCONTROL         - TX Control Register
* TXTEARDOWN        - TX Teardown Register
* RXIDVER           - RX Identification and Version Register
* RXCONTROL         - RX Control Register
* RXTEARDOWN        - RX Teardown Register
* RXMBPENABLE       - RX Mulicast/Bcast/Promisc Channel Enable Register
* RXUNICASTSET      - RX Unicast Set Register
* RXUNICASTCLEAR    - RX Unicast Clear Register
* RXMAXLEN          - RX Maximum Length Register
* RXBUFFEROFFSET    - RX Buffer Offset Register
* RXFILTERLOWTHRESH - RX Filer Low Priority Packets Threshhold
* RX0FLOWTHRESH     - RX Channel 0 Flow Control Threshhold
* RX1FLOWTHRESH     - RX Channel 1 Flow Control Threshhold
* RX2FLOWTHRESH     - RX Channel 2 Flow Control Threshhold
* RX3FLOWTHRESH     - RX Channel 3 Flow Control Threshhold
* RX4FLOWTHRESH     - RX Channel 4 Flow Control Threshhold
* RX5FLOWTHRESH     - RX Channel 5 Flow Control Threshhold
* RX6FLOWTHRESH     - RX Channel 6 Flow Control Threshhold
* RX7FLOWTHRESH     - RX Channel 7 Flow Control Threshhold
* RX0FREEBUFFER     - RX Channel 0 Free Buffer Count Register
* RX1FREEBUFFER     - RX Channel 1 Free Buffer Count Register
* RX2FREEBUFFER     - RX Channel 2 Free Buffer Count Register
* RX3FREEBUFFER     - RX Channel 3 Free Buffer Count Register
* RX4FREEBUFFER     - RX Channel 4 Free Buffer Count Register
* RX5FREEBUFFER     - RX Channel 5 Free Buffer Count Register
* RX6FREEBUFFER     - RX Channel 6 Free Buffer Count Register
* RX7FREEBUFFER     - RX Channel 7 Free Buffer Count Register
* MACCONTROL        - MAC Control Register
* MACSTATUS         - MAC Status Register
* EMCONTROL         - Emulation Control Register
* TXINTSTATRAW      - TX Interrupt Status Register (Unmasked)
* TXINTSTATMASKED   - TX Interrupt Status Register (Masked)
* TXINTMASKSET      - TX Interrupt Mask Set Register
* TXINTMASKCLEAR    - TX Interrupt Mask Clear Register
* MACINVECTOR       - MAC Input Vector
* MACEOIVECTOR      - MAC EOI Vector
* RXINTSTATRAW      - RX Interrupt Status Register (Unmasked)
* RXINTSTATMASKED   - RX Interrupt Status Register (Masked)
* RXINTMASKSET      - RX Interrupt Mask Set Register
* RXINTMASKCLEAR    - RX Interrupt Mask Clear Register
* MACINTSTATRAW     - MAC Interrupt Status Register (Unmasked)
* MACINTSTATMASKED  - MAC Interrupt Status Register (Masked)
* MACINTMASKSET     - MAC Interrupt Mask Set Register
* MACINTMASKCLEAR   - MAC Interrupt Mask Clear Register
* MACADDRL0         - MAC Address Channel 0 Lower Byte Register
* MACADDRL1         - MAC Address Channel 1 Lower Byte Register
* MACADDRL2         - MAC Address Channel 2 Lower Byte Register
* MACADDRL3         - MAC Address Channel 3 Lower Byte Register
* MACADDRL4         - MAC Address Channel 4 Lower Byte Register
* MACADDRL5         - MAC Address Channel 5 Lower Byte Register
* MACADDRL6         - MAC Address Channel 6 Lower Byte Register
* MACADDRL7         - MAC Address Channel 7 Lower Byte Register
* MACADDRM          - MAC Address Middle Byte Register
* MACADDRH          - MAC Address High Bytes Register
* MACHASH1          - MAC Address Hash 1 Register
* MACHASH2          - MAC Address Hash 2 Register
* BOFFTEST          - Backoff Test Register
* TPACETEST         - Transmit Pacing Test Register
* RXPAUSE           - Receive Pause Timer Register
* TXPAUSE           - Transmit Pause Timer Register
* RXGOODFRAMES      - Number of Good Frames Received
* RXBCASTFRAMES     - Number of Good Broadcast Frames Received
* RXMCASTFRAMES     - Number of Good Multicast Frames Received
* RXPAUSEFRAMES     - Number of PauseRX Frames Received
* RXCRCERRORS       - Number of Frames Received with CRC Errors
* RXALIGNCODEERRORS - Number of Frames Received with Alignment/Code Errors
* RXOVERSIZED       - Number of Oversized Frames Received
* RXJABBER          - Number of Jabber Frames Received
* RXUNDERSIZED      - Number of Undersized Frames Received
* RXFRAGMENTS       - Number of RX Frame Fragments Received
* RXFILTERED        - Number of RX Frames Filtered Based on Address
* RXQOSFILTERED     - Number of RX Frames Filtered Based on QoS Filtering
* RXOCTETS          - Total Number of Received Bytes in Good Frames
* TXGOODFRAMES      - Number of Good Frames Sent
* TXBCASTFRAMES     - Number of Good Broadcast Frames Sent
* TXMCASTFRAMES     - Number of Good Multicast Frames Sent
* TXPAUSEFRAMES     - Number of PauseTX Frames Sent
* TXDEFERRED        - Number of Frames Where Transmission was Deferred
* TXCOLLISION       - Total Number of Frames Sent That Experienced a Collision
* TXSINGLECOLL      - Number of Frames Sent with Exactly One Collision
* TXMULTICOLL       - Number of Frames Sent with Multiple Colisions
* TXEXCESSIVECOLL   - Number of TX Frames Lost Due to Excessive Collisions
* TXLATECOLL        - Number of TX Frames Lost Due to a Late Collision
* TXUNDERRUN        - Number of TX Frames Lost with Transmit Underrun Error
* TXCARRIERSLOSS    - Numebr of TX Frames Lost Due to Carrier Sense Loss
* TXOCTETS          - Total Nu,ber of Transmitted Bytes in Good Frames
* FRAME64           - Total TX & RX Frames with Octet Size of 64
* FRAME65T127       - Total TX & RX Frames with Octet Size of 65 to 127
* FRAME128T255      - Total TX & RX Frames with Octet Size of 128 to 255
* FRAME256T511      - Total TX & RX Frames with Octet Size of 256 to 511
* FRAME512T1023     - Total TX & RX Frames with Octet Size of 512 to 1023
* FRAME1024TUP      - Total TX & RX Frames with Octet Size of 1024 or above
* NETOCTETS         - Sum of all Octets Sent or Received on the Network
* RXSOFOVERRUNS     - Total RX Start of Frame Overruns (FIFO or DMA)
* RXMOFOVERRUNS     - Total RX Middle of Frame Overruns (FIFO or DMA)
* RXDMAOVERRUNS     - Total RX DMA Overruns
* TX0HDP            - TX Channel 0 DMA Head Descriptor Pointer Register
* TX1HDP            - TX Channel 1 DMA Head Descriptor Pointer Register
* TX2HDP            - TX Channel 2 DMA Head Descriptor Pointer Register
* TX3HDP            - TX Channel 3 DMA Head Descriptor Pointer Register
* TX4HDP            - TX Channel 4 DMA Head Descriptor Pointer Register
* TX5HDP            - TX Channel 5 DMA Head Descriptor Pointer Register
* TX6HDP            - TX Channel 6 DMA Head Descriptor Pointer Register
* TX7HDP            - TX Channel 7 DMA Head Descriptor Pointer Register
* RX0HDP            - RX Channel 0 DMA Head Descriptor Pointer Register
* RX1HDP            - RX Channel 1 DMA Head Descriptor Pointer Register
* RX2HDP            - RX Channel 2 DMA Head Descriptor Pointer Register
* RX3HDP            - RX Channel 3 DMA Head Descriptor Pointer Register
* RX4HDP            - RX Channel 4 DMA Head Descriptor Pointer Register
* RX5HDP            - RX Channel 5 DMA Head Descriptor Pointer Register
* RX6HDP            - RX Channel 6 DMA Head Descriptor Pointer Register
* RX7HDP            - RX Channel 7 DMA Head Descriptor Pointer Register
* TX0INTACK         - TX Channel 0 Interrupt Acknowledge Register
* TX1INTACK         - TX Channel 1 Interrupt Acknowledge Register
* TX2INTACK         - TX Channel 2 Interrupt Acknowledge Register
* TX3INTACK         - TX Channel 3 Interrupt Acknowledge Register
* TX4INTACK         - TX Channel 4 Interrupt Acknowledge Register
* TX5INTACK         - TX Channel 5 Interrupt Acknowledge Register
* TX6INTACK         - TX Channel 6 Interrupt Acknowledge Register
* TX7INTACK         - TX Channel 7 Interrupt Acknowledge Register
* RX0INTACK         - RX Channel 0 Interrupt Acknowledge Register
* RX1INTACK         - RX Channel 1 Interrupt Acknowledge Register
* RX2INTACK         - RX Channel 2 Interrupt Acknowledge Register
* RX3INTACK         - RX Channel 3 Interrupt Acknowledge Register
* RX4INTACK         - RX Channel 4 Interrupt Acknowledge Register
* RX5INTACK         - RX Channel 5 Interrupt Acknowledge Register
* RX6INTACK         - RX Channel 6 Interrupt Acknowledge Register
* RX7INTACK         - RX Channel 7 Interrupt Acknowledge Register
*
*
* WRAPPER REGISTERS
*
* INTCTL            - Interrupt control register
*
*
* DESCRIPTOR FIELDS
*
* DSC_NEXTDSC       - Pointer to Next Descriptor
* DSC_BUFFER        - Pointer to Buffer
* DSC_OFFLEN        - Buffer Offset and Length
* DSC_STATUS        - Packet Status
*
*\******************************************************************************/
#ifndef _CSL_EMACHAL_H
#define _CSL_EMACHAL_H_

#include <csl_stdinc.h>
#include <csl_chip.h>


#if (EMAC_SUPPORT)
/******************************************************************************\
* EMAC Register section
\******************************************************************************/

#define _EMAC_BASE_ADDR             0x01c80000u

/* ----------------- */
/* FIELD MAKE MACROS */
/* ----------------- */

/* User Supplied Value */
#define EMAC_FMK(REG,FIELD,x)\
  ((x<<_EMAC_##REG##_##FIELD##_SHIFT)&_EMAC_##REG##_##FIELD##_MASK)

/* Symbolic Value Name */
#define EMAC_FMKS(REG,FIELD,SYM)\
  ((EMAC_##REG##_##FIELD##_##SYM<<_EMAC_##REG##_##FIELD##_SHIFT)\
  &_EMAC_##REG##_##FIELD##_MASK)

/* Channel Flag */
#define EMAC_FMKCHF(CHANNEL)    (1u<<(CHANNEL))


/* -------------------------------- */
/* RAW REGISTER/FIELD ACCESS MACROS */
/* -------------------------------- */

#define EMAC_ADDR(REG)\
    ((volatile Uint32 *)_EMAC_##REG##_ADDR)

#define EMAC_REG(REG)\
    *(volatile Uint32*)(_EMAC_##REG##_ADDR)

/* Standard Registers */
#define EMAC_RGET(REG)\
    (*(volatile Uint32*)(_EMAC_##REG##_ADDR))

#define EMAC_RSET(REG,x)\
    (*(volatile Uint32*)(_EMAC_##REG##_ADDR)=(x))

#define EMAC_FGET(REG,FIELD)\
    ((EMAC_RGET(REG)&_EMAC_##REG##_##FIELD##_MASK)\
    >>_EMAC_##REG##_##FIELD##_SHIFT)

#define EMAC_FSET(REG,FIELD,x)\
    EMAC_RSET(REG,(EMAC_RGET(REG)&~_EMAC_##REG##_##FIELD##_MASK)|\
    EMAC_FMK(REG,FIELD,x))

#define EMAC_FSETS(REG,FIELD,SYM)\
    EMAC_RSET(REG,(EMAC_RGET(REG)&~_EMAC_##REG##_##FIELD##_MASK)|\
    EMAC_FMKS(REG,FIELD,SYM))


/* Index Based Registers */
#define EMAC_RGETI(REGBASE,IDX)\
    (*(volatile Uint32*)(_EMAC_##REGBASE##_BASEADDR+((IDX)*sizeof(Uint32 *))))

#define EMAC_RSETI(REGBASE,IDX,x)\
    (*(volatile Uint32*)(_EMAC_##REGBASE##_BASEADDR+((IDX)*sizeof(Uint32 *)))=(x))

#define EMAC_FGETI(REGBASE,IDX,FIELD)\
    ((EMAC_RGETI(REGBASE,IDX)&_EMAC_##REGBASE##_##FIELD##_MASK)\
    >>_EMAC_##REGBASE##_##FIELD##_SHIFT)

#define EMAC_FSETI(REGBASE,IDX,FIELD,x)\
    EMAC_RSETI(REGBASE,IDX,(EMAC_RGETI(REGBASE,IDX)&\
    ~_EMAC_##REGBASE##_##FIELD##_MASK)|EMAC_FMK(REGBASE,FIELD,x))

#define EMAC_FSETSI(REGBASE,IDX,FIELD,SYM)\
    EMAC_RSETI(REGBASE,IDX,(EMAC_RGETI(REGBASE,IDX)&\
    ~_EMAC_##REGBASE##_##FIELD##_MASK)|EMAC_FMKS(REGBASE,FIELD,SYM))



/******************************************************************************\
* EMAC Descriptor section
\******************************************************************************/

#define _EMAC_DSC_BASE_ADDR         0x01c81000u

/* EMAC Descriptor Size and Element Count */
#define _EMAC_DSC_SIZE              4096
#define _EMAC_DSC_ENTRY_SIZE        16
#define _EDMA_DSC_ENTRY_COUNT       (_EMAC_DSC_SIZE/_EMAC_DSC_ENTRY_SIZE)


/*
// EMAC Descriptor
//
// The following is the format of a single buffer descriptor
// on the EMAC.
*/
typedef struct _EMAC_Desc {
  struct _EMAC_Desc *pNext;     /* Pointer to next descriptor in chain */
  Uint8             *pBuffer;   /* Pointer to data buffer              */
  Uint32            BufOffLen;  /* Buffer Offset(MSW) and Length(LSW)  */
  Uint32            PktFlgLen;  /* Packet Flags(MSW) and Length(LSW)   */
} EMAC_Desc;


/* ------------------------ */
/* DESCRIPTOR ACCESS MACROS */
/* ------------------------ */

/* Packet Flags */
#define EMAC_DSC_FLAG_SOP                       0x80000000u
#define EMAC_DSC_FLAG_EOP                       0x40000000u
#define EMAC_DSC_FLAG_OWNER                     0x20000000u
#define EMAC_DSC_FLAG_EOQ                       0x10000000u
#define EMAC_DSC_FLAG_TDOWNCMPLT                0x08000000u
#define EMAC_DSC_FLAG_PASSCRC                   0x04000000u
#define EMAC_DSC_FLAG_JABBER                    0x02000000u
#define EMAC_DSC_FLAG_OVERSIZE                  0x01000000u
#define EMAC_DSC_FLAG_FRAGMENT                  0x00800000u
#define EMAC_DSC_FLAG_UNDERSIZED                0x00400000u
#define EMAC_DSC_FLAG_CONTROL                   0x00200000u
#define EMAC_DSC_FLAG_OVERRUN                   0x00100000u
#define EMAC_DSC_FLAG_CODEERROR                 0x00080000u
#define EMAC_DSC_FLAG_ALIGNERROR                0x00040000u
#define EMAC_DSC_FLAG_CRCERROR                  0x00020000u
#define EMAC_DSC_FLAG_NOMATCH                   0x00010000u


/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

/******************************************************************************\
* _____________________
* |                   |
* |  TXIDVER          |
* |___________________|
*
* TXIDVER           - TX Identification and Version Register
*
* FIELDS (msb -> lsb)
* (r)   TXIDENT
* (r)   TXMAJORVER
* (r)   TXMINORVER
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_TXIDVER_ADDR                      (_EMAC_BASE_ADDR+0x0000u)

#define EMAC_TXIDVER                            EMAC_REG(TXIDVER)

#define _EMAC_TXIDVER_TXIDENT_MASK              0xFFFF0000u
#define _EMAC_TXIDVER_TXIDENT_SHIFT             16u
#define  EMAC_TXIDVER_TXIDENT_DEFAULT           0x00000004u

#define _EMAC_TXIDVER_TXMAJORVER_MASK           0x0000FF00u
#define _EMAC_TXIDVER_TXMAJORVER_SHIFT          8u
#define  EMAC_TXIDVER_TXMAJORVER_DEFAULT        0x00000000u

#define _EMAC_TXIDVER_TXMINORVER_MASK           0x000000FFu
#define _EMAC_TXIDVER_TXMINORVER_SHIFT          0u
#define  EMAC_TXIDVER_TXMINORVER_DEFAULT        0x00000000u



/******************************************************************************\
* _____________________
* |                   |
* |  TXCONTROL        |
* |___________________|
*
* TXCONTROL         - TX Control Register
*
* FIELDS (msb -> lsb)
* (rw)  TXEN        - Transmit Enable
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    y
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_TXCONTROL_ADDR                    (_EMAC_BASE_ADDR+0x0004u)

#define EMAC_TXCONTROL                          EMAC_REG(TXCONTROL)

#define _EMAC_TXCONTROL_TXEN_MASK               0x00000001u
#define _EMAC_TXCONTROL_TXEN_SHIFT              0u
#define  EMAC_TXCONTROL_TXEN_DEFAULT		0x00000000u
#define EMAC_TXCONTROL_TXEN_DISABLE             0u
#define EMAC_TXCONTROL_TXEN_ENABLE              1u



/******************************************************************************\
* _____________________
* |                   |
* |  TXTEARDOWN       |
* |___________________|
*
* TXTEARDOWN        - TX Teardown Register
*
* FIELDS (msb -> lsb)
* (w)  TXTDNCH      - Teardown Channel Number
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_TXTEARDOWN_ADDR                   (_EMAC_BASE_ADDR+0x0008u)

#define EMAC_TXTEARDOWN                         EMAC_REG(TXTEARDOWN)

#define _EMAC_TXTEARDOWN_TXTDNCH_MASK           0x00000007u
#define _EMAC_TXTEARDOWN_TXTDNCH_SHIFT          0u
#define  EMAC_TXTEARDOWN_TXTDNCH_DEFAULT	0x00000000u


/******************************************************************************\
* _____________________
* |                   |
* |  RXIDVER          |
* |___________________|
*
* RXIDVER           - RX Identification and Version Register
*
* FIELDS (msb -> lsb)
* (r)   RXIDENT
* (r)   RXMAJORVER
* (r)   RXMINORVER
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXIDVER_ADDR                      (_EMAC_BASE_ADDR+0x0010u)

#define EMAC_RXIDVER                            EMAC_REG(RXIDVER)

#define _EMAC_RXIDVER_RXIDENT_MASK              0xFFFF0000u
#define _EMAC_RXIDVER_RXIDENT_SHIFT             16u
#define  EMAC_RXIDVER_RXIDENT_DEFAULT		0x00000004u

#define _EMAC_RXIDVER_RXMAJORVER_MASK           0x0000FF00u
#define _EMAC_RXIDVER_RXMAJORVER_SHIFT          8u
#define	 EMAC_RXIDVER_RXMAJORVER_DEFAULT	0x00000000u

#define _EMAC_RXIDVER_RXMINORVER_MASK           0x000000FFu
#define _EMAC_RXIDVER_RXMINORVER_SHIFT          0u
#define  EMAC_RXIDVER_RXMINORVER_DEFAULT	0x00000000u


/******************************************************************************\
* _____________________
* |                   |
* |  RXCONTROL        |
* |___________________|
*
* RXCONTROL         - RX Control Register
*
* FIELDS (msb -> lsb)
* (rw)  RXEN        - Receive Enable
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    y
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   y
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXCONTROL_ADDR                    (_EMAC_BASE_ADDR+0x0014u)

#define EMAC_RXCONTROL                          EMAC_REG(RXCONTROL)

#define _EMAC_RXCONTROL_RXEN_MASK               0x00000001u
#define _EMAC_RXCONTROL_RXEN_SHIFT              0u
#define  EMAC_RXCONTROL_RXEN_DEFAULT		0x00000000u
#define EMAC_RXCONTROL_RXEN_DISABLE             0u
#define EMAC_RXCONTROL_RXEN_ENABLE              1u



/******************************************************************************\
* _____________________
* |                   |
* |  RXTEARDOWN       |
* |___________________|
*
* RXTEARDOWN        - RX Teardown Register
*
* FIELDS (msb -> lsb)
* (w)  RXTDNCH      - Teardown Channel Number
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXTEARDOWN_ADDR                   (_EMAC_BASE_ADDR+0x0018u)

#define EMAC_RXTEARDOWN                         EMAC_REG(RXTEARDOWN)

#define _EMAC_RXTEARDOWN_RXTDNCH_MASK           0x000000007u
#define _EMAC_RXTEARDOWN_RXTDNCH_SHIFT          0u
#define  EMAC_RXTEARDOWN_RXTDNCH_DEFAULT	0x00000000u


/******************************************************************************\
* _____________________
* |                   |
* |  RXMBPENABLE      |
* |___________________|
*
* RXMBPENABLE       - RX Mulicast/Bcast/Promisc Channel Enable Register
*
* FIELDS (msb -> lsb)
* (rw)  RXPASSCRC   - Pass Receive CRC
* (rw)  RXQOSEN     - RX QOS Enable
* (rw)  RXNOCHAIN   - RX No Buffer Chaining
* (rw)  RXCMFEN     - RX Copy MAC Control Frames Enable
* (rw)  RXCSFEN     - RX Copy Short Frames Enable
* (rw)  RXCEFEN     - RX Copy Error Frames Enable
* (rw)  RXCAFEN     - RX Copy All Frames Enable
* (rw)  RXPROMCH    - RX Promiscusous Channel Select
* (rw)  RXBROADEN   - RX Broadcast Frame Enable
* (rw)  RXBROADCH   - RX Broadcast Channel Select
* (rw)  RXMULTEN    - RX Multicast Enable
* (rw)  RXMULTCH    - RX Multicast Channel Select
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    y
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   y
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXMBPENABLE_ADDR                  (_EMAC_BASE_ADDR+0x0100u)

#define EMAC_RXMBPENABLE                        EMAC_REG(RXMBPENABLE)

#define _EMAC_RXMBPENABLE_RXPASSCRC_MASK        0x40000000u
#define _EMAC_RXMBPENABLE_RXPASSCRC_SHIFT       30u
#define  EMAC_RXMBPENABLE_RXPASSCRC_DEFAULT	0x00000000u
#define EMAC_RXMBPENABLE_RXPASSCRC_DISCARD      0u
#define EMAC_RXMBPENABLE_RXPASSCRC_INCLUDE      1u

#define _EMAC_RXMBPENABLE_RXQOSEN_MASK          0x20000000u
#define _EMAC_RXMBPENABLE_RXQOSEN_SHIFT         29u
#define  EMAC_RXMBPENABLE_RXQOSEN_DEFAULT	0x00000000u
#define EMAC_RXMBPENABLE_RXQOSEN_DISABLE        0u
#define EMAC_RXMBPENABLE_RXQOSEN_ENABLE         1u

#define _EMAC_RXMBPENABLE_RXNOCHAIN_MASK        0x10000000u
#define _EMAC_RXMBPENABLE_RXNOCHAIN_SHIFT       28u
#define  EMAC_RXMBPENABLE_RXNOCHAIN_DEFAULT	0x00000000u
#define EMAC_RXMBPENABLE_RXNOCHAIN_DISABLE      0u
#define EMAC_RXMBPENABLE_RXNOCHAIN_ENABLE       1u

#define _EMAC_RXMBPENABLE_RXCMFEN_MASK          0x01000000u
#define _EMAC_RXMBPENABLE_RXCMFEN_SHIFT         24u
#define  EMAC_RXMBPENABLE_RXCMFEN_DEFAULT	0x00000000u
#define EMAC_RXMBPENABLE_RXCMFEN_DISABLE        0u
#define EMAC_RXMBPENABLE_RXCMFEN_ENABLE         1u

#define _EMAC_RXMBPENABLE_RXCSFEN_MASK          0x00800000u
#define _EMAC_RXMBPENABLE_RXCSFEN_SHIFT         23u
#define  EMAC_RXMBPENABLE_RXCSFEN_DEFAULT	0x00000000u
#define EMAC_RXMBPENABLE_RXCSFEN_DISABLE        0u
#define EMAC_RXMBPENABLE_RXCSFEN_ENABLE         1u

#define _EMAC_RXMBPENABLE_RXCEFEN_MASK          0x00400000u
#define _EMAC_RXMBPENABLE_RXCEFEN_SHIFT         22u
#define  EMAC_RXMBPENABLE_RXCEFEN_DEFAULT	0x00000000u
#define EMAC_RXMBPENABLE_RXCEFEN_DISABLE        0u
#define EMAC_RXMBPENABLE_RXCEFEN_ENABLE         1u

#define _EMAC_RXMBPENABLE_RXCAFEN_MASK          0x00200000u
#define _EMAC_RXMBPENABLE_RXCAFEN_SHIFT         21u
#define  EMAC_RXMBPENABLE_RXCAFEN_DEFAULT	0x00000000u
#define EMAC_RXMBPENABLE_RXCAFEN_DISABLE        0u
#define EMAC_RXMBPENABLE_RXCAFEN_ENABLE         1u

#define _EMAC_RXMBPENABLE_PROMCH_MASK           0x00070000u
#define _EMAC_RXMBPENABLE_PROMCH_SHIFT          16u
#define  EMAC_RXMBPENABLE_PROMCH_DEFAULT	0x00000000u

#define _EMAC_RXMBPENABLE_BROADEN_MASK          0x00002000u
#define _EMAC_RXMBPENABLE_BROADEN_SHIFT         13u
#define  EMAC_RXMBPENABLE_BROADEN_DEFAULT	0x00000000u
#define  EMAC_RXMBPENABLE_BROADEN_DISABLE	0u
#define  EMAC_RXMBPENABLE_BROADEN_ENABLE         1u

#define _EMAC_RXMBPENABLE_BROADCH_MASK          0x00000700u
#define _EMAC_RXMBPENABLE_BROADCH_SHIFT         8u
#define  EMAC_RXMBPENABLE_BROADCH_DEFAULT	0x00000000u

#define _EMAC_RXMBPENABLE_MULTEN_MASK           0x00000020u
#define _EMAC_RXMBPENABLE_MULTEN_SHIFT          5u
#define  EMAC_RXMBPENABLE_MULTEN_DEFAULT	0x00000000u
#define EMAC_RXMBPENABLE_MULTEN_DISABLE         0u
#define EMAC_RXMBPENABLE_MULTEN_ENABLE          1u

#define _EMAC_RXMBPENABLE_MULTCH_MASK           0x00000007u
#define _EMAC_RXMBPENABLE_MULTCH_SHIFT          0u
#define  EMAC_RXMBPENABLE_MULTCH_DEFAULT	0x00000000u
/******************************************************************************\
* _____________________
* |                   |
* |  RXUNICASTSET     |
* |  RXUNICASTCLEAR   |
* |___________________|
*
* RXUNICASTSET      - RX Unicast Set Register
* RXUNICASTCLEAR    - RX Unicast Clear Register
*
* FIELDS (msb -> lsb)
*  (r/ws)(r/wc)  Channel Flags (use EMAC_FMKCHF)
*
* MACROS SUPPORTED
*  EMAC_FMK     .
*  EMAC_FMKS    .
*  EMAC_FMKCHF  y
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    .
*  EMAC_FSET    .
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXUNICASTSET_ADDR                 (_EMAC_BASE_ADDR+0x0104u)
#define _EMAC_RXUNICASTCLEAR_ADDR               (_EMAC_BASE_ADDR+0x0108u)

#define EMAC_RXUNICASTSET                       EMAC_REG(RXUNICASTSET)
#define EMAC_RXUNICASTCLEAR                     EMAC_REG(RXUNICASTCLEAR)



/******************************************************************************\
* _____________________
* |                   |
* |  RXMAXLEN         |
* |___________________|
*
* MAXLEN            - RX Maximum Length Register
*
* FIELDS (msb -> lsb)
*  (rw)  RXMAXLEN
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXMAXLEN_ADDR                     (_EMAC_BASE_ADDR+0x010Cu)

#define EMAC_RXMAXLEN                           EMAC_REG(RXMAXLEN)

#define _EMAC_RXMAXLEN_MAXLEN_MASK              0x0000FFFFu
#define _EMAC_RXMAXLEN_MAXLEN_SHIFT             0u
#define  EMAC_RXMAXLEN_MAXLEN_DEFAULT		0x000005EEu

/******************************************************************************\
* _____________________
* |                   |
* |  RXBUFFEROFFSET   |
* |___________________|
*
* RXBUFFEROFFSET        - RX Buffer Offset Register
*
* FIELDS (msb -> lsb)
*  (rw)  BUFFEROFFSET
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXBUFFEROFFSET_ADDR               (_EMAC_BASE_ADDR+0x0110u)

#define EMAC_RXBUFFEROFFSET                     EMAC_REG(RXBUFFEROFFSET)

#define _EMAC_RXBUFFEROFFSET_BUFFEROFFSET_MASK  0x0000FFFFu
#define _EMAC_RXBUFFEROFFSET_BUFFEROFFSET_SHIFT 0u
#define  EMAC_RXBUFFEROFFSET_BUFFEROFFSET_DEFAULT 0x00000000u
/******************************************************************************\
* _____________________
* |                   |
* | RXFILTERLOWTHRESH |
* |___________________|
*
* RXFILTERLOWTHRESH - RX Filer Low Priority Packets Threshhold
*
* FIELDS (msb -> lsb)
*  (rw)  FILTERTHRESH
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXFILTERLOWTHRESH_ADDR            (_EMAC_BASE_ADDR+0x0114u)

#define EMAC_RXFILTERLOWTHRESH                  EMAC_REG(RXFILTERLOWTHRESH)

#define _EMAC_RXFILTERLOWTHRESH_FILTERTHRESH_MASK    0x000000FFu
#define _EMAC_RXFILTERLOWTHRESH_FILTERTHRESH_SHIFT   0u
#define  EMAC_RXFILTERLOWTHRESH_FILTERTHRESH_DEFAULT 0x00000000u


/******************************************************************************\
* _____________________
* |                   |
* |   RXFLOWTHRESH    |
* |   RXnFLOWTHRESH   |
* |___________________|
*
* RXFLOWTHRESH      - RX Flow Control Threshhold for RSETI/RGETI
* RX0FLOWTHRESH     - RX Channel 0 Flow Control Threshhold
* RX1FLOWTHRESH     - RX Channel 1 Flow Control Threshhold
* RX2FLOWTHRESH     - RX Channel 2 Flow Control Threshhold
* RX3FLOWTHRESH     - RX Channel 3 Flow Control Threshhold
* RX4FLOWTHRESH     - RX Channel 4 Flow Control Threshhold
* RX5FLOWTHRESH     - RX Channel 5 Flow Control Threshhold
* RX6FLOWTHRESH     - RX Channel 6 Flow Control Threshhold
* RX7FLOWTHRESH     - RX Channel 7 Flow Control Threshhold
*
* FIELDS (msb -> lsb)
*  (rw)  FLOWTHRESH
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   y
*  EMAC_RSETI   y
*  EMAC_FGETI   y
*  EMAC_FSETI   y
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXFLOWTHRESH_BASEADDR             (_EMAC_BASE_ADDR+0x0120u)
#define _EMAC_RX0FLOWTHRESH_ADDR                (_EMAC_BASE_ADDR+0x0120u)
#define _EMAC_RX1FLOWTHRESH_ADDR                (_EMAC_BASE_ADDR+0x0124u)
#define _EMAC_RX2FLOWTHRESH_ADDR                (_EMAC_BASE_ADDR+0x0128u)
#define _EMAC_RX3FLOWTHRESH_ADDR                (_EMAC_BASE_ADDR+0x012Cu)
#define _EMAC_RX4FLOWTHRESH_ADDR                (_EMAC_BASE_ADDR+0x0130u)
#define _EMAC_RX5FLOWTHRESH_ADDR                (_EMAC_BASE_ADDR+0x0134u)
#define _EMAC_RX6FLOWTHRESH_ADDR                (_EMAC_BASE_ADDR+0x0138u)
#define _EMAC_RX7FLOWTHRESH_ADDR                (_EMAC_BASE_ADDR+0x013Cu)

#define EMAC_RX0FLOWTHRESH                      EMAC_REG(RX0FLOWTHRESH)
#define EMAC_RX1FLOWTHRESH                      EMAC_REG(RX1FLOWTHRESH)
#define EMAC_RX2FLOWTHRESH                      EMAC_REG(RX2FLOWTHRESH)
#define EMAC_RX3FLOWTHRESH                      EMAC_REG(RX3FLOWTHRESH)
#define EMAC_RX4FLOWTHRESH                      EMAC_REG(RX4FLOWTHRESH)
#define EMAC_RX5FLOWTHRESH                      EMAC_REG(RX5FLOWTHRESH)
#define EMAC_RX6FLOWTHRESH                      EMAC_REG(RX6FLOWTHRESH)
#define EMAC_RX7FLOWTHRESH                      EMAC_REG(RX7FLOWTHRESH)

#define _EMAC_RXFLOWTHRESH_FLOWTHRESH_MASK      0x000000FFu
#define _EMAC_RXFLOWTHRESH_FLOWTHRESH_SHIFT     0u
#define  EMAC_RXFLOWTHRESH_FLOWTHRESH_DEFAULT	0x00000000u
#define _EMAC_RX0FLOWTHRESH_FLOWTHRESH_MASK     0x000000FFu
#define _EMAC_RX0FLOWTHRESH_FLOWTHRESH_SHIFT    0u
#define  EMAC_RX0FLOWTHRESH_FLOWTHRESH_DEFAULT	0x00000000u
#define _EMAC_RX1FLOWTHRESH_FLOWTHRESH_MASK     0x000000FFu
#define _EMAC_RX1FLOWTHRESH_FLOWTHRESH_SHIFT    0u
#define  EMAC_RX1FLOWTHRESH_FLOWTHRESH_DEFAULT	0x00000000u
#define _EMAC_RX2FLOWTHRESH_FLOWTHRESH_MASK     0x000000FFu
#define _EMAC_RX2FLOWTHRESH_FLOWTHRESH_SHIFT    0u
#define  EMAC_RX2FLOWTHRESH_FLOWTHRESH_DEFAULT	0x00000000u
#define _EMAC_RX3FLOWTHRESH_FLOWTHRESH_MASK     0x000000FFu
#define _EMAC_RX3FLOWTHRESH_FLOWTHRESH_SHIFT    0u
#define  EMAC_RX3FLOWTHRESH_FLOWTHRESH_DEFAULT	0x00000000u
#define _EMAC_RX4FLOWTHRESH_FLOWTHRESH_MASK     0x000000FFu
#define _EMAC_RX4FLOWTHRESH_FLOWTHRESH_SHIFT    0u
#define  EMAC_RX4FLOWTHRESH_FLOWTHRESH_DEFAULT	0x00000000u
#define _EMAC_RX5FLOWTHRESH_FLOWTHRESH_MASK     0x000000FFu
#define _EMAC_RX5FLOWTHRESH_FLOWTHRESH_SHIFT    0u
#define  EMAC_RX5FLOWTHRESH_FLOWTHRESH_DEFAULT	0x00000000u
#define _EMAC_RX6FLOWTHRESH_FLOWTHRESH_MASK     0x000000FFu
#define _EMAC_RX6FLOWTHRESH_FLOWTHRESH_SHIFT    0u
#define  EMAC_RX6FLOWTHRESH_FLOWTHRESH_DEFAULT	0x00000000u
#define _EMAC_RX7FLOWTHRESH_FLOWTHRESH_MASK     0x000000FFu
#define _EMAC_RX7FLOWTHRESH_FLOWTHRESH_SHIFT    0u
#define  EMAC_RX7FLOWTHRESH_FLOWTHRESH_DEFAULT	0x00000000u
/******************************************************************************\
* _____________________
* |                   |
* |   RXFREEBUFFER    |
* |   RXnFREEBUFFER   |
* |___________________|
*
* RXFREEBUFFER      - RX Free Buffer Count for RSETI/RGETI
* RX0FREEBUFFER     - RX Channel 0 Free Buffer Count Register
* RX1FREEBUFFER     - RX Channel 1 Free Buffer Count Register
* RX2FREEBUFFER     - RX Channel 2 Free Buffer Count Register
* RX3FREEBUFFER     - RX Channel 3 Free Buffer Count Register
* RX4FREEBUFFER     - RX Channel 4 Free Buffer Count Register
* RX5FREEBUFFER     - RX Channel 5 Free Buffer Count Register
* RX6FREEBUFFER     - RX Channel 6 Free Buffer Count Register
* RX7FREEBUFFER     - RX Channel 7 Free Buffer Count Register
*
* FIELDS (msb -> lsb)
*  (rw)  FREEBUF
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   y
*  EMAC_RSETI   y
*  EMAC_FGETI   y
*  EMAC_FSETI   y
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXFREEBUFFER_BASEADDR             (_EMAC_BASE_ADDR+0x0140u)
#define _EMAC_RX0FREEBUFFER_ADDR                (_EMAC_BASE_ADDR+0x0140u)
#define _EMAC_RX1FREEBUFFER_ADDR                (_EMAC_BASE_ADDR+0x0144u)
#define _EMAC_RX2FREEBUFFER_ADDR                (_EMAC_BASE_ADDR+0x0148u)
#define _EMAC_RX3FREEBUFFER_ADDR                (_EMAC_BASE_ADDR+0x014Cu)
#define _EMAC_RX4FREEBUFFER_ADDR                (_EMAC_BASE_ADDR+0x0150u)
#define _EMAC_RX5FREEBUFFER_ADDR                (_EMAC_BASE_ADDR+0x0154u)
#define _EMAC_RX6FREEBUFFER_ADDR                (_EMAC_BASE_ADDR+0x0158u)
#define _EMAC_RX7FREEBUFFER_ADDR                (_EMAC_BASE_ADDR+0x015Cu)

#define EMAC_RX0FREEBUFFER                      EMAC_REG(RX0FREEBUFFER)
#define EMAC_RX1FREEBUFFER                      EMAC_REG(RX1FREEBUFFER)
#define EMAC_RX2FREEBUFFER                      EMAC_REG(RX2FREEBUFFER)
#define EMAC_RX3FREEBUFFER                      EMAC_REG(RX3FREEBUFFER)
#define EMAC_RX4FREEBUFFER                      EMAC_REG(RX4FREEBUFFER)
#define EMAC_RX5FREEBUFFER                      EMAC_REG(RX5FREEBUFFER)
#define EMAC_RX6FREEBUFFER                      EMAC_REG(RX6FREEBUFFER)
#define EMAC_RX7FREEBUFFER                      EMAC_REG(RX7FREEBUFFER)

#define _EMAC_RXFREEBUFFER_FREEBUF_MASK         0x0000FFFFu
#define _EMAC_RXFREEBUFFER_FREEBUF_SHIFT        0u
#define	 EMAC_RXFREEBUFFER_FREEBUF_DEFAULT	0x00000000u
#define _EMAC_RX0FREEBUFFER_FREEBUF_MASK        0x0000FFFFu
#define _EMAC_RX0FREEBUFFER_FREEBUF_SHIFT       0u
#define  EMAC_RX0FREEBUFFER_FREEBUF_DEFAULT	0x00000000u
#define _EMAC_RX1FREEBUFFER_FREEBUF_MASK        0x0000FFFFu
#define _EMAC_RX1FREEBUFFER_FREEBUF_SHIFT       0u
#define  EMAC_RX1FREEBUFFER_FREEBUF_DEFAULT	0x00000000u
#define _EMAC_RX2FREEBUFFER_FREEBUF_MASK        0x0000FFFFu
#define _EMAC_RX2FREEBUFFER_FREEBUF_SHIFT       0u
#define  EMAC_RX2FREEBUFFER_FREEBUF_DEFAULT	0x00000000u
#define _EMAC_RX3FREEBUFFER_FREEBUF_MASK        0x0000FFFFu
#define _EMAC_RX3FREEBUFFER_FREEBUF_SHIFT       0u
#define  EMAC_RX3FREEBUFFER_FREEBUF_DEFAULT	0x00000000u
#define _EMAC_RX4FREEBUFFER_FREEBUF_MASK        0x0000FFFFu
#define _EMAC_RX4FREEBUFFER_FREEBUF_SHIFT       0u
#define  EMAC_RX4FREEBUFFER_FREEBUF_DEFAULT	0x00000000u
#define _EMAC_RX5FREEBUFFER_FREEBUF_MASK        0x0000FFFFu
#define _EMAC_RX5FREEBUFFER_FREEBUF_SHIFT       0u
#define  EMAC_RX5FREEBUFFER_FREEBUF_DEFAULT	0x00000000u
#define _EMAC_RX6FREEBUFFER_FREEBUF_MASK        0x0000FFFFu
#define _EMAC_RX6FREEBUFFER_FREEBUF_SHIFT       0u
#define  EMAC_RX6FREEBUFFER_FREEBUF_DEFAULT	0x00000000u
#define _EMAC_RX7FREEBUFFER_FREEBUF_MASK        0x0000FFFFu
#define _EMAC_RX7FREEBUFFER_FREEBUF_SHIFT       0u
#define  EMAC_RX7FREEBUFFER_FREEBUF_DEFAULT	0x00000000u


/******************************************************************************\
* _____________________
* |                   |
* |   MACCONTROL      |
* |___________________|
*
* MACCONTROL        - MAC Control Register
*
* FIELDS (msb -> lsb)
* (rw)  TXPTYPE     - TX Priority Queue Type
* (rw)  TXPACE      - TX Pacing Enable
* (rw)  MIIEN       - MII Enable
* (rw)  TXFLOWEN    - TX Flow Control Enable
* (rw)  RXFLOWEN    - RX Flow Control Enable
* (rw)  MTEST       - Manufacturer's Test Enable
* (rw)  LOOPBACK    - Loopback Mode Enable
* (rw)  FULLDUPLEX  - Full Duplex Mode Enable
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    y
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   y
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_MACCONTROL_ADDR                   (_EMAC_BASE_ADDR+0x0160u)

#define EMAC_MACCONTROL                         EMAC_REG(MACCONTROL)

#define _EMAC_MACCONTROL_TXPTYPE_MASK           0x00000200u
#define _EMAC_MACCONTROL_TXPTYPE_SHIFT          9u
#define  EMAC_MACCONTROL_TXPTYPE_DEFAULT	0x00000000u
#define EMAC_MACCONTROL_TXPTYPE_RROBIN          0u
#define EMAC_MACCONTROL_TXPTYPE_CHANNELPRI      1u

#define _EMAC_MACCONTROL_TXPACE_MASK            0x00000040u
#define _EMAC_MACCONTROL_TXPACE_SHIFT           6u
#define  EMAC_MACCONTROL_TXPACE_DEFAULT		0x00000000u
#define EMAC_MACCONTROL_TXPACE_DISABLE          0u
#define EMAC_MACCONTROL_TXPACE_ENABLE           1u

#define _EMAC_MACCONTROL_MIIEN_MASK             0x00000020u
#define _EMAC_MACCONTROL_MIIEN_SHIFT            5u
#define  EMAC_MACCONTROL_MIIEN_DEFAULT		0x00000000u
#define EMAC_MACCONTROL_MIIEN_DISABLE           0u
#define EMAC_MACCONTROL_MIIEN_ENABLE            1u

#define _EMAC_MACCONTROL_TXFLOWEN_MASK          0x00000010u
#define _EMAC_MACCONTROL_TXFLOWEN_SHIFT         4u
#define  EMAC_MACCONTROL_TXFLOWEN_DEFAULT	0x00000000u
#define EMAC_MACCONTROL_TXFLOWEN_DISABLE        0u
#define EMAC_MACCONTROL_TXFLOWEN_ENABLE         1u

#define _EMAC_MACCONTROL_RXFLOWEN_MASK          0x00000008u
#define _EMAC_MACCONTROL_RXFLOWEN_SHIFT         3u
#define  EMAC_MACCONTROL_RXFLOWEN_DEFAULT	0x00000000u
#define EMAC_MACCONTROL_RXFLOWEN_DISABLE        0u
#define EMAC_MACCONTROL_RXFLOWEN_ENABLE         1u

#define _EMAC_MACCONTROL_MTEST_MASK             0x00000004u
#define _EMAC_MACCONTROL_MTEST_SHIFT            2u
#define  EMAC_MACCONTROL_MTEST_DEFAULT		0x00000000u
#define EMAC_MACCONTROL_MTEST_DISABLE           0u
#define EMAC_MACCONTROL_MTEST_ENABLE            1u

#define _EMAC_MACCONTROL_LOOPBACK_MASK          0x00000002u
#define _EMAC_MACCONTROL_LOOPBACK_SHIFT         1u
#define  EMAC_MACCONTROL_LOOPBACK_DEFAULT	0x00000000u
#define EMAC_MACCONTROL_LOOPBACK_DISABLE        0u
#define EMAC_MACCONTROL_LOOPBACK_ENABLE         1u

#define _EMAC_MACCONTROL_FULLDUPLEX_MASK        0x00000001u
#define _EMAC_MACCONTROL_FULLDUPLEX_SHIFT       0u
#define  EMAC_MACCONTROL_FULLDUPLEX_DEFAULT	0x00000000u
#define EMAC_MACCONTROL_FULLDUPLEX_DISABLE      0u
#define EMAC_MACCONTROL_FULLDUPLEX_ENABLE       1u



/******************************************************************************\
* _____________________
* |                   |
* |   MACSTATUS       |
* |___________________|
*
* MACSTATUS         - MAC Status Register
*
* FIELDS (msb -> lsb)
* (r)  TXERRCODE    - TX Host Error Code
* (r)  THERRCH      - TX Host Error Channel
* (r)  RXERRCODE    - RX Host Error Code
* (r)  RXERRCH      - RX Host Error Channel
* (r)  RXQOSACT     - RX QOS Service Currently Active
* (r)  RXFLOWACT    - RX Flow Control Currently Active
* (r)  TXFLOWACT    - TX Flow Control Currently Active
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    y
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   y
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_MACSTATUS_ADDR                    (_EMAC_BASE_ADDR+0x0164u)

#define EMAC_MACSTATUS                          EMAC_REG(MACSTATUS)

#define _EMAC_MACSTATUS_TXERRCODE_MASK          0x00F00000u
#define _EMAC_MACSTATUS_TXERRCODE_SHIFT         20u
#define  EMAC_MACSTATUS_TXERRCODE_DEFAULT	0x00000000u
#define EMAC_MACSTATUS_TXERRCODE_NOERROR        0u
#define EMAC_MACSTATUS_TXERRCODE_SOPERROR       1u
#define EMAC_MACSTATUS_TXERRCODE_OWNERSHIP      2u
#define EMAC_MACSTATUS_TXERRCODE_NOEOP          3u
#define EMAC_MACSTATUS_TXERRCODE_NULLPTR        4u
#define EMAC_MACSTATUS_TXERRCODE_NULLLEN        5u
#define EMAC_MACSTATUS_TXERRCODE_LENRRROR       6u

#define _EMAC_MACSTATUS_TXERRCH_MASK            0x00070000u
#define _EMAC_MACSTATUS_TXERRCH_SHIFT           16u
#define  EMAC_MACSTATUS_TXERRCH_DEFAULT		0x00000000u

#define _EMAC_MACSTATUS_RXERRCODE_MASK          0x0000F000u
#define _EMAC_MACSTATUS_RXERRCODE_SHIFT         12u
#define  EMAC_MACSTATUS_RXERRCODE_DEFAULT	0x00000000u
#define EMAC_MACSTATUS_RXERRCODE_NOERROR        0u
#define EMAC_MACSTATUS_RXERRCODE_SOPERROR       1u
#define EMAC_MACSTATUS_RXERRCODE_OWNERSHIP      2u
#define EMAC_MACSTATUS_RXERRCODE_NOEOP          3u
#define EMAC_MACSTATUS_RXERRCODE_NULLPTR        4u
#define EMAC_MACSTATUS_RXERRCODE_NULLLEN        5u
#define EMAC_MACSTATUS_RXERRCODE_LENRRROR       6u

#define _EMAC_MACSTATUS_RXERRCH_MASK            0x00000700u
#define _EMAC_MACSTATUS_RXERRCH_SHIFT           8u
#define  EMAC_MACSTATUS_RXERRCH_DEFAULT		0x00000000u

#define _EMAC_MACSTATUS_RXQOSACT_MASK           0x00000004u
#define _EMAC_MACSTATUS_RXQOSACT_SHIFT          2u
#define  EMAC_MACSTATUS_RXQOSACT_DEFAULT	0x00000000u

#define _EMAC_MACSTATUS_RXFLOWACT_MASK          0x00000002u
#define _EMAC_MACSTATUS_RXFLOWACT_SHIFT         1u
#define  EMAC_MACSTATUS_RXFLOWACT_DEFAULT	0x00000000u

#define _EMAC_MACSTATUS_TXFLOWACT_MASK          0x00000001u
#define _EMAC_MACSTATUS_TXFLOWACT_SHIFT         0u
#define  EMAC_MACSTATUS_TXFLOWACT_DEFAULT	0x00000000u

/******************************************************************************\
* _____________________
* |                   |
* |   EMCONTROL       |
* |___________________|
*
* EMCONTROL         - Emulation Control Register
*
* FIELDS (msb -> lsb)
* (rw)  SOFT    - Emulation Soft Bit
* (rw)  FREE    - Emulation Free Bit
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_EMCONTROL_ADDR                    (_EMAC_BASE_ADDR+0x0168u)

#define EMAC_EMCONTROL                          EMAC_REG(EMCONTROL)

#define _EMAC_EMCONTROL_SOFT_MASK               0x00000002u
#define _EMAC_EMCONTROL_SOFT_SHIFT              1u

#define _EMAC_EMCONTROL_FREE_MASK               0x00000001u
#define _EMAC_EMCONTROL_FREE_SHIFT              0u



/******************************************************************************\
* _____________________
* |                   |
* |  MACINVECTOR      |
* |___________________|
*
* MACINVECTOR       - MAC Input Vector
*
* FIELDS (msb -> lsb)
*  (r) USERINT  - MDIO User Interrupt
*  (r) LINKINT  - MDIO Link Change Interrupt
*  (r) HOSTPEND - Host Pending Interrupt
*  (r) STATPEND - Statistics Interrupt
*  (r) RXPEND   - RX Pending Interrupt Flags (7-0)
*  (r) TXPEND   - TX Pending Interrupt Falgs (7-0)
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    .
*  EMAC_FGET    y
*  EMAC_FSET    .
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_MACINVECTOR_ADDR                  (_EMAC_BASE_ADDR+0x0180u)

#define EMAC_MACINVECTOR                        EMAC_REG(MACINVECTOR)

#define _EMAC_MACINVECTOR_USERINT_MASK          0x80000000u
#define _EMAC_MACINVECTOR_USERINT_SHIFT         31u
#define  EMAC_MACINVECTOR_USERINT_DEFAULT	0x00000000u
#define _EMAC_MACINVECTOR_LINKINT_MASK          0x40000000u
#define _EMAC_MACINVECTOR_LINKINT_SHIFT         30u
#define  EMAC_MACINVECTOR_LINKINT_DEFAULT	0x00000000u
#define _EMAC_MACINVECTOR_HOSTPEND_MASK         0x00020000u
#define _EMAC_MACINVECTOR_HOSTPEND_SHIFT        17u
#define  EMAC_MACINVECTOR_HOSTPEND_DEFAULT	0x00000000u
#define _EMAC_MACINVECTOR_STATPEND_MASK         0x00010000u
#define _EMAC_MACINVECTOR_STATPEND_SHIFT        16u
#define  EMAC_MACINVECTOR_STATPEND_DEFAULT	0x00000000u
#define _EMAC_MACINVECTOR_RXPEND_MASK           0x0000FF00u
#define _EMAC_MACINVECTOR_RXPEND_SHIFT          8u
#define  EMAC_MACINVECTOR_RXPEND_DEFAULT	0x00000000u
#define _EMAC_MACINVECTOR_TXPEND_MASK           0x000000FFu
#define _EMAC_MACINVECTOR_TXPEND_SHIFT          0u
#define  EMAC_MACINVECTOR_TXPEND_DEFAULT	0x00000000u


/******************************************************************************\
* _____________________
* |                   |
* |  MACEOIVECTOR     |
* |___________________|
*
* MACEOIVECTOR      - MAC EOI Vector
*
* FIELDS (msb -> lsb)
*  (r/w) Flags
*
* MACROS SUPPORTED
*  EMAC_FMK     .
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    .
*  EMAC_FSET    .
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_MACEOIVECTOR_ADDR                 (_EMAC_BASE_ADDR+0x0184u)

#define EMAC_MACEOIVECTOR                       EMAC_REG(MACEOIVECTOR)


/******************************************************************************\
* _____________________
* |                   |
* |  TXINTSTATRAW     |
* |  TXINTSTATMASKED  |
* |  TXINTMASKSET     |
* |  TXINTMASKCLEAR   |
* |  RXINTSTATRAW     |
* |  RXINTSTATMASKED  |
* |  RXINTMASKSET     |
* |  RXINTMASKCLEAR   |
* |___________________|
*
* TXINTSTATRAW      - TX Interrupt Status Register (Unmasked)
* TXINTSTATMASKED   - TX Interrupt Status Register (Masked)
* TXINTMASKSET      - TX Interrupt Mask Set Register
* TXINTMASKCLEAR    - TX Interrupt Mask Clear Register
* RXINTSTATRAW      - RX Interrupt Status Register (Unmasked)
* RXINTSTATMASKED   - RX Interrupt Status Register (Masked)
* RXINTMASKSET      - RX Interrupt Mask Set Register
* RXINTMASKCLEAR    - RX Interrupt Mask Clear Register
*
* FIELDS (msb -> lsb)
*  (r)(r/ws)(r/wc) Channel Flags (use EMAC_FMKCHF)
*
* MACROS SUPPORTED
*  EMAC_FMK     .
*  EMAC_FMKS    .
*  EMAC_FMKCHF  y
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    .
*  EMAC_FSET    .
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_TXINTSTATRAW_ADDR                 (_EMAC_BASE_ADDR+0x0170u)
#define _EMAC_TXINTSTATMASKED_ADDR              (_EMAC_BASE_ADDR+0x0174u)
#define _EMAC_TXINTMASKSET_ADDR                 (_EMAC_BASE_ADDR+0x0178u)
#define _EMAC_TXINTMASKCLEAR_ADDR               (_EMAC_BASE_ADDR+0x017Cu)
#define _EMAC_RXINTSTATRAW_ADDR                 (_EMAC_BASE_ADDR+0x0190u)
#define _EMAC_RXINTSTATMASKED_ADDR              (_EMAC_BASE_ADDR+0x0194u)
#define _EMAC_RXINTMASKSET_ADDR                 (_EMAC_BASE_ADDR+0x0198u)
#define _EMAC_RXINTMASKCLEAR_ADDR               (_EMAC_BASE_ADDR+0x019Cu)

#define EMAC_TXINTSTATRAW                       EMAC_REG(TXINTSTATRAW)
#define EMAC_TXINTSTATMASKED                    EMAC_REG(TXINTSTATMASKED)
#define EMAC_TXINTMASKSET                       EMAC_REG(TXINTMASKSET)
#define EMAC_TXINTMASKCLEAR                     EMAC_REG(TXINTMASKCLEAR)
#define EMAC_RXINTSTATRAW                       EMAC_REG(RXINTSTATRAW)
#define EMAC_RXINTSTATMASKED                    EMAC_REG(RXINTSTATMASKED)
#define EMAC_RXINTMASKSET                       EMAC_REG(RXINTMASKSET)
#define EMAC_RXINTMASKCLEAR                     EMAC_REG(RXINTMASKCLEAR)



/******************************************************************************\
* _____________________
* |                   |
* |  MACINTSTATRAW    |
* |  MACINTSTATMASKED |
* |  MACINTMASKSET    |
* |  MACINTMASKCLEAR  |
* |___________________|
*
* MACINTSTATRAW     - MAC Interrupt Status Register (Unmasked)
* MACINTSTATMASKED  - MAC Interrupt Status Register (Masked)
* MACINTMASKSET     - MAC Interrupt Mask Set Register
* MACINTMASKCLEAR   - MAC Interrupt Mask Clear Register
*
* FIELDS (msb -> lsb)
* (r)(r/ws)(r/wc) HOSTERRINT  - Host Error Interrupt
* (r)(r/ws)(r/wc) STATINT     - Statistics Interrupt
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_MACINTSTATRAW_ADDR                (_EMAC_BASE_ADDR+0x01A0u)
#define _EMAC_MACINTSTATMASKED_ADDR             (_EMAC_BASE_ADDR+0x01A4u)
#define _EMAC_MACINTMASKSET_ADDR                (_EMAC_BASE_ADDR+0x01A8u)
#define _EMAC_MACINTMASKCLEAR_ADDR              (_EMAC_BASE_ADDR+0x01ACu)

#define EMAC_MACINTSTATRAW                      EMAC_REG(MACINTSTATRAW)
#define EMAC_MACINTSTATMASKED                   EMAC_REG(MACINTSTATMASKED)
#define EMAC_MACINTMASKSET                      EMAC_REG(MACINTMASKSET)
#define EMAC_MACINTMASKCLEAR                    EMAC_REG(MACINTMASKCLEAR)

#define _EMAC_MACINTSTATRAW_HOSTERRINT_MASK     0x00000002u
#define _EMAC_MACINTSTATMASKED_HOSTERRINT_MASK  0x00000002u
#define _EMAC_MACINTMASKSET_HOSTERRINT_MASK     0x00000002u
#define _EMAC_MACINTMASKCLEAR_HOSTERRINT_MASK   0x00000002u
#define _EMAC_MACINTSTATRAW_HOSTERRINT_SHIFT    1u
#define  EMAC_MACINTSTATRAW_HOSTERRINT_DEFAULT	0x00000000u
#define _EMAC_MACINTSTATMASKED_HOSTERRINT_SHIFT 1u
#define  EMAC_MACINTSTATMASKED_HOSTERRINT_DEFAULT 0x00000000u
#define _EMAC_MACINTMASKSET_HOSTERRINT_SHIFT    1u
#define  EMAC_MACINTMASKSET_HOSTERRINT_DEFAULT	0x00000000u
#define _EMAC_MACINTMASKCLEAR_HOSTERRINT_SHIFT  1u
#define  EMAC_MACINTMASKCLEAR_HOSTERRINT_DEFAULT 0x00000000u

#define _EMAC_MACINTSTATRAW_STATINT_MASK        0x00000001u
#define _EMAC_MACINTSTATMASKED_STATINT_MASK     0x00000001u
#define _EMAC_MACINTMASKSET_STATINT_MASK        0x00000001u
#define _EMAC_MACINTMASKCLEAR_STATINT_MASK      0x00000001u
#define _EMAC_MACINTSTATRAW_STATINT_SHIFT       0u
#define  EMAC_MACINTSTATRAW_STATINT_DEFAULT	0x00000000u
#define _EMAC_MACINTSTATMASKED_STATINT_SHIFT    0u
#define  EMAC_MACINTSTATMASKED_STATINT_DEFAULT	0x00000000u
#define _EMAC_MACINTMASKSET_STATINT_SHIFT       0u
#define  EMAC_MACINTMASKSET_STATINT_DEFAULT	0x00000000u
#define _EMAC_MACINTMASKCLEAR_STATINT_SHIFT     0u
#define  EMAC_MACINTMASKCLEAR_STATINT_DEFAULT	0x00000000u

/******************************************************************************\
* _____________________
* |                   |
* |   MACADDRL        |
* |   MACADDRLn       |
* |___________________|
*
* MACADDRL          - MAC Address Lower Byte Register for RSETI/RGETI
* MACADDRL0         - MAC Address Channel 0 Lower Byte Register
* MACADDRL1         - MAC Address Channel 1 Lower Byte Register
* MACADDRL2         - MAC Address Channel 2 Lower Byte Register
* MACADDRL3         - MAC Address Channel 3 Lower Byte Register
* MACADDRL4         - MAC Address Channel 4 Lower Byte Register
* MACADDRL5         - MAC Address Channel 5 Lower Byte Register
* MACADDRL6         - MAC Address Channel 6 Lower Byte Register
* MACADDRL7         - MAC Address Channel 7 Lower Byte Register
*
* FIELDS (msb -> lsb)
*  (rw)  MACADDR8   - 8 bits of MAC Address
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   y
*  EMAC_RSETI   y
*  EMAC_FGETI   y
*  EMAC_FSETI   y
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_MACADDRL_BASEADDR                 (_EMAC_BASE_ADDR+0x01B0u)
#define _EMAC_MACADDRL0_ADDR                    (_EMAC_BASE_ADDR+0x01B0u)
#define _EMAC_MACADDRL1_ADDR                    (_EMAC_BASE_ADDR+0x01B4u)
#define _EMAC_MACADDRL2_ADDR                    (_EMAC_BASE_ADDR+0x01B8u)
#define _EMAC_MACADDRL3_ADDR                    (_EMAC_BASE_ADDR+0x01BCu)
#define _EMAC_MACADDRL4_ADDR                    (_EMAC_BASE_ADDR+0x01C0u)
#define _EMAC_MACADDRL5_ADDR                    (_EMAC_BASE_ADDR+0x01C4u)
#define _EMAC_MACADDRL6_ADDR                    (_EMAC_BASE_ADDR+0x01C8u)
#define _EMAC_MACADDRL7_ADDR                    (_EMAC_BASE_ADDR+0x01CCu)

#define EMAC_MACADDRL0                          EMAC_REG(MACADDRL0)
#define EMAC_MACADDRL1                          EMAC_REG(MACADDRL1)
#define EMAC_MACADDRL2                          EMAC_REG(MACADDRL2)
#define EMAC_MACADDRL3                          EMAC_REG(MACADDRL3)
#define EMAC_MACADDRL4                          EMAC_REG(MACADDRL4)
#define EMAC_MACADDRL5                          EMAC_REG(MACADDRL5)
#define EMAC_MACADDRL6                          EMAC_REG(MACADDRL6)
#define EMAC_MACADDRL7                          EMAC_REG(MACADDRL7)

#define _EMAC_MACADDRL_MACADDR8_MASK            0x000000FFu
#define _EMAC_MACADDRL_MACADDR8_SHIFT           0u
#define  EMAC_MACADDRL_MACADDR8_DEFAULT		0x00000000u
#define _EMAC_MACADDRL0_MACADDR8_MASK           0x000000FFu
#define _EMAC_MACADDRL0_MACADDR8_SHIFT          0u
#define  EMAC_MACADDRL0_MACADDR8_DEFAULT	0x00000000u
#define _EMAC_MACADDRL1_MACADDR8_MASK           0x000000FFu
#define _EMAC_MACADDRL1_MACADDR8_SHIFT          0u
#define  EMAC_MACADDRL1_MACADDR8_DEFAULT	0x00000000u
#define _EMAC_MACADDRL2_MACADDR8_MASK           0x000000FFu
#define _EMAC_MACADDRL2_MACADDR8_SHIFT          0u
#define  EMAC_MACADDRL2_MACADDR8_DEFAULT	0x00000000u
#define _EMAC_MACADDRL3_MACADDR8_MASK           0x000000FFu
#define _EMAC_MACADDRL3_MACADDR8_SHIFT          0u
#define  EMAC_MACADDRL3_MACADDR8_DEFAULT	0x00000000u
#define _EMAC_MACADDRL4_MACADDR8_MASK           0x000000FFu
#define _EMAC_MACADDRL4_MACADDR8_SHIFT          0u
#define  EMAC_MACADDRL4_MACADDR8_DEFAULT	0x00000000u
#define _EMAC_MACADDRL5_MACADDR8_MASK           0x000000FFu
#define _EMAC_MACADDRL5_MACADDR8_SHIFT          0u
#define  EMAC_MACADDRL5_MACADDR8_DEFAULT	0x00000000u
#define _EMAC_MACADDRL6_MACADDR8_MASK           0x000000FFu
#define _EMAC_MACADDRL6_MACADDR8_SHIFT          0u
#define  EMAC_MACADDRL6_MACADDR8_DEFAULT	0x00000000u
#define _EMAC_MACADDRL7_MACADDR8_MASK           0x000000FFu
#define _EMAC_MACADDRL7_MACADDR8_SHIFT          0u
#define  EMAC_MACADDRL7_MACADDR8_DEFAULT	0x00000000u


/******************************************************************************\
* _____________________
* |                   |
* |   MACADDRM        |
* |___________________|
*
* MACADDRM          - MAC Address Byte 1 Register (bits 15:8)
*
* FIELDS (msb -> lsb)
*  (rw)  MACADDR8   - 8 bits of MAC Address
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_MACADDRM_ADDR                     (_EMAC_BASE_ADDR+0x01D0u)

#define EMAC_MACADDRM                           EMAC_REG(MACADDRM)

#define _EMAC_MACADDRM_MACADDR8_MASK            0x000000FFu
#define _EMAC_MACADDRM_MACADDR8_SHIFT           0u
#define  EMAC_MACADDRM_MACADDR8_DEFAULT		0x00000000u



/******************************************************************************\
* _____________________
* |                   |
* |   MACADDRH        |
* |___________________|
*
* MACADDRH          - MAC Address High Bytes Register (bits 47:16)
*
* FIELDS (msb -> lsb)
*  (rw)  MACADDR32  - 32 bits of MAC Address
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_MACADDRH_ADDR                     (_EMAC_BASE_ADDR+0x01D4u)

#define EMAC_MACADDRH                           EMAC_REG(MACADDRH)

#define _EMAC_MACADDRH_MACADDR32_MASK           0xFFFFFFFFu
#define _EMAC_MACADDRH_MACADDR32_SHIFT          0u
#define  EMAC_MACADDRH_MACADDR32_DEFAULT	0x00000000u



/******************************************************************************\
* _____________________
* |                   |
* |   MACHASH1        |
* |   MACHASH2        |
* |___________________|
*
* MACHASH1          - MAC Address Hash 1 Register
* MACHASH2          - MAC Address Hash 2 Register
*
* FIELDS (msb -> lsb)
*  (rw)  HASHBITS   - 32 Hash Bits
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_MACHASH1_ADDR                     (_EMAC_BASE_ADDR+0x01D8u)
#define _EMAC_MACHASH2_ADDR                     (_EMAC_BASE_ADDR+0x01DCu)

#define EMAC_MACHASH1                           EMAC_REG(MACHASH1)
#define EMAC_MACHASH2                           EMAC_REG(MACHASH2)

#define _EMAC_MACHASH1_HASHBITS_MASK            0xFFFFFFFFu
#define  EMAC_MACHASH1_HASHBITS_DEFAULT		0x00000000u
#define _EMAC_MACHASH1_HASHBITS_SHIFT           0u
#define _EMAC_MACHASH2_HASHBITS_MASK            0xFFFFFFFFu
#define _EMAC_MACHASH2_HASHBITS_SHIFT           0u
#define  EMAC_MACHASH2_HASHBITS_DEFAULT		0x00000000u




/******************************************************************************\
* _____________________
* |                   |
* |   BOFFTEST        |
* |___________________|
*
* BOFFTEST          - Backoff Test Register
*
* FIELDS (msb -> lsb)
*  (rw)  BOFFHALT   - Halt Random Number Generator
*  (rw)  ATTEMPT    - Initial Collision Attempt Count
*  (rw)  BOFFRNG    - Backoff Random Number Generator
*  (rw)  RETRYCOUNT - Retry Count
*  (rw)  BOFFCOUNT  - Backoff Current Count
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_BOFFTEST_ADDR                     (_EMAC_BASE_ADDR+0x01E0u)

#define EMAC_BOFFTEST                           EMAC_REG(BOFFTEST)

#define _EMAC_BOFFTEST_BOFFHALT_MASK            0x8000000u
#define _EMAC_BOFFTEST_BOFFHALT_SHIFT           31u
#define	 EMAC_BOFFTEST_BOFFHALT_DEFAULT		0x00000000u

#define _EMAC_BOFFTEST_ATTEMPT_MASK             0x78000000u
#define _EMAC_BOFFTEST_ATTEMPT_SHIFT            27u
#define  EMAC_BOFFTEST_ATTEMPT_DEFAULT		0x00000000u

#define _EMAC_BOFFTEST_BOFFRNG_MASK             0x07FF0000u
#define _EMAC_BOFFTEST_BOFFRNG_SHIFT            16u
#define  EMAC_BOFFTEST_BOFFRNG_DEFAULT		0x00000000u

#define _EMAC_BOFFTEST_RETRYCOUNT_MASK          0x0000F000u
#define _EMAC_BOFFTEST_RETRYCOUNT_SHIFT         12u
#define  EMAC_BOFFTEST_RETRYCOUNT_DEFAULT	0x00000000u

#define _EMAC_BOFFTEST_BOFFCOUNT_MASK           0x000003FFu
#define _EMAC_BOFFTEST_BOFFCOUNT_SHIFT          0u
#define  EMAC_BOFFTEST_BOFFCOUNT_DEFAULT	0x00000000u


/******************************************************************************\
* _____________________
* |                   |
* |   TPACETEST       |
* |___________________|
*
* TPACETEST         - Transmit Pacing Test Register
*
* FIELDS (msb -> lsb)
*  (rw)  PACEVAL    - Pace Register Current Value
*  (rw)  PACEINIT   - Pace Register Initial Value
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_TPACETEST_ADDR                      (_EMAC_BASE_ADDR+0x01E4u)

#define EMAC_TPACETEST                            EMAC_REG(TPACETEST)

#define _EMAC_TPACETEST_PACEVAL_MASK              0x0000001Fu
#define _EMAC_TPACETEST_PACEVAL_SHIFT             0u
#define  EMAC_TPACETEST_PACEVAL_DEFAULT		  0x00000000u 

/******************************************************************************\
* _____________________
* |                   |
* |    RXPAUSE        |
* |    TXPAUSE        |
* |___________________|
*
* RXPAUSE           - Receive Pause Timer Register
* TXPAUSE           - Transmit Pause Timer Register
*
* FIELDS (msb -> lsb)
*  (rw)  PAUSETIMER - Pause Timer
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXPAUSE_ADDR                      (_EMAC_BASE_ADDR+0x01E8u)
#define _EMAC_TXPAUSE_ADDR                      (_EMAC_BASE_ADDR+0x01ECu)

#define EMAC_RXPAUSE                            EMAC_REG(RXPAUSE)
#define EMAC_TXPAUSE                            EMAC_REG(TXPAUSE)

#define _EMAC_RXPAUSE_PAUSETIMER_MASK           0x0000FFFFu
#define _EMAC_RXPAUSE_PAUSETIMER_SHIFT          0u
#define  EMAC_RXPAUSE_PAUSETIMER_DEFAULT	0x00000000u

#define _EMAC_TXPAUSE_PAUSETIMER_MASK           0x0000FFFFu
#define _EMAC_TXPAUSE_PAUSETIMER_SHIFT          0u
#define  EMAC_TXPAUSE_PAUSETIMER_DEFAULT	0x00000000u

/******************************************************************************\
* _____________________
* |                   |
* |   TXHDP           |
* |   TXnHDP          |
* |___________________|
*
* TXHDP             - TX DMA Head Descriptor Pointer Register for RSETI/RGETI
* TX0HDP            - TX Channel 0 DMA Head Descriptor Pointer Register
* TX1HDP            - TX Channel 1 DMA Head Descriptor Pointer Register
* TX2HDP            - TX Channel 2 DMA Head Descriptor Pointer Register
* TX3HDP            - TX Channel 3 DMA Head Descriptor Pointer Register
* TX4HDP            - TX Channel 4 DMA Head Descriptor Pointer Register
* TX5HDP            - TX Channel 5 DMA Head Descriptor Pointer Register
* TX6HDP            - TX Channel 6 DMA Head Descriptor Pointer Register
* TX7HDP            - TX Channel 7 DMA Head Descriptor Pointer Register
*
* FIELDS (msb -> lsb)
*  (rw) DESCPTR     - Descriptor Pointer
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   y
*  EMAC_RSETI   y
*  EMAC_FGETI   y
*  EMAC_FSETI   y
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_TXHDP_BASEADDR                (_EMAC_BASE_ADDR+0x0600u)
#define _EMAC_TX0HDP_ADDR                   (_EMAC_BASE_ADDR+0x0600u)
#define _EMAC_TX1HDP_ADDR                   (_EMAC_BASE_ADDR+0x0604u)
#define _EMAC_TX2HDP_ADDR                   (_EMAC_BASE_ADDR+0x0608u)
#define _EMAC_TX3HDP_ADDR                   (_EMAC_BASE_ADDR+0x060Cu)
#define _EMAC_TX4HDP_ADDR                   (_EMAC_BASE_ADDR+0x0610u)
#define _EMAC_TX5HDP_ADDR                   (_EMAC_BASE_ADDR+0x0614u)
#define _EMAC_TX6HDP_ADDR                   (_EMAC_BASE_ADDR+0x0618u)
#define _EMAC_TX7HDP_ADDR                   (_EMAC_BASE_ADDR+0x061Cu)

#define EMAC_TX0HDP                         EMAC_REG(TX0HDP)
#define EMAC_TX1HDP                         EMAC_REG(TX1HDP)
#define EMAC_TX2HDP                         EMAC_REG(TX2HDP)
#define EMAC_TX3HDP                         EMAC_REG(TX3HDP)
#define EMAC_TX4HDP                         EMAC_REG(TX4HDP)
#define EMAC_TX5HDP                         EMAC_REG(TX5HDP)
#define EMAC_TX6HDP                         EMAC_REG(TX6HDP)
#define EMAC_TX7HDP                         EMAC_REG(TX7HDP)

#define _EMAC_TXHDP_DESCPTR_MASK            0xFFFFFFFFu
#define _EMAC_TXHDP_DESCPTR_SHIFT           0u
#define  EMAC_TXHDP_DESCPTR_DEFAULT         0x00000000u  
#define _EMAC_TX0HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_TX0HDP_DESCPTR_SHIFT          0u
#define  EMAC_TX0HDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_TX1HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_TX1HDP_DESCPTR_SHIFT          0u
#define  EMAC_TX1HDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_TX2HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_TX2HDP_DESCPTR_SHIFT          0u
#define  EMAC_TX2HDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_TX3HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_TX3HDP_DESCPTR_SHIFT          0u
#define  EMAC_TX3HDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_TX4HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_TX4HDP_DESCPTR_SHIFT          0u
#define  EMAC_TX4HDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_TX5HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_TX5HDP_DESCPTR_SHIFT          0u
#define  EMAC_TX5HDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_TX6HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_TX6HDP_DESCPTR_SHIFT          0u
#define  EMAC_TX6HDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_TX7HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_TX7HDP_DESCPTR_SHIFT          0u
#define  EMAC_TX7HDP_DESCPTR_DEFAULT	    0x00000000u


/******************************************************************************\
* _____________________
* |                   |
* |   RXHDP           |
* |   RXnHDP          |
* |___________________|
*
* RXHDP             - RX DMA Head Descriptor Pointer Register for RSETI/RGETI
* RX0HDP            - RX Channel 0 DMA Head Descriptor Pointer Register
* RX1HDP            - RX Channel 1 DMA Head Descriptor Pointer Register
* RX2HDP            - RX Channel 2 DMA Head Descriptor Pointer Register
* RX3HDP            - RX Channel 3 DMA Head Descriptor Pointer Register
* RX4HDP            - RX Channel 4 DMA Head Descriptor Pointer Register
* RX5HDP            - RX Channel 5 DMA Head Descriptor Pointer Register
* RX6HDP            - RX Channel 6 DMA Head Descriptor Pointer Register
* RX7HDP            - RX Channel 7 DMA Head Descriptor Pointer Register
*
* FIELDS (msb -> lsb)
*  (rw) DESCPTR     - Descriptor Pointer
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   y
*  EMAC_RSETI   y
*  EMAC_FGETI   y
*  EMAC_FSETI   y
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXHDP_BASEADDR                (_EMAC_BASE_ADDR+0x0620u)
#define _EMAC_RX0HDP_ADDR                   (_EMAC_BASE_ADDR+0x0620u)
#define _EMAC_RX1HDP_ADDR                   (_EMAC_BASE_ADDR+0x0624u)
#define _EMAC_RX2HDP_ADDR                   (_EMAC_BASE_ADDR+0x0628u)
#define _EMAC_RX3HDP_ADDR                   (_EMAC_BASE_ADDR+0x062Cu)
#define _EMAC_RX4HDP_ADDR                   (_EMAC_BASE_ADDR+0x0630u)
#define _EMAC_RX5HDP_ADDR                   (_EMAC_BASE_ADDR+0x0634u)
#define _EMAC_RX6HDP_ADDR                   (_EMAC_BASE_ADDR+0x0638u)
#define _EMAC_RX7HDP_ADDR                   (_EMAC_BASE_ADDR+0x063Cu)

#define EMAC_RX0HDP                         EMAC_REG(RX0HDP)
#define EMAC_RX1HDP                         EMAC_REG(RX1HDP)
#define EMAC_RX2HDP                         EMAC_REG(RX2HDP)
#define EMAC_RX3HDP                         EMAC_REG(RX3HDP)
#define EMAC_RX4HDP                         EMAC_REG(RX4HDP)
#define EMAC_RX5HDP                         EMAC_REG(RX5HDP)
#define EMAC_RX6HDP                         EMAC_REG(RX6HDP)
#define EMAC_RX7HDP                         EMAC_REG(RX7HDP)

#define _EMAC_RXHDP_DESCPTR_MASK            0xFFFFFFFFu
#define _EMAC_RXHDP_DESCPTR_SHIFT           0u
#define  EMAC_RXHDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_RX0HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_RX0HDP_DESCPTR_SHIFT          0u
#define  EMAC_RX0HDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_RX1HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_RX1HDP_DESCPTR_SHIFT          0u
#define  EMAC_RX1HDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_RX2HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_RX2HDP_DESCPTR_SHIFT          0u
#define  EMAC_RX2HDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_RX3HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_RX3HDP_DESCPTR_SHIFT          0u
#define  EMAC_Rx3HDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_RX4HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_RX4HDP_DESCPTR_SHIFT          0u
#define  EMAC_RX4HDP_DESCPTR_DEFAULT        0x00000000u
#define _EMAC_RX5HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_RX5HDP_DESCPTR_SHIFT          0u
#define  EMAC_RX5HDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_RX6HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_RX6HDP_DESCPTR_SHIFT          0u
#define  EMAC_RX6HDP_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_RX7HDP_DESCPTR_MASK           0xFFFFFFFFu
#define _EMAC_RX7HDP_DESCPTR_SHIFT          0u
#define  EMAC_RX7HDP_DESCPTR_DEFAULT	    0x00000000u
/***************************************************************************************************************************\
*  ___________________
* |   TXINTACK        |
* |   TXnINTACK       |
* |___________________|
*
* TXINTACK          - TX Interrupt Ack Register for RSETI/RGETI
* TX0INTACK         - TX Channel 0 Interrupt Acknowledge Register
* TX1INTACK         - TX Channel 1 Interrupt Acknowledge Register
* TX2INTACK         - TX Channel 2 Interrupt Acknowledge Register
* TX3INTACK         - TX Channel 3 Interrupt Acknowledge Register
* TX4INTACK         - TX Channel 4 Interrupt Acknowledge Register
* TX5INTACK         - TX Channel 5 Interrupt Acknowledge Register
* TX6INTACK         - TX Channel 6 Interrupt Acknowledge Register
* TX7INTACK         - TX Channel 7 Interrupt Acknowledge Register
*
* FIELDS (msb -> lsb)
*  (rw) DESCPTR     - Descriptor Pointer
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   y
*  EMAC_RSETI   y
*  EMAC_FGETI   y
*  EMAC_FSETI   y
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_TXINTACK_BASEADDR             (_EMAC_BASE_ADDR+0x0640u)
#define _EMAC_TX0INTACK_ADDR                (_EMAC_BASE_ADDR+0x0640u)
#define _EMAC_TX1INTACK_ADDR                (_EMAC_BASE_ADDR+0x0644u)
#define _EMAC_TX2INTACK_ADDR                (_EMAC_BASE_ADDR+0x0648u)
#define _EMAC_TX3INTACK_ADDR                (_EMAC_BASE_ADDR+0x064Cu)
#define _EMAC_TX4INTACK_ADDR                (_EMAC_BASE_ADDR+0x0650u)
#define _EMAC_TX5INTACK_ADDR                (_EMAC_BASE_ADDR+0x0654u)
#define _EMAC_TX6INTACK_ADDR                (_EMAC_BASE_ADDR+0x0658u)
#define _EMAC_TX7INTACK_ADDR                (_EMAC_BASE_ADDR+0x065Cu)

#define EMAC_TX0INTACK                      EMAC_REG(TX0INTACK)
#define EMAC_TX1INTACK                      EMAC_REG(TX1INTACK)
#define EMAC_TX2INTACK                      EMAC_REG(TX2INTACK)
#define EMAC_TX3INTACK                      EMAC_REG(TX3INTACK)
#define EMAC_TX4INTACK                      EMAC_REG(TX4INTACK)
#define EMAC_TX5INTACK                      EMAC_REG(TX5INTACK)
#define EMAC_TX6INTACK                      EMAC_REG(TX6INTACK)
#define EMAC_TX7INTACK                      EMAC_REG(TX7INTACK)

#define _EMAC_TXINTACK_DESCPTR_MASK         0xFFFFFFFFu
#define _EMAC_TXINTACK_DESCPTR_SHIFT        0u
#define  EMAC_TXINTACK_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_TX0INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_TX0INTACK_DESCPTR_SHIFT       0u
#define  EMAC_TX0INTACK_DESCPTR_DEFAULT	    0x00000000u 	 
#define _EMAC_TX1INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_TX1INTACK_DESCPTR_SHIFT       0u
#define  EMAC_TX1INTACK_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_TX2INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_TX2INTACK_DESCPTR_SHIFT       0u
#define  EMAC_TX2INTACK_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_TX3INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_TX3INTACK_DESCPTR_SHIFT       0u
#define  EMAC_TX3INTACK_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_TX4INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_TX4INTACK_DESCPTR_SHIFT       0u
#define  EMAC_TX4INTACK_DESCPTR_DEFAULT     0x00000000u
#define _EMAC_TX5INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_TX5INTACK_DESCPTR_SHIFT       0u
#define  EMAC_TX5INTACK_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_TX6INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_TX6INTACK_DESCPTR_SHIFT       0u
#define  EMAC_TX6INTACK_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_TX7INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_TX7INTACK_DESCPTR_SHIFT       0u
#define  EMAC_TX7INTACK_DESCPTR_DEFAULT	    0x00000000u

/******************************************************************************\
* _____________________
* |                   |
* |   RXINTACK        |
* |   RXnINTACK       |
* |___________________|
*
* RXINTACK          - RX Channel 0 Interrupt Ack Register for RSETI/RGETI
* RX0INTACK         - RX Channel 0 Interrupt Acknowledge Register
* RX1INTACK         - RX Channel 1 Interrupt Acknowledge Register
* RX2INTACK         - RX Channel 2 Interrupt Acknowledge Register
* RX3INTACK         - RX Channel 3 Interrupt Acknowledge Register
* RX4INTACK         - RX Channel 4 Interrupt Acknowledge Register
* RX5INTACK         - RX Channel 5 Interrupt Acknowledge Register
* RX6INTACK         - RX Channel 6 Interrupt Acknowledge Register
* RX7INTACK         - RX Channel 7 Interrupt Acknowledge Register
*
* FIELDS (msb -> lsb)
*  (rw) DESCPTR     - Descriptor Pointer
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   y
*  EMAC_RSETI   y
*  EMAC_FGETI   y
*  EMAC_FSETI   y
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXINTACK_BASEADDR             (_EMAC_BASE_ADDR+0x0660u)
#define _EMAC_RX0INTACK_ADDR                (_EMAC_BASE_ADDR+0x0660u)
#define _EMAC_RX1INTACK_ADDR                (_EMAC_BASE_ADDR+0x0664u)
#define _EMAC_RX2INTACK_ADDR                (_EMAC_BASE_ADDR+0x0668u)
#define _EMAC_RX3INTACK_ADDR                (_EMAC_BASE_ADDR+0x066Cu)
#define _EMAC_RX4INTACK_ADDR                (_EMAC_BASE_ADDR+0x0670u)
#define _EMAC_RX5INTACK_ADDR                (_EMAC_BASE_ADDR+0x0674u)
#define _EMAC_RX6INTACK_ADDR                (_EMAC_BASE_ADDR+0x0678u)
#define _EMAC_RX7INTACK_ADDR                (_EMAC_BASE_ADDR+0x067Cu)

#define EMAC_RX0INTACK                      EMAC_REG(RX0INTACK)
#define EMAC_RX1INTACK                      EMAC_REG(RX1INTACK)
#define EMAC_RX2INTACK                      EMAC_REG(RX2INTACK)
#define EMAC_RX3INTACK                      EMAC_REG(RX3INTACK)
#define EMAC_RX4INTACK                      EMAC_REG(RX4INTACK)
#define EMAC_RX5INTACK                      EMAC_REG(RX5INTACK)
#define EMAC_RX6INTACK                      EMAC_REG(RX6INTACK)
#define EMAC_RX7INTACK                      EMAC_REG(RX7INTACK)

#define _EMAC_RXINTACK_DESCPTR_MASK         0xFFFFFFFFu
#define _EMAC_RXINTACK_DESCPTR_SHIFT        0u
#define  EMAC_RXINTACK_DESCPTR_DEFAULT      0x00000000u
#define _EMAC_RX0INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_RX0INTACK_DESCPTR_SHIFT       0u
#define  EMAC_RX0INTACK_DESCPTR_DEFAULT     0x00000000u
#define _EMAC_RX1INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_RX1INTACK_DESCPTR_SHIFT       0u
#define  EMAC_RX1INTACK_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_RX2INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_RX2INTACK_DESCPTR_SHIFT       0u
#define  EMAC_RX2INTACK_DESCPTR_DEFAULT     0x00000000u
#define _EMAC_RX3INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_RX3INTACK_DESCPTR_SHIFT       0u
#define  EMAC_RX3INTACK_DESCPTR_DEFAULT	    0x00000000u
#define _EMAC_RX4INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_RX4INTACK_DESCPTR_SHIFT       0u
#define  EMAC_RX4INTACK_DESCPTR_DEFAULT     0x00000000u
#define _EMAC_RX5INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_RX5INTACK_DESCPTR_SHIFT       0u
#define  EMAC_RX5INTACK_DESCPTR_DEFAULT     0x00000000u
#define _EMAC_RX6INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_RX6INTACK_DESCPTR_SHIFT       0u
#define  EMAC_RX6INTACK_DESCPTR_DEFAULT     0x00000000u
#define _EMAC_RX7INTACK_DESCPTR_MASK        0xFFFFFFFFu
#define _EMAC_RX7INTACK_DESCPTR_SHIFT       0u
#define  EMAC_RX7INTACK_DESCPTR_DEFAULT     0x00000000u


/******************************************************************************\
* _____________________
* |                   |
* | RXGOODFRAMES      |
* | RXBCASTFRAMES     |
* | RXMCASTFRAMES     |
* | RXPAUSEFRAMES     |
* | RXCRCERRORS       |
* | RXALIGNCODEERRORS |
* | RXOVERSIZED       |
* | RXJABBER          |
* | RXUNDERSIZED      |
* | RXFRAGMENTS       |
* | RXFILTERED        |
* | RXQOSFILTERED     |
* | RXOCTETS          |
* | TXGOODFRAMES      |
* | TXBCASTFRAMES     |
* | TXMCASTFRAMES     |
* | TXPAUSEFRAMES     |
* | TXDEFERRED        |
* | TXCOLLISION       |
* | TXSINGLECOLL      |
* | TXMULTICOLL       |
* | TXEXCESSIVECOLL   |
* | TXLATECOLL        |
* | TXUNDERRUN        |
* | TXCARRIERSLOSS    |
* | TXOCTETS          |
* | FRAME64           |
* | FRAME65T127       |
* | FRAME128T255      |
* | FRAME256T511      |
* | FRAME512T1023     |
* | FRAME1024TUP      |
* | NETOCTETS         |
* | RXSOFOVERRUNS     |
* | RXMOFOVERRUNS     |
* | RXDMAOVERRUNS     |
* |___________________|
*
* RXGOODFRAMES      - Number of Good Frames Received
* RXBCASTFRAMES     - Number of Good Broadcast Frames Received
* RXMCASTFRAMES     - Number of Good Multicast Frames Received
* RXPAUSEFRAMES     - Number of PauseRX Frames Received
* RXCRCERRORS       - Number of Frames Received with CRC Errors
* RXALIGNCODEERRORS - Number of Frames Received with Alignment/Code Errors
* RXOVERSIZED       - Number of Oversized Frames Received
* RXJABBER          - Number of Jabber Frames Received
* RXUNDERSIZED      - Number of Undersized Frames Received
* RXFRAGMENTS       - Number of RX Frame Fragments Received
* RXFILTERED        - Number of RX Frames Filtered Based on Address
* RXQOSFILTERED     - Number of RX Frames Filtered Based on QoS Filtering
* RXOCTETS          - Total Number of Received Bytes in Good Frames
* TXGOODFRAMES      - Number of Good Frames Sent
* TXBCASTFRAMES     - Number of Good Broadcast Frames Sent
* TXMCASTFRAMES     - Number of Good Multicast Frames Sent
* TXPAUSEFRAMES     - Number of PauseTX Frames Sent
* TXDEFERRED        - Number of Frames Where Transmission was Deferred
* TXCOLLISION       - Total Number of Frames Sent That Experienced a Collision
* TXSINGLECOLL      - Number of Frames Sent with Exactly One Collision
* TXMULTICOLL       - Number of Frames Sent with Multiple Colisions
* TXEXCESSIVECOLL   - Number of TX Frames Lost Due to Excessive Collisions
* TXLATECOLL        - Number of TX Frames Lost Due to a Late Collision
* TXUNDERRUN        - Number of TX Frames Lost with Transmit Underrun Error
* TXCARRIERSLOSS    - Numebr of TX Frames Lost Due to Carrier Sense Loss
* TXOCTETS          - Total Nu,ber of Transmitted Bytes in Good Frames
* FRAME64           - Total TX & RX Frames with Octet Size of 64
* FRAME65T127       - Total TX & RX Frames with Octet Size of 65 to 127
* FRAME128T255      - Total TX & RX Frames with Octet Size of 128 to 255
* FRAME256T511      - Total TX & RX Frames with Octet Size of 256 to 511
* FRAME512T1023     - Total TX & RX Frames with Octet Size of 512 to 1023
* FRAME1024TUP      - Total TX & RX Frames with Octet Size of 1024 or above
* NETOCTETS         - Sum of all Octets Sent or Received on the Network
* RXSOFOVERRUNS     - Total RX Start of Frame Overruns (FIFO or DMA)
* RXMOFOVERRUNS     - Total RX Middle of Frame Overruns (FIFO or DMA)
* RXDMAOVERRUNS     - Total RX DMA Overruns
*
* FIELDS (msb -> lsb)
*  (rw) COUNT       - 32 bit count value
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_RXGOODFRAMES_ADDR             (_EMAC_BASE_ADDR+0x0200u)
#define _EMAC_RXBCASTFRAMES_ADDR            (_EMAC_BASE_ADDR+0x0204u)
#define _EMAC_RXMCASTFRAMES_ADDR            (_EMAC_BASE_ADDR+0x0208u)
#define _EMAC_RXPAUSEFRAMES_ADDR            (_EMAC_BASE_ADDR+0x020Cu)
#define _EMAC_RXCRCERRORS_ADDR              (_EMAC_BASE_ADDR+0x0210u)
#define _EMAC_RXALIGNCODEERRORS_ADDR        (_EMAC_BASE_ADDR+0x0214u)
#define _EMAC_RXOVERSIZED_ADDR              (_EMAC_BASE_ADDR+0x0218u)
#define _EMAC_RXJABBER_ADDR                 (_EMAC_BASE_ADDR+0x021Cu)
#define _EMAC_RXUNDERSIZED_ADDR             (_EMAC_BASE_ADDR+0x0220u)
#define _EMAC_RXFRAGMENTS_ADDR              (_EMAC_BASE_ADDR+0x0224u)
#define _EMAC_RXFILTERED_ADDR               (_EMAC_BASE_ADDR+0x0228u)
#define _EMAC_RXQOSFILTERED_ADDR            (_EMAC_BASE_ADDR+0x022Cu)
#define _EMAC_RXOCTETS_ADDR                 (_EMAC_BASE_ADDR+0x0230u)
#define _EMAC_TXGOODFRAMES_ADDR             (_EMAC_BASE_ADDR+0x0234u)
#define _EMAC_TXBCASTFRAMES_ADDR            (_EMAC_BASE_ADDR+0x0238u)
#define _EMAC_TXMCASTFRAMES_ADDR            (_EMAC_BASE_ADDR+0x023Cu)
#define _EMAC_TXPAUSEFRAMES_ADDR            (_EMAC_BASE_ADDR+0x0240u)
#define _EMAC_TXDEFERRED_ADDR               (_EMAC_BASE_ADDR+0x0244u)
#define _EMAC_TXCOLLISION_ADDR              (_EMAC_BASE_ADDR+0x0248u)
#define _EMAC_TXSINGLECOLL_ADDR             (_EMAC_BASE_ADDR+0x024Cu)
#define _EMAC_TXMULTICOLL_ADDR              (_EMAC_BASE_ADDR+0x0250u)
#define _EMAC_TXEXCESSIVECOLL_ADDR          (_EMAC_BASE_ADDR+0x0254u)
#define _EMAC_TXLATECOLL_ADDR               (_EMAC_BASE_ADDR+0x0258u)
#define _EMAC_TXUNDERRUN_ADDR               (_EMAC_BASE_ADDR+0x025Cu)
#define _EMAC_TXCARRIERSLOSS_ADDR           (_EMAC_BASE_ADDR+0x0260u)
#define _EMAC_TXOCTETS_ADDR                 (_EMAC_BASE_ADDR+0x0264u)
#define _EMAC_FRAME64_ADDR                  (_EMAC_BASE_ADDR+0x0268u)
#define _EMAC_FRAME65T127_ADDR              (_EMAC_BASE_ADDR+0x026Cu)
#define _EMAC_FRAME128T255_ADDR             (_EMAC_BASE_ADDR+0x0270u)
#define _EMAC_FRAME256T511_ADDR             (_EMAC_BASE_ADDR+0x0274u)
#define _EMAC_FRAME512T1023_ADDR            (_EMAC_BASE_ADDR+0x0278u)
#define _EMAC_FRAME1024TUP_ADDR             (_EMAC_BASE_ADDR+0x027Cu)
#define _EMAC_NETOCTETS_ADDR                (_EMAC_BASE_ADDR+0x0280u)
#define _EMAC_RXSOFOVERRUNS_ADDR            (_EMAC_BASE_ADDR+0x0284u)
#define _EMAC_RXMOFOVERRUNS_ADDR            (_EMAC_BASE_ADDR+0x0288u)
#define _EMAC_RXDMAOVERRUNS_ADDR            (_EMAC_BASE_ADDR+0x028Cu)

#define EMAC_RXGOODFRAMES                   EMAC_REG(RXGOODFRAMES)
#define EMAC_RXBCASTFRAMES                  EMAC_REG(RXBCASTFRAMES)
#define EMAC_RXMCASTFRAMES                  EMAC_REG(RXMCASTFRAMES)
#define EMAC_RXPAUSEFRAMES                  EMAC_REG(RXPAUSEFRAMES)
#define EMAC_RXCRCERRORS                    EMAC_REG(RXCRCERRORS)
#define EMAC_RXALIGNCODEERRORS              EMAC_REG(RXALIGNCODEERRORS)
#define EMAC_RXOVERSIZED                    EMAC_REG(RXOVERSIZED)
#define EMAC_RXJABBER                       EMAC_REG(RXJABBER)
#define EMAC_RXUNDERSIZED                   EMAC_REG(RXUNDERSIZED)
#define EMAC_RXFRAGMENTS                    EMAC_REG(RXFRAGMENTS)
#define EMAC_RXFILTERED                     EMAC_REG(RXFILTERED)
#define EMAC_RXQOSFILTERED                  EMAC_REG(RXQOSFILTERED)
#define EMAC_RXOCTETS                       EMAC_REG(RXOCTETS)
#define EMAC_TXGOODFRAMES                   EMAC_REG(TXGOODFRAMES)
#define EMAC_TXBCASTFRAMES                  EMAC_REG(TXBCASTFRAMES)
#define EMAC_TXMCASTFRAMES                  EMAC_REG(TXMCASTFRAMES)
#define EMAC_TXPAUSEFRAMES                  EMAC_REG(TXPAUSEFRAMES)
#define EMAC_TXDEFERRED                     EMAC_REG(TXDEFERRED)
#define EMAC_TXCOLLISION                    EMAC_REG(TXCOLLISION)
#define EMAC_TXSINGLECOLL                   EMAC_REG(TXSINGLECOLL)
#define EMAC_TXMULTICOLL                    EMAC_REG(TXMULTICOLL)
#define EMAC_TXEXCESSIVECOLL                EMAC_REG(TXEXCESSIVECOLL)
#define EMAC_TXLATECOLL                     EMAC_REG(TXLATECOLL)
#define EMAC_TXUNDERRUN                     EMAC_REG(TXUNDERRUN)
#define EMAC_TXCARRIERSLOSS                 EMAC_REG(TXCARRIERSLOSS)
#define EMAC_TXOCTETS                       EMAC_REG(TXOCTETS)
#define EMAC_FRAME64                        EMAC_REG(FRAME64)
#define EMAC_FRAME65T127                    EMAC_REG(FRAME65T127)
#define EMAC_FRAME128T255                   EMAC_REG(FRAME128T255)
#define EMAC_FRAME256T511                   EMAC_REG(FRAME256T511)
#define EMAC_FRAME512T1023                  EMAC_REG(FRAME512T1023)
#define EMAC_FRAME1024TUP                   EMAC_REG(FRAME1024TUP)
#define EMAC_NETOCTETS                      EMAC_REG(NETOCTETS)
#define EMAC_RXSOFOVERRUNS                  EMAC_REG(RXSOFOVERRUNS)
#define EMAC_RXMOFOVERRUNS                  EMAC_REG(RXMOFOVERRUNS)
#define EMAC_RXDMAOVERRUNS                  EMAC_REG(RXDMAOVERRUNS)

#define _EMAC_RXGOODFRAMES_COUNT_MASK       0xFFFFFFFFu
#define _EMAC_RXBCASTFRAMES_COUNT_MASK      0xFFFFFFFFu
#define _EMAC_RXMCASTFRAMES_COUNT_MASK      0xFFFFFFFFu
#define _EMAC_RXPAUSEFRAMES_COUNT_MASK      0xFFFFFFFFu
#define _EMAC_RXCRCERRORS_COUNT_MASK        0xFFFFFFFFu
#define _EMAC_RXALIGNCODEERRORS_COUNT_MASK  0xFFFFFFFFu
#define _EMAC_RXOVERSIZED_COUNT_MASK        0xFFFFFFFFu
#define _EMAC_RXJABBER_COUNT_MASK           0xFFFFFFFFu
#define _EMAC_RXUNDERSIZED_COUNT_MASK       0xFFFFFFFFu
#define _EMAC_RXFRAGMENTS_COUNT_MASK        0xFFFFFFFFu
#define _EMAC_RXFILTERED_COUNT_MASK         0xFFFFFFFFu
#define _EMAC_RXQOSFILTERED_COUNT_MASK      0xFFFFFFFFu
#define _EMAC_RXOCTETS_COUNT_MASK           0xFFFFFFFFu
#define _EMAC_TXGOODFRAMES_COUNT_MASK       0xFFFFFFFFu
#define _EMAC_TXBCASTFRAMES_COUNT_MASK      0xFFFFFFFFu
#define _EMAC_TXMCASTFRAMES_COUNT_MASK      0xFFFFFFFFu
#define _EMAC_TXPAUSEFRAMES_COUNT_MASK      0xFFFFFFFFu
#define _EMAC_TXDEFERRED_COUNT_MASK         0xFFFFFFFFu
#define _EMAC_TXCOLLISION_COUNT_MASK        0xFFFFFFFFu
#define _EMAC_TXSINGLECOLL_COUNT_MASK       0xFFFFFFFFu
#define _EMAC_TXMULTICOLL_COUNT_MASK        0xFFFFFFFFu
#define _EMAC_TXEXCESSIVECOLL_COUNT_MASK    0xFFFFFFFFu
#define _EMAC_TXLATECOLL_COUNT_MASK         0xFFFFFFFFu
#define _EMAC_TXUNDERRUN_COUNT_MASK         0xFFFFFFFFu
#define _EMAC_TXCARRIERSLOSS_COUNT_MASK     0xFFFFFFFFu
#define _EMAC_TXOCTETS_COUNT_MASK           0xFFFFFFFFu
#define _EMAC_FRAME64_COUNT_MASK            0xFFFFFFFFu
#define _EMAC_FRAME65T127_COUNT_MASK        0xFFFFFFFFu
#define _EMAC_FRAME128T255_COUNT_MASK       0xFFFFFFFFu
#define _EMAC_FRAME256T511_COUNT_MASK       0xFFFFFFFFu
#define _EMAC_FRAME512T1023_COUNT_MASK      0xFFFFFFFFu
#define _EMAC_FRAME1024TUP_COUNT_MASK       0xFFFFFFFFu
#define _EMAC_NETOCTETS_COUNT_MASK          0xFFFFFFFFu
#define _EMAC_RXSOFOVERRUNS_COUNT_MASK      0xFFFFFFFFu
#define _EMAC_RXMOFOVERRUNS_COUNT_MASK      0xFFFFFFFFu
#define _EMAC_RXDMAOVERRUNS_COUNT_MASK      0xFFFFFFFFu

#define _EMAC_RXGOODFRAMES_COUNT_SHIFT      0u
#define _EMAC_RXBCASTFRAMES_COUNT_SHIFT     0u
#define _EMAC_RXMCASTFRAMES_COUNT_SHIFT     0u
#define _EMAC_RXPAUSEFRAMES_COUNT_SHIFT     0u
#define _EMAC_RXCRCERRORS_COUNT_SHIFT       0u
#define _EMAC_RXALIGNCODEERRORS_COUNT_SHIFT 0u
#define _EMAC_RXOVERSIZED_COUNT_SHIFT       0u
#define _EMAC_RXJABBER_COUNT_SHIFT          0u
#define _EMAC_RXUNDERSIZED_COUNT_SHIFT      0u
#define _EMAC_RXFRAGMENTS_COUNT_SHIFT       0u
#define _EMAC_RXFILTERED_COUNT_SHIFT        0u
#define _EMAC_RXQOSFILTERED_COUNT_SHIFT     0u
#define _EMAC_RXOCTETS_COUNT_SHIFT          0u
#define _EMAC_TXGOODFRAMES_COUNT_SHIFT      0u
#define _EMAC_TXBCASTFRAMES_COUNT_SHIFT     0u
#define _EMAC_TXMCASTFRAMES_COUNT_SHIFT     0u
#define _EMAC_TXPAUSEFRAMES_COUNT_SHIFT     0u
#define _EMAC_TXDEFERRED_COUNT_SHIFT        0u
#define _EMAC_TXCOLLISION_COUNT_SHIFT       0u
#define _EMAC_TXSINGLECOLL_COUNT_SHIFT      0u
#define _EMAC_TXMULTICOLL_COUNT_SHIFT       0u
#define _EMAC_TXEXCESSIVECOLL_COUNT_SHIFT   0u
#define _EMAC_TXLATECOLL_COUNT_SHIFT        0u
#define _EMAC_TXUNDERRUN_COUNT_SHIFT        0u
#define _EMAC_TXCARRIERSLOSS_COUNT_SHIFT    0u
#define _EMAC_TXOCTETS_COUNT_SHIFT          0u
#define _EMAC_FRAME64_COUNT_SHIFT           0u
#define _EMAC_FRAME65T127_COUNT_SHIFT       0u
#define _EMAC_FRAME128T255_COUNT_SHIFT      0u
#define _EMAC_FRAME256T511_COUNT_SHIFT      0u
#define _EMAC_FRAME512T1023_COUNT_SHIFT     0u
#define _EMAC_FRAME1024TUP_COUNT_SHIFT      0u
#define _EMAC_NETOCTETS_COUNT_SHIFT         0u
#define _EMAC_RXSOFOVERRUNS_COUNT_SHIFT     0u
#define _EMAC_RXMOFOVERRUNS_COUNT_SHIFT     0u
#define _EMAC_RXDMAOVERRUNS_COUNT_SHIFT     0u

#define EMAC_RXGOODFRAMES_COUNT_DEFAULT	    0x00000000u
#define	EMAC_RXBCASTFRAMES_COUNT_DEFAULT    0x00000000u
#define EMAC_RXMCASTFRAMES_COUNT_DEFAULT    0x00000000u
#define EMAC_RXPAUSEFRAMES_COUNT_DEFAULT    0x00000000u
#define EMAC_RXCRCERRORS_COUNT_DEFAULT      0x00000000u
#define EMAC_RXALIGNCODEERRORS_COUNT_DEFAULT 0x00000000u
#define	EMAC_RXOVERSIZED_COUNT_DEFAULT       0x00000000u
#define EMAC_RXJABBER_COUNT_DEFAULT          0x00000000u
#define EMAC_RXUNDERSIZED_COUNT_DEFAULT      0X00000000u
#define EMAC_RXFRAGMENTS_COUNT_DEFAULT	     0x00000000u
#define EMAC_RXFILTERED_COUNT_DEFAULT        0x00000000u
#define EMAC_RXQOSFILTERED_COUNT_DEFAULT     0x00000000u
#define EMAC_RXOCTETS_COUNT_DEFAULT          0x00000000u
#define EMAC_TXGOODFRAMES_COUNT_DEFAULT	     0x00000000u
#define EMAC_TXBCASTFRAMES_COUNT_DEFAULT     0x00000000u
#define EMAC_TXMCASTFRAMES_COUNT_DEFAULT     0x00000000u
#define EMAC_TXPAUSEFRAMES_COUNT_DEFAULT     0x00000000u
#define EMAC_TXDEFERRED_COUNT_DEFAULT        0x00000000u
#define EMAC_TXCOLLISION_COUNT_DEFAULT       0x00000000u
#define EMAC_TXSINGLECOLL_COUNT_DEFAULT      0x00000000u
#define EMAC_TXMULTICOLL_COUNT_DEFAULT       0x00000000u
#define EMAC_TXEXCESSIVECOLL_COUNT_DEFAULT   0x00000000u
#define EMAC_TXLATECOLL_COUNT_DEFAULT        0x00000000u
#define EMAC_TXUNDERRUN_COUNT_DEFAULT        0x00000000u
#define EMAC_TXCARRIERSLOSS_COUNT_DEFAULT    0x00000000u
#define EMAC_TXOCTETS_COUNT_DEFAULT          0x00000000u
#define EMAC_FRAME64_COUNT_DEFAULT           0x00000000u
#define EMAC_FRAME65T127_COUNT_DEFAULT	     0x00000000u
#define EMAC_FRAME128T255_COUNT_DEFAULT      0x00000000u
#define EMAC_FRAME256T511_COUNT_DEFAULT      0x00000000u
#define EMAC_FRAME512T1023_COUNT_DEFAULT     0x00000000u
#define EMAC_FRAME1024TUP_COUNT_DEFAULT      0x00000000u
#define EMAC_NETOCTETS_COUNT_DEFAULT         0x00000000u
#define EMAC_RXSOFOVERRUNS_COUNT_DEFAULT     0x00000000u
#define EMAC_RXMOFOVERRUNS_COUNT_DEFAULT     0x00000000u
#define EMAC_RXDMAOVERRUNS_COUNT_DEFAULT     0x00000000u
/******************************************************************************\
* _____________________
* |                   |
* |   EWTRCTRL        |
* |___________________|
*
* EWTRCTRL         - TR Control
*
* FIELDS (msb -> lsb)
*
* MACROS SUPPORTED
*  EMAC_FMK     .
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    .
*  EMAC_FSET    .
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_EWTRCTRL_ADDR                     (_EMAC_BASE_ADDR+0x3000u)

#define EMAC_EWTRCTRL                           EMAC_REG(EWTRCTRL)

/******************************************************************************\
* _____________________
* |                   |
* |   EWCTL           |
* |___________________|
*
* EWCTL             - Interrupt control register
*
* FIELDS (msb -> lsb)
*  (rw)  EMACRST    - EMAC Reset
*  (rw)  MDIORST    - MDIO Reset
*  (rw)  INTEN      - EMAC/MDIO Global Interrupt Enable
*
* MACROS SUPPORTED
*  EMAC_FMK     y
*  EMAC_FMKS    y
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    y
*  EMAC_FSET    y
*  EMAC_FSETS   y
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_EWCTL_ADDR                        (_EMAC_BASE_ADDR+0x3004u)

#define EMAC_EWCTL                              EMAC_REG(EWCTL)

#define _EMAC_EWCTL_EMACRST_MASK                0x4u
#define _EMAC_EWCTL_EMACRST_SHIFT               2u
#define  EMAC_EWCTL_EMACRST_DEFAULT             0x00000000u
#define EMAC_EWCTL_EMACRST_YES                  1u
#define EMAC_EWCTL_EMACRST_NO                   0u

#define _EMAC_EWCTL_MDIORST_MASK                0x2u
#define _EMAC_EWCTL_MDIORST_SHIFT               1u
#define  EMAC_EWCTL_MDIORST_DEFAULT             0x00000000u
#define EMAC_EWCTL_MDIORST_YES                  1u
#define EMAC_EWCTL_MDIORST_NO                   0u

#define _EMAC_EWCTL_INTEN_MASK                  0x1u
#define _EMAC_EWCTL_INTEN_SHIFT                 0u
#define  EMAC_EWCTL_INTEN_DEFAULT               0x00000000u
#define EMAC_EWCTL_INTEN_ENABLE                 1u
#define EMAC_EWCTL_INTEN_DISABLE                0u

/******************************************************************************\
* _____________________
* |                   |
* |   EWINTTCNT       |
* |___________________|
*
* EWINTTCNT         - Interrupt Timer Count
*
* FIELDS (msb -> lsb)
*
* MACROS SUPPORTED
*  EMAC_FMK     .
*  EMAC_FMKS    .
*  EMAC_FMKCHF  .
*  EMAC_ADDR    y
*  EMAC_REG     y
*  EMAC_RGET    y
*  EMAC_RSET    y
*  EMAC_FGET    .
*  EMAC_FSET    .
*  EMAC_FSETS   .
*  EMAC_RGETI   .
*  EMAC_RSETI   .
*  EMAC_FGETI   .
*  EMAC_FSETI   .
*  EMAC_FSETSI  .
*
\******************************************************************************/
#define _EMAC_EWINTTCNT_ADDR                    (_EMAC_BASE_ADDR+0x3008u)

#define EMAC_EWINTTCNT                          EMAC_REG(EWINTTCNT)



#endif /* EMAC_SUPPORT */

#endif /* _CSL_EMACHAL_H_ */
/******************************************************************************\
* End of csl_emachal.h
\******************************************************************************/





