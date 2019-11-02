/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>


typedef struct myStack* Stack;
struct myStack {
    int stackSize;
    int *Data;  /* 数组实现，存放栈高 */
    int *Bottem;
    int *Top;   /* 栈顶 */
};

int isEmpty(Stack stack) {
    if (stack->Top == NULL) {
        return 1;
    }
    return 0;
}

Stack initStack(int stackSize) {
    Stack stack;
    stack->stackSize = stackSize;
    stack->Data = (int*) malloc (sizeof(int)*stackSize);
    stack->Bottem = stack->Data;    /* 指向第一个元素 */
    stack->Top = NULL;
    return stack;
}

int Push(Stack stack, int x) {
    if (isEmpty(stack)) {
        *(stack->Data) = x;
        stack->Top = stack->Data;
        return 1;   /* 代表PUSH成功 */
    }
    if ((stack->Top) - (stack->Bottem) == stack->stackSize-1) {
        printf("The stack is overflowed.");
        return 0;   /* 代表PUPSH失败 */
    }
    stack->Top++;   /* 栈顶+1 */
    *(stack->Top) = x;
    return 1;
}

int Pop(Stack stack) {
    if (isEmpty(stack)) {
        printf("The stack is underflowed. ");
        return 0;
    }
    int element = *(stack->Top);    /* element是pop掉的数据 */
    stack->Top--;
    return element;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = nums1Size;
    int const resultSize = *returnSize, firstGreaterSize = nums2Size;
    int result[resultSize];
    int firstGreater[firstGreaterSize];
    Stack stack = initStack(firstGreaterSize);
    int i, j;
    for (i = nums2Size-1; i >= 0; i--) {    /* 倒着入栈 */
        while (!isEmpty(stack) && *(stack->Top) <= nums2[i]) {
            Pop(stack);
        }
        firstGreater[i] = isEmpty(stack) ? -1 : *(stack->Top);
        Push(stack, nums2[i]);
    }
    for (i = 0; i < nums1Size; i++) {
        for (j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                result[i] = firstGreater[j];
                break;
            }
        }
    }
    return result;
}

void print(int* result, int resultSize) {
    int i;
    for (i = 0; i < resultSize-1; i++) {
        printf("%d ", result[i]);
    }
}

int main() {
    int nums1[3] = {4, 1, 2};
    int nums2[4] = {1, 3, 4, 2};
    int returnSize;
    int* result = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);
    print(result, returnSize);
    return 0;
}