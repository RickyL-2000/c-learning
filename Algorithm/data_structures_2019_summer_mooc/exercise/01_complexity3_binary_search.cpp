// L是用户传入的一个线性表，其中ElementType元素可以通过>、==、<进行比较，并且题目保证传入的数据是递增有序的。
// 函数BinarySearch要查找X在Data中的位置，即数组下标（注意：元素从下标1开始存储）。找到则返回下标，否则返回一个特殊的失败标记NotFound。
#include <iostream>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput() {
    size_t length;
    scanf("%d", &length);
    List L;
    L->Last = length;
    int num;
    for (size_t i = 1; i != length + 1; ++i) {
        scanf("%d", &num);
        L->Data[i] = num;
    }
    return L;
}

Position BinarySearch( List L, ElementType X) {
    Position left = 1;
    Position right = L->Last;   // ???
    Position mid = (left + right) / 2;
    while (mid < right && L->Data[mid] != X) {
        if (X < L->Data[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }
    if (L->Data[mid] != X) {
        return NotFound;
    }
    return mid;
}