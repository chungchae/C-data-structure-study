#pragma warning(disable :4996)
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    int line = 0; int space = 0; int word = 0;
    int i = 0;
    FILE* fs; //FILE* 형 변수 fs 선언
    fs = fopen("ctest.txt", "r"); //ctest.txt 파일을 읽기 모드로 열기
    printf("파일 내용: \n");

    while (feof(fs) == 0) //파일이 끝날때까지
    {
        char str[MAX];
        fgets(str, MAX, fs);
        while (str[i]!='\0') //한 줄씩 읽어 공백, 문자 변수에 추가
        {
            if (str[i] == ' ')
                space++;
            else
                word++;
            i++;
        }
        printf("%s", str); //입력된 문장 출력
        line++; //줄 수 추가
        i = 0;
    }

    printf("\n줄 수: %d\n", line);
    printf("공백 미포함 글자 수: %d\n", word); 
    printf("공백 포함 글자 수: %d\n", word + space);

    fclose(fs);
}