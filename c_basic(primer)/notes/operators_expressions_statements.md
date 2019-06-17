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

**NOTE**：do while适合不停地检测输入，但是貌似不适合对每一次的输入做处理

example:

    const int secret_code = 13;
    int code_entered;
    do
    {
        ...;
    }  //注意，这个复合语句(或者简单语句)是没有分号的
    while (code_entered != secret_code);


### 嵌套循环

### 循环辅助 continue 和 break






## 控制语句：分支和跳转

### if

> example: divisors.c

form:

    if (test1) 
        statement 1;
    else if (test2)
        statement 2;
    ...
    else
        statement n;

**NOTE**：else与离它最近的if匹配，除非最近的if被花括号括起来

> example: rows2.c (*)

### 多重选择 switch 和 break

format: 

    switch (expression) 

    /*计算expression中的值，使其与“标签”（即case关键字后面的字符）相匹配。若扫描过程中找到某一个标签相匹配，则执行此标签下的语句。*/

    {
        case 1: statement 1;
                break;    

            /*break是用来跳出switch语句。否则就会从匹配标签开始执行到switch末尾*/

        case 2: statement 2;
                break;
        ...
        default: statement n;

    若没有标签符合条件，就会运行default标签下的语句
    }

#### 多重标签

example:

    switch(ch)
    {
        case 'a':
        case 'A': ...;
                break;
        case 'e':
        case 'E': ...;
                break;
        default: break;
    }
以上程序中，如果ch是'a'，那么switch语句会定位到标签case 'a':的位置，但是由于该标签没有关联break语句，所以程序流会**直接执行下一条语句**。（当然，在本程序中，如果在一开始就加入toupper(ch)就不用这么麻烦了）

**NOTE**：如果是根据浮点类型的变量或者表达式类选择，就无法使用switch，尤其是如果根据变量在某范围内决定程序流的去向，使用switch就会很麻烦。这种情况用if就很方便


## goto 语句

format:

    goto part2;

    part2: printf("Refined analysis:\n");

**NOTE**： 避免使用goto。过度地使用goto语句，会让程序错综复杂





## 基本运算符

example: wordcnt.c

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
|      &&      |           and            |
|     ｜｜     |            or            |
|      !       |           not            |
|      ?       |   contidtion operator    |





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
9. 条件运算符"?"，是表达if else语句的一种便捷方式。example:

        x = (y < 0) ? -y : y;
        max = (a > b) ? a : b;
    第一个语句的意思是如果y小于0，那么x = -y；否则x = y。实际上就是求绝对值。这个语句用if else可以这样:

        if (y<0)
            x = -y;
        else
            x = y;
    条件表达式的通用形式如下:

        test ? expression1 : expression2;
        //这个expression也可以被看成一个函数，其“返回值”可以被用在比如printf()函数中，其第二个和第三个运算对象可以是字符串。
    > example: paint.c 


### 副作用和序列点 (???)

## 