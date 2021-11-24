/*****************************************************************************\
*           Copyright (C) 1999-2003 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_emac.h
* DATE CREATED.. 02/08/2002
* LAST MODIFIED. 04/24/2003
*------------------------------------------------------------------------------
* NOTE:
*   When used in an multitasking environment, no EMAC function may be
*   called while another EMAC function is operating on the same device
*   handle in another thread. It is the responsibility of the application
*   to assure adherence to this restriction.
*
\******************************************************************************/
#ifndef _CSL_EMAC_H
#define _CSL_EMAC_H_

/* Include the main CSL file */
#include <csl.h>

#include <csl_mdio.h>

#if (EMAC_SUPPORT)
/*-----------------------------------------------------------------------*\
* NEW TYPES
\*-----------------------------------------------------------------------*/
#ifndef _CSL_EMAC_TYPES
#define _CSL_EMAC_TYPES
typedef unsigned int uint;
typedef void * Handle;
#endif

/*-----------------------------------------------------------------------*\
* STANDARD DATA STRUCTURES
\*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*\
* EMAC_Pkt
*
* The packet structure defines the basic unit of memory used to hold data
* packets for the EMAC device.
*
* A packet is comprised of one or more packet buffers. Each packet buffer
* contains a packet buffer header, and a pointer to the buffer data.
* The EMAC_Pkt structure defines the packet buffer header.
*
* The pDataBuffer field points to the packet data. This is set when the
* buffer is allocated, and is not altered.
*
* BufferLen holds the the total length of the data buffer that is used to
* store the packet (or packet fragment). This size is set by the entity
* that originally allocates the buffer, and is not altered.
*
* The Flags field contains additional information about the packet
*
* ValidLen holds the length of the valid data currently contained in the
* data buffer.
*
* DataOffset is the byte offset from the start of the data buffer to the
* first byte of valid data. Thus (ValidLen+DataOffet)<=BufferLen.
*
* Note that for receive buffer packets, the DataOffset field may be
* assigned before there is any valid data in the packet buffer. This allows
* the application to reserve space at the top of data buffer for private
* use. In all instances, the DataOffset field must be valid for all packets
* handled by EMAC.
*
* The data portion of the packet buffer represents a packet or a fragment
* of a larger packet. This is determined by the Flags parameter. At the
* start of every packet, the SOP bit is set in Flags. If the EOP bit is
* also set, then the packet is not fragmented. Otherwise; the next packet
* structure pointed to by the pNext field will contain the next fragment in
* the packet. On either type of buffer, when the SOP bit is set in Flags,
* then the PktChannel, PktLength, and PktFrags fields must also be valid.
* These fields contain additional information about the packet.
*
* The PktChannel field detetmines what channel the packet has arrived on,
* or what channel it should be transmitted on. The EMAC library supports
* only a single receive channel, but allows for up to eight transmit
* channels. Transmit channels can be treated as round-robin or priority
* queues.
*
* The PktLength field holds the size of the entire packet. On single frag
* packets (both SOP and EOP set in BufFlags), PktLength and ValidLen will
* be equal.
*
* The PktFrags field holds the number of fragments (EMAC_Pkt records) used
* to describe the packet. If more than 1 frag is present, the first record
* must have EMAC_PKT_FLAGS_SOP flag set, with corresponding fields validated.
* Each frag/record must be linked list using the pNext field, and the final
* frag/record must have EMAC_PKT_FLAGS_EOP flag set and pNext=0.
*
* In systems where the packet resides in cacheable memory, the data buffer
* must start on a cache line boundary and be an even multiple of cache
* lines in size. The EMAC_Pkt header must not appear in the same cache line
* as the data portion of the packet. On multi-fragment packets, some packet
* fragments may reside in cacheable memory where others do not.
*
* ** NOTE: It is up to the caller to assure that all packet buffers    **
* ** residing in cacheable memory are not currently stored in L1 or L2 **
* ** cache when passed to any EMAC function                             **
*
* Some of the packet Flags can only be set if the device is in the
* proper configuration to receive the corresponding frames. In order to
* enable these flags, the following modes must be set:
*       RxCrc Flag  : RXCRC Mode in EMAC_Config
*       RxErr Flags : PASSERROR Mode in EMAC_Config
*       RxCtl Flags : PASSCONTROL Mode in EMAC_Config
*       RxPrm Flag  : EMAC_RXFILTER_ALL in EMAC_setReceiveFilter()
*
\*-----------------------------------------------------------------------*/
typedef struct _EMAC_Pkt {
    Uint32           AppPrivate;   /* For use by the application            */
    struct _EMAC_Pkt *pPrev;       /* Previous record                       */
    struct _EMAC_Pkt *pNext;       /* Next record                           */
    Uint8            *pDataBuffer; /* Pointer to Data Buffer (read only)    */
    Uint32          BufferLen;    /* Physical Length of buffer (read only) */
    Uint32          Flags;        /* Packet Flags                          */
    Uint32          ValidLen;     /* Length of valid data in buffer        */
    Uint32          DataOffset;   /* Byte offset to valid data             */
    Uint32          PktChannel;   /* Tx/Rx Channel/Priority 0-7 (SOP only) */
    Uint32          PktLength;    /* Length of Packet (SOP only)           */
                                  /* (same as ValidLen on single frag Pkt) */
    Uint32          PktFrags;     /* Number of frags in packet (SOP only)  */
                                   /* (frag is EMAC_Pkt record - normally 1)*/
    } EMAC_Pkt;

