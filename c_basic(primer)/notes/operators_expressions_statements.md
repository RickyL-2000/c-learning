# 运算符、表达式和语句

## 循环

### while

while循环是**入口条件循环**，也是不确定循环

> example: summing.c 整数求和

**NOTE**:只有在对测试条件求值时，才决定是终止还是继续循环 (???)

### for

for循环是计数循环(知道要循环多少次)，也是入口条件循环

example:

    const int NUMBER = 22;
    int count;
    for (count = 1; count <= NUMBER; count++)
        ...
在这个例子里，count = 1先带入循环体计算，最后再+1带回测试条件检验是否进入下一个循环。**而不是检验完了以后就+1带入本次循环！！！**

for后面跟的三个表达式，分别用两个分号隔开:
1. 初始化
2. 测试条件
3. 执行更新

**NOTE**：for循环可以使用得非常灵活！

example 1:

    int num = 0;
    for (printf("Keep entering numbers!\n"); num != 6;)
        scanf("%d", &num);
    //第一个表达式不一定是给变量赋初值，也可以使用printf()。但是，在执行循环的其他变量之前，只对第一个表达式求值一次或执行一次。

example 2:

    int ounces, cost;
    for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost += NEXT_OZ)
        ...
    //在for的表达式中运用逗号运算符，这样可以使多个变量进行迭代

example 3:

    for ( ; test ; ) //这条语句省略了第一个和第三个表达式，和while效果相同

### do while

do while是出口条件循环，即在循环的每次迭代之后检查测试条件，这保证了至少执行循环体中的内容一次。

example:

    const int secret_code = 13;
    int code_entered;
    do
    {
        ...;
    }  //注意，这个复合语句(或者简单语句)是没有分号的
    while (code_entered != secret_code);


### 嵌套循环

> example: rows2.c (*)

## 基本运算符

|   operator   |         meaning          |
| :----------: | :----------------------: |
|      =       |        assignment        |
| (+,-,*,/,%)= |        assignment        |
|      +       |           plus           |
|      -       |       subtraction        |
|      *       |         mutiply          |
|      /       |         divider          |
|    sizeof    |       size of var        |
|      %       |          module          |
|      ++      |  increase(before/after)  |
|      --      |  decrease(before/after)  |
|      <       |       smaller than       |
|      <=      | smaller than or equal to |
|      ==      |         equal to         |
|      >=      | larger than or equal to  |
|      >       |       larger than        |
|      !=      |       not equal to       |

**NOTE**：
1. 整数除法结果的小数部分会被丢弃，这一过程被称为截断(truncation)
2. C有一个**typedef机制**：
   
   example:

        typedef double real;
    这样，real就是double的一个别名

3. 递增运算符和递减运算符都有两种方式，*前缀*模式和*后缀*模式。两种模式的区别在于递增行为发生的时间不同。
    example 1:

        q = 2*++a; //首先，a递增1；然后，2乘以a，并将结果赋给q
        q = 2*a++; //首先，2乘以a，并将结果赋给q；然后，a递增1
    example 2:

        shoe = 2.0;
        while (++shoe < 18.5) 
            /*
            如果使用shoe++而不是++shoe，shoe就会被增加到19，
            因为shoe会在与18.5比较之后才递增，而不是先递增再比较
            */
        {
            ...;
        }
    
    example 3: pound.c

4. 不要一次用太多递增运算符，会糊涂。尤其是在printf()函数中。C语言中，编译器可以自行选择先对函数中的哪个参数求值，这样做提高了编译器的效率，但是如果在函数的参数中使用了递增运算符，有可能会出问题。**即运算优先级的问题**
5. 不能用关系运算符比较字符串
6. 比较浮点数时，尽量只使用<和>，因为浮点数的舍入误差会导致在逻辑上应该相等的两数却不相等
7. 一般而言，所有的非零值都视为真，只有0被视为假
8. <<=，>>=的优先级比==, !=高


### 副作用和序列点 (???)

## 