#include <stdio.h>
#include <string.h>
int main()
{
    char first[40];
    char last[40];

    printf("What's your full name?\n");
    scanf("%s", first);
    scanf("%s", last);

    printf("\"%s %s\"\n", first, last);
    printf("\"%20s %s\"\n", first, last);
    printf("\"%s %-20s\"\n", first, last);

    int lenf = strlen(first), 
        lenl = strlen(last);
    printf("%-*s %-*s\n", 
          strlen(first), first, strlen(last), last);
    //emmmmmmm 所以这个到底怎么做？？？

    return 0;
}