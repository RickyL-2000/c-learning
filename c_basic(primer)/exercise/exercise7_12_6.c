//读取输入，读到#停止，报告ei出现的次数
#include <stdio.h>
int main()
{
    char ch1, ch2; //分别表示当下的字符和前一次的字符
    int n = 0;
    printf("Enter some sentences and end them with #: \n");
    ch1 = getchar();
    if (ch1 == '#')
        printf("OK...Done!");
    else if (ch1 != '#' && scanf("%c", &ch2) == 1)
    {
        while (ch2 != '#')
        {
            if (ch2 != 'i')
            {
                ch1 = ch2;
                ch2 = getchar(); //这两句话应该没问题...??? （de完bug的我回来了...这句话确实没问题...）
                printf("ch2 != i and then ch1 = %c, ch2 = %c\n", ch1, ch2); //用于debug
            }
            else if (ch2 == 'i')
            {
                if (ch1 != 'e')
                {
                    ch1 = ch2;
                    ch2 = getchar();
                    printf("ch1 != e and then ch1 = %c, ch2 = %c\n", ch1, ch2); //用于debug
                }
                else
                {
                    n += 1;
                    ch1 = ch2;
                    ch2 = getchar();
                    printf("ch1 == e and ch2 == i\n"); //用于debug
                }
            }
        }
        switch (n)
        {
            case 0: printf("There is no \'ei\'.");
                    break;
            case 1: printf("There is only one \'ei\'.");
                    break;
            default: printf("There are %u \'ei\'s.",n); //wdnmd!!!de了我半天的bug原来时因为这里忘记写'n'了！！！！！
        }
    }

    return 0;
}