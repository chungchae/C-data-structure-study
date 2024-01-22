#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define min(x, y) (x) < (y) ? (x) : (y)
#define max(x, y) (x) > (y) ? (x) : (y) 

//min, max �Լ� ����

struct circle //�߽� ��ǥ�� �������� ������ �� ����ü
{
	float x;
	float y;
	float r;
};

void type(struct circle a, struct circle b) 
{
	float d;
	d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); //���� �߽� ������ �Ÿ� d

	if (d == a.r + b.r)
		printf("\n�� ���� �� �� ��ġ�մϴ�.");
	else if ((a.r == b.r) && (a.x == b.x) && (a.y == b.y))
		printf("\n�� ���� ��ġ�մϴ�.");
	else if (d > a.r + b.r)
		printf("\n�� ���� ������ �ʽ��ϴ�");
	else if ((d + min(a.r, b.r)) < max(a.r, b.r))
	{
		if (a.r > b.r)
			printf("\nB�� A�ȿ� �ֽ��ϴ�.");
		else if (a.r < b.r)
			printf("\nA�� B�ȿ� �ֽ��ϴ�.");
	}
	else
		printf("\nA�� B�� �� �� ��ġ�մϴ�.");
}

int main()
{
	struct circle a;
	struct circle b;

	printf("ù ��° ���� �߽��� �Է��ϼ���: ");
	scanf_s("%f %f", &a.x, &a.y);
	printf("ù ��° ���� �������� �Է��ϼ���: ");
	scanf_s("%f", &a.r);

	printf("�� ��° ���� �߽��� �Է��ϼ���: ");
	scanf_s("%f %f", &b.x, &b.y);
	printf("�� ��° ���� �������� �Է��ϼ���: ");
	scanf_s("%f", &b.r);

	type(a, b);
}