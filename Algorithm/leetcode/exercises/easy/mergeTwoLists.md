# 合并两个有序链表

## my solution 1    2019/9/7    2 h (?)

**FAIL**😭

```
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ans, 
                    *pre,   // pre 是 l1 中指向 指针l1 之前的元素的指针
                    *temp;  // 用于交换
    // temp = (struct ListNode*) malloc (sizeof (struct ListNode));  // 申请内存
    ans = l1;
    pre = NULL;
    while (l1 != NULL && l2 != NULL) {   // l1 和 l2 是用来在两个链表中遍历的指针
        if (l1->val <= l2->val) {
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
```

出了很多很多问题....

最后执行出错，就是没有想到居然会有
``` [] [0] ```
这种神奇的测试样例...


## my solution 2    2019/9/7    10 min

time: 8 ms  68.45%

memory: 7.2 mb  94.23%

```
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
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
        if (l1->val <= l2->val) {        /***主要是加了这一块判断***/
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
```

(我还自己写了裁判系统嘿嘿嘿)

思路：思路明天写！