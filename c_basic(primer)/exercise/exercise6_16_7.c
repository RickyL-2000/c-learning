#include <stdio.h>
#include <string.h>
int main()
{
    printf("Enter a word: \n");
    char word[40];
    scanf("%s", word);
    int length;
    length = strlen(word);
    for (int i = length-1; i >= 0; i--)
        printf("%c", word[i]);
    return 0;
}