#include <reg51.h>

unsigned char data1[] = {0x01,0x02,0x04,0x08};      //0000 0001, 0000 0010, 0000 0100, 0000 1000.
                                                    //rotates the motor anti-clockwise.
unsigned char data2[] = {0x08,0x04,0x02,0x01};      //0000 1000, 0000 0100, 0000 0010, 0000 0001.
                                                    //rotates the motor clockwise.
                                                    //data1 and data2 inits first 4 pins of Port 2 and 3.
unsigned char data3[] = {0x10, 0x20, 0x40, 0x80};   //0001 0000, 0010 0000, 0100 0000, 1000 0000.
                                                    //rotates the motor anti-clockwise.
unsigned char data4[] = {0x80, 0x40, 0x20, 0x10};   //1000 0000, 0100 0000, 0010 0000, 0001 0000.
                                                    //rotates the motor clockwise.
                                                    //data3 and data4 inits first 4 pins of Port 2 and 3.

unsigned char x,y;
int input,bit1,bit2;         //Global parameters to be accessed in functions.

sbit R0 = P1^0;              //Assigning variables to pins for accessing.
sbit R1 = P1^1;
sbit R2 = P1^2;
sbit R3 = P1^3;
sbit C0 = P1^4;
sbit C1 = P1^5;
sbit C2 = P1^6;

void delay();

void upward();

void downward();

void forward();

void reverse();

void left();

void right();

void gripclose();

void gripopen();

void stop();

int check();

void takeInput();

void takeInput()         //takes distance units from keypad for the movement of robotic arm (Servo Motors).
{                        //distance units = (number of rotations).
	int s =0;
	next:
	if (R0 == 1){
		if (C0 == 1)
		{
			delay();
			s++;
			if (s==1)
			{
				bit1 = 1;
			}
			else if (s==2)
			{
				bit2 = 1;
				return ;
			}
		}
		else if (C1 == 1)
		{
			delay();
			s++;
			if (s==1)
			{
				bit1 = 2;
			}
			else if (s==2)
			{
				bit2 = 2;
				return ;
			}
		}
		else if (C2 == 1)
		{
			delay();
			s++;
			if (s==1)
			{
				bit1 = 3;
			}
			else if (s==2)
			{
				bit2 = 3;
				return;
			}
		}}

	else if (R1 == 1){
		if (C0 == 1)
		{
			delay();
			s++;
			if (s==1)
			{
				bit1 = 4;
			}
			else if (s==2)
			{
				bit2 = 4;
				return;
			}}
		else if (C1 == 1)
		{
			delay();
			s++;
			if (s==1)
			{
				bit1 = 5;
			}
			else if (s==2)
			{
				bit2 = 5;
				return;
			}}
		else if (C2 == 1)
			{
				delay();
				s++;
				if (s==1)
				{
					bit1 = 6;
				}
				else if (s==2)
				{
					bit2 = 6;
					return;
				}}}
	
	else if (R2 == 1){
		if (C0 == 1)
		{
			delay();
			s++;
			if (s==1)
			{
				bit1 = 7;
			}
			else if (s==2)
			{
				bit2 = 7;
				return;
			}}
		else if (C1 == 1)
		{
			delay();
			s++;
			if (s==1)
			{
				bit1 = 8;
			}
			else if (s==2)
			{
				bit2 = 8;
				return;
			}}
		else if (C2 == 1)
		{
			delay();
			s++;
			if (s==1)
			{
				bit1 = 9;
			}
			else if (s==2)
			{
				bit2 = 9;
				return;
			}}}
	
	if (R3 == 1)
	{
		if (C1 ==1)
		{
			delay();
			s++;
			if (s==1)
			{
				bit1 = 0;
			}
			else if (s==2)
			{
				bit2 = 0;
				return;
			}}}
	goto next;
}

