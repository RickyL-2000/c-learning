# Something about Compiler

## Intro

 编译器是翻译代码为计算机语言的一个工具，我们平时写的代码如果想在某个特定的计算机上执行（计算机的cpu构架不同），就需要编译器来对代码进行编译汇编链接，而汇编和链接的过程对于每个不同的平台上过程都不一样。 

**主流的编译器有 gcc, clang, make, cmake，其中， gcc和clang是两个不同的编译器，而make和cmake是搭配编译器来方便用户进行多文件编译而发明的工具。 **

 https://oldpan.me/archives/gcc-make-cmake-clang-tell 

## make

 make工具相当于一个智能的批处理工具，本身没有编译和链接的功能，而是用类似于批处理的方式通过调用makefile文件中用户指定的命令来进行编译和链接。而makefile又是什么，就相当于用户将要执行的一系列命令，make根据makefile中的命令对相应的源文件进行编译和链接的。 



## cmake

cmake工具可以非常方便地生成makefile文件。而且cmake可以跨平台生成对应平台能使用的makefile，无需自己根据每个平台的不同特性去修改。而cmake需要根据 CMakeLists.txt 文件（组态档）去生成 makefile。

然而，如果不在CLion等IDE下，比如在VSCode下，CMakeLists.txt是需要自己写的

来源：[利用vscode和cmake编译构建C++工程代码](https://oldpan.me/archives/use-vscode-cmake-tools-build-project)

