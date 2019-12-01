# 格式化输入/输出

**NOTE**：printf()和sacnf()的参数个数是可变的，不像其他函数，因此可能产生相应的错误。

## 缓冲区 (?)

缓冲分为两类：完全缓冲I/O和行缓冲I/O。
完全缓冲输入指的是当缓冲区被填满时才刷新缓冲区（内容被发送至目的地），通常出现在文件输入中。缓冲区的大小取决于系统，常见的大小是512字节和4096字节。
行缓冲I/O指的是在出现换行符时刷新缓冲区。

## 结束键盘输入 (?)

### 文件 (?)

从较低层面上，C可以使用主机操作系统的基本文件工具直接处理文件，这些直接调用操作系统的函数被成为底层I/O。然而从较高层面上，C还可以通过标准I/O包来处理文件。

文件结尾

检测文件结尾的一种方法是，在文件末尾放一个特殊的字符标记文件结尾。CP/M, MS-DOS的文本文件曾经使用过这种方法。如今，这些操作系统可以使用内嵌的Ctrl+Z字符来标记文件结尾。

无论操作系统实际使用何种方法检测文件结尾，在C语言中，用getchar()读取文件检测到文件结尾时将返回一个特殊的值，即EOF。通常，EOF定义在stdio.h文件中:

    #define EOF (-1)
因为getchar()的返回值通常都介于0~127或者0~255（扩展字符集）。-1都不对应任何字符。

**NOTE**：只要包含stdio.h文件，并使用EOF符号，就不必担心EOF值不同的问题，也不用担心EOF的实际值。可以把getchar()的返回值和eof作比较：

    while ((ch = getchar()) != EOF)

### 重定向和文件 (?)

假设已经编译了echo_eof.c文件:

    #include <stdio.h>
    int main()
    {
        int ch;
        while ((ch = getchar()) != EOF)
            putchar(ch);
        return 0;
    }
并且把可执行版本放入一个名为echo_eof.exe的文件（在win系统中）。

#### 重定向输入

假设你要用该程序处理名为words的文本文件，只需要用下面的命令：

    echo_eof < words
<符号是UNIX和DOS/Windows的重定向运算符。该运算符使words文件与stdin流相关联，把文件中的内容导入echo_eof程序。echo_eof程序本身并不知道输入的内容是来自文件还是键盘，它只知道这是需要导入的字符流。因为C把文件和I/O设备放在一个层面，所以文件就是现在的I/O设备。

#### 重定向输出

假设现在要用echo_eof把键盘输入的内容发送到名为mywords的文件中。然后，输入以下命令并开始输入:

    echo_eof > mywords
这个符号是第二个重定向运算符，它创建了一个名为mywords的新文件，然后把输出重定向至该文件中。重定向把stdout从显示设备赋给mywords文件。如果已经有一个名为mywords的文件，通常会擦除该文件的内容，然后替换新的内容（但是很多操作系统有保护现有文件的选项，使其成为只读文件）。

#### 组合重定向

现在，假设你希望制作一份mywords文件的副本，并命名为savewords。只需输入如下命令：

    echo_eof < mywords > savewords

#### 注释

#### 混合数值和字符输入

主要就是getchar()和换行符的问题！

## 文件输入与输出

### 流

一共有三种默认流：

* stdin	(descriptor 0)	keyboard
* stdout  (descriptor 1)    display (normal)
* stderr   (descriptor 2)    display (error)

程序员可以自己创造新的流变量，

example:

``` FILE* my_file;```

**NOTE**: Descriptors可以被重载，比如把stdout输出到一个file，再用stderr把错误显示在屏幕上。

### 打开文件

https://www.runoob.com/cprogramming/c-file-io.html

用fopen()打开Disk上的一个文件，as a Stream

您可以使用 fopen( ) 函数来创建一个新的文件或者打开一个已有的文件，这个调用会初始化类型 FILE 的一个对象，类型 FILE 包含了所有用来控制流的必要的信息。

如果打开成功，该函数会返回一个新的流；如果失败，该函数会返回NULL

下面是这个函数调用的原型：

```
FILE *fopen( const char * filename, const char * mode );
```
这里，filename是字符串，用来命名文件，访问模式mode的值可以是下列值中的一个：

