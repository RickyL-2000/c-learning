# 搜索插入位置

## my solution 1    2019/9/8

**FAIL**

思路：二分查找！

```
int searchInsert(int* nums, int numsSize, int target){
    size_t left = 0, 
           right = numsSize-1,
           mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (target < nums[mid]) {
            right = mid - 1;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else if (target == nums[mid]) {
            break;
        }
    }
    return left;
}
```

总是因为奇奇怪怪的测试样例而解答错误......

不过，断点调试和单步跳过有点好用啊！

## mysolution 2    2019/9/8    30 min

time: 4 ms     99.73%

memory: 7.3 mb    69.42%

```
int searchInsert(int* nums, int numsSize, int target){
    size_t left = 0, 
           right = numsSize-1,
           mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (target < nums[mid]) {
            if (mid == 0) break;
            right = mid - 1;
        } else if (target > nums[mid]) {
            if (mid == numsSize-1) {left = numsSize; break;}
            left = mid + 1;
        } else if (target == nums[mid]) {
            break;
        }
    }
    /*********这一段只是为了应付测试样例，怎么看都觉得丑*********/
    if (target == nums[mid]) return mid;
    if (target != nums[mid]) return left;
    return mid;
}
```