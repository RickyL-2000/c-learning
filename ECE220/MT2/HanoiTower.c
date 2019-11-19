#include <stdio.h>

void HanoiTower(int N, char A, char B, char C) {
    static int step = 0;
    if (N == 1) {
        step++;
        printf("step %d: move disk %d from %c to %c\n", step, N, A, C);
        return;
    }
    HanoiTower(N-1, A, C, B);   //*from A to B, FIXME: ???*//
    step++;
    printf("step %d: move disk %d from %c to %c\n", step, N, A, C);
    HanoiTower(N-1, B, A, C);
    return;
}

int main() {
    char A = 'A', B = 'B', C = 'C';
    HanoiTower(3, A, B, C);
    return 0;
}