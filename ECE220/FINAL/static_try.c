#include <stdio.h>


void emmm();

void emmm() {
    static int a = 0;
    {
        a = a+1;
        for (; a < 10; a++) {
            a += 2;
        }
    }
    printf("%d", a);
}

int main() {
    emmm();
    return 0;
}