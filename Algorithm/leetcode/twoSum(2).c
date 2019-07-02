//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
//尽量把时间复杂度控制在O(nln(n))

int* twoSum(int* nums, int numsSize, int target, int *returnSize)
{
    #define HASHSIZE 40960
    #define HASHEND (HASHSIZE - 1)

    int i, h, h1, found;
    int *ret = (int *)malloc(2 * sizeof(int));

    struct hashnode {
        int index;
        int num;
        struct hashnode *next;
    }
    hashnodes[HASHSIZE] = {[0 ... HASHEND] = {-1, 0, NULL}};
    struct hashnode *pnext = NULL, *pre = NULL;

    *returnSize = 0;
    for (i = 0; i < numsSize; i++) {
        h = nums[i] < 0 ? (0 - nums[i]) % HASHSIZE : nums[i] % HASHSIZE;
        h1 = target - nums[i] < 0 ? (nums[i] - target) % HASHSIZE : (target - nums[i]) % HASHSIZE;
        found = 0;
        if (hashnodes[h1].index > -1) {
            pnext = (struct hashnode *)&hashnodes[h1];
            do {
                pre = pnext;
                if (nums[i] == pnext->num) {
                    found = 1;
                    break;
                }
                pnext = pre->next;
            } 
            while (pnext != NULL);
        }
        if (found) {
            ret[0] = pre->index;
            ret[1] = i;
            *returnSize = 2;
            break;
        }
        else {
            pnext = (struct hashnode *)&hashnodes[h];
            do {
                pre = pnext;
                pnext = pre->next;
            }
            while (pnext != NULL);
            pre->next = (struct hashnode *)malloc(sizeof(struct hashnode));
            pre->next->index = i;
            pre->next->num = target - nums[i];
            pre->next->next = NULL;
        }
    }

    return ret;
}