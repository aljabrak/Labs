#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    // a is previous number.
    // b is current number.
    // c is next number.
    a = 0;
    printf("0\n");
    b = 1;
    while(b <= 100)
    {
        printf("%d\n", b);
        c = a + b;
        a = b;
        b = c;
        if( b > 100)
        {
            printf("%d\n", b);
        }
    }
    return 0;
}
