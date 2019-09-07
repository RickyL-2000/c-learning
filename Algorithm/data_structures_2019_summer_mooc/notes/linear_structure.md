# 线性结构

以下用 C 语言实现 (其实要用C++实现也非常简单，只要把内存管理部分和结构体语法部分稍作改动即可)

## 线性表及其实现

### example: 存储一元多项式

* 方法1：顺序表直接存储
* 方法2：顺序存储**结构**表示非零项
  esample:

        struct Polynomial {
            int coef;
            int expon;
        }

* 方法3：链表结构存储非零项
  链表中每个节点存储多项式中的一个非零项，包括系数和指数两个数据域以及一个指针域： (coef)(expon)(link)
  example:

        typedef struct PolyNode *Polynomial; /* Polynomial 是一个指针类型，指向 struct PolyNode (及链表结点) */
        struct PolyNode {
            int coef;
            int expon;
            Polynomial link;
        }


### 线性表的顺序存储实现

利用数组的连续存储空间顺序存放线性表的各元素

    typedef struct LNode *List;     /* 创建一个指向 LNode 的指针*类型*List */
    struct LNode {
        ElementType Data[MAXISIZE];
        int Last;  /* 最后一个元素的位置 */
    };
    struct LNode L;
    List PtrL;     /* 创建一个指向 LNode 的指针，同时并没有创建 LNode 类的数据来被它所指 */
    /* 访问下标为 i 的元素：L.Data[i] 或 PtrL -> Data[i] */
    /* 线性表的长度：L.Last+1 或者PtrL->Last+1 */

#### 主要操作的实现

1. 初始化(建立空的顺序表)
   
        List MakeEmpty () {
            List PtrL;
            PtrL = (List) malloc (sizeof(struct LNode));  /* 先去申请这样一个结构 */
            PtrL->Last = -1;  /* 代表最后一个元素，因为表里没用元素 */
            return PtrL;
        }

2. 查找

        int Find(ElementType X, List PtrL) {
            int i = 0;
            while (i <= PtrL->Last && PtrL->Data[i] != X) {
                i++;
            }
            if (i > PtrL->Last)  return -1;
            else  return i;
        }

3. 插入 (第i(1<=i<=n+1)个位置上插入一个值为X的新元素)

        void Insert(ElementType X, int i, List PtrL) {
            int j;
            if (PtrL->Last == MAXSIZE-1) {
                printf("It's full");
                return;
            }
            if (i < 1 || i > PtrL->Last+2) {   /* 检查插入位置的合法性 */
                printf("The place is not valid");
                return;
            }
            for (j = PtrL->Last; j >= i-1; j--) {
                PtrL->Data[j+1] = PtrL->Data[j];
            }
            PtrL->Data[i-1] = X;
            PtrL->Last++;
            return;
        }

4. 删除(同上)


### 线性表的链式存储实现

    typedef struct LNode *List;
    struct LNode {
        ElementType Data;
        List Next;
    };
    struct Lnode L;
    List PtrL;

#### 主要操作的实现

1. 求表长

        int Length(List PtrL) {
            List p = PtrL;
            int j = 0;
            while (p) {
                p = p->Next;
                j++;          // 当前 p 指向第 j 个结点 */
            }
            return j;
        }

2. 查找

        List FindKth(int K, List PtrL) {
            List p = PtrL;   /* 表头 */
            int i = 1;
            while (p != NULL && i < K) {
                p = p->Next;
                i++;
            }
            if (i == K) return p;
            else return NULL;
        }

3. 插入 (第i-1(1<=i<=n+1)个位置上插入一个值为X的新元素)

        List Insert(ElementType X, int i, List PtrL) {
            List p, s;
            if (i == 1) {
                s = (List)malloc(sizeof(struct LNode));
                s->Data = X;
                s->Next = PtrL;
                return s;
            }
            p = FindKth(i-1, PtrL);
            if (p == NULL) {
                printf("wrong args.");
                return NULL;
            } else {
                s = (List)malloc(sizeof(struct LNode));  /* 申请、填装结点*/
                s->Data = X;
                s->Next = p->Next;
                p->Next = s;
                return PtrL;
            }
        }

## 广义表

example: 二元多项式的表示

    看成关于 x 的一元多项式，其中有 y 的系数又可以看成关于 x 的一元多项式。所以，上述二元多项式可以用“复杂”链表表示

