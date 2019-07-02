#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double *ptd;
    int max, number, i = 0;

    puts("What is the maximum number of type double entries?");
    if (scanf("%d", &max) != 1) {
        puts("Number not correctly entered -- bye.");
        exit(EXIT_FAILURE);  //程序中止（异常中止）
    }
    ptd = (double *) malloc(max * sizeof(double));
    if (ptd == NULL) {  //malloc()函数分配不到所需的内存，函数会返回空指针
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }
    puts("Enter the values (q to quit):");
    while (i < max && scanf("%lf", &ptd[i]) == 1) { //这个读数组的方法新奇
        ++i;
    }
    printf("Here are your %d entries:\n", number = i);  //??
    for (i = 0; i < number; i++) {
        printf("%7.2f ", ptd[i]);
        if (i % 7 == 6)
            putchar('\n');
    }
    if (i % 7 != 0)
        putchar('\n');
    puts("Done.");
    free(ptd);

    return 0;
}