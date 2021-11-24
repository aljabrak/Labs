/*************************************************************************
* FILENAME: $RCSfile: t2h.c,v $
* VERSION : $Revision: 1.1 $
* DATE    : $Date: 2000/11/03 19:12:05 $
* Copyright (c) 1997-2000 Texas Instruments Incorporated
*
* Target-To-Host Test:
*____________________________________________________________________
* - Sends 100 integers, one at a time via RTDX_write().
* - Uses ONE output channel.
*
* - Tests Data transmission from target to host at the User layer.
* - This is the module to be run on the TARGET.
* - This program is meant to be used with the RTDX Diagnostics
*   Control's Target-To-Host test option.
*************************************************************************/
#include <stdio.h>              /* fprintf(), puts()                    */
#include <stdlib.h>             /* abort()                              */
#include <rtdx.h>               /* RTDX                                 */
#include "target.h"             /* TARGET_INITIALIZE()                  */

/* Declare and initialize an output channel called "ochan"              */
RTDX_CreateOutputChannel(ochan);

#define NUMBER_MESSAGES 100

void main( void )
{
    unsigned int data;
    
    /* Target Specific Initialization                                   */
    TARGET_INITIALIZE();
    
    /* Enable the output channel, "ochan"                               */
    RTDX_enableOutput(&ochan);
    
    printf("Sending %d Messages to Host...\n", NUMBER_MESSAGES);
    for ( data = 0; data < NUMBER_MESSAGES; data++ ) {
        /* Send the data to the host                                    */
        if ( !RTDX_write( &ochan, &data, sizeof(data) ) ) {
            fprintf(stderr, "\nError: RTDX_write() failed!\n");
            abort();
        }
        
        /* Wait for Target-to-Host transfer to complete                 */
        while ( RTDX_writing != NULL ) {
#if RTDX_POLLING_IMPLEMENTATION
            /* If polling implementation of RTDX...                     */
            /* ...call RTDX_Poll to do data transfer                    */
            RTDX_Poll();
#endif
        }
        
        /* Display what was sent in the stdout window                   */
        fprintf(stdout, "Value %i was sent to the host\n", data);
    }
    
    /* Disable the output channel, "ochan"                              */
    RTDX_disableOutput(&ochan);
    
    puts("\nTest Completed!"); 
}
