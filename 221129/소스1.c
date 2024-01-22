#include <stdio.h>
#define SIZE 4

typedef struct node
{ //��� ����ü ����
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
	{ //�Էµ� ������� Ȯ��
		for (j = 0; j < SIZE; j++)
		{
			printf("%d ", ad[i][j]);
		}
		printf("\n");
	}
	node n[SIZE][SIZE]; 
	//������ �迭 ��� ����
	for (i = 0; i < SIZE; i++)
	{
		for(j=0;j<SIZE;j++)
		{ //��� ��� �ʱ�ȭ
			n[i][j].data = j;
			n[i][j].link = NULL;
		}
	}

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (ad[i][j] == 1)
			{ //��������� ���� 1�� ��
				if (n[i][i].link != NULL)
				{//link�� NULL�� �ƴϸ�
					for (p = n[i][i].link; p->link != NULL; p = p->link) {
					} //NULL�� ���� ã�� �� ��忡 link
					p->link = &n[i][j];
				}
				else //link�� NULL�̸� link
					n[i][i].link = &n[i][j];
				count[i]++; //�Էµ� ������ count 1 ����
			}
			
		}
	}
	printf("\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", n[i][i].data);
		for (p = n[i][i].link; p != NULL && count[i]>0; p = p->link)
		{ //link�� ���� NULL�̰�, count�� 0���� ũ�� ���
			if (p != NULL && p->data != i)
				printf(" -> %d ", p->data); 
			count[i]--;
		}
		printf("\n");
	}
}
