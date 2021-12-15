#include <stdio.h>

int main()
{
    int n, x, f;
    printf("n = ");
    scanf("%d", &n);
    x = n;
    f = n;

    if(n == 0 || n == 1)
    {
        printf("%d! = ", n);
        printf("%d", n);
    }
    else if(n > 1)
    {        
        while (n > 1)
        {
            n = n - 1;
            f *= n;
        }
        printf("%d! = ", x);
        printf("%d", f);
    }
    else
    {
        printf("Factorial of negative integers is not defined.");
    }
    return 0;
}