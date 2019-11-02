#include <stdio.h>
#include <stdlib.h>

typedef struct Stack MinStack;
typedef MinStack *Node;
struct Stack {
    int Data;
    Node Prev;
    int isBottom;     /* if it's the bottom, Bottom == 1 */
    int isEmpty;    /* if it's an empty stack */
};
typedef Node Bottom;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    Bottom PtrS;
    PtrS = (Bottom) malloc (sizeof(MinStack));
    PtrS->isBottom = 1;     /* it is the bottom */
    PtrS->Prev = NULL;
    PtrS->isEmpty = 1;
    return PtrS;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->isEmpty) {
        obj->isEmpty = 0;
        obj->Data = x;
        return;
    }
    Node node = (Node) malloc (sizeof(MinStack));
    node->Data = x;
    node->isBottom = 0;
    node->isEmpty = 0;
    node->Prev = obj;
    obj = node;
    return;
}

void minStackPop(MinStack* obj) {
    if (obj->isBottom && obj->isEmpty) {
        printf("The stack underflow.\n");
        return;
    }
    obj = obj->Prev;
    return;
}

int minStackTop(MinStack* obj) {
    return obj->Data;
}

int minStackGetMin(MinStack* obj) {
    Node node = obj;
    int min = obj->Data;
    obj = obj->Prev;
    while (!node->isBottom) {
        if (node->Data < min) {
            min = node->Data;
        }
        node = node->Prev;
    }
    if (node->Data < min) {
        min = node->Data;
    }
    return min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/*
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
 */


/* Driver Function */

int main() {
    
}