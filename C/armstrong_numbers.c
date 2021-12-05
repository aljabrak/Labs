// Armstrong number is a number that is equal to the sum of cubes of its digits.
// For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
#include <stdio.h>

int cube(int a);
int main(void)
{    
    int n, a, sum = 0, N;
    printf("Enter the number: N = ");
    scanf("%d",&n);
    N = n;
    while(n > 0)
    {
        a = n % 10;
        sum += cube(a);
        n = n/10;
    }
    if(N == sum)
    {
        printf("Armstrong  Number.");
    }
    else
    {
        printf("Not Armstrong Number.");
    }
    return 0;  
}


int cube(int a)
{
    return a*a*a;
}