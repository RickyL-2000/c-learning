/* Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
For the purpose of this problem, we will return 0 when needle is an empty string.  */

#include <stdio.h>
#include <string.h>

int strStr(char * haystack, char * needle);

int main() {
    char *haystack = "mississippi";
    char *needle = "issip";
    int index = strStr(haystack, needle);
    printf("%d", index);
    return 0;
}

int strStr(char * haystack, char * needle) {
    int needleSize = strlen(needle);
    if (needleSize == 0) return 0;
    int haystackSize = strlen(haystack);
    if (needleSize > haystackSize) return -1;
    int index = -1;
    int i, j = 0;
    for (i = 0; i < haystackSize; i++) {
        if (haystack[i] == needle[j] && j < needleSize) {
            j++;
            continue;
        } else if (haystack[i] != needle[j]) {
            if (j > 0) {
                i -= j;
                j = 0;
            }
        } else if ()
        /* 上次写到这里 */
        /* 上面的代码是对下面代码的重构 */


        while (haystack[i] == needle[j] && j < needleSize && i < haystackSize) {
            i++;
            j++;
        }
        if (j == needleSize) {
            index = i - needleSize;
            break;      /* now the return val should be i - needleSize + 1 */
        } else if (j > 0) {
            i -= j;
        }
    }
    return index;
}