/*
// Packet Buffer Flags set in Flags
*/
#define EMAC_PKT_FLAGS_SOP         0x80000000u /* Start of packet           */
#define EMAC_PKT_FLAGS_EOP         0x40000000u /* End of packet             */

/*
// The Following Packet flags are set in Flags on RX packets only
*/
#define EMAC_PKT_FLAGS_HASCRC      0x04000000u /* RxCrc: PKT has 4byte CRC  */
#define EMAC_PKT_FLAGS_JABBER      0x02000000u /* RxErr: Jabber             */
#define EMAC_PKT_FLAGS_OVERSIZE    0x01000000u /* RxErr: Oversize           */
#define EMAC_PKT_FLAGS_FRAGMENT    0x00800000u /* RxErr: Fragment           */
#define EMAC_PKT_FLAGS_UNDERSIZED  0x00400000u /* RxErr: Undersized         */
#define EMAC_PKT_FLAGS_CONTROL     0x00200000u /* RxCtl: Control Frame      */
#define EMAC_PKT_FLAGS_OVERRUN     0x00100000u /* RxErr: Overrun            */
#define EMAC_PKT_FLAGS_CODEERROR   0x00080000u /* RxErr: Code Error         */
#define EMAC_PKT_FLAGS_ALIGNERROR  0x00040000u /* RxErr: Alignment Error    */
#define EMAC_PKT_FLAGS_CRCERROR    0x00020000u /* RxErr: Bad CRC            */
#define EMAC_PKT_FLAGS_NOMATCH     0x00010000u /* RxPrm: No Match           */


