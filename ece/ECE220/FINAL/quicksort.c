#include <stdio.h>

int partition(int* array, int left, int right);
void quicksort(int* array, int left, int right);

int main() {
    /* nothing */
}

int partition(int* array, int left, int right) {
    int i = left-1,
        j = left,
        temp;
    for (; j < right; j++) {
        if (*(array+j) < *(array+right)) {
            i++;
            temp = *(array+i);
            *(array+i) = *(array+j);
            *(array+j) = temp;
        }
    }
    temp = *(array+i+1);
    *(array+i+1) = *(array+right);
    *(array+right) = temp;
    return i+1;
}

void quicksort(int* array, int left, int right) {
    if (left < right) {
        int mid = partition(array, left, right);
        quicksort(array, left, mid-1);
        quicksort(array, mid+1, right);
    }
}