# Plus one for a number

## My Solution 1    19/10/24    30 min

time: 8 ms  29.11%

memory: 7.1 mb  5.51%

```
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i, carry;
    for (i = digitsSize - 1; i >= 0; i--) {
        *(digits+i) += 1;
        carry = 0;
        if (*(digits+i) == 10) {
            *(digits+i) = 0;
            carry = 1;
        } else {
            break;
        }
    }
    if (carry == 1) {
        *returnSize = digitsSize + 1;
        int *num = (int*) malloc(sizeof(int) * (digitsSize+1));
        num[0] = 1;
        for (i = 0; i < digitsSize; i++) {
            num[i+1] = *(digits+i);
        }
        return num;
    } else {
        *returnSize = digitsSize;
        return digits;
    }
}
```