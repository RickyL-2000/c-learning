#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *myfile3;
    if ((myfile3 = fopen("file3.txt", "w")) == NULL) {
        puts("can't open file");
        return 0;
    }
    int data[] = {1, 2, 3, 4};
    fwrite(data, sizeof(int), 4, myfile3);

    fclose(myfile3);



    if ((myfile3 = fopen("file3.txt", "w")) == NULL) {
        puts("can't open file");
        return 0;
    }

    // char str[20];
    // fgets(str, 19, myfile3);
    // fputs(str, stdout);  

    // fclose(myfile3);

    return 0;
}