#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
	int a, b, c, d;
	int i, k, j, l;
	printf("행렬 A=(axb)의 a,b 값을 입력하시오: "); //A의 행, 열 수 입력
	scanf("%d %d", &a, &b);

	printf("\n행렬 B=(cxd)의 c,d 값을 입력하시오: "); //B의 행, 열 수 입력
	scanf("%d %d", &c, &d);

	while (b != c)
	{
		printf("\n잘못된 c값이 입력되었습니다. 행렬 B=(cxd)의 c,d 값을 다시 입력하시오"); //b, c값 일치
		scanf("%d %d", &c, &d);
	}

	int** A = NULL; //행렬 A 메모리 할당
	A = (int**)malloc(sizeof(int*) * a);
	for (i = 0; i < a; i++)
	{
		A[i] = (int*)malloc(sizeof(int) * b);
	}

	int** B = NULL; //행렬 B 메모리 할당
	B = (int**)malloc(sizeof(int*) * c);
	for (i = 0; i < c; i++)
	{
		B[i] = (int*)malloc(sizeof(int) * d);
	}

	int** C = NULL; //행렬 C 메모리 할당
	C = (int**)malloc(sizeof(int*) * a);
	for (i = 0; i < a; i++)
	{
		C[i] = (int*)malloc(sizeof(int) * d);
	}

	printf("\n행렬 A의 요소를 입력하시오: \n"); //A 요소 입력


	for (i = 0; i < a; i++)
	{
		for (k = 0; k < b; k++)
		{
			printf("A[%d][%d]요소 입력: ", i, k);
			scanf("%d", &A[i][k]);
		}
	}
	printf(" \n행렬 A: \n");

	for (i = 0; i < a; i++) //A 출력
	{
		for (k = 0; k < b; k++)
			printf("%d  ", A[i][k]);
		printf("\n");
	}


	printf("\n행렬 B의 요소를 입력하시오: \n"); //B 요소 입력
	for (i = 0; i < c; i++)
	{
		for (k = 0; k < d; k++)
		{
			printf("B[%d][%d]요소 입력: ", i, k);
			scanf("%d", &B[i][k]);
		}
	}


	printf(" \n행렬 B: \n"); //B 출력

	for (i = 0; i < c; i++)
	{
		for (k = 0; k < d; k++)
			printf("%d  ", B[i][k]);
		printf("\n");
	}



	for (i = 0; i < a; i++) //행렬곱 결과 C에 입력
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

	printf("\n행렬 C=AB: \n\n"); //C 출력

	for (i = 0; i < a; i++)
	{
		for (k = 0; k < d; k++)
		{
			printf("%d  ", C[i][k]);
		}
		printf("\n\n");
	}
	//메모리 할당 해제
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