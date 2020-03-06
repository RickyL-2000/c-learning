#include <stdio.h>

int main() {
    char *ch = "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ";
    int i, sum = 0;
    for (i = 0; ch[i] != '\0'; i++) {
        if (ch[i] == '0') {
            sum++;
        }
    }
    printf("%d", sum);
    return 0;
    
}