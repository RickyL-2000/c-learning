#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char* str = "hello";
    char* b = "hh";
    char* c = (char*) malloc (10 * sizeof(char));
    strcpy(c, b);   // only data on heap can be modified
    printf("%s", c);
    return 0;
}