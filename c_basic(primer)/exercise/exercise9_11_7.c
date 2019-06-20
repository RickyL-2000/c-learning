#include <stdio.h>
#include <ctype.h>
int charPosition(char ch);

int main()
{
    printf("Enter a string of characters: ");
    char ch = getchar();
    while (ch != EOF)                            //这个EOF在键盘输入的情景之中貌似怪怪的
    {
        int position = charPosition(ch);
        if (position > 0)
        {
            printf("\'%c\' is a letter and the position of it is %d.\n", 
                    ch, position);
        }
        else
        {
            printf("\'%c\' is not a letter.\n", ch);
        }
        ch = getchar();
    }
    printf("Done.");
}

int charPosition(char ch)
{
    if (isalpha(ch))
    {
        ch = toupper(ch);            //果然，这个toupper是个函数而不是method，或者说char是个mutable的类型
        int position = ch - 'A' + 1;
        return position;
    }
    else
        return -1;
}