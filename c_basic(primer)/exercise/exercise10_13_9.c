//初始化一个double类型的3x5二维数组，使用一个处理变长数组的函数将其拷贝至另一个二维数组中。
//还要编写一个以变长数组为形参的函数以显示两个数组的内容。这两个函数应该能处理任意NxM数组。
#include <stdio.h>
void copyArray(int rows, int cols, double source[rows][cols], double target[rows][cols]);
void showArray(int rows, int cols, double array[rows][cols]);

int main()
{
    double source[3][5] = {
        {1.0, 2.0, 3.0, 4.0, 5.0},
        {5.0, 6.0, 7.0, 8.0, 9.0},
        {9.0, 10.0, 11.0, 12.0, 13.0},
    };
    double target[3][5];
    printf("Now source data is:\n");
    showArray(3,5,source);
    copyArray(3,5,source,target);
    printf("Now copy data is:\n");
    showArray(3,5,target);
    return 0;
}

void copyArray(int rows, int cols, double source[rows][cols], double target[rows][cols])
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
            target[r][c] = source[r][c];
    }
}

void showArray(int rows, int cols, double array[rows][cols])
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
            printf("%f  ", array[r][c]);
        printf("\n");
    }
}