void main(void)
{
start:                  //start Label.
	P1 = 0xFF;      //Port 1 pins initialized FFFFh (1111 1111 1111 1111) for Input from Keypad.            
	P2 = 0x00;      //Port 2 pins initialized 0000h (0000 0000 0000 0000) for Output to Servo Motor 1 and 2.
	P3 = 0x00;      //Port 3 pins initialized 0000h (0000 0000 0000 0000) for Output to Servo Motor 3 and 4.

	if (R0 == 1){
		if (C0 == 1)         //1 is pressed from Keypad.
		{
			delay();     //delay fucntion for delay.
			takeInput();
			input = (bit1*10) + bit2;
			upward();
		}
		else if (C1 == 1)         //2 is pressed from Keypad.
		{	delay();          //delay fucntion adds delay.
			takeInput();
			input = (bit1*10) + bit2;
			downward();
		}
		else if (C2 == 1)         //3 is pressed from Keypad.
		{	delay();
			takeInput();
			input = (bit1*10) + bit2;
			forward();
		}}

	else if (R1 == 1){
		if (C0 == 1)              //4 is pressed from Keypad.
		{	delay();
			takeInput();
			input = (bit1*10) + bit2;
			reverse();
		}
		else if (C1 == 1)         //5 is pressed from Keypad.
		{	delay();
			takeInput();
			input = (bit1*10) + bit2;
			left();
		}
		else if (C2 == 1)         //6 is pressed from Keypad.
		{	delay();
			takeInput();
			input = (bit1*10) + bit2;
			right();
		}}
	
	else if (R2 == 1){
		if (C0 == 1)              //7 is pressed from Keypad.
		{	delay();
			takeInput();
			input = (bit1*10) + bit2;
			gripclose();
		}
		else if (C1 == 1)         //8 is pressed from Keypad.
		{	delay();
			takeInput();
			input = (bit1*10) + bit2;
			gripopen();
		}
		else if (C2 == 0)         //9 is pressed from Keypad.
		{}
	}
	goto start;         //Repeats and goes to start label.
}

void delay()         //Delay Function.
{
	unsigned char i,j,k;
	for(i=0;i<2;i++)
		for(j=0;j<255;j++)
	for(k=0;k<255;k++);
}

void upward()         //Upward motion (anti-clockwise rotation) with Servo Motor 1.
{
	for (y=0;y<=input;y++)
	{
		for (x=0;x<=3;x++)
		{
			P2 = data1[x];
			delay();
			if (check())
			{return;}
		}
	}
}

void downward()         //Downward motion (clockwise rotation) with Servo Motor 1.
{
	for (y=0;y<=input;y++)
	{
		for (x=0;x<=3;x++)
		{
			P2 = data2[x];
			delay();
			if (check())
			{return;}
		}
	}
}

void forward()         //Forward motion (anti-clockwise rotation) with Servo Motor 2.
{
	for (y=0;y<=input;y++)
	{
		for (x=0;x<=3;x++)
		{
			P2 = data3[x];
			delay();
			if (check())
			{return;}
		}
	}
}

void reverse()         //Reverse motion (clockwise rotation) with Servo Motor 2.
{
	for (y=0;y<=input;y++)
	{
		for (x=0;x<=3;x++)
		{
			P2 = data4[x];
			delay();
			if (check())
			{return;}
		}
	}
}


void left()          //Left motion (anti-clockwise rotation) with Servo Motor 3.
{
	for (y=0;y<=input;y++)
	{
		for (x=0;x<=3;x++)
		{
			P3 = data1[x];
			delay();
		if (check())
			{return;}
		}
	}
}

void right()        //Right motion (clockwise rotation) with Servo Motor 3.
{
	for (y=0;y<=input;y++)
	{
		for (x=0;x<=3;x++)
		{
			P3 = data2[x];
			delay();
			if (check())
			{return;}
		}
	}
}

void gripclose()        //Grip close motion (anti-clockwise rotation) with Servo Motor 4.
{
	for (y=0;y<=input;y++)
	{
		for (x=0;x<=3;x++)
		{
			P3 = data3[x];
			delay();
			if (check())
			{return;}
		}
	}
	return;
}

void gripopen()         //Grip open motion (clockwise rotation) with Servo Motor 4.
{
	for (y=0;y<=input;y++)
	{
		for (x=0;x<=3;x++)
		{
			P3 = data4[x];
			delay();
			if (check())
			{return;}
		}
	}
}

int check()          //Checks if 9 is pressed from Keypad. If pressed then returns to main.
{
	
	
	if (R2 == 1){
		if (C2 == 1)
		{return 1;}}
	return 0;

}
