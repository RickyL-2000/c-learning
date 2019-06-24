# C语言概论

## "#include" 指令和头文件(header)

C预处理指令(preprocessor directive): #include

stdio.h文件：包含供编译使用的输入和输出函数

## bug

**NOTE**：检查bug有哪些：(满满的都是泪啊)
1. scanf()里面非字符串是否加"&"了？
2. printf()里面是否添加了待打印变量？

当出现“分段错误”(Segmentation fault)时，检查在scanf()中是否添加了&符号。这是说明该程序试图访问未分配的内存

## 练习

exercise5_11_7.c ？？？啥bug???
exercise5_11_9.c，相同的问题，无论输入什么都输出0
exercise6_16_9.c  所以为什么又出问题了...感觉和function有关的东西都很容易出问题
exercise9_11_6.c  太棒了，又出问题了...又是function...无论输入什么都输出0
exercise9_11_8.c 哈哈哈哈哈哈哈哈哈哈哈我tm又来了哈哈哈哈哈哈哈又是同一个问题哈哈哈哈哈哈无论如何都输出0！这tm是为什么！
总算解决了问题！！！！！！！
总结：发现输入和输出double类型的数据的格式化字符居然是不一样的....printf()用的是%f，而scanf()用的是%lf。
     另外，关于long double的事情一直一直就搞不好...以后还是就不碰这个奇怪的类型了吧....:(


问题又来了：exercise5_11_9下面的计算表达式，为什么5/9写在前面就会得出0而写在后面就正确了？


exercise10_13_2.c 第一次自主运用sizeof()函数，但是为什么sizeof(array)比sizeof(array[0])还要小？？？？
上了卡耐基梅隆大学的一个奇怪网站，才知道问题所在。原来在通过函数传递的时候，此时的array已经不是一个数组而是一个指针了。所以无论如何，不论array有多长，sizeof(array)都是8。