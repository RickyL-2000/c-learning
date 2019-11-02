#include <stdio.h>

int main() {
    int a[5];
    int b[10];
    int (*p5)[5];
    p5 = &a;
    p5 = &b;
    return 0;
}