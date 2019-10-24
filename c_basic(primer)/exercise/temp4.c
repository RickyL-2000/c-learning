#include <stdio.h>

int main() {
    int sum_size = 3;
    char *sum = (char *) malloc (sizeof(char)*(sum_size+1));
    sum[sum_size] = '\0';
    sum[0] = '1';
    sum[1] = '2';
    sum[2] = '3';
    printf("%s", sum);
    return 0;
}
