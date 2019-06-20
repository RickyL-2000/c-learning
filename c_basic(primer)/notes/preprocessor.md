# 预处理器

## headers

### stdio.h

### string.h

### math.h

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