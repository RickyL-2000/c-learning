//初始化一个double类型的二维数组，把该数组中的数据拷贝至另一个二维数组中
#include <stdio.h>
void copy_arr(double target1[], double source[], int n);
int main()
{
    double array[4][4] = {
        {1.0, 2.0, 3.0, 4.0},
        {5.0, 6.0, 7.0, 8.0},
        {9.0, 10.0, 11.0, 12.0},
        {13.0, 14.0, 15.0, 16.0},
    };
    double target[4][4];
    for (int i = 0; i < 4; i++)
        copy_arr(target[i], array[i], 4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%.1f  ", array[i][j]);
        printf("\n");
    }

    return 0;
}

void copy_arr(double target[], double source[], int n)
{
    for (int i = 0; i < n; i++)
        target[i] = source[i];
}