/*-----------------------------------------------------------------------*\
* EMAC_Config
*
* The config structure defines how the EMAC device should operate. It is
* passed to the device when the device is opened, and remains in effect
* until the device is closed.
*
* The following is a short description of the configuration fields:
*
* ModeFlags    - Specify the Fixed Operating Mode of the Device
* EMAC_CONFIG_MODEFLG_CHPRIORITY  - Treat TX channels as Priority Levels
*                                  (Channel 7 is highest, 0 is lowest)
* EMAC_CONFIG_MODEFLG_MACLOOPBACK - Set MAC in Internal Loopback for Testing
* EMAC_CONFIG_MODEFLG_RXCRC       - Include the 4 byte EtherCRC in RX frames
* EMAC_CONFIG_MODEFLG_TXCRC       - Assume TX Frames Include 4 byte EtherCRC
* EMAC_CONFIG_MODEFLG_PASSERROR   - Receive Error Frames for Testing
* EMAC_CONFIG_MODEFLG_PASSCONTROL - Receive Control Frames for Testing
*
* MdioModeFlags - Specify the MDIO/PHY Operation (See EMACMDIO.H)
*
* TxChannels    - Number of TX Channels to use (1-8, usually 1)
*
* MacAddr       - Device MAC address
*
* RxMaxPktPool  - Max Rx packet buffers to get from pool
*                 (Must be in the range of 8 to 192)
*
* A list of callback functions is used to register callback functions with
* a particular instance of the EMAC peripheral. Callback functions are
* used by EMAC to communicate with the application. These functions are
* REQUIRED for operation. The same callback table can be used for multiple
* driver instances.
*
* The callback functions can be used by EMAC during any EMAC function, but
* mostly occur during calls to EMAC_statusIsr() and EMAC_statusPoll().
*
* pfcbGetPacket -  Called by EMAC to get a free packet buffer from the
*                  application layer for receive data. This function
*                  should return NULL is no free packets are available.
*                  The size of the packet buffer must be large enough
*                  to accommodate a full sized packet (1514 or 1518
*                  depending on the EMAC_CONFIG_MODEFLG_RXCRC flag), plus
*                  any application buffer padding (DataOffset).
*
* pfcbFreePacket - Called by EMAC to give a free packet buffer back to
*                  the application layer. This function is used to
*                  return transmit packets. Note that at the time of the
*                  call, structure fields other than pDataBuffer and
*                  BufferLen are in an undefined state.
*
* pfcbRxPacket   - Called to give a received data packet to the application
*                  layer. The applicaiton must accept the packet.
*                  When the application is finished with the packet, it
*                  can return it to its own free queue.
*
*                  This function also returns a pointer to a free packet to
*                  replace the received packet on the EMAC free list. It
*                  returns NULL when no free packets are available. The
*                  return packet is the same as would be returned by
*                  pfcbGetPacket.
*
*                  Thus if a newly received packet is not desired, it can
*                  simply be returned to EMAC via the return value.
*
* pfcbStatus     - Called to indicate to the application that it
*                  should call EMAC_getStatus() to read the current
*                  device status. This call is made when device status
*                  changes.
*
* pfcbStatistics - Called to indicate to the application that it
*                  should call EMAC_getStatistics() to read the
*                  current Ethernet statistics. Called when the
*                  statistic counters are to the point of overflow.
*
* The hApplication calling calling argument is the application's handle
* as supplied to the EMAC device in the EMAC_open() function.
\*-----------------------------------------------------------------------*/
typedef struct _EMAC_Config {
    uint        ModeFlags;      /* Configuation Mode Flags                */
    uint        MdioModeFlags;  /* CSL_MDIO Mode Flags (see CSL_MDIO.H)   */
    uint        TxChannels;     /* Number of Tx Channels to use (1-8)     */
    Uint8       MacAddr[6];     /* Mac Address                            */
    uint        RxMaxPktPool;   /* Max Rx packet buffers to get from pool */
    EMAC_Pkt *  (*pfcbGetPacket)(Handle hApplication);
    void        (*pfcbFreePacket)(Handle hApplication, EMAC_Pkt *pPacket);
    EMAC_Pkt *  (*pfcbRxPacket)(Handle hApplication, EMAC_Pkt *pPacket);
    void        (*pfcbStatus)(Handle hApplication);
    void        (*pfcbStatistics)(Handle hApplication);
} EMAC_Config;

/*
//  Configuration Mode Flags
*/
#define EMAC_CONFIG_MODEFLG_CHPRIORITY  0x0001 /* Use Tx channel priority  */
#define EMAC_CONFIG_MODEFLG_MACLOOPBACK 0x0002 /* MAC internal loopback    */
#define EMAC_CONFIG_MODEFLG_RXCRC       0x0004 /* Include CRC in RX frames */
#define EMAC_CONFIG_MODEFLG_TXCRC       0x0008 /* Tx frames include CRC    */
#define EMAC_CONFIG_MODEFLG_PASSERROR   0x0010 /* Pass error frames        */
#define EMAC_CONFIG_MODEFLG_PASSCONTROL 0x0020 /* Pass control frames      */

/*-----------------------------------------------------------------------*\
* EMAC_Status
*
* The status structure contains information about the MAC's run-time
* status.
*
* The following is a short description of the configuration fields:
*
* MdioLinkStatus - Current link status (non-zero on link) (see CSL_MDIO.H)
*
* PhyDev         - Current PHY device in use (0-31)
*
* RxPktHeld      - Current number of Rx packets held by the EMAC device
*
* TxPktHeld      - Current number of Tx packets held by the EMAC device
*
* FatalError     - Fatal Error Code (TBD)
\*-----------------------------------------------------------------------*/
typedef struct _EMAC_Status {
    uint        MdioLinkStatus; /* CSL_MDIO Link status (see CSL_MDIO.H) */
    uint        PhyDev;         /* Current PHY device in use (0-31)      */
    uint        RxPktHeld;      /* Number of packets held for Rx         */
    uint        TxPktHeld;      /* Number of packets held for Tx         */
    uint        FatalError;     /* Fatal Error when non-zero             */
} EMAC_Status;


