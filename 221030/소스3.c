#include <stdio.h>

BinarySearch(int* a, int len, int val) {

    int first = 0;
    int last = len - 1;
    int mid;

    while (first <= last) {

        mid = (first + last) / 2;

        if (a[mid] == val) {
            return mid;
        }
        else {
            if (a[mid] > val)
                last = mid - 1;
            else
                first = mid + 1;
        }

    }

    return -1;
}

int main()
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("%d", BinarySearch(A, 10, 6));
}