#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct circle //�� ����ü, ��ǥ�� ������
{
	float x;
	float y;
	float r;
};
struct point //�� ����ü, ��ǥ
{
	float x;
	float y;
};
void type(struct circle c, struct point p) //�� ����ü�� �� ����ü�� �Էº����� ����
{
	float d;
	d = (c.x - p.x)*(c.x - p.x) + (c.y - p.y)*(c.y - p.y); //���� �߽ɰ� ��ǥ������ �Ÿ��� ����

	if (d > c.r * c.r)
		printf("\n�� �ۿ� �ֽ��ϴ�.");
	else if (d  == c.r * c.r)
		printf("\n�� ���� �ֽ��ϴ�.");
	else if (d  < c.r * c.r)
		printf("\n�� �ȿ� �ֽ��ϴ�.");
}
int main()
{
	struct circle c; //�� ����ü ���� c
	struct point p; //�� ����ü ���� p

	printf("���� �߽��� �Է��ϼ���: "); 
	scanf_s("%f %f", &c.x, &c.y);
	printf("\n���� �������� �Է��ϼ���: ");
	scanf_s("%f", &c.r);

	printf("\n���� ��ǥ�� �Է��ϼ���: ");
	scanf_s("%f %f", &p.x, &p.y);

	type(c, p);
}