#include "test.h"
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    printf(" 2 + 3 = %d\n", add(2, 3));
    printf(" 2 - 3 = %d\n", sub(2, 3));
    return 1;
}