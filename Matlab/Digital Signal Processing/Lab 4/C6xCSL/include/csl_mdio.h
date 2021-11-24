/*****************************************************************************\
*           Copyright (C) 1999-2003 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_mdio.h
* DATE CREATED.. 02/08/2002
* LAST MODIFIED. 05/09/2003
*------------------------------------------------------------------------------
* NOTE:
*   When used in an multitasking environment, no MDIO function may be
*   called while another MDIO function is operating on the same device
*   handle in another thread. It is the responsibility of the application
*   to assure adherence to this restriction.
*
* ALSO NOTE:
*   When using the CSL EMAC module, the EMAC module will make use of this
*   MDIO module. It is not necessary for the application to call any MDIO
*   functions directly when the CSL EMAC module is in use.
*
\******************************************************************************/
#ifndef _CSL_MDIO_H
#define _CSL_MDIO_H_

#include <csl.h>
#include <csl_chip.h>
#include <csl_irq.h>
#include <csl_mdiohal.h>


#if (MDIO_SUPPORT)
/*-----------------------------------------------------------------------*\
* NEW TYPES
\*-----------------------------------------------------------------------*/
#ifndef _CSL_EMAC_TYPES
#define _CSL_EMAC_TYPES
typedef unsigned int uint;
typedef void * Handle;
#endif

/*-----------------------------------------------------------------------*\
* MDIO Configuration Mode Flags
*
* These flags determine how the MDIO module behaves
\*-----------------------------------------------------------------------*/
#define MDIO_MODEFLG_AUTONEG     0x0001 /* Use Autonegotiate         */
/* The following bits are used for manual and fallback configuration */
#define MDIO_MODEFLG_HD10        0x0002 /* Use 10Mb/s Half Duplex    */
#define MDIO_MODEFLG_FD10        0x0004 /* Use 10Mb/s Full Duplex    */
#define MDIO_MODEFLG_HD100       0x0008 /* Use 100Mb/s Half Duplex   */
#define MDIO_MODEFLG_FD100       0x0010 /* Use 100Mb/s Full Duplex   */
#define MDIO_MODEFLG_LOOPBACK    0x0020 /* Use PHY Loopback          */
/* The following bits are reserved for use by the MDIO module */
#define MDIO_MODEFLG_NWAYACTIVE  0x0040 /* NWAY is currently active  */

/*-----------------------------------------------------------------------*\
* MDIO Link Status Values
*
* These values indicate current PHY link status
\*-----------------------------------------------------------------------*/
#define MDIO_LINKSTATUS_NOLINK   0
#define MDIO_LINKSTATUS_HD10     1
#define MDIO_LINKSTATUS_FD10     2
#define MDIO_LINKSTATUS_HD100    3
#define MDIO_LINKSTATUS_FD100    4

/*-----------------------------------------------------------------------*\
* MDIO Events
*
* These events are returned by MDIO_timerTick() to allow the application
* (or EMAC) to track MDIO status.
\*-----------------------------------------------------------------------*/
#define MDIO_EVENT_NOCHANGE      0   /* No change from previous status */
#define MDIO_EVENT_LINKDOWN      1   /* Link down event                */
#define MDIO_EVENT_LINKUP        2   /* Link (or re-link) event        */
#define MDIO_EVENT_PHYERROR      3   /* No PHY connected               */


/*-----------------------------------------------------------------------*\
* MDIO_open()
*
* Opens the MDIO peripheral and start searching for a PHY device.
*
* It is assumed that the MDIO module is reset prior to calling this
* function.
\*-----------------------------------------------------------------------*/
CSLAPI Handle MDIO_open( uint mdioModeFlags );

/*-----------------------------------------------------------------------*\
* MDIO_close()
*
* Close the MDIO peripheral and disable further operation.
\*-----------------------------------------------------------------------*/
CSLAPI void MDIO_close( Handle hMDIO );

/*-----------------------------------------------------------------------*\
* MDIO_getStatus()
*
* Called to get the status of the MDIO/PHY
\*-----------------------------------------------------------------------*/
CSLAPI void MDIO_getStatus( Handle hMDIO, uint *pPhy, uint *pLinkStatus );

/*-----------------------------------------------------------------------*\
* MDIO_timerTick()
*
* Called to signify that approx 100mS have elapsed
*
* Returns an MDIO event code (see MDIO Events in CSL_MDIO.H).
\*-----------------------------------------------------------------------*/
CSLAPI uint MDIO_timerTick( Handle hMDIO );

/*-----------------------------------------------------------------------*\
* MDIO_initPHY()
*
* Force a switch to the specified PHY, and start negotiation.
*
* This call is only used to override the normal PHY detection process.
*
* Returns 1 if the PHY selection completed OK, else 0
\*-----------------------------------------------------------------------*/
CSLAPI uint MDIO_initPHY( Handle hMDIO, uint phyAddr );

/*-----------------------------------------------------------------------*\
* MDIO_phyRegRead()
*
* Raw data read of a PHY register.
*
* Returns 1 if the PHY ACK'd the read, else 0
\*-----------------------------------------------------------------------*/
CSLAPI uint MDIO_phyRegRead( uint phyIdx, uint phyReg, Uint16 *pData );

/*-----------------------------------------------------------------------*\
* MDIO_phyRegWrite()
*
* Raw data write  of a PHY register.
*
* Returns 1 if the PHY ACK'd the write, else 0
\*-----------------------------------------------------------------------*/
CSLAPI uint MDIO_phyRegWrite( uint phyIdx, uint phyReg, Uint16 data );

#endif /* MDIO_SUPPORT */
#endif /* _CSL_MDIO_H_ */
/******************************************************************************\
* End of mdio.h
\******************************************************************************/
