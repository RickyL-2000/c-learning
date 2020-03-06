#include <stdio.h>

int main() {
    char nums[2][10];
    int i, j;
    char num, space;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 10; j++) {
            num = fgetc(stdin);
            if (num == EOF) {
                break;
            }
            nums[i][j] = num;
            space = fgetc(stdin);
            if (space == EOF) {
                break;
            }
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c ", nums[i][j]);
        }
    }
    return 0;
}

