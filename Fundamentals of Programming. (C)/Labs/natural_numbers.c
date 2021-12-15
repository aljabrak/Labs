#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Enter the value of x =");
    scanf("%d",&x);
    while(x>=1)
    {
        printf("%d\n",x);
        x--;
    }
    return 0;
}
