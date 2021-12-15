#include <stdio.h>
#include <math.h>

double zeta(int n, int s);
int main(void)
{
	int n, s;
	double z;
	printf("Enter Summation Limit: n = ");
	scanf("%d", &n);
	printf("Zeta(s): s = ");
	scanf("%d", &s);
	printf("%.10f \n", zeta(n, s));
	return 0;
}


double zeta(int n, int s)
{
	double sum = 0.0;
	for(int i = 1; i <= n; i++)
	{
		sum += 1/pow(i, s);
	}
	double z = sum;
	return z;
}
