#include <reg51.h>

sbit R0 = P1^0;                 //Port 1 of Atmel 89C51.            
sbit R1 = P1^1;                 //Assigning variables to pins for accessing.
sbit R2 = P1^2;
sbit R3 = P1^3;
sbit C0 = P1^4;
sbit C1 = P1^5;
sbit C2 = P1^6;

sbit X0 = P2^0;                  //Port 2 of Atmel 89C51.            
sbit X1 = P2^1;
sbit X2 = P2^2;
sbit X3 = P2^3;
sbit Y0 = P2^4;
sbit Y1 = P2^5;
sbit Y2 = P2^6;

sbit U0 = P3^0;                  //Port 3 of Atmel 89C51.            
sbit U1 = P3^1;
sbit U2 = P3^2;
sbit U3 = P3^3;
sbit V0 = P3^4;
sbit V1 = P3^5;
sbit V2 = P3^6;

void main (void)
{
	P1 = 0xFF;      //Port 1 pins initialized FFFFh (1111 1111 1111 1111) for Input.            
	P2 = 0x00;      //Port 2 pins initialized 0000h (0000 0000 0000 0000) for Output to Servo Motors.
	P3 = 0x00;      //Port 3 pins initialized 0000h (0000 0000 0000 0000) for Output to LCD.
	
	R1 = R2 = R3 = 1;
	R0 = 0;
	if (C0 == 0)       //If 1 is pressed.      
	{
		X0 = 1;
		Y0 = 1;
		U0 = 1;
		V0 = 1;
	}
	else if (C1 == 0)   //If 2 is presssed. 
	{
		X0 = 1;
		Y1 = 1;
		U0 = 1;
		V1 = 1;
	}
	else if (C2 == 0)   //If 3 is pressed.   
	{
		X0 = 1;
		Y2 = 1;
		U0 = 1;
		V2 = 1;
	}

	R0 = R2 = R3 = 1;
	R1 = 0;
	if (C0 == 0)         //If 4 is pressed.     
	{
		X1 = 1;
		Y0 = 1;
		U1 = 1;
		V0 = 1;
	}
	else if (C1 == 0)    //If 5 is pressed.   
	{
		X1 = 1;
		Y1 = 1;
		U1 = 1;
		V1 = 1;
	}
	else if (C2 == 0)    //If 6 is pressed.
	{
		X1 = 1;
		Y2 = 1;
		U1 = 1;
		V2 = 1;
	}
	
	R0 = R1 = R3 = 1;
	R2 = 0;
	if (C0 == 0)         //If 7 is pressed.        
	{
		X2 = 1;
		Y0 = 1;
		U2 = 1;
		V0 = 1;
	}
	else if (C1 == 0)    //If 8 is pressed. 
	{
		X2 = 1;
		Y1 = 1;
		U2 = 1;
		V1 = 1;
	}
	else if (C2 == 0)    //If 9 is pressed.
	{
		X2 = 1;
		Y2 = 1;
		U2 = 1;
		V2 = 1;
	}

	R0 = R1 = R2 = 1;
	R3 = 0;
	if (C0 == 0)        //If * is pressed.       
	{
		X3 = 1;
		Y0 = 1;
		U3 = 1;
		V0 = 1;
	}
	else if (C1 == 0)   //If 0 is pressed.  
	{
		X3 = 1;
		Y1 = 1;
		U3 = 1;
		V1 = 1;
	}
	else if (C2 == 0)   //If # is pressed.
	{
		X3 = 1;
		Y2 = 1;
		U3 = 1;
		V2 = 1;
	}
}
