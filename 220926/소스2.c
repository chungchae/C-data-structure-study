#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int com_mul(int a, int b)
{
	int i, count, c, d;
	c = 0; count = 0;
	for (i = 1; (i <= a) && (i <= b); ++i)
	{
		if ((a % i == 0) && (b % i == 0))
			c = i;
	}
	d = a * b / c;
	count = 1000000 / d;
	return count;
}

int com_fac(int a, int b)
{
	int i, count, c;
	count = 0; c = 0;
	for (i = 1; (i <= a) && (i <= b); i++)
	{
		if ((a % i == 0) && (b % i == 0)) 
			c = i;
	}

	for (i = 1; i <= c; i++)
	{
		if ((c % i) == 0)
			count++;
	}
	return count;
}

int main()
{
	printf("%d", com_mul(5, 12));
	printf("\n%d", com_fac(400, 5));
}