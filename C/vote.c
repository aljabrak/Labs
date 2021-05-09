#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x;
   // x is the Age of Person.
   printf("Enter the age of Person. x =  ");
   scanf("%d", &x);
   if(x>=18)
   {
        printf("Person is eligible for voting");

   }
   else
   {
       printf("Person is not eligible for voting");
   }
   return 0;
}
