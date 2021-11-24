/*************************************************************************
* FILENAME: $RCSfile: h2t.c,v $
* VERSION : $Revision: 1.2 $
* DATE    : $Date: 2000/11/03 19:16:30 $
* Copyright (c) 1997-2000 Texas Instruments Incorporated
*
* Host-To-Target Test:
*____________________________________________________________________
* - Reads 100 integers, one at a time, via RTDX_read().
* - Uses ONE input channel, and ONE output channel to report the
*   result.
*
* - Tests Data transmission from host to target at the User layer.
* - This is the module to be run on the TARGET.
* - This program is meant to be used with the RTDX Diagnostics
*   Control's Host-To-Target test option.
*************************************************************************/
#include <stdio.h>              /* fprintf(), puts()                    */
#include <stdlib.h>             /* abort()                              */
#include <rtdx.h>               /* RTDX                                 */
#include "target.h"             /* TARGET_INITIALIZE()                  */

#define ITERATIONS      100

typedef enum {FALSE,TRUE} BOOL;

/* Declare and initialize an:
* input channel called "ichan"
* output channel called "results"
*/

RTDX_CreateInputChannel(ichan);
RTDX_CreateOutputChannel(results);

struct tagData {
    int  recvd;                 /* Data received                        */
#ifdef HSRTDX
    // Silicon HSRTDX workaround...
    // - User must define extra 32bit word AFTER all Host-to-target receive
    //   buffers & align on 32bit boundaries.
#ifdef _TMS320C6X
    unsigned dummy;
#elif defined(__TMS320C55X__)
    unsigned long dummy;
#else
#error "Unknown how to use Dummy word for this target."
#endif
#endif
} data;

int  last_recvd=0;              /* Last data received                   */


void main( void )
{
    BOOL error = FALSE;         /* Assume false until error occurs      */
    BOOL first_time = TRUE;     /* Indicate first read                  */
    unsigned int i;             /* Loop counter                         */
    
    /* Target Specific Initialization                                   */
    TARGET_INITIALIZE();
    
    /* Enable the channels                                              */
    RTDX_enableInput(&ichan);
    RTDX_enableOutput(&results);
    
    printf("Recieving %d Messages from the Host...\n", ITERATIONS);
    for ( i = 0; i < ITERATIONS; i++ ) {
        unsigned ausrcvd;
        /* Initialize data received to validate change                  */
        data.recvd = 0;
        
        /* Request an integer from the host                             */
        ausrcvd = RTDX_read( &ichan, &data.recvd, sizeof(data.recvd));
        if( ausrcvd != sizeof(data.recvd) ) {
            fprintf(stderr, "\nError: RTDX_read() failed!\n");
            abort();
        }
        
        /* Set flag for first read                                      */
        if ( first_time ) {
            first_time = FALSE;
        } else {
            /* Validate sequential data                                 */
            if ( data.recvd != last_recvd + 1) {
                fprintf(stderr, "\nError: Unexpected Data!\n" \
                    "Received %i, Expected %i\n",
                    data.recvd, last_recvd);
                error = TRUE;
                break;
            }
        }
        /* Display what was read in the stdout window                   */
        fprintf(stdout, "Value %i was read from the host\n", data.recvd);
        last_recvd = data.recvd;
    }
    
    /* Send test result to the host                                     */
    RTDX_write( &results, &error, sizeof(error) );
    
    /* Wait for Target-to-Host transfer to complete                     */
    while ( RTDX_writing != NULL ) {
#if RTDX_POLLING_IMPLEMENTATION
        /* If polling implementation of RTDX...                         */
        /* ...call RTDX_Poll to do data transfer                        */
        RTDX_Poll();
#endif
    }
    
    /* Disable the channels                                             */
    RTDX_disableInput(&ichan);
    RTDX_disableOutput(&results);
    
    puts("\nApplication Completed ");
    if ( !error ) {
        puts("Successfully!");
    } else {
        puts("with Errors!");
    }
}
