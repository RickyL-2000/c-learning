#include <stdio.h>
int main()
{
    int num, i = 0;
    printf("Enter an integer: \n");
    scanf("%d", &num);

    while (++i <= 11) //这里是11，因为一共有11个数
        printf("%d ", num+i-1);

    return 0;    
}


/* 这个程序是失败案例！！！
#include <stdio.h>
int main()
{
    int num;
    printf("Enter an integer: \n");
    scanf("%d", &num);
    printf("%d", num);
    while (++num <= num+10) //这个地方右边的num会一起+1，这样就会死循环
        printf("%d", num);
    return 0;    
}
 */