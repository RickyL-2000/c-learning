# 排序算法

## 插入排序 (insertion sorting)

时间复杂度：O(n^2)

> example: insertionSorting.c

包含元素array[0..j-1]的子数组构成了当前排序好的左手中的牌，剩余的子数组array[j..n-1]对应于仍在桌子上的牌堆。事实上，元素array[0..j-1]就是原来在位置0到j-1的元素，但现在已经按序排列。我们把array[0..j-1]的这些性质形式地表示为一个**循环不变式**

插入排序的算法设计技术使用了**增量**的方法。

在插入排序的插入步骤中，需要O(n)的时间才能把选取的数据插入到合适的位置，因为经典的插入排序是遍历整个已排序的数组的。然而，可以使用二分查找(binary searching)的思想把这一时间缩短至O(ln(n))。

> example: exercise2_3_6.c

↑ 这是我自己想出来的算法。其中binarySearch函数就是用来代替原来遍历的算法的。然而，在本题中二分查找可能是找不到原值的(是插值)，这就导致边界条件可能会很复杂...或者只有我觉得很复杂...所以我又去学习了很多其他人的算法：

> example: exercise2_3_6(2).c

emmmm其实他的算法比我高明的地方就在于他在递归的最开始使用了一个检测机制，检查mid索引和right索引之间的关系。这种trick还是需要多积累!


## 归并排序 (merge sorting)

时间复杂度：$O(n\log_2{n})$

空间复杂度：O(n)

> example: mergeSorting.c

原理：
1. 分解待排序的n个元素的序列成各具n/2个元素的两个子序列
2. 使用归并排序递归地排序两个子序列，当待排序的序列长度为1时，递归“开始回升”
3. 合并两个已经排序的子序列以产生已经排序的答案

归并排序算法的关键操作是“合并”步骤中两个已经排序的序列的合并。我们通过调用一个辅助过程MERGE(A, p, q, r)来完成合并。该过程假设子数组A[left...mid]和A[mid+1...right]都已经排好序，它将合并这两个子数组形成单一的已经排好序的子数组并代替当前的子数组A[left...right]

过程MERGE需要O(n)的时间。因为当两个子数组都已经排好序，考虑扑克牌的例子，我们只需要一次从两堆牌中选取较小的那一张牌并放入新的一堆牌中用于输出，直到某一堆牌被取完。这样总的时间需要(n)

在例子mergeSorting.c中实现了上面的思想，但有一个额外的变化，以避免在每个基本步骤必须检查是否有堆为空。在每个堆的底部放置一张哨兵牌，它包含一个特殊的值，用于简化代码。这里，我们使用0x3f3f3f3f(infinity)作为哨兵值，结果每当显露一张值为infinity的牌，它不可能为较小的牌，除非两个堆都已经显露出其哨兵牌，那样算法就可以停止。

**以上思想被修改。不再使用多余的一项作为哨兵值，这样容易出错。取而代之的是从left到mid和从mid+1到right同步进行循环，这样当某一个子数组到底的时候就会停止循环。再用两个while循环检查是哪一个子数组完成了循环，再将剩余的数据填入temp，最后再把temp中的数据写入array。这样总的时间复杂度仍然是O(nln(n))。考虑到虽然这种算法需要临时申请一个数组来暂时存放排好序的数据，但是这个临时空间是可以重复利用的，因此归并排序的空间复杂度为O(n)，最多需要存放n个数据。**

归并排序算法分析：
1. 归并排序是一个稳定的排序算法，在进行子数组合并的时候，我们可以设置当元素大小相等时，先将前半部分的数据放入临时数组，这样就可以保证相等元素在排序后依然保持原来的顺序(?)。
2. 不仅递归求解的问题可以写成递推公式，递归代码的时间复杂度也可以写成递归公式。如果我们堆n个元素进行归并排序所需要的时间是T(n)，那分解成两个子数组排序的时间都是T(n/2)，而合并两个子数组的时间复杂度为O(n)。所以，归并排序的时间复杂度计算公式是：
    $$ T(1) = CT(n) = 2*T(\frac{n}{2})+n, n>1 $$
    n = 1时，只需要常量级的执行时间，所以表示为C
    $$ T(n) = 2T(\frac{n}{2})+n=2[2T(\frac{n}{4}+\frac{n}{2}]+n = 4T(\frac{n}{4})+2n \\ = 4[2T(\frac{n}{8})+\frac{n}{4}]+2n = 8T(\frac{n}{8})+3n \\...... \\ = 2^kT(\frac{n}{2^k}) + kn $$
    当$\frac{n}{2^k}=1$时，$k=\log_2{n}$，代入上式得：
    $$ T(n) = nC + n\log_2{n} $$
    所以归并排序的时间复杂度为$O(n\log_2{n})$