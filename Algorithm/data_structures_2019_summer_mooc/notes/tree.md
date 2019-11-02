# 树

## 应用实例

### 二分查找

```
typedef struct LNode *List;
struct LNode {
    ElementType Element[MAXSIZE];
    int Length;
};
// 二分查找
int BinarySearch (List Tbl, ElementType K) {
    int left, right, mid, NotFound = -1;
    left = 1;
    right = Tbl->Length;
    while (left <= right) {
        mid = (left+right)/2;
        if (L < Tbl->Element[mid])      right = mid - 1;
        elseif (K > Tbl->Element[mid])  left = mid + 1;
        else                            return mid;
    }
    return NotFound;
}
```

#### 二分查找判定树
```
             -> 11
       -> 10
  
  -> 9
             -> 8
       -> 7

6 
             -> 5
       -> 4
  
  -> 3  
             -> 2
       -> 1
```
![](C:\Users\RickyLi\Documents\GitHub\c-learning\Algorithm\data_structures_2019_summer_mooc\notes\binary_search_decision_tree.PNG)


## 树的定义和术语

* 空树
* 根(Root)
* 用递归定义树
* 子树不相交
* 无环
* 结点的度(Degree)：结点的子树个数
* 树的度：树所有结点中最大的度数
* 叶节点(Leaf)：度为0的结点
* 父节点(Parent)：有子树的结点是其子树的根节点的父节点
* 子节点
* 兄弟节点(Sibling)
* 路径和路径长度。路径所包含边的个数为路径的长度
* 祖先节点(Ancestor)
* 子孙节点
* 节点的层次(Level)：规定根结点在1层
* 树的深度(Depth)：最大层次

## 树的存储

若把所有子节点都作为结构内的指针，那么会造成巨量的空间上的浪费

* 解决方法：儿子-兄弟表示法

|  Element   |             |
| :--------: | :---------: |
| FirstChild | NextSibling |

```
struct TreeNode {
    ElementType Data;
    struct TreeNode *FirstChild;
    struct TreeNode *NextSibling;
};
struct TreeNode *Tree;
```

![](C:\Users\RickyLi\Documents\GitHub\c-learning\Algorithm\data_structures_2019_summer_mooc\notes\tree&binary_tree.PNG)

所有树都可以被表示为二叉树

| Element |       |
| :-----: | :---: |
|  Left   | Right |


## 二叉树

### 二叉树的定义、性质

* 一个有穷的节点集合
* 该集合可以为空
* 由根节点和称为其左子树和右子树的两个不相交的二叉树组成

**NOTE**：二叉树的子树有左右之分

#### 特殊二叉树

* 斜二叉树：其实就是链表
* 完美二叉树(满二叉树)：全部填满
* 完全二叉树：其实就是堆


#### 重要性质

* 一个二叉树第 i 层的最大节点数为 2^(i-1)
* 深度为 k 的二叉树有最大节点总数为 2^k - 1
* 对任何非空二叉树 T，若 n_0 表示叶节点的个数，n_2 是度为 2 的非叶节点个数，那么两者满足关系 n_0 = n_2 + 1
  * 证明： n_0 + n_1 + n_2 - 1 = 0 * n_0 + 1 * n_1 + 2 * n_2  解方程

### 二叉树的操作集

* 判断是否为空
* 遍历，非常重要！！！
* 创建


## 二叉树的存储结构

### 顺序存储结构

一般适用于完全二叉树。按照从上到下、从左到右顺序存储

重要性质，对于 n 个节点的完全二叉树：
* 非根节点(i>1)的父节点的序号i/2
* 节点(i)的左孩子节点是 2i (若2i>n，则没有左孩子)，右孩子的序号是 2i+1 (若2i+1>n，则没有右孩子)

一般二叉树也可以采用这种结构，即没有节点的地方用空节点代替。所以会造成巨量的空间浪费

### 链表形式存储

```
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
```
### 二叉树的遍历 (以链式存储为例)

* 先序遍历

```
void PreOrderTraversal(BinTree BT) {
    if (BT) {
        printf("%d", BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}
```
A (B D F E) (C G H I)

* 中序遍历

```
void InOderTraversal(BinTree BT) {
    if (BT) {
        InOrderTraversal(BT->Left);
        printf("%d", BT->Data);
        InOrderTraversal(BT->Right);
    }
}
```

(D B E F) A (G H C I)

* 后序遍历

```
void PostOderTraversal(BinTree BT) {
    if (BT) {
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right);
        printf("%d", BT->Data);
    }
}
```

#### 二叉树的非递归遍历算法

**解决方法**： 使用堆栈

* 先序遍历

```
void InORderTraversal(BinTree BT) {
    BinTree T = BT;
    Stack S = CreatStack(MaxSize);
    while (T || !IsEmpty(S)) {
        while (T) {
            Push(S, T);
            printf("%5d", T->Data);
            T = T->Left;
        }
        if (!IsEmpty(S)) {
            T = Pop(S);
            T = T->Right;
        }
    }
}
```

* 中序遍历

将有左子树的元素先暂时放入栈，然后遍历其左子树，直到遍历到一个没有左子树的元素，将其printf之后遍历其右子树，如此递归