| 模式  |                                                                            描述                                                                            |
| :---: | :--------------------------------------------------------------------------------------------------------------------------------------------------------: |
|   r   |                                                           打开一个已有的文本文件，允许读取文件。                                                           |
|   w   | 打开一个文本文件，允许写入文件。如果文件不存在，则会创建一个新文件。在这里，您的程序会从文件的开头写入内容。如果文件存在，则该会被截断为零长度，重新写入。 |
|   a   |                  打开一个文本文件，以追加模式写入文件。如果文件不存在，则会创建一个新文件。在这里，您的程序会在已有的文件内容中追加内容。                  |
|  r+   |                                                              打开一个文本文件，允许读写文件。                                                              |
|  w+   |                        打开一个文本文件，允许读写文件。如果文件已存在，则文件会被截断为零长度，如果文件不存在，则会创建一个新文件。                        |
|  a+   |                     打开一个文本文件，允许读写文件。如果文件不存在，则会创建一个新文件。读取会从文件的开头开始，写入则只能是追加模式。                     |

**NOTE**:如果处理的是二进制文件，则需要在每个模式字符串的后面（“+”号前）加一个"b"

### 关闭文件

为了关闭文件，请使用 fclose( ) 函数。函数的原型如下：
```
int fclose( FILE *fp );
```

如果成功关闭文件，fclose( ) 函数返回零，如果关闭文件时发生错误，函数返回 EOF。这个函数实际上，会清空缓冲区中的数据，关闭文件，并释放用于该文件的所有内存。EOF 是一个定义在头文件 stdio.h 中的常量。

C 标准库提供了各种函数来按字符或者以固定长度字符串的形式读写文件。

### 写入文件

函数 fputc() 把参数 c 的字符值写入到 fp 所指向的输出流中。如果写入成功，它会返回写入的字符，如果发生错误，则会返回 EOF。
```
int fputc( int c, FILE *fp );
```

函数 fputs() 把字符串 s 写入到 fp 所指向的输出流中。如果写入成功，它会返回一个非负值，如果发生错误，则会返回 EOF。
```
int fputs( const char *s, FILE *fp );
```

> example:
```
#include <stdio.h>
 
int main()
{
   FILE *fp = NULL;
 
   fp = fopen("/tmp/test.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
}
```

### 读取文件

fgetc() 函数从 fp 所指向的输入文件中读取一个字符。返回值是读取的字符，如果发生错误则返回 EOF。
```
int fgetc( FILE * fp );
```

函数 fgets() 从 fp 所指向的输入流中读取 n - 1 个字符。它会把读取的字符串复制到缓冲区 buf，并在最后追加一个 null 字符来终止字符串。

如果这个函数在读取最后一个字符之前就遇到一个换行符 '\n' 或文件的末尾 EOF，则只会返回读取到的字符，包括换行符。您也可以使用 int fscanf(FILE *fp, const char *format, ...) 函数来从文件中读取字符串，但是在遇到第一个空格字符时，它会停止读取。
```
char *fgets( char *buf, int n, FILE *fp );
```

> example:
```
#include <stdio.h>
 
int main()
{
   FILE *fp = NULL;
   char buff[255];
 
   fp = fopen("/tmp/test.txt", "r");
   fscanf(fp, "%s", buff);
   printf("1: %s\n", buff );
 
   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );
   
   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   fclose(fp);
 
}
```

**NOTICE**: 为了避免读到空文件，应该使用**入口条件循环**进行文件输入。

example:
```
int ch;
FILE *fp;
fp = fopen("mmp.txt", "r");
while ((ch = getc(fp)) != EOF) {
    putchar(ch);
}
```

### 二进制I/O函数

```
size_t fread(void *ptr, size_t size_of_elements, 
             size_t number_of_elements, FILE *a_file);
              
size_t fwrite(const void *ptr, size_t size_of_elements, 
             size_t number_of_elements, FILE *a_file);
```

这两个函数都是用于存储块的读写 - 通常是数组或结构体。



## 常用IO函数及其转换说明

目录：
1. 一次一个字符
2. 读写strings
3. 格式化IO
4. 二进制IO
5. string的格式化IO

### 一次一个字符

#### fgetc(), getc()

syntax:
```
int fgetc(FILE* stream);
int getc(FILE* stream);
```

