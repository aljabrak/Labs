//A program, which will require the user to give calorific value, octane content and 
//specific density of the petrol under consideration and output the grade of the petrol. 


#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a,b;
   float c;
   // a is calorific factor.
   // b is octane rating.
   // c is specific density.
   printf("a = ");
   scanf("%d",&a);
    printf("b = ");
   scanf("%d",&b);
    printf("c = ");
   scanf("%f",&c);
   if((a>50000 && b<70) && c<0.8)
   {
       printf("Grade X petrol");
   }
   else if((a<50000 && b<70) && c<0.8)
   {
       printf("Grade XI petrol");
   }
   else if((a>50000 && b>70) && c<0.8)
   {
       printf("Grade VIII petrol");
   }
   else if((a>50000 && b<70) && c>0.8)
   {
       printf("Grade VII petrol");
   }
   else if((a<50000 && b>70) && c>0.8)
   {
       printf("Grade V petrol");
   }
   else
    {
        printf("Grade VI petrol");
    }
    return 0;
}
