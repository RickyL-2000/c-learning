#include <stdio.h>
int main()
{
    for (int row = 0; row < 6; row++)
    {
        for (char ch = 'A'+row*(row+1)/2; 
            ch <= 'A' + row*(row+1)/2+row;
            ch++ )
            printf("%c", ch);
        printf("\n");
    }
    return 0;
}