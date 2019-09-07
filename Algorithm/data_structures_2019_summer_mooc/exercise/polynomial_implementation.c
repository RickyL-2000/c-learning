#include <stdio.h>

// 多项式实现
struct PolyNode {
    int coef;
    int expon;
    struct PolyNode *link;   // 指向下一个结点的指针
};
typedef struct PolyNode *Polynomial;
Polynomial P1, P2;

// 入队操作
void Attach(int c, int e, Polynomial *pRear) {  // pRear是指针rear的指针，这么做的原因是函数参数的传递
    Polynomial P;  // 创建一个新结点
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;  // 对新节点赋值
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;   // 将新结点连入链表
    *pRear = P;   // 修改pRear值至当前的最后一个结点
}

// 多项式相加
Polynomial PolyAdd (Polynomial P1, Polynomial P2) {
    Polynomial front, rear, temp;
    int sum;
    rear = (Polynomial) malloc (sizeof (struct PolyNode));
    front = rear;
    while (P1 && P2) { // 当两个多项式都有非零项待处理时
        switch (Compare(P1->expon, P2->expon)) {
            case 1:
                Attach(P1->coef, P1->expon, &rear);
                P1 = P1->link;
                break;
            case -1:
                Attach(P2->coef, P2->expon, &rear);
                P2 = P2->link;
                break;
            case 0:
                sum = P1->coef + P2->coef;
                if ( sum ) Attach(sum, P1->expon, &rear); // 舍弃零系数项
                P1 = P1->link;
                P2 = P2->link;
                break;
        }
    }
    // 将两个多项式的剩余的项全数加到链表的最后：
    for (; P1; P1 = P1->link) Attach(P1->coef, P1->expon, &rear);
    for (; P2; P2 = P2->link) Attach(P2->coef, P2->expon, &rear);
    rear->link = NULL;
    temp = front;
    front = front->link;
    free(temp);
    return front;
}


// 多项式相乘