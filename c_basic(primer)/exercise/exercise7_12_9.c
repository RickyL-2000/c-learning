//接受正整数输入，显示所有小于或等于该数的素数
#include <stdio.h>
int main()
{
    printf("Enter a positive integer (not 1) and enter \"q\" to quit: ");
    unsigned int num;
    while (scanf("%u", &num) == 1)
    {
        switch (num)
        {
            case 2: printf("The prime number is 2.\n");
                    break;
            case 3: 
            case 4: printf("The prime number is 2 3");
                    break;
            default: 
                    printf("The prime numbers are:\n2\n3\n");
                    for (unsigned int i = 5; i <= num; i++)
                    {
                        int isPrime = 1;                        
                        //printf("Now i = %u\n", i);                     //debug
                        for (unsigned int j = 2; j*j <= i; j++)
                        {
                            if (i % j == 0)
                            {
                                isPrime = 0;
                                break;
                            }
                            else 
                                continue;    //为什么加入这一句就不会输出9,15这些错误的数字了呢？？？这bug de的我摸不着头脑
                        }
                        if (isPrime)
                        {
                            printf("%u\n", i);
                        }
                    }
        }
        printf("Enter the next one: ");
    }
    printf("Done.");

    return 0;
}