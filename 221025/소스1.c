#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
	int a, b, c, d;
	int i, k, j, l;
	printf("��� A=(axb)�� a,b ���� �Է��Ͻÿ�: "); //A�� ��, �� �� �Է�
	scanf("%d %d", &a, &b);

	printf("\n��� B=(cxd)�� c,d ���� �Է��Ͻÿ�: "); //B�� ��, �� �� �Է�
	scanf("%d %d", &c, &d);

	while (b != c)
	{
		printf("\n�߸��� c���� �ԷµǾ����ϴ�. ��� B=(cxd)�� c,d ���� �ٽ� �Է��Ͻÿ�"); //b, c�� ��ġ
		scanf("%d %d", &c, &d);
	}

	int** A = NULL; //��� A �޸� �Ҵ�
	A = (int**)malloc(sizeof(int*) * a);
	for (i = 0; i < a; i++)
	{
		A[i] = (int*)malloc(sizeof(int) * b);
	}

	int** B = NULL; //��� B �޸� �Ҵ�
	B = (int**)malloc(sizeof(int*) * c);
	for (i = 0; i < c; i++)
	{
		B[i] = (int*)malloc(sizeof(int) * d);
	}

	int** C = NULL; //��� C �޸� �Ҵ�
	C = (int**)malloc(sizeof(int*) * a);
	for (i = 0; i < a; i++)
	{
		C[i] = (int*)malloc(sizeof(int) * d);
	}

	printf("\n��� A�� ��Ҹ� �Է��Ͻÿ�: \n"); //A ��� �Է�


	for (i = 0; i < a; i++)
	{
		for (k = 0; k < b; k++)
		{
			printf("A[%d][%d]��� �Է�: ", i, k);
			scanf("%d", &A[i][k]);
		}
	}
	printf(" \n��� A: \n");

	for (i = 0; i < a; i++) //A ���
	{
		for (k = 0; k < b; k++)
			printf("%d  ", A[i][k]);
		printf("\n");
	}


	printf("\n��� B�� ��Ҹ� �Է��Ͻÿ�: \n"); //B ��� �Է�
	for (i = 0; i < c; i++)
	{
		for (k = 0; k < d; k++)
		{
			printf("B[%d][%d]��� �Է�: ", i, k);
			scanf("%d", &B[i][k]);
		}
	}


	printf(" \n��� B: \n"); //B ���

	for (i = 0; i < c; i++)
	{
		for (k = 0; k < d; k++)
			printf("%d  ", B[i][k]);
		printf("\n");
	}



	for (i = 0; i < a; i++) //��İ� ��� C�� �Է�
	{
		for (k = 0; k < d; k++)
		{
			C[i][k] = 0;
			for (j = 0; j < b; j++)
			{
				C[i][k] += A[i][j] * B[j][k];
			}
		}
	}

	printf("\n��� C=AB: \n\n"); //C ���

	for (i = 0; i < a; i++)
	{
		for (k = 0; k < d; k++)
		{
			printf("%d  ", C[i][k]);
		}
		printf("\n\n");
	}
	//�޸� �Ҵ� ����
	for (i = 0; i < a; i++)
		free(A[i]);
	free (A);

	for (i = 0; i < c; i++)
		free(B[i]);
	free(B);

	for (i = 0; i < a; i++)
		free(C[i]);
	free(C);
}