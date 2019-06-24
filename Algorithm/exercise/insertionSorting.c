#include <stdio.h>
void insertionSort(int array[], int length);
void show1dArray(int array[], int length);
int main(void)
{
    puts("Enter 8 integers: ");
    int array[8];
    for (int i = 0; i < 8; i++) {
        scanf("%d", &array[i]);
    }
    insertionSort(array, 8);
    show1dArray(array, 8);
    return 0;
}

void insertionSort(int array[], int length)
{
    for (int j = 1; j < length; j++) {
        int key = array[j];
        // Insert array[j] into the sorted sequence array[0..j-1]
        int i = j - 1;
        while (i >= 0 && array[i] > key) {
            array[i+1] = array[i];    //对比的数据向前移动一格
            i--;                      //继续对比下一格数据
        }
        array[i+1] = key;             //要放在比key小的数前面，所以i+1
    }
}

void show1dArray(int array[], int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
}