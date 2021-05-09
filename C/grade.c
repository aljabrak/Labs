//Finding Average grades of multiple classes. 
//We would like a program to compute the average grade of each of a set of classes. 
//Need to be careful that the average grade for each class is computed independently of other classes! 
//After computing the average for a class, need to see if there is another class.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,m,i;
    // x is the number of classes.
   // y is the number of students.
   // m s the average marks of class.
   float z;
   // z is the total marks.
   printf("Enter the value of x = ");
   scanf("%d", &x);
   for(i = 1; i <= x; i++)
   {
       printf("Enter the value of y%d = ", i);
       scanf("%d", &y);
       printf("Please enter the value of z = ");
		scanf("%f", &z);
        m = z/y;
        if(m > 90 && m <= 100)
        {
            printf("average grades of this class is A+ \n");
        }
        else if(m > 80 && m <= 90)
        {
            printf("average grades of this class is A \n");
        }
        else if(m > 70 && m <= 80)
        {
          printf("average grades of this class is B+ \n");
        }
        else if(m > 60 && m <= 70)
        {
            printf("average grades of this class is B \n");
        }
        else if(m > 50 && m <= 60)
        {
            printf("average grades of this class is C+ \n");
        }
        else
        {
            printf("average grades of this class is F \n");
        }
   }

    return 0;
}
