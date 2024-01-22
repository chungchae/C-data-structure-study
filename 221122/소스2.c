#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEAP_SIZE 256 //heap�� �ִ� ������ ����

int heap[HEAP_SIZE];
int heap_count = 0; 

void swap(int* a, int* b) //�� ���� �ٲٴ� �Լ�
{
	int tmp = *a; *a = *b; *b = tmp;
}

void push(int data) //������ �Է� �Լ�
{
	heap[++heap_count] = data;

	int child = heap_count; //�ڽ� ����� �ε�����
	int parent = child / 2;
	while (child > 1 && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);
		child = parent; //�ڽ�,�θ� ��� �� �� ��ȯ
		parent = child / 2;
	}
}

void deleteH(int num)
{ //��� ���� �Լ�
	if (heap_count == 1)
	{ //��尡 �ϳ��� �ִ� ���
		heap[1] == NULL;
		heap_count--;
	}
	else
	{ //���� ã����, ���� ��尡 ���� ��带 ��ü
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
		printf("�����Ǿ����ϴ�.");
	}
}

void printH()
{
	printf("\n�Էµ� Heap: ");
	for (int i = 1; i <= heap_count; i++)
	{
		printf("\narr[%d]=%d ",i, heap[i]);
	}
}

void searchH(int len, int num)
{ //��� Ž�� �Լ�
	int keynum; int b = 0; int i; int j = 0;
	if (heap_count == 0)
		printf("����ֽ��ϴ�.");
	else
	{ //�� ã��
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
	{ //ã�� ���� �Ѹ����� ���� ��� ���
		printf("�Ѹ� ������ %d�� ���: ", num);
		while (j > 0)
		{
			printf("%d ", heap[j]);
			j = j / 2;
		}
	}
	else
		printf("���� ã�� �� �����ϴ�.");	
}

void sortH() 
{ //heap ���� �Լ�
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
	printf("������ �޴��� �����ϼ���: 1. �迭 �Է� 2. ���� 3. Ž�� 4. ��� 5. ������ �迭  ");
	scanf_s("%d", &key);

	while (key != 0)
	{
		switch (key)
		{
		case 1: {
			printf("�迭�� ���̸� �Է��ϼ���: ");
			scanf_s("%d", &len);
			
			while (len > 256)
			{
				printf("\n�迭�� ���̴� %d�� �ʰ��� �� �����ϴ�. �ٽ� �Է��ϼ���: ", HEAP_SIZE);
				scanf_s("%d", &len);
			}
			len = len + 1;

			int* arr = (int*)malloc(sizeof(int) * len);
			arr[0] = 0;

			printf("\n�迭�� �Է��ϼ���: ");
			for (int i = 1; i < len; i++)
			{
				scanf_s("%d", &arr[i]);
			}
			for (int i = 1; i < len; i++) {
				push(arr[i]);
			}
			printf("\n�ԷµǾ����ϴ�.\n");
			break;
		}

		case 2: {
			printf("������ ���� �Է��ϼ���: ");
			int dnum = 0;
			scanf_s("%d", &dnum);
			deleteH(dnum);
			break;
		}
		case 3:
		{
			printf("Ž���� ���� �Է��ϼ���: ");
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
			printf("�迭�� ���̸� �Է��Ͻÿ�: ");
			scanf_s("%d", &len2);
			srand(time(NULL)); //������ �迭 ����
			int* arr2 = (int*)malloc(sizeof(int) * len);
			arr2[0] = 0;
			for (int i = 0; i < len2; i++) {
				arr2[i] = rand() % 100 + 1;
				for (int j = 0; j < i; j++)
				{
					if (arr2[i] == arr2[j]) i--;
				}
			}
			printf("\n������ ������ �迭: ");
			for (int i = 1; i < len2; i++) {
				push(arr2[i]);
				printf("%d ", arr2[i]);
			}
			sortH(); //heap ���� �� ���
			printf("\n���ĵ� �迭: ");
			printH();
			break;
		}
		}
		printf("\n������ �޴��� �����ϼ���: 1. �迭 �Է� 2. ���� 3. Ž�� 4. ��� 5. ������ �迭  ");
		scanf_s("%d", &key);
	}
	return 0;
}