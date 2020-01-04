#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * defangIPaddr(char * address);

int main() {
    char str[] = "255.100.50.0";
    char* ans = defangIPaddr(str);
    printf("%s", ans);
    return 0;
}

char * defangIPaddr(char * address){
    char* ans = (char*) malloc ((strlen(address)+6) * sizeof (char));
    //ans[13] = '\0';
    int i, j;
    for (i = 0, j = 0; i < strlen(address); i++) {
        if (address[i] != '.') {
            ans[j] = address[i];
            j++;
            continue;
        }
        ans[j] = '[';
        ans[j+1] = '.';
        ans[j+2] = ']';
        //i++;
        j += 3;
    }
    return ans;
}