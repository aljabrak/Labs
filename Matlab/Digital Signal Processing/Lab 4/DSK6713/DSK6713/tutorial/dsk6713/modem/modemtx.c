#include "modemtx.h"
#include "razedcos.h"  /* table for raised cosine shaping filter */
#include "sinetab.h"   /* sine look-up table */

/* definition of constelation space */
struct POINT constellation[NUM_CONSTELATION_POINTS] = 
{
	/* first quadrant */
	{0x1000, 0x1000},
	{0x3000, 0x3000},
	{0x1000, 0x3000},
	{0x3000, 0x1000},

	/* second quadrant */
	{-0x1000, 0x1000},
	{-0x3000, 0x3000},
	{-0x1000, 0x3000},
	{-0x3000, 0x1000},

	/* third quadrant */
	{-0x1000, -0x1000},
	{-0x3000, -0x3000},
	{-0x1000, -0x3000},
	{-0x3000, -0x1000},

	/* fourth quadrant */
	{0x1000, -0x1000},
	{0x3000, -0x3000},
	{0x1000, -0x3000},
	{0x3000, -0x1000},
};

/* global structures */
struct MODEM_PARAMETERS g_ModemData;

struct TEST
{
	long i;
	long j;
} g_test;


/*******************************************************
	SineLookup()
	============
	
	This function returns a sine function.  It is 
	implemented with a 1/4 wave look up table.  To 
	
	
	
*******************************************************/
int SineLookup(int sample)
{                                             
	int sineValue;
	
	/* Find offset into 1/4 wave table, adjusting
		for quadrants 2 and 4 */
	int offset = sample & (SIZE_SINE_TABLE-1);
	if (sample & SIZE_SINE_TABLE)  
		offset = SIZE_SINE_TABLE-1-offset;      

	/* Read value from sine table, 
		adjusting the sign for quadrants 3 and 4 */		
	sineValue = sineTable[offset];
	if (sample & (SIZE_SINE_TABLE*2))
		sineValue = -sineValue;

	return(sineValue);
}

/*******************************************************
	CosineLookup()
	==============
	
	This function returns a cosine function.  It is 
	implemented by calling the SineLookup() function
	and adjusting the phase.
	
*******************************************************/
int CosineLookup(int sample)
{
	return( SineLookup(sample + SIZE_SINE_TABLE) );
}

/*******************************************************
	Modulation()
	==============
	
	This function the modulated result of an in-phase
	and quadrature phase component, added together.
	
*******************************************************/
int Modulation(int Isample, int Qsample, int phase)
{   
#if defined(PROD_C6X)
	/* work-around C6x compiler bug when using long multiplication */
	long result = (short)Isample * (short)SineLookup(phase);
	result += (short)Qsample * (short)CosineLookup(phase);
#else
	long result = (long)Isample * (long)SineLookup(phase);
	result += (long)Qsample * (long)CosineLookup(phase);
#endif
	result >>= 14;
	return((int)result);
}

/*******************************************************
	ShapingFilter()
	===============
	
	This function shapes either the in-phase or 
	quadrature phase component using a raised cosine
	filter.  The user must pass in a delayLine big
	enough to hold the shaping filter.  The output
	is calculated one baud at a time, and is found at 
	the front of the delay line.
	
*******************************************************/
void ShapingFilter(int *delayLine, int amplitudeOfSymbol)
{
	int i;
	
	/* shift the delay line */
	for(i = 0; i < SIZE_SHAPING_FILTER - SAMPLES_PER_BAUD; i++ )
	{
		delayLine[i] = delayLine[i+SAMPLES_PER_BAUD];
	}

	/* clear end of delay buffer before addition operation */
	for( ; i < SIZE_SHAPING_FILTER; i++ )
	{
		delayLine[i] = 0;
	}

	/* add new symbol into delay line  */
	for( i = SIZE_SHAPING_FILTER; i--; )
	{
	#if defined(PROD_C6X)
		delayLine[i] += (((short)raisedCosineTable[i] * (short)amplitudeOfSymbol)>>14);
	#else
		delayLine[i] += ((raisedCosineTable[i] * (long)amplitudeOfSymbol)>>14);
	#endif
	}
}
                  
/*******************************************************
	ModemTransitter()
	=================
	
	This function runs the Tx modulator to generate one
	baud of output signal.  This function calls the 
	ShapingFilter() function to generate I and Q samples,
	then modulates by the carrier frequency and adds the
	I and Q together.
	
*******************************************************/
void ModemTransmitter(int baudIndex, int *outputBuffer)
{
	/* local variables */
	int Iamplitude;    	/* Quadrature component amplitude */
//	int Qamplitude;    	/* Quadrature component amplitude */
//	int n;				/* loop index for each baud */
//	static struct POINT ConstellationPoint;

	/*******************
	1. Look up in-phase and quadrature amplitudes
	********************/
	Iamplitude = g_ModemData.cPoints[baudIndex].I;
//	Qamplitude = g_ModemData.cPoints[baudIndex].Q;

	/*******************
	2. Run in-phase and quadrature components through baseband
		shaping filter, with interpolation
	********************/
	ShapingFilter(g_ModemData.Idelay, Iamplitude);
/*RP:TEMP	ShapingFilter(g_ModemData.Qdelay, Qamplitude); */

	/*******************
	4. Modulate the in-phase and quadrature components to
		generate the output signal from the transmitter
	********************/
/*RP:TEMP
	for (n = 0; n < SAMPLES_PER_BAUD; n++ )
	{
		outputBuffer[n] = Modulation(g_ModemData.Idelay[n], 
			g_ModemData.Qdelay[n], g_ModemData.phase);  

		 increment phase for next pass 
		g_ModemData.phase += g_ModemData.carrierFreq;
	}   */
}

