#include <stdio.h>
void func(int a, int b)
{
	int x1, x2, x3, x4;

	x1 = b / 1000;
	x2 = (b % 1000) / 100;
	x3 = (b % 100) / 10;
	x4 = (b % 10);
	

	if (x1 != 0)
		printf("%d\n", a * x1);
	if (x2 != 0)
		printf("%d\n", a * x2);
	if (x3 != 0)
		printf("%d\n", a * x3);
	if (x4 != 0)
		printf("%d\n", a * x4);
	printf("%d\n", a * b);

}
int main()
{
	func(4984, 25);
}
