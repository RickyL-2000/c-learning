# Blood and Tears

## 关于数组拷贝

来自ECE220 mp7

数组拷贝的时候一定要写一个循环一个个拷贝！直接赋值指针会导致很多奇奇怪怪的问题！！！比如原来的数组空间会变成野空间等等！！！

## 关于字符串

非heap上申请的字符串变量不可以用strcpy()等库函数进行修改，但是却可以用str[0] = 'c'的方式进行修改！

example:
```
char word[10] = "hello"
word[0] = 'H';
```
then word[] will become "Hello"