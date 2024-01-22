#include <stdio.h>
#define MAX 100
int front = -1;
int rear = -1;
int queue[MAX]; //ũŰ MAX�� ������ �迭 queue


int IsEmpty(void) {
    if (front == rear)//front�� rear�� ������ ť�� ����ִ� ���� 
        return 1;
    else return 0;
}
int IsFull(void) {
    int tmp = (rear + 1) % MAX; //���� ť���� rear+1�� MAX�� ���� ����������
    if (tmp == front)//front�� ������ ť�� ������ �ִ� ���� 
        return 1;
    else
        return 0;
}
void addq(int value) {
    if (IsFull())
        printf("Queue is Full.\n");
    else {
        rear = (rear + 1) % MAX;
        queue[rear] = value;
    }

}
int deleteq() {
    if (IsEmpty())
        printf("Queue is Empty.\n");
    else {
        front = (front + 1) % MAX;
        return queue[front];
    }
}

int main() {

    addq(1);
    addq(2);
    addq(3);
    printf("%d\n", deleteq());
    printf("%d\n", deleteq());
    printf("%d\n", deleteq());
    deleteq();

    return 0;
}