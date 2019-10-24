/* Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself. */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);
void print(int* num, int numSize);

int main() {
    int digitsSize = 1;
    int returnSize;
    int digits[1] = {0};
    int *num = plusOne(digits, digitsSize, &returnSize);
    print(num, returnSize);
    return 0;
}

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

void print(int* num, int numSize) {
    int i;
    for (i = 0; i < numSize; i++) {
        printf("%d ", *(num+i));
    }
    printf("\n");
    return;
}