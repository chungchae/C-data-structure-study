#include <stdio.h>

int func1(int n)
{
	if (n == 1)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	else if (n == 3)
	{
		return 2;
	}
	else
	{
		return (func1(n - 1) + func1(n - 2) + func1(n - 3));
	}

}

int func2(int n)
{
	int f1, f2, f3, f4;
	f1 = 0; f2 = 1; f3 = 2; f4 = 0;
	if (n == 1) return f1;
	else if (n == 2) return f2;
	else if (n == 3) return f3;
	else
	{
		for (int i = 0; i < n-3; i++)
		{
			f4 = f1 + f2 + f3;
			f1 = f2;
			f2 = f3;
			f3 = f4;
		}
	}
			return f3;
}

int main()
{
	printf("%d", func1(5));
	printf("\n%d", func2(5));
}