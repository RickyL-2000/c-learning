#include <stdio.h>
int main()
{
    const int ROW = 6;
    const int CHAR = 6;
    int row;
    char ch;
    
    for (row = 0; row < ROW; row++)
    {
        for (ch = 'F'; ch >= 'F' - row; ch--)
            printf("%c", ch);
        printf("\n");
    }
    return 0;
}