example:
```
int fgetc(stdin);
```

**NOTE**: fgetc() 是一个库函数，getc()是一个预处理器宏。库函数需要时间，但是不占空间。预处理器宏是个inline function，每次调用都会把函数拷贝到当前位置，所以虽然很快，但是会占空间。

这两个函数都返回 1 Byte 或者 EOF

**NOTE**: fgetc()读取'\n'

#### fputc(), putc()

syntax:
```
int fputc(int c, FILE* stream);
int putc(int c, FILE* stream);
```

#### getchar(), putchar()

**可以使用getchar()和putchar()作为以上函数的缩写**

```
int getchar (void);
int putchar(int c);
```

这两个函数通常定义在stdio.h头文件中。而且，它们也是预处理宏，而不是真正的函数。

**NOTE**： getchar()可以获取空白字符！（包括\n！）

它们比更通用的scanf()和printf()更快、更简洁。而且不需要转换说明。

##### **example: 只读每行的首字符**

这种丢弃一行中其他字符的行为，经常出现在响应单字符的叫虎程序中。
example:

    while ((ch = getchar()) != '#')
    {
        ...                         //对第一个字符的操作
        while (getchar() != '\n')   //忽略除了第一个字符外的本行的所有字符
            continue;
    }



### 读写 strings: fgets()

#### fgets()

syntax:
```
char* fgets(char* s, int size, FILE* stream);
```

returns NULL on failure

**NOTE**: fgets() will stop reading at the first case of the following three:
1. end of the input (such as a file)
2. end of a line (ASCII 0x0A or 0x0D)
3. end of array s(leaving room for a NUL)
   
**fgets()** is the best way to process line-oriented inputs

**NOTE**：可以用fgets()和string IO来处理可读的文件。只需要先用fgets()把各行读入string，然后再用string IO来处理string。相比之下fscanf()很容易出错！(FIXME)


#### fputs()

syntax:
```
int fputs(const char* s, FILE *stream);
```
returns non-negative number or EOF on failure

#### puts()

puts() is a shortcut for fputs(stdout)

还有一点和fputs(stdout)不一样的是，puts()会在行结尾加入一个换行符(linefeed, ASCII 0x0A on Unix)

#### never use shortcut for reading a string from stdin

**It is a security hazard!**

gets从标准输入设备读字符串函数，其可以无限读取，不会判断上限，以回车结束读取，所以程序员应该确保buffer的空间足够大，以便在执行读操作时不发生溢出。

而因为本函数可以无限读取，易发生溢出。如果溢出，多出来的字符将被写入到堆栈中，这就覆盖了堆栈原先的内容，破坏一个或多个不相关变量的值。

### 格式化IO

#### fscanf()

syntax:
```
int fscanf(FILE* stream, const char* format, ...);
```

* format is the format specifier

#### fprintf()

syntax:
```
int fprintf(FILE* stream, const char* format, ...);
```

**NOTE**: scanf() and printf() are the shortcut of these two functions.



#### printf()

printf()的格式化字符
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

**NOTE**：
1. d后缀：表示十进制整数
2. x后缀：表示十六进制整数
3. o后缀：表示八进制整数
4. u后缀：表示unsigned
5. l前缀：表示long
6. ll前缀：表示long long
7. h前缀：表示short
8. 如果用%d格式输出char，则输出ASCII码
9.  对于float一类的带"e"的科学记数法的十六进制格式，只需要把e和E分别用a和A代替即可
10. 字符串被储存在char类型的数组中。数组末尾有一个字符\0，代表空字符(null character)。C语言用它来标记字符串的结束。*这意味着数组的容量必须至少比待存储字符串中的字符数多1*
    example: 

        char name[40];
11. 用""括起来的是字符串数组，而用''括起来的是字符
12. 转换说明%p通常以十六进制显示指针的值
13. printf() 不自带换行符
    


