#include <reg51.h>

void main (void)
{
  unsigned char z;
  for(z=0,z<=255,z++)
    P1 = z                  //sends values from 00 to FF to Port 1.
}