/*******************************************************
	Initialize()
	============
	
	This function initializes the global modem parameter
	structure;
	
*******************************************************/
void Initialize(void)
{
	int i;
	
#if defined(C54X)
	asm(" RSBX OVM");             
#endif
	
	g_ModemData.carrierFreq = 15;  /* increment through 125Hz sine table */
	g_ModemData.phase = 0;			/* initialize phase for carrier */
	g_ModemData.samplesPerBaud = SAMPLES_PER_BAUD;
	g_ModemData.noiseLevel = 0;
	
	/* zero delay lines for shaping filter */
	for( i = SIZE_SHAPING_FILTER; i--; )
	{
		g_ModemData.Idelay[i] = 0;
		g_ModemData.Qdelay[i] = 0;
	}
	/* clear output buffer */
	for( i = SAMPLES_PER_BAUD*BAUD_PER_LOOP; i--; )
	{
		g_ModemData.OutputBuffer[i] = 0;
	}
	
	/* clear data, constellation, and noise buffers */
	for( i = BAUD_PER_LOOP; i--; )
	{
		g_ModemData.dataSymbols[i] = 0;
		g_ModemData.cPoints[i].I = 0;
		g_ModemData.cPoints[i].Q = 0;
		g_ModemData.cNoise[i].I = 0;
		g_ModemData.cNoise[i].Q = 0;
	}
	
	for( i = BAUD_PER_LOOP; i--; )
	{
		int j;
		g_ModemData.SymbolClock[i*SAMPLES_PER_BAUD] = 1;
		for( j = SAMPLES_PER_BAUD; --j > 0; )
		{
			g_ModemData.SymbolClock[i*SAMPLES_PER_BAUD+j] = -1;
		}
	}
}


/* read next data, convert to constellation points, and add noise */
void ReadNextData(void)
{
	/* add code here to generate modem data */
	ReadConstellation();
}

/* convert data to constellation points and add noise */
void ReadConstellation(void)
{
	AddNoiseSignal();
}


/*******************************************************
	AddNoiseSignal()
	================
	
	This function adds noise to the constellation points
	for the modem transmitter;
	
*******************************************************/
void AddNoiseSignal(void)
{    
	 /* Add code here to read noise signal from disk */

	int i;
	int noiseVolume = 10 - g_ModemData.noiseLevel;

	for( i = BAUD_PER_LOOP; i--; )
	{
		/* convert data to constellation points */
		g_ModemData.cPoints[i] = constellation[(g_ModemData.dataSymbols[i])&15];
	 
		/* Add noise to constellation points, only if level not zero */
		if (g_ModemData.noiseLevel != 0)
		{
			if (noiseVolume < 0)		
			{  
				/* if volume is negative, shift to the left */
				g_ModemData.cPoints[i].I += (g_ModemData.cNoise[i].I << (-noiseVolume));
				g_ModemData.cPoints[i].Q += (g_ModemData.cNoise[i].Q << (-noiseVolume));
			}
			else
			{
				g_ModemData.cPoints[i].I += (g_ModemData.cNoise[i].I >> noiseVolume);
				g_ModemData.cPoints[i].Q += (g_ModemData.cNoise[i].Q >> noiseVolume);
			}
		}
	}
}

/*******************************************************
	Main()
	======
	
	Main loop for modem transmitter example program.
	
*******************************************************/
void main(void)
{   
	int i;  
	
	g_test.i = -16;
	g_test.j = 0x12345678; 
	g_test.j <<= 4;   
	g_test.i *= g_test.j;

	/* Initialize modem transmitter */
	Initialize();
                      
	/* testing the carrier signal generator */
	for(i = 0; i < SAMPLES_PER_BAUD; i++ )
	{
		g_ModemData.OutputBuffer[i] = SineLookup(i*g_ModemData.carrierFreq);
	}                      

	for(i = 0; i < SAMPLES_PER_BAUD; i++ )
	{
		g_ModemData.OutputBuffer[i] = CosineLookup(i*g_ModemData.carrierFreq);
	}                      
	
	/* loop forever */
	while(1)
	{
		/* get modem data, convert to constellation points, and add noise. */
		ReadNextData();

		/* run modem on new data */	
		for( i = 0; i < BAUD_PER_LOOP; i++ )
		{
			ModemTransmitter(i, &(g_ModemData.OutputBuffer[i*SAMPLES_PER_BAUD]));
		}
	}
}