/*-----------------------------------------------------------------------*\
* EMAC_Statistics
*
* The statistics structure is the used to retrieve the current count
* of various packet events in the system. These values represent the
* delta values from the last time the statistics were read.
\*-----------------------------------------------------------------------*/
typedef struct _EMAC_Statistics {
    Uint32 RxGoodFrames;     /* Good Frames Received                         */
    Uint32 RxBCastFrames;    /* Good Broadcast Frames Received               */
    Uint32 RxMCastFrames;    /* Good Multicast Frames Received               */
    Uint32 RxPauseFrames;    /* PauseRx Frames Received                      */
    Uint32 RxCRCErrors;      /* Frames Received with CRC Errors              */
    Uint32 RxAlignCodeErrors;/* Frames Received with Alignment/Code Errors   */
    Uint32 RxOversized;      /* Oversized Frames Received                    */
    Uint32 RxJabber;         /* Jabber Frames Received                       */
    Uint32 RxUndersized;     /* Undersized Frames Received                   */
    Uint32 RxFragments;      /* Rx Frame Fragments Received                  */
    Uint32 RxFiltered;       /* Rx Frames Filtered Based on Address          */
    Uint32 RxQOSFiltered;    /* Rx Frames Filtered Based on QoS Filtering    */
    Uint32 RxOctets;         /* Total Received Bytes in Good Frames          */
    Uint32 TxGoodFrames;     /* Good Frames Sent                             */
    Uint32 TxBCastFrames;    /* Good Broadcast Frames Sent                   */
    Uint32 TxMCastFrames;    /* Good Multicast Frames Sent                   */
    Uint32 TxPauseFrames;    /* PauseTx Frames Sent                          */
    Uint32 TxDeferred;       /* Frames Where Transmission was Deferred       */
    Uint32 TxCollision;      /* Total Frames Sent With Collision             */
    Uint32 TxSingleColl;     /* Frames Sent with Exactly One Collision       */
    Uint32 TxMultiColl;      /* Frames Sent with Multiple Colisions          */
    Uint32 TxExcessiveColl;  /* Tx Frames Lost Due to Excessive Collisions   */
    Uint32 TxLateColl;       /* Tx Frames Lost Due to a Late Collision       */
    Uint32 TxUnderrun;       /* Tx Frames Lost with Transmit Underrun Error  */
    Uint32 TxCarrierSLoss;   /* Tx Frames Lost Due to Carrier Sense Loss     */
    Uint32 TxOctets;         /* Total Transmitted Bytes in Good Frames       */
    Uint32 Frame64;          /* Total Tx&Rx with Octet Size of 64            */
    Uint32 Frame65t127;      /* Total Tx&Rx with Octet Size of 65 to 127     */
    Uint32 Frame128t255;     /* Total Tx&Rx with Octet Size of 128 to 255    */
    Uint32 Frame256t511;     /* Total Tx&Rx with Octet Size of 256 to 511    */
    Uint32 Frame512t1023;    /* Total Tx&Rx with Octet Size of 512 to 1023   */
    Uint32 Frame1024tUp;     /* Total Tx&Rx with Octet Size of >=1024      */
    Uint32 NetOctets;        /* Sum of all Octets Tx or Rx on the Network    */
    Uint32 RxSOFOverruns;    /* Total Rx Start of Frame Overruns             */
    Uint32 RxMOFOverruns;    /* Total Rx Middle of Frame Overruns            */
    Uint32 RxDMAOverruns;    /* Total Rx DMA Overruns                        */
} EMAC_Statistics;


/*-----------------------------------------------------------------------*\
* Packet Filtering
*
* Packet Filtering Settings (cumulative)
\*-----------------------------------------------------------------------*/
#define EMAC_RXFILTER_NOTHING      0
#define EMAC_RXFILTER_DIRECT       1
#define EMAC_RXFILTER_BROADCAST    2
#define EMAC_RXFILTER_MULTICAST    3
#define EMAC_RXFILTER_ALLMULTICAST 4
#define EMAC_RXFILTER_ALL          5

