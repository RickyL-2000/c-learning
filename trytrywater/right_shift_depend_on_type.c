#include <stdio.h>

void print_binary(int n) //将整型数值n二进制输出。
{ 
    if(n == 0) return;
    print_binary(n>>1); 
    printf("%d",n&0x1); 
}

int main() {
    int a = 10;
    unsigned int b = 10;
    // print_binary(a);
    // printf("\n");
    // print_binary(b);
    a = a >> 1;
    b = b >> 1;
    print_binary(a);
    printf("\n");
    print_binary(b);
    printf("\n");
    
    unsigned int c = 0xFFFFFF00;
    printf("%d", c);

    return 0;
}