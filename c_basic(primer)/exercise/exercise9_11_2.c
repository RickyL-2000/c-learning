//设计一个函数chline(ch, i, j)，打印指定的字符j行i列。
#include <stdio.h>
void chline(char, int, int);
int main()
{
    char ch = '*';
    int i = 10, j = 5;
    chline(ch, i, j);

    return 0;
}

void chline(char ch, int i, int j)
{
    for (int n = 0; n < j; n++)
    {
        for (int m = 0; m < i; m++)
            printf("%c", ch);
        printf("\n");
    }

    return;
}