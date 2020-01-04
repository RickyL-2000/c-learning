/* Use getchar/putchar as Shortcuts with stdin/stdout */

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *myfile = fopen("file1.txt", "r");
    FILE *myfile2 = fopen("file2.txt", "w");
    int i;
    int a[9];
    int b[9];
    for (i = 0; i < 9; i++) {
        a[i] = fgetc(myfile);
        b[i] = getc(myfile);
    }

    for (i = 0; i < 9; i++) {
        putc(a[i], myfile2);   
    }

    // printf("\n");

    // for (i = 0; i < 9; i++) {
    //     printf("%d ", b[i]);
    // }

    fclose(myfile);
    fclose(myfile2);

    return 0;
}