/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char *s);

int main() {
    char s[] = "Hello World!";
    int length = lengthOfLastWord(&s);
    printf("%d", length);
    return 0;
}

int lengthOfLastWord(char *s) {
    int size = 0;
    char *ptr = s;
    while (*(s + size) != '\0') {
        size++;
    }
    if (size == 0) return 0;
    ptr = s + size - 1;
    while (
        !(((*ptr >= 'a') && (*ptr <= 'z')) || ((*ptr >= 'A') && (*ptr <= 'Z'))) && (ptr > s)
        ) {
        ptr--;
    }
    int length = 0;
    while (((*ptr >= 'a') && (*ptr <= 'z')) || ((*ptr >= 'A') && (*ptr <= 'Z'))) {
        length++;
        if (ptr > s) {
            ptr--;
        } else break;
    }
    return length;
}