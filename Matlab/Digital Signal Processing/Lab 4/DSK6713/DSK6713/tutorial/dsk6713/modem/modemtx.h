
#include "sinetab.h"
#include "razedcos.h"

#define NUM_CONSTELATION_POINTS 16
#define SAMPLES_PER_BAUD 32
#define BAUD_PER_LOOP 1

struct POINT 
{ 
	int I;	/* in-phase symbol amplitude */
	int Q;  /* quadrature-phase symbol amplitude */
};

struct MODEM_PARAMETERS
{       
	int samplesPerBaud;
	int phase;
	int carrierFreq;   
	int noiseLevel;  /* 0 to 16 */ 
	int dataSymbols[BAUD_PER_LOOP];
	struct POINT cPoints[BAUD_PER_LOOP];
	struct POINT cNoise[BAUD_PER_LOOP];
	int Idelay[SIZE_SHAPING_FILTER];
	int Qdelay[SIZE_SHAPING_FILTER];
	int OutputBuffer[SAMPLES_PER_BAUD*BAUD_PER_LOOP];
	int SymbolClock[SAMPLES_PER_BAUD*BAUD_PER_LOOP];
};

/* function prototypes */
int SineLookup(int);
int CosineLookup(int);
int Modulation(int, int, int);
void ShapingFilter(int *, int);
void ModemTransmitter(int, int *);
void Initialize(void);
void ReadNextData(void);
void ReadConstellation(void);
void AddNoiseSignal(void);

