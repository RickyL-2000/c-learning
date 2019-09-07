/* 设计函数分别求两个一元多项式的乘积与和。*/
/* 输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数     // 先给出个数!!!!!!审题不清！！！！！
（绝对值均为不超过1000的整数）。数字间以空格分隔。*/
/* 输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。
数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。*/

// FIXME: 貌似有很严重的 bug

#include <stdio.h>

// 多项式实现
struct PolyNode {
    int coef;
    int expon;
    struct PolyNode *link;
};
typedef struct PolyNode* Polynomial;
Polynomial P1, P2;

// 函数声明
void Attach(int, int, Polynomial*);
Polynomial PolyAdd (Polynomial, Polynomial);
int Compare(int, int);
Polynomial PolyMultiply(Polynomial, Polynomial);
Polynomial read();
void print(Polynomial); //此函数不包含回车

// 主函数
int main() {
    Polynomial P1, P2, Sum, Prod;
    P1 = read();
    P2 = read();
    Sum = PolyAdd(P1, P2);
    Prod = PolyMultiply(P1, P2);
    print(Prod);
    printf("\n");
    print(Sum);
    return 0;
}

// 入队操作
void Attach(int c, int e, Polynomial *pRear) {
    Polynomial P;
    P = (Polynomial) malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;
}

// 多项式相加
Polynomial PolyAdd (Polynomial P1, Polynomial P2) {
    Polynomial front, rear, temp;
    int sum;
    rear = (Polynomial) malloc (sizeof (struct PolyNode));
    front = rear;
    while (P1 && P2) {
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
    for (; P1; P1 = P1->link) Attach(P1->coef, P1->expon, &rear);
    for (; P2; P2 = P2->link) Attach(P2->coef, P2->expon, &rear);
    rear->link = NULL;
    temp = front;
    front = front->link;
    free(temp);
    return front;
}

// 比较大小
int Compare(int e1, int e2) {
    if (e1 > e2) return 1;
    if (e1 < e2) return -1;
    return 0;
}

// 多项式相乘
Polynomial PolyMultiply(Polynomial P1, Polynomial P2) {
    if (! (P1 && P2)) return NULL;  // 如果有一个为0
    Polynomial P, rear, temp, t_rear, p_P2;
    int sum;
    rear = (Polynomial) malloc (sizeof (struct PolyNode));
    P = rear;    
    for (; P1; P1 = P1->link) {
        // 复制 P2 到 temp
        p_P2 = P2;     // 代替 P2 在队列P2中游走的指针，这样P2就可以保持不变，成为表头
        temp = (Polynomial) malloc (sizeof (struct PolyNode));
        temp->coef = p_P2->coef * P1->coef;
        temp->expon = p_P2->expon * P1->expon;
        temp->link = NULL;
        t_rear = temp;
        p_P2 = p_P2->link;  // 以上是为了初始化temp中的第一个元素
        for (; p_P2; p_P2 = p_P2->link) {
            Attach(p_P2->coef * P1->coef, p_P2->expon * P1->expon, &t_rear);
        }
        P = PolyAdd(P, temp);
        free(temp);
    }
    return P;
}

// 读入多项式
Polynomial read() {
    int size, coef, expon;
    // 是否为0
    scanf("%d ", &size);
    if (size == 0) return NULL;
    //建立链表
    Polynomial P = NULL, rear = NULL, new = NULL;
    while (size) {
        scanf("%d ", &coef);
        scanf("%d ", &expon);
        if (P == NULL) {
            P = (Polynomial) malloc (sizeof (struct PolyNode));
            P->coef = coef;
            P->expon = expon;
            P->link = NULL;
            rear = P;
        }
        new = (Polynomial) malloc (sizeof (struct PolyNode));
        new->coef = coef;
        new->expon = expon;
        new->link = NULL;
        rear->link = new;
        rear = new;
        --size;
    }
    return P;
}

// 输出多项式
void print(Polynomial P) { //此函数不包含回车
    if (P == NULL) {
        printf("0 0");
        return;
    }
    for (; P; P = P->link) {
        printf("%d %d", P->coef, P->expon);
        if (P->link) printf(" ");
    }
}