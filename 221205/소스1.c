#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
int count = 0; int count2 = 0;

void bubble(int arr[MAX])
{ //bubble sort
    int i, j, k, temp;

    for (i = MAX - 1; i > 0; i--) 
    {
        for (j = 0; j < i; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            { //값 비교 후 교환
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        } //단계마다 배열 출력
        printf("step %d: ", MAX-i);
        for (k = 0; k < MAX; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

void insert(int arr[MAX]) 
{ //insertion sort
    int i, j, k, key;
    for (i = 1; i < MAX; i++) 
    { //key값 설정
        key = arr[i]; 
        for (j = i - 1; j >= 0 && arr[j] > key; j--) 
        { 
            arr[j + 1] = arr[j]; 
        }
        arr[j + 1] = key;
        //단계마다 배열 출력
        printf("step %d: ", i);
        for (k = 0; k < MAX; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

void quick(int arr[MAX], int L, int R) 
{ //quick sort
    int left = L, right = R, k = 0; 
    //left, right값 설정, pivot 값 설정
    int pivot = arr[(L + R) / 2]; 
    int temp;
    do
    {
        //단계마다 배열 출력
        printf("step %d: ", count++ + 1);
        for (k = 0; k < MAX; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
        while (arr[left] < pivot) 
            left++;
        while (arr[right] > pivot) 
            right--;
        if (left <= right)  
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    } while (left <= right);  

    if (L < right)
    { //변경된 값으로 재귀 실행
        quick(arr, L, right);
    }
    if (left < R)
    { //변경된 값으로 재귀 실행
        quick(arr, left, R);
    }
}

void merge(int list[], int left, int mid, int right) 
{ 
    int i, j, k, l;
    int sorted[MAX];
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right) 
    { //정렬된 배열 합병
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    if (i > mid) 
    {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
        //남은 값 복사
    }
    else 
    {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }

    for (l = left; l <= right; l++) 
    {
        list[l] = sorted[l];
    }
    printf("step %d: ", count2++ + 1);
    for (k = 0; k < MAX; k++)
    {
        printf("%d ", list[k]);
    }
    printf("\n");
}

void merge_sort(int arr[], int left, int right) 
{ //merge sort
    int mid, k;
    if (left < right) 
    {
        mid = (left + right) / 2; //중간 위치 찾아 분할
        merge_sort(arr, left, mid); //앞 배열 정렬
        merge_sort(arr, mid + 1, right); //뒤 배열 정렬
        merge(arr, left, mid, right); //정렬된 두 배열 합병
    }
}

int main() 
{
    int arr[MAX]; int arr2[MAX]; int k = 0;
    //임의의 배열 생성 후 arr저장, arr2에 초기 배열값 저장
	srand((int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{ //중복 없는 임의의 배열 생성
		arr[i] = rand() % 100 + 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
                i--;
        }
	}
    for (k = 0; k < MAX; k++)
    { //초기 값 저장
        arr2[k] = arr[k];
    }
    printf("랜덤 배열: ");
    for (k = 0; k < MAX; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n\n");
    //각 정렬 과정과 결과 출력
    printf("bubble sort: \n");
    bubble(arr); printf("\n");
    for (k = 0; k < MAX; k++)
    { //정렬 후 초기 값으로 변경
        arr[k] = arr2[k];
    }
    printf("insert sort: \n");
    insert(arr); printf("\n");
    for (k = 0; k < MAX; k++)
    {
        arr[k] = arr2[k];
    }
    printf("quick sort: \n");
    quick(arr,0,MAX-1); printf("\n");
    for (k = 0; k < MAX; k++)
    {
        arr[k] = arr2[k];
    }
    printf("merge sort: \n");
    merge_sort(arr, 0, MAX - 1);
}