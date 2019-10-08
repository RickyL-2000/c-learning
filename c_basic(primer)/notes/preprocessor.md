# 预处理器

## headers

### stdio.h

### string.h

### math.h

https://www.runoob.com/cprogramming/c-standard-library-math-h.html

math.h 头文件定义了各种数学函数和一个宏。在这个库中所有可用的功能都带有一个 double 类型的参数，且都返回 double 类型的结果。

下面是这个库中定义的唯一的一个宏：

HUGE_VAL

当函数的结果不可以表示为浮点数时。如果是因为结果的幅度太大以致于无法表示，则函数会设置 errno 为 ERANGE 来表示范围错误，并返回一个由宏 HUGE_VAL 或者它的否定（- HUGE_VAL）命名的一个特定的很大的值。

如果结果的幅度太小，则会返回零值。在这种情况下，error 可能会被设置为 ERANGE，也有可能不会被设置为 ERANGE。

### ctype.h

ctype.h头文件中的字符测试函数

|    name    |    if are these types, true     |
| :--------: | :-----------------------------: |
| isalnum()  |        letter or number         |
| isalpha()  |             letter              |
| isblank()  |         standard blank          |
| isspace()  |           blank char            |
| iscntrl()  |    control char, like Ctrl+B    |
| isdigit()  |             number              |
| isxdigit() |           number(16)            |
| isgraph()  | any printable char exepct space |
| islower()  |          lower letter           |
| isupper()  |         capital letter          |
| isprint()  |         printable char          |
| ispunct()  |           punctuation           |

ctype.h头文件中的字符映射函数

|   name    |    activity     |
| :-------: | :-------------: |
| tolower() | upper --> lower |
| toupper() | lower --> upper |


**NOTE**：
1. isblank()和isspace()有什么区别？？？
2. tolower()和toupper()是函数，有返回值，而且需要把返回值重新赋给一个变量才有作用。换句话说，char是mutable的类型。


### stdbool.h

包含 bool 类型，可以代替_Bool类型

### iso646.h

可以用and代替&&，or代替||，not代替！

### limits.h (?)

### float.h (?)



## 在预处理器中定于常量: #define

form:

    #define NAME value

example:

    #define PI 3.141593