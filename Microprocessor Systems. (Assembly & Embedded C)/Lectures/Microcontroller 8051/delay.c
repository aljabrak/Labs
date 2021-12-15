//Delay in Embedded C.
#include <reg51.h>
void Delay(unsigned int);

void main(void)
{
  while (1)                  //repeat forever
  {
    P1=0x55;
    Delay(250);
    P1=0xAA;
    Delay(250);
  }
}
void Delay(unsigned int t)
{
  unsigned int i,j;
  for (i=0;i<t;i++)       //this is For(); loop delay used to define delay value in Embedded C.
  {
    for (j=0;j<1275;j++);
  }
}
