//Toggle P1 forever
#include <reg51.h>

void main(void)
{
  for(;;)
    P1 = 0x55;    //01010101
    P1 = 0xAA;    //10101010
}
