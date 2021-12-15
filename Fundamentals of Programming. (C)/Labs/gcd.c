//Greatest Common Divisor (between 2 numbers) Calculator.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,g,i;
    // x and y are integers.
    // g is Greatest Common Divisor.
    printf("Enter two integers: \n");
    scanf("%d%d", &x,&y);
    for(i=1; i <= x && i <= y; ++i)
           if(x%i==0 && y%i==0)
            g = i;
      printf("g of %d and %d is %d", x,y,g);
    return 0;
}
