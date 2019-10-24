# Remove the duplicated numbers from an array

## My solution 1    2019/10/24      1.5 hour

FAIL

I don't understand, why I can run the code on my own machine, but not the judge system.

```
int removeDuplicates(int* nums, int numsSize) {
    /* returnSize store the size of the array that will be returned */
    int i = 0, targetSize = 0, returnSize = numsSize;
    while (i < returnSize) {
        while (*(nums+i) == *(nums+i+1)) {
            targetSize++;
            i++;
        }
        i -= targetSize-1;
        bubble(nums, returnSize, nums+i, targetSize);   /* move <targetSize> digits to the right of the array */
        returnSize -= targetSize;
        targetSize = 0;
    }
    return returnSize;
}

void bubble(int* nums, int numsSize, int*target, int targetSize) {
    int temp, i;
    /* have to loop for nums+numsSize-target - targetSize times */
    for (i = 0; i < nums+numsSize-target - targetSize; i++) {
        temp = *(target+targetSize+i);
        *(target+targetSize+i) = *(target+i);
        *(target+i) = temp;
    }
    return;
}
```