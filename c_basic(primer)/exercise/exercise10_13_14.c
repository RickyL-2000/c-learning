//提示用户输入3组数，每组数包含5个double类型。用变长数组作为形参，完成以下任务：
//a. 把用户输入的数据存储在3x5的数组中
//b. 计算每组数据的平均值
//c. 计算所有数据的平均值
//d. 找出这15个数据中的最大值
#include <stdio.h>
double average(double array1d[], int cols);
double maximum(int rows, int cols, double array2d[rows][cols]);

int main()
{
    const int ROWS = 3, COLS = 5;
    double numbers[ROWS][COLS];
    printf("Enter %d groups of numbers, each group has %d float-point numbers: \n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            scanf("%lf", &numbers[i][j]);           //input the array
    }
    double avg_all;
    for (int i = 0; i < ROWS; i++)
    {
        double avg = average(numbers[i], COLS);
        printf("The average of group %d is %f.\n", i+1, avg);   //average of each group
        avg_all += avg;
    }
    avg_all /= ROWS;
    printf("The average of all the numbers is %f.\n", avg_all);   //average of all the numbers
    double max = maximum(ROWS, COLS, numbers);
    printf("The maximum of all the numbers is %f.", max);       //maximum of all the numbers
    return 0;
}

double average(double array1d[], int cols)
{
    double avg = 0.0;
    for (int i = 0; i < cols; i++)
        avg += array1d[i];
    avg /= cols;
    return avg;
}

double maximum(int rows, int cols, double array2d[rows][cols])
{
    double max = array2d[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (max < array2d[i][j])
                max = array2d[i][j];
        }
    }

    return max;
}