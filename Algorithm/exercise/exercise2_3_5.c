//二分查找
#include <stdio.h>
int biSearch(int array[], int left, int right, int v);
int main()
{
    int array[8];
    printf("Enter 8 sorted integers: \n");
    for (int i = 0; i < 8; i++) {
        scanf("%d", &array[i]);
    }
    int v = 10;
    int index = biSearch(array, 0, 7, v);
    printf("%d", index+1);
    return 0;
}

int biSearch(int array[], int left, int right, int v)
{
    int mid = left + (right - left + 1) / 2; //[left...mid-1]&[mid...right] or [left...mid-1]&[mid]&[mid+1...right]
    if (v > array[mid]) {
        biSearch(array, mid+1, right, v);
    }
    else if (v < array[mid]) {
        biSearch(array, left, mid-1, v);
    }
    else if (v = array[mid]) {
        return mid;
    }
}