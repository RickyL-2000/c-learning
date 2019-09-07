/* L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；
函数Merge要将L1和L2合并为一个非递减的整数序列。
应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。*/

// 裁判程序：
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read() {
    int size;
    ElementType num;
    scanf("%d", &size);
    PtrToNode front = NULL;
    PtrToNode rear = NULL;
    PtrToNode new = NULL;
    while(scanf("%d", &num) && size > 0) {
        if (front == NULL) {
            front = (PtrToNode) malloc(sizeof(struct Node));
            front->Data = num;
            rear = front;
        } else {   // FIXME: 应该是这里逻辑有问题！
            new = (PtrToNode) malloc(sizeof(struct Node));
            new->Data = num;
            rear->Next = new;
            rear = new;
        }
        --size;
    }
    return front;
}

void Print( List L ) {
    if (L == NULL) printf("NULL\n");
    while (L) {
        printf("%d ", L->Data);
        L = L->Next;
    }
    printf("\n");
}

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

// 我的答案：
// FIXME: 有bug
List Merge(List L1, List L2) { // List 是指向链表第一个元素的指针
    if (L1 == NULL) return L2;
    if (L2 == NULL) return L1;
    if (L1 == NULL && L2 == NULL) return NULL;
    PtrToNode front = NULL;
    front = (PtrToNode) malloc (sizeof (struct Node));
    if (L1->Data <= L2->Data) {
        front = L1;
        L1 = L1->Next;
    } else {
        front = L2;
        L2 = L2->Next;
    }
    PtrToNode rear = front;
    while (L1 && L2) {
        if (L1->Data <= L2->Data) {
            rear->Next = L1;
            rear = L1;
        } else {
            rear->Next = L2;
            rear = L2;
        }
    }
    while (L1) {
        rear->Next = L1;
    }
    while (L2) {
        rear->Next = L2;
    }
    return front;
}