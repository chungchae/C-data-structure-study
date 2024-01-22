#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define min(x, y) (x) < (y) ? (x) : (y)
#define max(x, y) (x) > (y) ? (x) : (y) 

//min, max 함수 선언

struct circle //중심 좌표와 반지름을 포함한 원 구조체
{
	float x;
	float y;
	float r;
};

void type(struct circle a, struct circle b) 
{
	float d;
	d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); //원의 중심 사이의 거리 d

	if (d == a.r + b.r)
		printf("\n두 원은 한 점 일치합니다.");
	else if ((a.r == b.r) && (a.x == b.x) && (a.y == b.y))
		printf("\n두 원은 일치합니다.");
	else if (d > a.r + b.r)
		printf("\n두 원은 만나지 않습니다");
	else if ((d + min(a.r, b.r)) < max(a.r, b.r))
	{
		if (a.r > b.r)
			printf("\nB가 A안에 있습니다.");
		else if (a.r < b.r)
			printf("\nA가 B안에 있습니다.");
	}
	else
		printf("\nA와 B는 두 점 일치합니다.");
}

int main()
{
	struct circle a;
	struct circle b;

	printf("첫 번째 원의 중심을 입력하세요: ");
	scanf_s("%f %f", &a.x, &a.y);
	printf("첫 번째 원의 반지름을 입력하세요: ");
	scanf_s("%f", &a.r);

	printf("두 번째 원의 중심을 입력하세요: ");
	scanf_s("%f %f", &b.x, &b.y);
	printf("두 번째 원의 반지름을 입력하세요: ");
	scanf_s("%f", &b.r);

	type(a, b);
}