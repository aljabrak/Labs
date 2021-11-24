// ****************************************************************
// Description: This application uses ProbePoints to obtain input
// (a sine wave). It then takes this signal, and applies a gain
// factor to it.
// Filename: Sine.h
// ****************************************************************

// define boolean TRUE
#ifndef TRUE
#define TRUE 1
#endif

// buffer constants 
#define BUFFSIZE 0x64
#define INITIALGAIN 5

// IO buffer structure
typedef struct IOBuffer {				
	int input[BUFFSIZE]; 			
	int output[BUFFSIZE];	
} BufferContents;

                  	
