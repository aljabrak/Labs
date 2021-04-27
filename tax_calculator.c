#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pay;
    float tax;
    char cat;


    printf("Enter your Category(A/B/C) : ");
    scanf(" %c", &cat);
    printf("Enter your Pay : ");
    scanf("%d", &pay);

    if (cat = 'A')
    {

        if (pay<= 2300)
        tax = 0;
        else if (pay<=3400)
        tax =0.24* pay;

        else if (pay<=4400)
        tax =0.26* pay;

        else if (pay<=6500)
        tax =0.28* pay;

        else if (pay<=8500)
        tax =0.29* pay;

        else if (pay<=10800){
        tax =0.31* pay;}
        else if (pay > 10800)
        {
            printf("Go hire an accountant\n");
        }
        printf("Tax you have to pay is %.2f",tax);

    }
    else if (cat = 'B')
    {
      if (pay<= 2300)
        tax = 0;
        else if (pay<=3400)
        tax =0.14* pay;

        else if (pay<=4400)
        tax =0.16* pay;

        else if (pay<=6500)
        tax =0.18* pay;

        else if (pay<=8500)
        tax =0.19* pay;

        else if (pay<=10800){
        tax =0.21* pay;}
        else if (pay > 10800)
        {
            printf("Get promoted to Officer\n");
        }
            printf("Tax you have to pay is %.2f",tax);
    }
    else if (cat = 'C')
    {
         if (pay<= 2300)
        tax = 0;
        else if (pay<=3400)
        tax =0.04* pay;

        else if (pay<=4400)
        tax =0.06* pay;

        else if (pay<=6500)
        tax =0.08* pay;

        else if (pay<=8500)
        tax =0.09* pay;

        else if (pay<=10800){
        tax =0.11* pay;}
        else if (pay > 10800)
        {
            printf("Good job find a professional");
        }
        printf("Tax you have to pay is %.2f",tax);
    }
   else {printf("Please Enter correct category ");}
    return 0;
}
