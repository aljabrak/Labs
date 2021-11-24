
// ****************************************************************
// Description: This application uses Probe Points to obtain input
// (a sine wave). It then takes this signal, and applies a gain
// factor to it.
// Filename: Sine.c
// ****************************************************************

#include <stdio.h>
#include "sine.h"

// gain control variable 
int gain = INITIALGAIN;   

// declare and initalize a IO buffer	   
BufferContents currentBuffer;

// Define some functions 
static void processing();						// process the input and generate output 
static void dataIO();							// dummy function to be used with ProbePoint

void main()
{
	puts("SineWave example started.\n");
			
    while(TRUE) // loop forever
    {       
        /*  Read input data using a probe-point connected to a host file. 
            Write output data to a graph connected through a probe-point. */
        dataIO();
        
        /* Apply the gain to the input to obtain the output */
        processing();
    }
}

/*
 * FUNCTION:		Apply signal processing transform to input signal 
 *			 		to generate output signal
 * PARAMETERS: 		BufferContents struct containing input/output arrays of size BUFFSIZE
 * RETURN VALUE: 	none.
 */
static void processing()
{
    int size = BUFFSIZE;

    while(size--){
        currentBuffer.output[size] = currentBuffer.input[size] * gain;	// apply gain to input
    }
}

/*
 * FUNCTION: 		Read input signal and write processed output signal
 *					using ProbePoints
 * PARAMETERS: none.
 * RETURN VALUE: none.
 */
static void dataIO()
{
    /* do data I/O */
    return;
}

