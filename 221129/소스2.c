#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX 100	
#define INF	10000

typedef struct GraphType {
	int n;
	int weight[MAX][MAX];
} GraphType;

int distance[MAX];
int found[MAX];

int choose(int distance[], int n, int found[])
{ //�ִܰŸ��� �ε����� ��ȯ�ϴ� �Լ�
	int i, min, minpos;

	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void shortest_path(GraphType* g)
{ //�ִܰŸ��� ã�� �Լ�
	int i, u, w;
	for (i = 0; i < g->n; i++) 
	{ //v0�� �������� �Ÿ� �ʱ�ȭ
		distance[i] = g->weight[0][i];
		found[i] = FALSE;
	} //FALSE�� �ʱ�ȭ
	found[0] = TRUE; //v0 �湮
	distance[0] = 0;
	for (i = 0; i < g->n - 1; i++) {
		u = choose(distance, g->n, found);
		found[u] = TRUE; //�湮 �Ŀ� TRUE
		for (w = 0; w < g->n; w++) //���� ����ŭ �ݺ�
			if (!found[w]) //�ִܰŸ��� ã���� ����
				if (distance[u] + g->weight[u][w] < distance[w])
					distance[w] = distance[u] + g->weight[u][w];
	}
}
int main(void)
{ //�׷��� �Է�
	GraphType g = { 6,
	{{ 0,  INF,  25, 15, INF,  INF },
	{ 15,  0,  INF,  INF,  10,  INF },
	{ 10,  50, 0, INF, 65, INF },
	{ INF,  20, INF, 0, 35, INF },
	{ INF,  INF,  INF,  30,   0, INF },
	{ INF, INF,  INF, 3, INF, 0 } }
	};

	shortest_path(&g); //�ִܰŸ� ã�� distance�� ����
	for (int i = 0; i < g.n; i++)
	{
		if (distance[i]==INF) //���Ѵ�� ��� �������� ǥ��
			printf("v0 -> v%d�� �ִܰŸ�: ��� ����", i);
		else
			printf("v0 -> v%d�� �ִܰŸ�: %d\n", i, distance[i]);
	}
}

