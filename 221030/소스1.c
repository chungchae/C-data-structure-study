#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1; //top을 -1로 초기화

int IsEmpty() {
    if (top < 0) //top이 0보다 작으면 1 반환
        return 1;
    else
        return 0;
}
int IsFull() {
    if (top >= MAX - 1) //스택이 다 차있으면 1 반환
        return 1;
    else
        return 0;
}

void push(int value) {
    if (IsFull() == 1)
        printf("스택이 가득 찼습니다.");
    else
        stack[++top] = value; //top을 1 증가시킨 후 새로운 값 입력
}

int pop() {
    if (IsEmpty() == 1)
        printf("스택이 비었습니다.");
    else
        return stack[top--]; //top값을 반환 후 top 1 감소
}

int main() {

    push(1);
    push(2);
    push(3);
    printf("%d ", pop());
    printf("%d ", pop());
    printf("%d ", pop());

    return 0;
}