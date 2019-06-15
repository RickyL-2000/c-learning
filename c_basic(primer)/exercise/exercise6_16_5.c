#include <stdio.h>
int main()
{
    const char init = 'A'; //这个初始值可以随意改，不一定是'A' :))))))
    printf("Enter a capital letter: \n");
    char ch;
    scanf("%c", &ch);
    int len = ch - init;
    for (int row = 0; row < len+1; row++)
    {
        for (int i = len-row; i > 0; i--)
            printf(" ");
        for (char c = init; c < init+row; c++)
            printf("%c", c);
        char mid = init+row;
        printf("%c", mid);
        for (char c = init+row-1; c >= init; c--)
            printf("%c", c);
        printf("\n");
    }
    return 0;
}