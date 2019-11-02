#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    int x = 5, y = 10;
    int velocity = 1;

    // for (x = 1; x < 10; x++) {
    while (1) {
        if (x % 10 == 0) {
            velocity *= -1;
        }
        x += velocity;
        system("cls");
        for (i = 0; i < x; i++) {
            printf("\n");
        }
        for (j = 0; j < y; j++) {
            printf(" ");
        }
        printf("0\n");
    }

    system("pause");
    return 0;
}