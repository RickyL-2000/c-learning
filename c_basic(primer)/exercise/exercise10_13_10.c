//编写一个函数，把两个数组中相对应的元素相加，然后把结果储存到第三个数组中
#include <stdio.h>
void addArrays(double array1[], double array2[], double sum[], int n);

int main()
{
    double array1[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double array2[5] = {5.0, 6.0, 7.0, 8.0, 9.0};
    double sum[5];
    addArrays(array1, array2, sum, 5);
    for (int i = 0; i < 5; i++)
        printf("%f  ", sum[i]);
    return 0;
}

void addArrays(double array1[], double array2[], double sum[], int n)
{
    for (int i = 0; i < n; i++)
        sum[i] = array1[i] + array2[i];
}