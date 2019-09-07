#include <stdio.h>
void p(int);

void p(int num) {
    printf("%d ", num);
    return;
}
int main() {
    int i = 0;
    for (; i < 5; ++i) {
        p(i);
    }
    return 0;
}