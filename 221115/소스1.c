#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef struct student //student 구조체 생성
{
	char name[20]; //이름
	int score; //점수
}student;

typedef struct node //student를 data로 가지는 노드 생성
{
	struct node* pre;
	student data;
	struct node* next;
}node;

typedef struct node* NodePointer; //node포인터 생성
NodePointer head, tail; //노드의 head와 tail 생성


void init(node* head) //노드 초기화 함수
{
	head->next = tail;
	head->pre = head;
	tail->next = tail;
	tail->pre = head;
} 

void insert() //노드 입력 함수
{
	NodePointer i, e;
	i = head->next;
	student d;

	printf("\n입력할 학생 이름: ");
	scanf_s("%s", d.name, (int) sizeof(d.name));

	printf("입력할 학생 점수: ");
	scanf_s("%d", &d.score);
	if (d.score < 0 || d.score>100)
	{
		printf("잘못된 점수가 입력되었습니다. 다시 입력해주세요: "); //0~100점이 아니면 다시 입력
		scanf_s("%d", &d.score);
	}

	while (i->data.score <= d.score && i != tail) //성적의 크기에 따라 정렬되도록 입력
		i = i->next;
	e = (NodePointer)malloc(sizeof(node));
	e->data = d;
	i->pre->next = e; //i앞에 e넣기
	e->pre = i->pre;
	i->pre = e;
	e->next = i;

	printf("입력이 완료되었습니다.\n\n");
}

void search() //학생 검색 함수
{
	char sname[20]; int count = 0; int wcount = 0;
	NodePointer seek = 0;
	printf("검색할 학생 이름: ");
	scanf_s("%s", sname, (int)sizeof(sname));
	for (seek = head->next; seek != tail; seek = seek->next)
	{
		wcount++; //전체 노드의 개수를 wcount에 저장
	}

	for (seek = head->next; seek != tail; seek = seek->next)
	{
		count++;
		if (strcmp(seek->data.name , sname) == 0)
		{ //(전체 노드-찾은 노드 위치 +1) 로 등수 출력
			printf("\n이름: %s / 점수: %d 점 / 등수: %d 등\n\n", seek->data.name, seek->data.score, wcount-count+1); 
			return;
		}
	}
	printf("데이터가 없습니다.\n");
}
void removenode() //노드 제거 함수
{
	char rname[20];
	NodePointer seek = 0;
	printf("삭제할 학생 이름: ");
	scanf_s("%s", rname, (int)sizeof(rname));
	for (seek = head->next; seek != tail; seek = seek->next)
	{
		if (strcmp(seek->data.name, rname) == 0) 
		{ //노드 찾아 삭제하고 메모리 회수
			seek->pre->next = seek->next;
			seek->next->pre = seek->pre;
			free(seek);
			printf("삭제하였습니다.\n");
			return;
		}
	}
	printf("데이터가 없습니다.\n");
}

int main()
{
	head = (NodePointer)malloc(sizeof(node)); //head와 tail 동적할당
	tail = (NodePointer)malloc(sizeof(node));
	init(head); //head와 tail 생성 후 초기화

	int key;
	printf("실행할 메뉴를 선택하세요\n\n");
	printf("========================");
	printf("\n0: 종료 \n1: 학생 입력 \n2: 학생 검색 \n3: 학생 제거\n");
	printf("========================\n");
	scanf_s("%d", &key);

	while (key != 0) //0을 입력할 때까지 반복실행, 0입력 시 종료
	{
		switch (key)
		{
		case 1: insert(); break;
		case 2: search(); break;
		case 3: removenode(); break;
		}
		printf("실행할 메뉴를 선택하세요\n");
		printf("========================");
		printf("\n0: 종료 \n1: 학생 입력 \n2: 학생 검색 \n3: 학생 제거\n");
		printf("========================\n");
		scanf_s("%d", &key);
	}
}