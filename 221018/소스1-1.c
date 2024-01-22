#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct circle //원 구조체, 좌표와 반지름
{
	float x;
	float y;
	float r;
};
struct point //점 구조체, 좌표
{
	float x;
	float y;
};
void type(struct circle c, struct point p) //원 구조체와 점 구조체를 입력변수로 가짐
{
	float d;
	d = (c.x - p.x)*(c.x - p.x) + (c.y - p.y)*(c.y - p.y); //원의 중심과 좌표까지의 거리의 제곱

	if (d > c.r * c.r)
		printf("\n원 밖에 있습니다.");
	else if (d  == c.r * c.r)
		printf("\n원 위에 있습니다.");
	else if (d  < c.r * c.r)
		printf("\n원 안에 있습니다.");
}
int main()
{
	struct circle c; //원 구조체 변수 c
	struct point p; //점 구조체 변수 p

	printf("원의 중심을 입력하세요: "); 
	scanf_s("%f %f", &c.x, &c.y);
	printf("\n원의 반지름을 입력하세요: ");
	scanf_s("%f", &c.r);

	printf("\n점의 좌표를 입력하세요: ");
	scanf_s("%f %f", &p.x, &p.y);

	type(c, p);
}