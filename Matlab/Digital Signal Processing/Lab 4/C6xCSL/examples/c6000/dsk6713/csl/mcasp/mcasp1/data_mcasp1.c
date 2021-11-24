/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------data_mcasp1.c---------
 * Contains helper functions used to set up data in memory and 
 * test for correct McASP transfers
 */ 
 
#include "mcasp1.h"


/************************************************************************\
 name:      FillMem( Uint32 start_location, Uint32 length,
                      Uint32 fill_value, Uint8 fill_type )  

 purpose:   Fills a memory location with a pattern as requested. 
            Beginning at 'start_location', 'length' words (32-bit) are filled,
            starting with 'fill_value'.  After the initial value, the
            other memory locations are filled with either a constant
            value, incrementing values, or decrementing values.

 inputs:    Uint32 start_location : Memory location to start filling.
            Uint32 length : Number of bytes to fill.
            Uint32 fill_value : 32-bit value to start filling with.
            Uint8 fill_type : Type of fill: 
                              FILL_CONST, FILL_INC, FILL_DEC

 returns:   Uint32 flag : PASS for a success
                          ERROR_FILL for a failure
\************************************************************************/
Uint32 FillMem( Uint32 start_location, Uint32 length, Uint32 fill_value, Uint8 fill_type )
{
  Uint32         *loc;
  unsigned int   i;
  
  loc = (Uint32*) start_location;
  
  for (i = 0 ; i < length ; i++) {

      if (fill_type == FILL_CONST) {
          *loc = fill_value;
          if (*loc != fill_value)    /* Check that value was written correctly */
              return ERROR_FILL;
      }
      else if (fill_type == FILL_INC) {
          *loc = (Uint32)(fill_value+i);
          if ( *loc != (Uint32)(fill_value+i) )  /* Check that value was written correctly */
              return ERROR_FILL;
      }
      else if (fill_type == FILL_DEC) {
          *loc = (Uint32)(fill_value-i);
          if ( *loc != (Uint32)(fill_value-i) )  /* Check that value was written correctly */
              return ERROR_FILL;
      }
      else {                   /* Error if non-valid fill type */
          return ERROR_FILL;
      }
    
      loc++;
  }

  return PASS;
}


/************************************************************************\
 name:      ClearMem( Uint32 start_location, Uint32 length )  

 purpose:   Clears a memory location.  Beginning at 'start_location',
            'length' 32-bit words are set to zero.

 inputs:    Uint32 start_location : Memory location to start filling.
            Uint32 length : Number of 32-bit words to fill.

 returns:   Uint32 flag : PASS for a success
                          ERROR_FILL for a failure
\************************************************************************/
Uint32 ClearMem( Uint32 start_location, Uint32 length )
{
  return FillMem(start_location, length, 0x00000000, FILL_CONST);
}



/************************************************************************\
 name:      SetupSrcLocations(Uint32 desired_src_addr, Uint32 length,
                              Uint32 serializer )

 purpose:   Sets up src mem for a transfer. It fills the source space with an 
            alternating pattern between a set of incremented value
            and a set of zeros. The size of the "set" is equal to the 
            number of serializer pins. The incremented value is also processed.
            The following example assumes 8 serializer pins, in which case
            the src setup:
            
            0xF0001000, 0xF0002000, 0xF0003000, 0xF0004000
            0xF0005000, 0xF0006000, 0xF0007000, 0xF0008000            
            0x00000000, 0x00000000, 0x00000000, 0x00000000
            0x00000000, 0x00000000, 0x00000000, 0x00000000
            0xF0009000, 0xF000A000, 0xF000B000, 0xF000C000
            0xF000D000, 0xF000E000, 0xF000F000, 0xF0010000            
            0x00000000, 0x00000000, 0x00000000, 0x00000000
            0x00000000, 0x00000000, 0x00000000, 0x00000000
            ...etc.
 
            Note that this is setting up TWICE the amount of data
            needed for transfers (i.e. if the transmitter only 
            needs to transfer "length" number of words, this function
            sets up "length"*2 number of words.
            The DMA will be setup with a frame index to SKIP the zeros.
            In other words, the DMA only transfers the incremented
            values.

            The purpose of this setup is for testing inactive transmit
            slots for this particular testcase. The transmitter only
            transmits only every other active slots, while the receiver
            receives on ALL slots. Setting up data this way will allow
            the destination data to mimic the source setup and therefore
            data comparison will be easier.
            
            Note that EDMA frame index is to go from pointing to 0xF0001000
            to 0xF0009000. It has to "jump across" the zeros.
            This is calculated as:
            2 * NUM_XMT_SERIALIZER * word-size
            
            where word-size = 4 bytes
            
                        

 inputs:    
            Uint32 desired_src_addr : Memory to be used for test.
                                      Will be filled with a pattern.
            Uint32 length           : Number of 32-bit words to transmit            
            Uint32 serializer       : Number of transmit serializers

 returns:   n/a
\************************************************************************/
void SetupSrcLocations(Uint32 desired_src_addr, Uint32 length, Uint32 serializer)
{
  Uint32         *loc;
  unsigned int   i;
  unsigned int   j;
  unsigned int   inc = 0;
  Uint32         fill_value = 0xFFFF0001;


  /*-------------------------------------------------*/
  /* Fill source space                               */
  /*-------------------------------------------------*/  
  loc = (Uint32*) desired_src_addr;

  for (i = 0 ; i < length ; i = i + serializer) {
  
       /* Setup j incremental data, where j=number of xmt serializers */
       for (j = 0 ; j < serializer ; j++) {
            *loc = (fill_value + inc);
            ProcessMem((Uint32)loc, 1, SHIFT_LEFT, 12); /* process data at location */
            loc++;
            inc++;
       } /* end for j */

       /* Setup j 32-bit zero, where j = number of xmt serializers */  
       for (j = 0 ; j < serializer ; j++) {
            *loc = 0x00000000;
            loc++;  
       }
  }
  

}