/*-----------------------------------------------------------------------*\
* STANDARD ERROR CODES
\*-----------------------------------------------------------------------*/
#define EMAC_ERROR_ALREADY   1   /* Operation has already been started        */
#define EMAC_ERROR_NOTREADY  2   /* Device is not open or not ready           */
#define EMAC_ERROR_DEVICE    3   /* Device hardware error                     */
#define EMAC_ERROR_INVALID   4   /* Function or calling parameter is invalid  */
#define EMAC_ERROR_BADPACKET 5   /* Supplied packet was invalid               */
#define EMAC_ERROR_MACFATAL  6   /* Fatal Error in MAC - EMAC_close() required */

/*-----------------------------------------------------------------------*\
* STANDARD API FUNCTIONS
*
* IMPORTANT NOTE
* --------------
*   The application is charged with verifying that only one of the
* following API calls may only be executing at a given time across
* all threads and all interrupt functions.
*
\*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*\
* EMAC_enumerate()
*
* Enumerates the EMAC peripherals installed in the system and returns an
* integer count. The EMAC devices are enumerated in a consistent
* fashion so that each device can be later referenced by its physical
* index value ranging from "1" to "n" where "n" is the count returned
* by this function.
\*-----------------------------------------------------------------------*/
CSLAPI uint EMAC_enumerate( void );


/*-----------------------------------------------------------------------*\
* EMAC_open()
*
* Opens the EMAC peripheral at the given physical index and initializes
* it to an embryonic state.
*
* The calling application must supply a operating configuration that
* includes a callback function table. Data from this config structure is
* copied into the device's internal instance structure so the structure
* may be discarded after EMAC_open() returns. In order to change an item
* in the configuration, the the EMAC device must be closed and then
* re-opened with the new configuration.
*
* The application layer may pass in an hApplication callback handle,
* that will be supplied by the EMAC device when making calls to the
* application callback functions.
*
* An EMAC device handle is written to phEMAC. This handle must be saved
* by the caller and then passed to other EMAC device functions.
*
* The default receive filter prevents normal packets from being received
* until the receive filter is specified by calling EMAC_receiveFilter().
*
* A device reset is achieved by calling EMAC_close() followed by EMAC_open().
*
* The function returns zero on success, or an error code on failure.
*
* Possible error codes include:
*   EMAC_ERROR_ALREADY   - The device is already open
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*
\*-----------------------------------------------------------------------*/
CSLAPI uint EMAC_open( int physicalIndex, Handle hApplication,
                       EMAC_Config *pEMACConfig, Handle *phEMAC );


/*-----------------------------------------------------------------------*\
* EMAC_close()
*
* Closed the EMAC peripheral indicated by the supplied instance handle.
* When called, the EMAC device will shutdown both send and receive
* operations, and free all pending transmit and receive packets.
*
* The function returns zero on success, or an error code on failure.
*
* Possible error code include:
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*
\*-----------------------------------------------------------------------*/
CSLAPI uint EMAC_close( Handle hEMAC );


/*-----------------------------------------------------------------------*\
* EMAC_getStatus()
*
* Called to get the current status of the device. The device status
* is copied into the supplied data structure.
*
* The function returns zero on success, or an error code on failure.
*
* Possible error code include:
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*
\*-----------------------------------------------------------------------*/
CSLAPI uint EMAC_getStatus( Handle hEMAC, EMAC_Status *pStatus );


/*-----------------------------------------------------------------------*\
* EMAC_setReceiveFilter()
*
* Called to set the packet filter for received packets. The filtering
* level is inclusive, so BROADCAST would include both BROADCAST and
* DIRECTED (UNICAST) packets.
*
* Available filtering modes include the following:
*  EMAC_RXFILTER_NOTHING      - Receive nothing
*  EMAC_RXFILTER_DIRECT       - Receive only Unicast to local MAC addr
*  EMAC_RXFILTER_BROADCAST    - Receive direct and Broadcast
*  EMAC_RXFILTER_MULTICAST    - Receive above plus multicast in mcast list
*  EMAC_RXFILTER_ALLMULTICAST - Receive above plus all multicast
*  EMAC_RXFILTER_ALL          - Receive all packets
*
* Note that if error frames and control frames are desired, reception of
* these must be specified in the device configuration.
*
* The function returns zero on success, or an error code on failure.
*
* Possible error code include:
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*
\*-----------------------------------------------------------------------*/
CSLAPI uint EMAC_setReceiveFilter( Handle hEMAC, uint ReceiveFilter );