```
void InOrderTraversal(BinTree BT) {
    BinTree T = BT;
    Stack S = CreatStack(MaxSize);
    while (T || !IsEmpty(S)) {
        while(T) {  // 一直向左
            Push(S, T);
            T = T->Left;
        }
        if (!IsEmpty(S)) {
            T = Pop(S);   // 结点弹出堆栈
            printf("%5d", T->Data);   /* 先序和中序的区别就在于这printf()的位置 */
            T = T->Right;  // 转向右子树
        }
    }
}
```

* 后序遍历

```
void PostOrderTraversal(BinTree BT) {
    BinTree T = BT;
    Stack S = CreatStack(MaxSize);
    while (T || !IsEmpty(S)) {
        while (T) {
            Push(S, T);
            printf("%5d", T->Data);
            T = T->Right;
        }
        if (!IsEmpty(S)) {
            T = Pop(S);
            T = T->Left;
        }
    }
}
```

#### 层序遍历

**NOTE**：二叉树遍历的核心问题：二维结构的线性化

1. 从结点访问其左、右孩子结点
2. 访问左孩子后，右孩子怎么办？

**解决方法**：
1. 需要一个存储结构保存暂时不访问的结点
2. 存储结构：堆栈、队列
3. 用队列实现层序遍历

核心思想：遍历从根节点开始，首先将根节点入队。然后开始执行循环：结点出队、访问该节点、其左右儿子入队

```c
void LevelOrderTraversal(BinTree BT) {
    Queue Q;
    BinTree T;
    if (!BT) return;
    Q = CreatQueue(MaxSize);
    AddQ(Q, BT);
    while (!IsEmptyQ(Q)) {
        T = DeleteQ(Q);
        printf("%d\n", T->Data);
        if (T->Left)  AddQ(Q, T->Left);
        if (T->Right) AddQ(Q, T->Right);
    }
}
```

#### 二叉树遍历的应用

##### 求二叉树的高度

思想：二叉树的高度即为左右两个子树的最大高度+1

```
int PostOrderGetHight(BinTree BT) {
    int HL, HR, MaxH;
    if (BT) {
        HL = PostOrderGetHeight(BT->Left);
        HR = PostOrderGetHeight(BT->Right);
        MaxH = (HL > HR) ? HL : HR;
        return (MaxH + 1);
    }
    else return 0;  // 空树深度为0
}
```


##### 二元运算表达式树及其遍历

a + b*c + (d*e + f)*g 的二元表达式

```
                   /+
        /+                       *
    a          *             +           g
            b     c       *      f
                        d   e
```

三种不同的遍历可以得到三种不同的访问结果

**NOTE**：中缀表达式会受到运算符优先级的影响

##### 由两种遍历序列确定二叉树

**NOTE**：这两种遍历中必须要有中序遍历！

* 用先序和中序遍历序列确定一棵二叉树

1. 根据先序遍历序列第一个结点确定根节点
2. 根据根节点在中序遍历序列中分割出左右两个子序列
3. 对左子树和右子树分别递归使用相同的方法继续分解


### 二叉树的应用实例

#### 树的同构(顺序结构存储)

思路：
1. 二叉树表示
2. 建二叉树
3. 同构判别

**结构数组表示二叉树：静态列表：物理上的结构是数组，但是思想是链表的思想**

|   A   |   B   |   C   |   D   |
| :---: | :---: | :---: | :---: |
|  -1   |   2   |  -1   |  -1   |
|   1   |   3   |  -1   |  -1   |

```
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode {
    ElementType Element;
    Tree Left;         // 这里的左孩子不是指针
    Tree Right;
} T1[MaxTree], T2[MaxTree];   // 定义数组
```

程序框架搭建：
```
int main() {
    Tree R1, R2;
    ...
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if (Isomorphic(R1, R2)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
```

建二叉树：
```
Tree BuildTree(struct TreeNode T[]) {
    ...
    scanf("%d\n", &N);
    if (N) {
        for (i = 0; i < N; ++i) check[i] = 0;
        for (i = 0; i < N; ++i) {
            scanf("%c %c %c\n", &T[i].Element, &cl, &cr)'
            if (cl != '-') {
                T[i].Left = cl - '0';   // 这个方法妙啊！！！
                check[T[i].Left] = 1;   // 用这种方法找出根结点
            } else {
                T[i].Left = Null;
            }
            ... // 对 cr 的对应处理
        }
        for (i = 0; i < N; ++i) {
            if (!check[i]) break;
        }
        Root = i;
    }
    return Root;
}
```

判别二叉树同构：
```
int Isomorphic(Tree R1. Tree R2) {
    if ((R1 == Null) && (R2 == Null)) return 1;
    if (((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null))) return 0;
    if (T1[R1].Element != T2[R2].Element) return 0;   /* 根不相同 */
    if ((T1[R1].Left == Null)&&(T2[R2].Left == Null)) {  /* 如果都没有左子树的话 */
        return Isomorphic(T1[R1].Right, T2[R2].Right);
    }
    if (((T1[R1].Left != Null)&&(T2[R2].Left != Null))&&(T1[T1[R1].Left].Element == T2[T2[R2].Left].Element)) {  // 左子树同时不空且左子树的根相同
        return (Isomorphic(T1[R1].Left, T2[R2].Left) &&
                Isomorphic(T1[R1].Right, T2[R2].Right));
    } else { // 将左右子树交换
        return (Isomorphic(T1[R1].Left, T2[R2].Right) &&
                Isomorphic(T1[R1].Right, T2[R2].Left));
        }
}
```