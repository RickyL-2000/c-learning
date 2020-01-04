#include <stdio.h>
#include <stdlib.h>

// what does fgets() return?

int main() {
    FILE *myfile2 = fopen("file2.txt", "r");
    char s[11];
    fgets(s, 11, myfile2);
    printf("the non-negative number: %d\n", fputs(s, stdout));
    puts(s);
    return 0;
}