//读取整数直到用户输入0，报告用户输入的偶数（不包括0）的个数、平均值，以及输入的奇数的个数、平均值
#include <stdio.h>
int main()
{
    printf("Enter some positive integers and end it with 0 (use blank space to split them out): \n");
    int num, evens = 0, odds = 0;
    float av_evens = 0.0, av_odds = 0.0;
    scanf("%u", &num);
    while (num != 0)
    {
        if (num % 2 == 0)
        {
            ++evens;
            av_evens += num;
        }
        else
        {
            ++odds;
            av_odds += num;
        }
        scanf("%u", &num);
    }
    av_evens /= evens;
    av_odds /= odds;
    if (evens == 0)
        printf("There is no even numbers.\n");
    else if (evens == 1)
        printf("There is 1 even number.\n");
    else 
        printf("There are %d even numbers and the average of them is %f\n", evens, av_evens);
    if (odds == 0)
        printf("There is no odd numbers.");
    else if (odds == 1)
        printf("There is 1 odd number.");
    else 
        printf("There are %d odd numbers and the average of them is %f\n", odds, av_odds);
    
    return 0;
}