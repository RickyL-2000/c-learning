# 函数

## 函数的声明

编译器要知道函数返回值的类型，才能知道有多少字节的数据，以及如何解释它们。这就是为什么必须声明函数的原因。

## 形参和实参

形参(parameter)，实参(argument)。在C99的标准中，这两个英文单词是不能互换的。

## 函数的定义

## 函数的调用

原型(prototype)是函数的声明，描述了函数的返回值和参数

## 返回值

函数名前有void关键字的函数没有返回值

定义函数时返回值的类型需要在函数名前标出

> example: power.c

example:

    double power (double n, int p)
    {
        double pow = 1;
        int i;

        for (i = 1; i <= p; i++)
            pow *= n;
        
        return pow;   //返回pow的值
    }