/************************************************************************\
 name:      ProcessMem( Uint32 start_location, Uint32 length,
                      Uint8 shift_type, Uint8 shift_amount )  

 purpose:   Process data in memory.
            Beginning at 'start_location', 'length' words (32-bit) are processed.
            Every 32-bit word is shift left or right (determined by 
            "shift_type") for "shift_amount" bits.

 inputs:    Uint32 start_location : Memory location to start filling.
            Uint32 length : Number of bytes to fill.
            Uint8 shift_type : SHIFT_NONE: no shifting
                               SHIFT_LEFT: shift left by shift_amount bits
                                           pad rightmost bits with zero
                               SHIFT_RIGHT_SIGNED: shift right and sign
                                           extend to the leftmost bits
                               SHIFT_RIGHT_ZERO: shift right and pad leftmost
                                           bits with zero
            Uint8 shift_amount : Number of bits to shift

 returns:   Uint32 flag : PASS for a success
                          ERROR_FILL for a failure
\************************************************************************/
Uint32 ProcessMem( Uint32 start_location, Uint32 length, Uint8 shift_type, Uint8 shift_amount )
{
  Uint32         *loc;
  Uint32         value;
  Int32          valueSigned;
  unsigned int   i;
  
  loc = (Uint32*) start_location;
  
  for (i = 0 ; i < length ; i++) {

      if (shift_type == SHIFT_LEFT) {
           value = *loc; 
           value = value << shift_amount;
           *loc = value;
          if (*loc != value)    /* Check that value was written correctly */
              return ERROR_FILL;
      }
      else if (shift_type == SHIFT_RIGHT_SIGNED) {
           valueSigned = *loc; 
           valueSigned = valueSigned >> shift_amount;
           *loc = valueSigned;
          if (*loc != valueSigned)    /* Check that value was written correctly */
              return ERROR_FILL;
      }
      else if (shift_type == SHIFT_RIGHT_ZERO) {
           value = *loc; 
           value = value >> shift_amount;
           *loc = value;
          if (*loc != value)    /* Check that value was written correctly */
              return ERROR_FILL;
      }
      else if (shift_type == SHIFT_NONE) {
          /* do nothing */
      }
      else {                   /* Error if non-valid fill type */
          return ERROR_FILL;
      }
    
      loc++;
  }

  return PASS;
}


/************************************************************************\
 name:      CheckTransfer(Uint32 desired_src_addr, Uint32 desired_dst_addr
                             Uint32 length )

 purpose:   Checks that a transfer was successful by comparing the data
            in the destination scratch area against the data in the 
            source space. The total amount of data compared is "length"
            32-bit words.

            Before checking src and dst data, it processes the source
            data so that it will look like the dst data.
            In this case, SRC data is shifted right 12 bits and sign-extended.

            original SRC      processed SRC        DST
            0xF0001000        0xFFFF0001           0xFFFF0001
            0xF0002000        0xFFFF0002           0xFFFF0002
            ...
            0x00000000        0x00000000           0x00000000
            ...etc.


 inputs:    Uint32 desired_src_addr : Memory in the source space.
                                       
            Uint32 desired_dst_addr : Memory in the destination space.
                                       Should match source space
            Uint32 length           : Number of 32-bit words to check  
                                     

 returns:   Uint32 flag : PASS for a matching comparison
                          ERROR_TEST for a non-match
\************************************************************************/
Uint32 CheckTransfer(Uint32 desired_src_addr, Uint32 desired_dst_addr, Uint32 length )
{
  Uint32         *src_loc;
  Uint32         *dst_loc;
  unsigned int   i;


  /* Process data for compare between src and dst */
  /* this is testcase specific.                   */
  ProcessMem(desired_src_addr, length, SHIFT_RIGHT_SIGNED, 12); 

  /* Compare */
  src_loc = (Uint32*) desired_src_addr;
  dst_loc = (Uint32*) desired_dst_addr;
  
  for (i = 0 ; i < length ; i++) {
  
      if (*src_loc != *dst_loc) { 
           return ERROR_TEST;
      }     

      src_loc++;
      dst_loc++;
  }
  
  return PASS;  /* If no error from the previous, test passed */

}
