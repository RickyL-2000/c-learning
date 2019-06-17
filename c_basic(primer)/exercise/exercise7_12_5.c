//用switch编写程序，读取输入，读到#时停止。用感叹号替换句号，用两个感叹号替换原来的感叹号，最后报告进行了多少次替换
#include <stdio.h>
int main()
{
    printf("Enter a sentence and end it with #: \n");
    unsigned int n = 0;
    char ch;
    ch = getchar();
    while (ch != '#')
    {
        switch (ch)
        {
            case '.': printf("!");
                    ++n;
                    break;
            case '!': printf("!!");
                    ++n;
                    break;
            default: printf("%c",ch);
        }
        ch = getchar();
    }
    printf("\n");
    switch (n)
    {
        case 0: printf("No substitutions have been done.");
                break;
        case 1: printf("Only one substitution has been done.");
                break;
        default: printf("%u substitutions have been done.", n);
    }
    return 0; 
}