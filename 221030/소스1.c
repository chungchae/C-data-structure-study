#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1; //top�� -1�� �ʱ�ȭ

int IsEmpty() {
    if (top < 0) //top�� 0���� ������ 1 ��ȯ
        return 1;
    else
        return 0;
}
int IsFull() {
    if (top >= MAX - 1) //������ �� �������� 1 ��ȯ
        return 1;
    else
        return 0;
}

void push(int value) {
    if (IsFull() == 1)
        printf("������ ���� á���ϴ�.");
    else
        stack[++top] = value; //top�� 1 ������Ų �� ���ο� �� �Է�
}

int pop() {
    if (IsEmpty() == 1)
        printf("������ ������ϴ�.");
    else
        return stack[top--]; //top���� ��ȯ �� top 1 ����
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