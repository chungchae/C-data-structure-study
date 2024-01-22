#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef struct student //student ����ü ����
{
	char name[20]; //�̸�
	int score; //����
}student;

typedef struct node //student�� data�� ������ ��� ����
{
	struct node* pre;
	student data;
	struct node* next;
}node;

typedef struct node* NodePointer; //node������ ����
NodePointer head, tail; //����� head�� tail ����


void init(node* head) //��� �ʱ�ȭ �Լ�
{
	head->next = tail;
	head->pre = head;
	tail->next = tail;
	tail->pre = head;
} 

void insert() //��� �Է� �Լ�
{
	NodePointer i, e;
	i = head->next;
	student d;

	printf("\n�Է��� �л� �̸�: ");
	scanf_s("%s", d.name, (int) sizeof(d.name));

	printf("�Է��� �л� ����: ");
	scanf_s("%d", &d.score);
	if (d.score < 0 || d.score>100)
	{
		printf("�߸��� ������ �ԷµǾ����ϴ�. �ٽ� �Է����ּ���: "); //0~100���� �ƴϸ� �ٽ� �Է�
		scanf_s("%d", &d.score);
	}

	while (i->data.score <= d.score && i != tail) //������ ũ�⿡ ���� ���ĵǵ��� �Է�
		i = i->next;
	e = (NodePointer)malloc(sizeof(node));
	e->data = d;
	i->pre->next = e; //i�տ� e�ֱ�
	e->pre = i->pre;
	i->pre = e;
	e->next = i;

	printf("�Է��� �Ϸ�Ǿ����ϴ�.\n\n");
}

void search() //�л� �˻� �Լ�
{
	char sname[20]; int count = 0; int wcount = 0;
	NodePointer seek = 0;
	printf("�˻��� �л� �̸�: ");
	scanf_s("%s", sname, (int)sizeof(sname));
	for (seek = head->next; seek != tail; seek = seek->next)
	{
		wcount++; //��ü ����� ������ wcount�� ����
	}

	for (seek = head->next; seek != tail; seek = seek->next)
	{
		count++;
		if (strcmp(seek->data.name , sname) == 0)
		{ //(��ü ���-ã�� ��� ��ġ +1) �� ��� ���
			printf("\n�̸�: %s / ����: %d �� / ���: %d ��\n\n", seek->data.name, seek->data.score, wcount-count+1); 
			return;
		}
	}
	printf("�����Ͱ� �����ϴ�.\n");
}
void removenode() //��� ���� �Լ�
{
	char rname[20];
	NodePointer seek = 0;
	printf("������ �л� �̸�: ");
	scanf_s("%s", rname, (int)sizeof(rname));
	for (seek = head->next; seek != tail; seek = seek->next)
	{
		if (strcmp(seek->data.name, rname) == 0) 
		{ //��� ã�� �����ϰ� �޸� ȸ��
			seek->pre->next = seek->next;
			seek->next->pre = seek->pre;
			free(seek);
			printf("�����Ͽ����ϴ�.\n");
			return;
		}
	}
	printf("�����Ͱ� �����ϴ�.\n");
}

int main()
{
	head = (NodePointer)malloc(sizeof(node)); //head�� tail �����Ҵ�
	tail = (NodePointer)malloc(sizeof(node));
	init(head); //head�� tail ���� �� �ʱ�ȭ

	int key;
	printf("������ �޴��� �����ϼ���\n\n");
	printf("========================");
	printf("\n0: ���� \n1: �л� �Է� \n2: �л� �˻� \n3: �л� ����\n");
	printf("========================\n");
	scanf_s("%d", &key);

	while (key != 0) //0�� �Է��� ������ �ݺ�����, 0�Է� �� ����
	{
		switch (key)
		{
		case 1: insert(); break;
		case 2: search(); break;
		case 3: removenode(); break;
		}
		printf("������ �޴��� �����ϼ���\n");
		printf("========================");
		printf("\n0: ���� \n1: �л� �Է� \n2: �л� �˻� \n3: �л� ����\n");
		printf("========================\n");
		scanf_s("%d", &key);
	}
}