#include <stdio.h>


int print_reverse(char * ch) {
    int sum;
    if (*ch == '\0') return 0;
    sum = print_reverse(ch+1);
    printf("%c", *ch);
    return sum+1;
}


int main() {
    char s[] = "Hello World!";
    int sum = print_reverse(s);
    printf("\n%d", sum);
    return 0;
}
