#pragma warning(disable :4996)
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    int line = 0; int space = 0; int word = 0;
    int i = 0;
    FILE* fs; //FILE* �� ���� fs ����
    fs = fopen("ctest.txt", "r"); //ctest.txt ������ �б� ���� ����
    printf("���� ����: \n");

    while (feof(fs) == 0) //������ ����������
    {
        char str[MAX];
        fgets(str, MAX, fs);
        while (str[i]!='\0') //�� �پ� �о� ����, ���� ������ �߰�
        {
            if (str[i] == ' ')
                space++;
            else
                word++;
            i++;
        }
        printf("%s", str); //�Էµ� ���� ���
        line++; //�� �� �߰�
        i = 0;
    }

    printf("\n�� ��: %d\n", line);
    printf("���� ������ ���� ��: %d\n", word); 
    printf("���� ���� ���� ��: %d\n", word + space);

    fclose(fs);
}