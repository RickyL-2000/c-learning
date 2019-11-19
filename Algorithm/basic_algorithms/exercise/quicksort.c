#include <stdio.h>
#define LENGTH 10

void quicksort(int* array, int left, int right);
int partition(int* array, int left, int right);

int main() {
    int array[LENGTH] = {2,5,32,1,5,7,36,4,1,4};
    quicksort(array, 0, LENGTH-1);
    for (int i = 0; i < LENGTH; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

void quicksort(int* array, int left, int right) {
    if (left < right) {
        int mid;
        mid = partition(array, left, right);
        quicksort(array, left, mid-1);
        quicksort(array, mid+1, right);
    }
}

int partition(int* array, int left, int right) {
    int pivot = *(array+right);
    int i = left - 1, j;
    int temp;
    for (j = left; j < right; j++) {
        if (*(array+j) <= pivot) {
            i += 1;
            temp = *(array+j);
            *(array+j) = *(array+i);
            *(array+i) = temp;
        }
    }
    temp = *(array+i+1);
    *(array+i+1) = *(array+right);
    *(array+right) = temp;
    return i+1;
}