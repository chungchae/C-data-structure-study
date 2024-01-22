#include <stdio.h>

void print_arr(int* arr, int length)
{

	for (int i = 0; i < length; i++)
	{
		printf("%d ",arr[i]);
	}
}
int main()
{
	int arr[3] = { 1,2,3 };
	print_arr(arr, sizeof(arr) / sizeof(int));
}
