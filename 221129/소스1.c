#include <stdio.h>
#define SIZE 4

typedef struct node
{ //노드 구조체 정의
	struct node* link;
	int data;
}node;

int main()
{
	int count[SIZE] = { 0, };
	int ad[SIZE][SIZE] = { {0,1,1,0},{1,0,1,1},{1,1,0,1},{0,1,1,0 }};
	int i, j;
	node* p;

	for (i = 0; i < SIZE; i++)
	{ //입력된 인접행렬 확인
		for (j = 0; j < SIZE; j++)
		{
			printf("%d ", ad[i][j]);
		}
		printf("\n");
	}
	node n[SIZE][SIZE]; 
	//이차원 배열 노드 선언
	for (i = 0; i < SIZE; i++)
	{
		for(j=0;j<SIZE;j++)
		{ //노드 요소 초기화
			n[i][j].data = j;
			n[i][j].link = NULL;
		}
	}

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (ad[i][j] == 1)
			{ //인접행렬의 값이 1일 때
				if (n[i][i].link != NULL)
				{//link가 NULL이 아니면
					for (p = n[i][i].link; p->link != NULL; p = p->link) {
					} //NULL일 때를 찾아 끝 노드에 link
					p->link = &n[i][j];
				}
				else //link가 NULL이면 link
					n[i][i].link = &n[i][j];
				count[i]++; //입력될 때마다 count 1 증가
			}
			
		}
	}
	printf("\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", n[i][i].data);
		for (p = n[i][i].link; p != NULL && count[i]>0; p = p->link)
		{ //link의 값이 NULL이고, count가 0보다 크면 출력
			if (p != NULL && p->data != i)
				printf(" -> %d ", p->data); 
			count[i]--;
		}
		printf("\n");
	}
}
