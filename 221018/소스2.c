#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char arr[100] = {0, };
	char b;
	int i = 0;

	printf("문장을 입력해주세요\n");
	
	gets(arr); //문자열 입력받기

	while (arr[i] != '\0') //입력받은 문자열까지만 반복
	{
		b = "\0";
		b = _getch(); //_getch()로 한 문자씩 입력받기
		if (arr[i] != b) //다르면 경고음 출력 후 
		{
			printf("\a");
			i--; //이전 문자로 돌아감
		}
		else
			printf("%c", b); //같으면 입력한 문자 출력

		i++;
	}
}