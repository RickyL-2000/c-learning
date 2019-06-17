//读取输入，读到#字符停止，然后报告读取的空格数、换行符数和所有其他字符的数量
#include <stdio.h>
int main()
{
    printf("Enter anything you want, ending with #: \n");
    char ch = getchar();
    unsigned int blanks=0, lines=0, chars=0;
    while (ch != '#')
    {
        if (ch == ' ')
            ++blanks;
        else if (ch == '\n')
            ++lines;
        else
            ++chars;
        ch = getchar();
    }
    printf("There are %u %s, %u %s and %u %s.",
        blanks, (blanks == 1 || blanks == 0) ? "blank" : "blanks",
        lines, (lines == 1 || lines == 0) ? "line break" : "line breaks",
        chars, (chars == 1 || chars == 0) ? "other char" : "other chars");
    
    return 0;
}