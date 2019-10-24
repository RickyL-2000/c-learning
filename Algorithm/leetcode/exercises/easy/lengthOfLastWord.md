# The length of the last word

## my solution 1    2019/10/24      30 min

time: 0 ms  100%

memory: 6.9 mb  82.66%

```
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
```