#include <stdio.h>
int main(void)
//为什么用%zd就是不行？？？但是用%d就是可以？？？好生奇怪:(
{
    printf("Type int has a size of %d bytes. \n", sizeof(int));
    printf("Type char has a size of %d bytes. \n", sizeof(char));
    printf("Type long has a size of %d bytes. \n", sizeof(long));
    printf("Type long long has a size of %d bytes. \n", sizeof(long long));
    printf("Type double has a size of %d bytes. \n", sizeof(double));
    printf("Type long double has a size of %d bytes. \n", sizeof(long double));

    return 0;
}