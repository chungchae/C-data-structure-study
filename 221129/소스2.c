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
{ //최단거리의 인덱스를 반환하는 함수
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
{ //최단거리를 찾는 함수
	int i, u, w;
	for (i = 0; i < g->n; i++) 
	{ //v0을 기준으로 거리 초기화
		distance[i] = g->weight[0][i];
		found[i] = FALSE;
	} //FALSE로 초기화
	found[0] = TRUE; //v0 방문
	distance[0] = 0;
	for (i = 0; i < g->n - 1; i++) {
		u = choose(distance, g->n, found);
		found[u] = TRUE; //방문 후에 TRUE
		for (w = 0; w < g->n; w++) //정점 수만큼 반복
			if (!found[w]) //최단거리를 찾으면 갱신
				if (distance[u] + g->weight[u][w] < distance[w])
					distance[w] = distance[u] + g->weight[u][w];
	}
}
int main(void)
{ //그래프 입력
	GraphType g = { 6,
	{{ 0,  INF,  25, 15, INF,  INF },
	{ 15,  0,  INF,  INF,  10,  INF },
	{ 10,  50, 0, INF, 65, INF },
	{ INF,  20, INF, 0, 35, INF },
	{ INF,  INF,  INF,  30,   0, INF },
	{ INF, INF,  INF, 3, INF, 0 } }
	};

	shortest_path(&g); //최단거리 찾아 distance에 저장
	for (int i = 0; i < g.n; i++)
	{
		if (distance[i]==INF) //무한대면 경로 없음으로 표시
			printf("v0 -> v%d의 최단거리: 경로 없음", i);
		else
			printf("v0 -> v%d의 최단거리: %d\n", i, distance[i]);
	}
}

