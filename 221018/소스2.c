#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char arr[100] = {0, };
	char b;
	int i = 0;

	printf("������ �Է����ּ���\n");
	
	gets(arr); //���ڿ� �Է¹ޱ�

	while (arr[i] != '\0') //�Է¹��� ���ڿ������� �ݺ�
	{
		b = "\0";
		b = _getch(); //_getch()�� �� ���ھ� �Է¹ޱ�
		if (arr[i] != b) //�ٸ��� ����� ��� �� 
		{
			printf("\a");
			i--; //���� ���ڷ� ���ư�
		}
		else
			printf("%c", b); //������ �Է��� ���� ���

		i++;
	}
}