上述这种复杂链表就是广义表

    typedef struct GNode *GList;
    struct GNode {
        int Tag;     /* 标志域：0表示结点是单元素，1表示结点是广义表 */
        union {      /* 子表指针域 Sublist 与单元素数据域 Data 复用，即共用存储空间 */
            ElementType Data;
            GList SubList;
        } URegion;
        GList Next;   /* 指向后继点
    };


## 多重链表

链表中的结点可能同时隶属于多个链

* 多重链表中结点的指针域会有多个，如前面例子包含了 Next 和 SubList 两个指针域
* 但包含两个指针域的链表不一定是多重链表，比如双向链表就不是多重链表

**NOTE**: 多重链表有广泛的用途：基本上树、图这样相对复杂的数据结构都可以采用多重链表方式实现存储


### example: 矩阵的存储

矩阵可以用二维数组表示，但是有两个缺陷：
1. 对数组的大小需要事先确定
2. 对于“稀疏矩阵”，将造成大量的存储空间浪费

解决方法：**十字链表**
1. 只存储矩阵非0元素项：结点的**数据域**：
   行坐标 Row、列坐标 Col、数值 Value
2. 每个结点通过两个**指针域**，把同行、同列串起来
   1. 行指针(向右指针) Right
   2. 列指针(下指针) Down

![多重链表](C:\Users\RickyLi\Documents\GitHub\cpp-learning\Algorithm\basic_algorithms\data_structures_2019_summer_mooc\notes\multiple_list.png)

此多重链表存在三种结点：
1. Term 结点，代表稀疏矩阵中非零的项。其由一个头节点构成一个行环向和一个列环向
2. Head 结点，既作为行链表的头节点，也作为列链表的头节点。所以第i行的头节点和第i列的头节点实际上是同一个头节点
3. 入口结点：结构和 Term 结点一样，但是是整个多重链表的入口。其中“行坐标”位置存储行数，“列坐标”位置存储列数，“数值”位置存储非零数据的个数。它的指针域指向所有行和列的头节点

结构：
用一个标识域 Tag 来区分头结点和非0元素结点：头节点的标识值为"Head"，矩阵非0元素结点的标识值为"Term"
1. 结点的总体结构：

    |       |   Tag   |       |
    | :---: | :-----: | :---: |
    | Down  | URegion | Right |

2. 矩阵非0元素结点
   
    |       |    Term     |       |
    | :---: | :---------: | :---: |
    |       | Row  \  Col |       |
    | Down  |    Value    | Right |

3. 头节点

    |       | Head  |       |
    | :---: | :---: | :---: |
    | Down  | Next  | Right |


## 堆栈

具有一定操作约束的线性表



### example: 表达式求值

运算符优先级

后缀表达式：运算符将操作运算符前最近的两个数据

前缀表达式：运算符将操作运算符后最近的两个数据

## 队列

* 插入和删除操作

### 队列的存储方式

#### 顺序存储实现

```
#define MaxSize
struct QNode {
    ElementType Data[ MaxSize ];
    int rear;   // 队尾
    int front;  // 队头   (front, rear]
};
typedef struct QNode *Queue;
// rear 指向实际最后一位数据，front指向实际第一位数据前一位的位置
```

以数组形式存储的队列，移动的是 rear 和 front 这两个“指针”。当rear移动到数组的最后一位时，尽管数组前面可能还有空位，但是此时新的数据就加不进去了。

* 解决方法：循环队列

即将后加入的数据加入到数组的最前面，循环进行

但是又出现一个问题，当 rear == front 的时候，既有可能是空的，也可能是满的

* 解决方法：
1. 使用额外标记：Size 或者 tag 域
2. 仅使用n-1个数组空间

采取第二种方法：
```
// 入队
void AddQ( Queue PtrQ, ElementType item) {
    if ((PtrQ->rear+1) % MaxSize == PtrQ->front) {
        printf("The queue is full");
        return;
    }
    PtrQ->rear = (PtrQ->rear+1)%MaxSize;
    PtrQ->Data[PtrQ->rear] = item;
}
```
```
// 出队
ElementType DeleteQ(Queue PtrQ) {
    if (PtrQ->front == PtrQ->rear) {
        printf("The queue is empty");
        return ERROR;
    } else {
        PtrQ->front = (PtrQ->front+1) % MaxSize;
        return PtrQ->Data[PtrQ->front];    /* 因为队首是front+1，所以此时返回的front就是刚被“删除”的队首 */
    }
}
```

#### 队列的链式存储实现

队列的链式存储结构也可以用一个**单链表**来实现

**NOTE**：front 必须作为链表的头，rear尾。因为如果 front 是链表的尾，删除 front 的操作无法使 front 移动到该结点前一个结点

```
struct Node{
    ElementType Data;
    struct Node *Next;
};
struct QNode {
    struct Node *rear;   // 指向队尾结点
    struct Node *front;  // 指向队头结点
};
typedef struct QNode *Queue;
Queue PtrQ;
```

出队操作
```
ElementType DeleteQ (Queue PtrQ) {
    struct Node *FrontCell;
    ElementType FrontElem;

    if (PtrQ->front == NULL) {
        printf("The queue is empty");
        return ERROR;
    }
    FrontCell = PtrQ->front;
    if (PtrQ->front == PtrQ->rear)       // 若队列只有一个元素
        PtrQ->front = PtrQ->rear = NULL; // 删除后队列设置为空
    else
        PtrQ->front = PtrQ->front->Next; // 删除第一个元素
    FrontElem = FrontCell->Data;
    free(FrontCell);   // 释放被删除结点空间
    return FrontElem;
}
```


## 应用：多项式加法运算

* 多项式实现

```
struct PolyNode {
    int coef;
    int expon;
    struct PolyNode *link;   // 指向下一个结点的指针
}；
typedef struct PolyNode *Polynomial;
Polynomial P1, P2;
```

* 多项式加法运算

