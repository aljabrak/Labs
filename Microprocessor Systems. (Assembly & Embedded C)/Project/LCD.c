#include <reg51.h>       //Atmel 89C51 Microcontroller library.
#define lcd P1           //Port 1 is connected to LCD.

sbit rs = P3^0;          //RS is named to Pin 0 of Port 3.
sbit e = P3^2;           //Enable is named to Pin 2 of Port 3.
sbit R0 = P2^0;
sbit R1 = P2^1;
sbit R2 = P2^2;
sbit R3 = P2^3;
sbit C0 = P2^4;
sbit C1 = P2^5;
sbit C2 = P2^6;
int input,bit1,bit2,v;        //Global variables.

void delay2(void);
void delay(void);
void cmd (char);
void display(char);
void string(char *);
void init(void);
void printInput();
void printMessage();

void delay()                  //Delay Function (slow delay).
{
	unsigned char i,j,k;
	for(i=0;i<2;i++)
		for(j=0;j<255;j++)
	for(k=0;k<100;k++);
}

void cmd (char c)             //Command Function.
{
	lcd = c;
	rs = 0;
	e = 1;
	delay();
	e = 0;
}
void display (char c)         //Display Function (displays a character).
{
	lcd=c;
	rs=1;                 //Command is given to LCD.
                              //Pulse Enable.
	e=1;                  //enable 1.
	delay();              //delay of 0.2 seconds.
	e=0;                  //enable 0.
}
void string(char *p)         //String Function (displays a string).
{
	while(*p)            //*p ==> pointer sends address of the string to the display of LCD.
	{
		display(*p++);
	}
}

void init(void)             //Initialization of Command Function.
{
	cmd(0x38);          //Function set (8 bit interface, 2 lines, 5*7 pixels).
	cmd(0x0e);          //Turn on visible underline cursor.
	cmd(0x01);          //Clear screan.
	cmd(0x06);          //Increment cursor (shift cursor to right).
	cmd(0x80);          //Force cursor to beginning ( 1st line).
}

void main()
{
	start:
	P1 = 0x00;          //Port 1 pins initialized 0000h (0000 0000 0000 0000) for Output.
	P2 = 0xFF;          //Port 2 pins initialized FFFFh (1111 1111 1111 1111) for Input. 
	P3 = 0x00;          //Port 3 pins initialized 0000h (0000 0000 0000 0000) for Output.
	init();
	string("ACTION: ");

	next:
	if (R0 == 1){
		if (C0 == 1)
		{	string("UPWARD");
			cmd(0xC0);
			string("NO OF TIMES:");
			printInput();
			goto start;
		}
		else if (C1 == 1)
		{	string("DOWNWARD");
			cmd(0xC0);
			string("NO OF TIMES: ");
			printInput();
			goto start;}
		else if (C2 == 1)
		{	string("FORWARD");
			cmd(0xC0);
			string("NO OF TIMES: ");
			printInput();
			goto start;}}

	else if (R1 == 1){
		if (C0 == 1)
		{	string("REVERSE");
			cmd(0xC0);
			string("NO OF TIMES: ");
			printInput();
			goto start;}
		else if (C1 == 1)
		{	string("LEFT");
			cmd(0xC0);
			string("NO OF TIMES: ");
			printInput();
			goto start;}
		else if (C2 == 1)
		{	string("RIGHT");
			cmd(0xC0);
			string("NO OF TIMES: ");
			printInput();
			goto start;}}
	
	else if (R2 == 1){
		if (C0 == 1)
		{
			cmd(0x10);
			string("GRIPCLOSE");
			cmd(0xC0);
			string("NO OF TIMES: ");
			printInput();
			goto start;}
		else if (C1 == 1)
		{	string("GRIPOPEN");
			cmd(0xC0);
			string("NO OF TIMES: ");
			printInput();
			goto start;}
		}

	goto next;
}

void printInput()          //Prints the distance units (number of rotations).
{
	int s = 0;
	next2:
	if (R0 == 1){
		if (C0 == 1)
		{	display('1');
			delay();
			s++;
			if (s==1){
				bit1 = 1;}
			else if (s==2){
				bit2 =1;
				input = (bit1 * 10) + bit2;
				printMessage();
				return;
		}	}
		else if (C1 == 1)
		{	display('2');
			delay();
			s++;
			if (s==1){
				bit1 = 2;}
			else if (s==2){
				bit2 = 2;
				input = (bit1 * 10) + bit2;
				printMessage();
				return;}}
		else if (C2 == 1)
		{	display('3');
			delay();
			s++;
			if (s==1){
				bit1 = 3;}
			else if (s==2){
				bit2 = 3;
				input = (bit1 * 10) + bit2;
				printMessage();
				return;}}}

	else if (R1 == 1){
		if (C0 == 1)
		{	display('4');
			delay();
			s++;
			if (s==1){
				bit1 = 4;}
			else if (s==2){
				bit2 = 4;
				input = (bit1 * 10) + bit2;
				printMessage();
				return;}}
		else if (C1 == 1)
		{	display('5');
			delay();
			s++;
			if (s==1){
				bit1 = 5;}
			else if (s==2){
				bit2 = 5;
				input = (bit1 * 10) + bit2;
				printMessage();
				return;}}
		else if (C2 == 1)
		{	display('6');
			delay();
			s++;
			if (s==1){
				bit1 = 6;}
			else if (s==2){
				bit2 = 6;
				input = (bit1 * 10) + bit2;
				printMessage();
				return;}}}
	
	else if (R2 == 1){
		if (C0 == 1)
		{
			display('7');
			delay();
			s++;
			if (s==1){
				bit1 = 7;}
			else if (s==2){
				bit2 = 7;
				input = (bit1 * 10) + bit2;
				printMessage();
				return;}}
		else if (C1 == 1)
		{	display('8');
			delay();
			s++;
			if (s==1){
				bit1 = 8;}
			else if (s==2){
				bit2 = 8;
				input = (bit1*10) + bit2;
				printMessage();
				return;}}
		else if (C2 == 1)
		{	display('9');
			delay();
			s++;
			if (s==1){
				bit1 = 9;}
			else if (s==2){
			bit2 = 9;
			input = (bit1 * 10) + bit2;
			printMessage();
			return;}}}

	else if (R3 == 1){
		if (C1 == 1)
		{	display('0');
			delay();
			s++;
			if (s==1){
				bit1 = 0;}
			else if (s==2){
				bit2 = 0;
				input = (bit1 * 10) + bit2;
				printMessage();
				return;}}
	}
	goto next2;
}

void printMessage(){          //Prints message "ROBARM IS MOVING" "PRESS 9 TO STOP".
	cmd(0x01);
	cmd(0x80);
	string("ROBARM IS MOVING");
	cmd(0xC0);
	string("PRESS 9 TO STOP");
	v = 0;
	msg:
		if (input < 10){
			delay2();
			delay2();}
		else if (input < 20){
			delay2();
			delay2();
			delay2();}
		else if (input <30){
			delay2();
			delay2();
			delay2();
			delay2();}
		else{
			delay2();
			delay2();
			delay2();
			delay2();
			delay2();}
		if (R2 == 1)
		{
			if(C2 == 1)
			{
				return;
			}
			else{
			v++;
			goto msg;}
		}
		else if (v == input){
			return;
		}
		else{
			v++;
			goto msg;}
}

void delay2(void)         //Delay Fucntion (fast delay).
{
	unsigned char i,j,k;
	for(i=0;i<2;i++)
		for(j=0;j<255;j++)
	for(k=0;k<255;k++);
}
