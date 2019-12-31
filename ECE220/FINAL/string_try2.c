#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char word[10] = "hello";
    word[0] = 'E';
    printf("%s", word);
    return 0;
}