/*-----------------------------------------------------------------------*\
* EMAC_getReceiveFilter()
*
* Called to get the current packet filter setting for received packets.
* The filter values are the same as those used in EMAC_setReceiveFilter().
*
* The current filter value is writter to the pointer supplied in
* pReceiveFilter.
*
* The function returns zero on success, or an error code on failure.
*
* Possible error code include:
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*
\*-----------------------------------------------------------------------*/
CSLAPI uint EMAC_getReceiveFilter( Handle hEMAC, uint *pReceiveFilter );


/*-----------------------------------------------------------------------*\
* EMAC_getStatistics()
*
* Called to get the current device statistics. The statistics structure
* contains a collection of event counts for various packet sent and
* receive properties. Reading the statistics also clears the current
* statistic counters, so the values read represent a delta from the last
* call.
*
* The statistics information is copied into the structure pointed to
* by the pStatistics argument.
*
* The function returns zero on success, or an error code on failure.
*
* Possible error code include:
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*
\*-----------------------------------------------------------------------*/
CSLAPI uint EMAC_getStatistics( Handle hEMAC, EMAC_Statistics *pStatistics );


/*-----------------------------------------------------------------------*\
* EMAC_setMulticast()
*
* This function is called to install a list of multicast addresses for
* use in multicast address filtering. Each time this function is called,
* any current multicast configuration is discarded in favor of the new
* list. Thus a set with a list size of zero will remove all multicast
* addresses from the device.
*
* Note that the multicast list configuration is stateless in that the
* list of multicast addresses used to build the configuration is not
* retained. Thus it is impossible to examine a list of currently installed
* addresses.
*
* The addresses to install are pointed to by pMCastList. The length of
* this list in bytes is 6 times the value of AddrCnt. When AddrCnt is
* zero, the pMCastList parameter can be NULL.
*
* The function returns zero on success, or an error code on failure.
* The multicast list settings are not altered in the event of a failure
* code.
*
* Possible error code include:
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*
\*-----------------------------------------------------------------------*/
CSLAPI uint EMAC_setMulticast( Handle hEMAC, uint AddrCnt, Uint8 *pMCastList );



/*-----------------------------------------------------------------------*\
* EMAC_sendPacket()
*
* Sends a Ethernet data packet out the EMAC device. On a non-error return,
* the EMAC device takes ownership of the packet. The packet is returned
* to the application's free pool once it has been transmitted.
*
* The function returns zero on success, or an error code on failure.
* When an error code is returned, the EMAC device has not taken ownership
* of the packet.
*
* Possible error codes include:
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*   EMAC_ERROR_BADPACKET - The packet structure is invalid
*
\*-----------------------------------------------------------------------*/
CSLAPI uint EMAC_sendPacket( Handle hEMAC, EMAC_Pkt *pPacket );


/*-----------------------------------------------------------------------*\
* EMAC_serviceCheck()
*
* This function should be called every time there is an EMAC device
* interrupt. It maintains the status the EMAC.
*
* Note that the application has the responsibility for mapping the
* physical device index to the correct EMAC_serviceCheck() function. If
* more than one EMAC device is on the same interrupt, the function must be
* called for each device.
*
* Possible error codes include:
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*   EMAC_ERROR_MACFATAL  - Fatal error in the MAC - Call EMAC_close()
*
\*-----------------------------------------------------------------------*/
CSLAPI uint EMAC_serviceCheck( Handle hEMAC );


/*-----------------------------------------------------------------------*\
* EMAC_timerTick()
*
* This function should be called for each device in the system on a
* periodic basis of 100mS (10 times a second). It is used to check the
* status of the EMAC and MDIO device, and to potentially recover from
* low Rx buffer conditions.
*
* Strict timing is not required, but the application should make a
* reasonable attempt to adhere to the 100mS mark. A missed call should
* not be "made up" by making mulitple sequential calls.
*
* A "polling" driver (one that calls EMAC_serviceCheck() in a tight loop),
* must also adhere to the 100mS timing on this function.
*
* Possible error codes include:
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*
\*-----------------------------------------------------------------------*/
CSLAPI uint EMAC_timerTick( Handle hEMAC );

#endif /* EMAC_SUPPORT */
#endif /* _CSL_EMAC_H_ */

/******************************************************************************\
* End of emi.h
\******************************************************************************/

