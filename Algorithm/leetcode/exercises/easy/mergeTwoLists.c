/* Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists. */

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode*, struct ListNode*);
struct ListNode* read();
void print(struct ListNode*);

int main() {
    struct ListNode* l1, *l2, *ans;
    /*
    l1 = read();
    l2 = read();
    */
    l1 = NULL;
    l2 = (struct ListNode*) malloc (sizeof(struct ListNode));
    l2->val = 0;
    ans = mergeTwoLists(l1, l2);
    print(ans);
    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ans, 
                    *pre,   // pre 是 l1 中指向 指针l1 之前的元素的指针
                    *temp;  // 用于交换
    // temp = (struct ListNode*) malloc (sizeof (struct ListNode));  // 申请内存
    if (l1 == NULL && l2 != NULL) {
        return l2;
    }
    ans = l1;
    pre = NULL;
    while (l1 != NULL && l2 != NULL) {   // l1 和 l2 是用来在两个链表中遍历的指针
        if (l1->val <= l2->val) {        /* 主要是加了这一块判断 */
            pre = l1;
            l1 = l1->next;
            continue;
        } else {     // 如果l1->val > l2->val，只需要把l2插入到l1和pre之间，然后把pre更新为插入之后的l2即可，再将l2往后移动一格
            if (pre == NULL) {  // 如果此时 l1 指向链表头
                ans = l2;  // 修改 answer 指针
                temp = l2->next;
                l2->next = l1;
                pre = l2;
                l2 = temp;
                continue;
            } else {
                temp = l2->next;    // ! 这里的链表插入极其容易出问题！
                pre->next = l2;
                l2->next = l1;
                l2 = temp;
                pre = pre->next;
            }
        }
    }
    // 此时 l1 应该已经空了，指针 l1 指向 NULL
    if (l2 != NULL) {   // ! 这里应该是 if !!! 不是 while !
        pre->next = l2;
    }
    return ans;
}

struct ListNode* read() {
    struct ListNode* list, *rear, *tempList;
    list = (struct ListNode*) malloc (sizeof(struct ListNode));
    int data;
    char temp;  // 用于存放空格
    scanf("%d%c", &data, &temp);
    list->val = data;    // 建立表头
    list->next = NULL;
    rear = list;
    while (temp != '\n') {   /* 这个循环，妙啊 */
        scanf("%d%c", &data, &temp);   // 刷新 temp
        tempList = (struct ListNode*) malloc (sizeof(struct ListNode));
        tempList->val = data;
        tempList->next = NULL;
        rear->next = tempList;
        rear = tempList;
    }
    return list;
}

void print(struct ListNode* list) {
    while (list != NULL) {
        printf("%d ", list->val);
        list = list->next;
    }
}