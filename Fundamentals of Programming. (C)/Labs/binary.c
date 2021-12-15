// Binary to Decimal Converter.
#include <stdio.h>
#include <math.h>

int main()
{
    int x, N, a, i, sum;
    printf("Enter Binary Number: ");
    scanf("%d", &x);
    N = x;
    sum = 0;
    i = 0;
    while (x > 0)
    {
        a = x % 10;
        sum += pow(2, i)*a;
        x = x/10;
        i += 1;
    }
    printf("Decimal Number: %d", sum);
    return 0;
}
