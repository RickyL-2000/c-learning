# 算法思想

## 分治法

许多有用的算法在结构上是递归的，为了解决一个给定的问题，算法一次或多次递归地调用其自身以解决紧密相关的若干子问题。

分治模式在每层递归时都有三个步骤：
1. 分解原问题为若干子问题，这些子问题是原问题的规模较小的实例。
2. 解决这些子问题，递归地求解各子问题。若子问题的规模足够小，则直接求解。
3. 合并这些子问题的解成原问题的解。
   
归并排序算法完全遵循分治模式。