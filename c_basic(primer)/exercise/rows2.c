#include <stdio.h>
int main()
{
    const int ROWS = 6;
    const int CHARS = 6;
    int row;
    char ch;

    for (row = 0; row < ROWS; row++)
    {
        for (ch = ('A' + row); ch < ('A' + CHARS); ch++)
            /* 字符加int貌似还是字符 */
            printf("%c", ch);
        printf("\n");
    }

    return 0;
}