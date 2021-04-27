// Fibonacci Series.
#include<stdio.h>
int f(int x)
{
	if(x == 0 || x == 1)
		return x;
	else
        return (f(x - 1) + f(x - 2));
}
int main()
{
	int x, i = 0, y;
	printf("Enter the number of terms required: x = ");
	scanf("%d", &x);
	printf("Fibonacci series:\n");
	for (y = 1; y <= x; y++)
	{
		printf("%d\n", f(i));
		i++;
	}
	return 0;
}