**printf()的修饰符**
1. 标记：五种标记(-、+、空格、#、和0)
   示例："%-10d"
2. 数字：最小字段宽度。若该字段不能容纳待打印的数字或者字符串，系统会使用更宽的字段
   示例："%4d"
3. .数字：精度(?????)
   示例："%5.2f"打印一个浮点数，字段宽度为5字符，其中小数点后有两位数字
4. h前缀：和整型转换说明一起使用，表示short int 或 unsigned short int类型的值
5. hh前缀：和整型转换说明一起使用，表示signed char 或 unsigned char
6. j前缀：和整型转换说明一起使用，表示intmax_t 或 uintmax_t类型的值。定义在stdint.h中
7. l前缀：long int, unsigned long int
8. ll前缀：long long int, unsigned long long int (C99)
9. L前缀：long double
10. t前缀：ptrdiff_t (是两个指针差值的类型)
11. z前缀：size_t (C99) (????)

> example:

    exercise4_8_2.c  (不过这最后一小题怎么做??????)

**修饰符中的标记**
1. \-  待打印项左对齐
2. \+  有符号值若为正，则在值前面显示加号，否则显示减号
3. 空格  有符号值若为正，则在值前面显示前导空格(不显示任何符号)，否则显示减号+标记覆盖一个空格
4. \#  把结果转换成另一种形式(??????)
5. 0  对于数值格式，用前导0代替空格填充字段宽度。对于整数格式，如果出现-标记或指定精度，则忽略该标记

**NOTE**：使用足够大的固定字段宽度可以让输出整齐美观
example:

    printf("%9d %9d %9d\n", val1, val2, val3);
output:

           12      234     1222
            4        5       23
        22334     2322    10001


##### 转换说明的意义 (??????)



#### scanf()

简单的规则：
1. 如果用scanf()读取基本变量类型的值，在变量名前加上一个&
2. 如果用scanf()把字符串读入字符数组中，不要使用&

**NOTE** 
1. scanf()的一大用处就是检测数据流。example:

        while (scanf("%f", n) == 1) {...}
    
    如果系统检测到的是符合scanf()预期的浮点数，那么scanf()就会返回1，否则就不会返回1(0或者EOF)，就不会进行循环体内的操作。scanf()返回的数字代表的是检测到的数据的个数。
2. scanf()在遇到第一个空白(空格、制表符或者换行符)时就不再读取输入了，因此，scanf()只会读取字符串中的第一个单词，而不是一整句。
3. 逐个读取数字的方法：

        for (int i = 0; i < length; i++)
            scanf("%1d", &array[i]);     //用字段宽度限制scanf()的读取范围！




scanf()的转换说明
|     转换说明     |       含义        |
| :--------------: | :---------------: |
|        %c        |       char        |
|      %d,%i       |  signed int (10)  |
| %e,%f,%g,%a(C99) |       float       |
|        %o        |  signed int (8)   |
|        %x        |  signed int (16)  |
|        %p        |      pointer      |
|        %s        |      string       |
|        %u        | unsigned int (10) |

scanf()转换说明中的修饰符
|  转换说明   |                               含义                               |
| :---------: | :--------------------------------------------------------------: |
|     \*      |       抑制赋值 e.g. "%*d"  **很重要！可以忽略特定输入！**        |
|    数字     |                           最大字段宽度                           |
|     hh      |     把整数作为signed char或unsigned char类型读取 e.g. "%hhd"     |
|     ll      | 把整数作为long long或unsigned long long类型读取(C99) e.g. "%lld" |
|   %hd,%hi   |                            short int                             |
| %ho,%hx,%hu |                        unsigned short int                        |
| %lo,%lx,%lu |                          unsigned long                           |
| %le,%lf,%lg |                              double                              |
| %Le,%Lf,%Lg |                           long double                            |






### 二进制IO

#### fread()

syntax:
```
size_t fread (void* ptr, size_t size, size_t n_elt, FILE* stream);
```

* ptr is address to which data are stored
* size is the size of one "thing"
* n_elt is the number of "things"
* returns number of "things" read or 0 on failure

#### fwrite()

syntax:
```
size_t fwrite (const void* ptr, size_t size, size_t nelt, FILE* stream);
```

* ptr is address from which data are written
* others are the same as fread()


### string 的格式化IO

#### sscanf()

use sscanf() to read formatted input from a string

syntax:
```
int sscanf(const char*s, const char* format, ...);
```

* s is the string from which to read

#### snprintf()

use snprintf() to write formatted output to a string

syntax：
```
int snprintf(char* s, size_t size, const char* format, ...);
```

* s is the array to which to write
* size is the length of array