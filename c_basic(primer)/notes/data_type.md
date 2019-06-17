# 基本数据类型

|    type     |      name      |       space       |
| :---------: | :------------: | :---------------: |
|    bool     |      布尔      |        无         |
|    char     |      字符      |      8位bit       |
|   wchar_t   |     宽字符     |       16位        |
|  charl16_t  |  Unicode 字符  |       16位        |
|  charl32_t  |  Unicode 字符  |       32位        |
|    short    |     短整型     |       16位        |
|     int     |      整型      |      16/32位      |
|    long     |     长整型     |       32位        |
|  long long  |     长整型     |       64位        |
|  unsigned   |   无符号整数   |         ?         |
|    float    |  单精度浮点数  | 6位有效数字 32位  |
|   double    |  双精度浮点数  | 13位有效数字 64位 |
| long double | 扩展精度浮点数 | 至少13位有效数字  |


**NOTE**
1. 对于float类型，正号可以省略，可以没有小数点（如2E5）或指数部分（如19.28），但是不能同时省略两者。可以省略小数部分（如3.E16）或整数部分（如.45E-1）。但是不能同时省略两者。不能在有效数字和"E"之间加空格。
2. 在浮点数后面加上f或者F可以覆盖默认设置，编译器会将浮点型常量看作float类型，如2.3f和9.11E9F。使用l或者L后缀使数字成为long double类型，而且建议使用L后缀，因为l后缀容易与数字1混淆。没有后缀的浮点型常量是double类型。
3. C99标准新加：用十六进制表示浮点型常量(???)
4. 将一个char和int相加并赋给一个char类型，得到的是这个char的ASCII码加上int后的ASCII码所对应的字符。若赋给一个int类型，则是得到相加之后的ASCII码
5. 字符串如何相加????

## 格式化字符(printf和scanf)

|         type          | Form  |
| :-------------------: | :---: |
|        int(10)        |  %d   |
|        int(10)        |  %i   |
|       long(10)        |  %ld  |
|        long(8)        |  %lo  |
|       long(16)        |  %lx  |
|     long long(10)     | %lld  |
|       short(10)       |  %hd  |
|       short(8)        |  %ho  |
|       short(16)       |  %hx  |
|   unsigned int(10)    |  %u   |
|    unsigned int(8)    |  %o   |
|     unsigned long     |  %lu  |
|    unsigned short     |  %hu  |
|         char          |  %c   |
|   float/double(10)    |  %f   |
| float/double(sci(10)) | %e/%E |
|       %f or %e        |  %g   |
|       %f or %E        |  %G   |
|    long double(10)    |  %Lf  |
| long double(sci(10))  |  %Le  |
|      _Bool (C99)      |   ?   |
|      char string      |  %s   |
|        pointer        |  %p   |
|           %           |  %%   |


1. d后缀：表示十进制整数
2. x后缀：表示十六进制整数
3. o后缀：表示八进制整数
4. u后缀：表示unsigned
5. l前缀：表示long
6. ll前缀：表示long long
7. h前缀：表示short
8. 如果用%d格式输出char，则输出ASCII码
9. 对于float一类的带"e"的科学记数法的十六进制格式，只需要把e和E分别用a和A代替即可
10. 字符串被储存在char类型的数组中。数组末尾有一个字符\0，代表空字符(null character)。C语言用它来标记字符串的结束。*这意味着数组的容量必须至少比待存储字符串中的字符数多1*
    example: 

        char name[40];
11. 用""括起来的是字符串数组，而用''括起来的是字符


## 基本函数

### strlen()函数

包含在string.h头文件中

给出字符串中的字符长度(string)，而且**忽略空字符**。而**sizeof**运算符是以字节为单位给出对象的大小。




**(?)**
为什么如下程序不行？？？

    #include <stdio.h>
    int main()
    {
        printf("Enter an ASCII code:\n");
        int code;
        scanf("d%\n", &code);
        printf("%c\n", code);
        return 0;
    }


### 复数和虚数类型

|          type          | form  |
| :--------------------: | :---: |
|     float _Complex     |   ?   |
|    double _Complex     |   ?   |
|  long double _Complex  |   ?   |
|    float _Imaginary    |   ?   |
|   double _Imaginary    |   ?   |
| long double _Imaginary |   ?   |

**NOTE**：如果包含complex.h头文件，便可用complex代替_Complex，用imaginary代替_Imaginary，还可以用I代替-1的平方根。


转义序列
|  ESC  |      meaning       |
| :---: | :----------------: |
|  \a   |        警报        |
|  \b   |        退格        |
|  \f   |        换页        |
|  \n   |        换行        |
|  \r   |        回车        |
|  \t   |     水平制表符     |
|  \v   |     垂直制表符     |
|  \\   |       反斜杠       |
|  \'   |       单引号       |
|  \"   |       双引号       |
|  \?   |        问号        |
| \0oo  |  八进制值(oo是数)  |
| \xhh  | 十六进制值(hh是数) |


## 类型大小 (?)

> example: typesize.c

用sizeof()函数返回string_size格式的类型大小

## 可移植类型: stdint.h 和 inttypes.h (??)

C99新增了两个头文件 stdint.h 和 inttypes.h，以确保C语言的类型在各系统中的功能相同。

## 程序的上溢(overflow)和下溢(underflow)

> example: overflow_and_underflow.c

当计算导致数字过大，超过当前类型能表达的范围时，就会发生上溢，此时会赋一个表示无穷大的特定值，比如inf或者infinity

而当除以一个很小的数时，情况更为复杂(?)

还有一个特殊的浮点值NaN(not a number的suoxie)。比如给反正弦函数输入了大于1的变量，返回的就是NaN。

**NOTE**：浮点数并不精确！

## 类型转换

基本的类型转换规则
1. 当类型转换出现在表达式时，无论是unsigned还是signed得char和short都会被自动转换成int，如有必要会被转换成unsigned int。由于都是较小类型转换为较大类型，所以这些转换被称为升级(promotion)
2. 涉及两种类型得运算，两个值会被分别转换成两种类型得更高级别
3. 类型得级别从高到低依次是
4. 赋值表达式语句中，计算得最终结果会被转换成被赋值变量得类型。这个过程可能导致类型升级或降级。
5. 当作为函数参数传递时，char和short倍转换成int, float被转换成double。
   

### 强制类型转换运算符

将其右侧得值转换成圆括号中指定得类型。

example:

    int mice;
    mice = (int)1.6 + (int)1.7;  //强制把1.6和1.7都变成1


## 数组(array)

### 声明数组

example:

    float debts[20]; //从debts[0]到debts[19]

### 使用数组

**NOTE**：考虑到影响执行的速度，C编译器不会检查数组的下标是否正确。比如debts[20]就不正确，但是编译器不会查找这样的错误。当运行程序时，这会导致数据被放置在已被其他数据占用的地方，可能会破坏程序的结果甚至导致程序异常终端。