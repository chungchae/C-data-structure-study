#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEAP_SIZE 256 //heap의 최대 사이즈 설정

int heap[HEAP_SIZE];
int heap_count = 0; 

void swap(int* a, int* b) //두 값을 바꾸는 함수
{
	int tmp = *a; *a = *b; *b = tmp;
}

void push(int data) //데이터 입력 함수
{
	heap[++heap_count] = data;

	int child = heap_count; //자식 노드의 인덱스값
	int parent = child / 2;
	while (child > 1 && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);
		child = parent; //자식,부모 노드 비교 후 교환
		parent = child / 2;
	}
}

void deleteH(int num)
{ //노드 삭제 함수
	if (heap_count == 1)
	{ //노드가 하나만 있는 경우
		heap[1] == NULL;
		heap_count--;
	}
	else
	{ //값을 찾으면, 뒤의 노드가 앞의 노드를 대체
		for (int i = 0; i < heap_count; i++)
		{
			if (heap[i] == num)
			{
				for (int j = i; j < heap_count; j++)
				{
					heap[j] = heap[j + 1];
				}
				heap_count--;
				i--;
			}
		}
		printf("삭제되었습니다.");
	}
}

void printH()
{
	printf("\n입력된 Heap: ");
	for (int i = 1; i <= heap_count; i++)
	{
		printf("\narr[%d]=%d ",i, heap[i]);
	}
}

void searchH(int len, int num)
{ //노드 탐색 함수
	int keynum; int b = 0; int i; int j = 0;
	if (heap_count == 0)
		printf("비어있습니다.");
	else
	{ //값 찾기
		for (i = 0; i < len; i++)
		{
			if (heap[i] == num)
			{
				keynum = heap[i];
				b = 1;
				j = i;
			}
		}
	}
	if (b == 1)
	{ //찾은 값이 뿌리까지 가는 경로 출력
		printf("뿌리 노드까지 %d의 경로: ", num);
		while (j > 0)
		{
			printf("%d ", heap[j]);
			j = j / 2;
		}
	}
	else
		printf("값을 찾을 수 없습니다.");	
}

void sortH() 
{ //heap 정렬 함수
	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= heap_count) {
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}
	while (child <= heap_count && heap[parent] < heap[child]) 
	{
		swap(&heap[parent], &heap[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= heap_count) 
		{
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
		}
	}
}

int main() 
{
	int key; int len = 0; int len2 = 0;
	printf("실행할 메뉴를 선택하세요: 1. 배열 입력 2. 삭제 3. 탐색 4. 출력 5. 임의의 배열  ");
	scanf_s("%d", &key);

	while (key != 0)
	{
		switch (key)
		{
		case 1: {
			printf("배열의 길이를 입력하세요: ");
			scanf_s("%d", &len);
			
			while (len > 256)
			{
				printf("\n배열의 길이는 %d을 초과할 수 없습니다. 다시 입력하세요: ", HEAP_SIZE);
				scanf_s("%d", &len);
			}
			len = len + 1;

			int* arr = (int*)malloc(sizeof(int) * len);
			arr[0] = 0;

			printf("\n배열을 입력하세요: ");
			for (int i = 1; i < len; i++)
			{
				scanf_s("%d", &arr[i]);
			}
			for (int i = 1; i < len; i++) {
				push(arr[i]);
			}
			printf("\n입력되었습니다.\n");
			break;
		}

		case 2: {
			printf("삭제할 값을 입력하세요: ");
			int dnum = 0;
			scanf_s("%d", &dnum);
			deleteH(dnum);
			break;
		}
		case 3:
		{
			printf("탐색할 값을 입력하세요: ");
			int snum = 0;
			scanf_s("%d", &snum);
			searchH(len, snum);
			break;
		}

		case 4: 
		{
			sortH();
			printH();
			break;
		}
		case 5:
		{
			printf("배열의 길이를 입력하시오: ");
			scanf_s("%d", &len2);
			srand(time(NULL)); //랜덤한 배열 생성
			int* arr2 = (int*)malloc(sizeof(int) * len);
			arr2[0] = 0;
			for (int i = 0; i < len2; i++) {
				arr2[i] = rand() % 100 + 1;
				for (int j = 0; j < i; j++)
				{
					if (arr2[i] == arr2[j]) i--;
				}
			}
			printf("\n생성된 임의의 배열: ");
			for (int i = 1; i < len2; i++) {
				push(arr2[i]);
				printf("%d ", arr2[i]);
			}
			sortH(); //heap 정렬 후 출력
			printf("\n정렬된 배열: ");
			printH();
			break;
		}
		}
		printf("\n실행할 메뉴를 선택하세요: 1. 배열 입력 2. 삭제 3. 탐색 4. 출력 5. 임의의 배열  ");
		scanf_s("%d", &key);
	}
	return 0;
}