#include <stdio.h>
int main(void)
{
    long num;
    long sum = 0L; //为了保持一致性，把sum初始化为Long类型的0。因为编译器会把0自动转换为合适的类型
    int status;
    
    printf("Please enter an integer to be summed ");
    printf(" (q to quit): ");
    status = scanf("%ld", &num);
    while (status == 1)
    {
        sum += num;
        printf("Please enter next integer (q to quit): ");
        status = scanf("%ld", &num);
    }
    printf("Those integers sum to %ld.\n", sum);

    return 0;
}