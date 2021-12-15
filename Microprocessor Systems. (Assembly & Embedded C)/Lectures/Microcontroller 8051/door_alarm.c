//Door Alarm.
#include <reg51.h>

void delay();
sbit Sensor = P1 ^ 1;
sbit Buzzer = P1 ^ 7;

void delay()                          //delay of 0.2 seconds.
{
	unsigned char i,j,k;
	for(i=0;i<2;i++)
		for(j=0;j<255;j++)
	for(k=0;k<100;k++);
}
void main(void)
{
	Sensor = 1;           //make P1 (port) an input.
	while (1)
	{
		while (Sensor == 1)      //while the door opens.
		{
			Buzzer = 0;
			delay();
			Buzzer = 1;
			delay();
		}
	}

}
