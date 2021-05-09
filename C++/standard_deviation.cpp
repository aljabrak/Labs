// Standard Deviation Calculator.

#include <iostream>
#include <cmath>
using namespace std;
float Mean(float marks[]);
float Variance(float marks[],float x);
float SD(float marks[]);
      float x,y;
int main()
{
    int i;
    float marks[5],x,y;;
    cout << "Enter marks of 5 courses: \n";
    for(i = 0; i < 5; ++i)
        {
         cin >> marks[i];
        }
        x = Mean(marks);
        y = Variance(marks,x);
    cout<<"mean = "<< x <<"\n";
    cout<<"variance = "<< y;
    cout << endl << "Standard Deviation = " << SD(marks);
    return 0;
}
float Mean(float marks[])
{
    float sum = 0.0, mean;
    int i;
    for(i = 0; i < 5; ++i)
    {
      sum += marks[i];
    }
       mean = sum/5;
       return mean;
}
float Variance(float marks[], float x)
{
    float v;
    v = 0;
    int i;
    for(i = 0; i < 5; ++i)
    {
      v += pow(marks[i] - x, 2);
    }
    return v;
}
float SD(float marks[])
{
    float sd,y;
    sd = sqrt(y/5);
    return sd;
}
