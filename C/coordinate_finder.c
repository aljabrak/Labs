#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    printf("Enter the value of abscissa x = ");
    scanf("%d", &x);
    printf("Enter the value of ordinate y = ");
    scanf("%d", &y);
    if(x>0 && y>0)
    {
        printf("Coordinates are in I Quadrant");
    }
    if(x<0 && y>0)
    {
        printf("Coordinates are in II Quadrant");
    }
    if(x<0 && y<0)
    {
        printf("Coordinates are in III Quadrant");
    }
    if(x>0 && y<0)
    {
        printf("Coordinates are in IV Quadrant");
    }
    else if(x == 0 && y == 0)
    {
        printf("Coordinates are at Origin");
    }
    return 0;
}
