# CPlus_Notes
现代 c++ 笔记

# GCC G++ 入门

## 用法
    gcc(g++) <options> <sourcefiles...>
    · 示例
    gcc main.cpp
    gcc -o main main.cpp
    gcc -o main main.cpp hello.cpp fun.cpp
    gcc -I../headers -o main main.cpp
    g++ -o main -I../headers -L../lib -lfun1 main.cpp hello.cpp

常用选项(options)

| 选项                  |                       作用   |    
|  ----  | ----  |
| -o <filename>            | 指定生成文件名          |                 
|-I<dir>	               | 指定头文件搜索路径       |
|-L<dir>	               | 指定库搜索路径          | 
|-static	               | 静态链接               | 
|-E -o<filename.i>	       | 编译过程进行到预处理    | 
|-S                        | 编译过程进行到编译      | 
|-c	                       | 编译过程进行到汇编      | 
|-O(0-3)	               | 指定代码优化级别        | 
|-Wall	                   | 输出警告信息            | 
|-fexec-charset=GBK	       | 指定运行时编码          | 
|-finput-charset=UTF-8	   | 指定源文件编码          | 
|-l<libname>	           | 指定链接库名            | 

### 静态链接库
#### 命名
    静态链接库命名采用lib<name>.a的形式，例如libmangle.a，libpng.a

#### 归档（静态链接库生成）
    先将需要归档到库的源文件编译成.o文件，再用下列命令归档
    ar rcs <libname> <objfilelist...>
    # 示例
    ar rcs libfun.a fun1.o fun2.o fun3.o # 将3个.o文件归档到同一库文件当中
#### 使用
    先将使用到对应静态库的源文件编译为.o文件，再进行链接
    gcc(g++) <ofilelist...> -L<dir> -l<lib>
    # 示例
    gcc main.o hello.o -L../lib -lfun1 -lfun2 -lfun3
    # 或者
    gcc main.o hello.o ../lib/libfun1.a ../lib/libfun2.a ../lib/libfun3.a
### 动态链接库

#### 命名
    动态链接库命名规则为lib<name>.dll (Windows) / lib<name>.so (Linux)，例如：libmangle.dll/libmangle.so，libpng.dll/libpng.so
#### 生成
    # 分步进行
    gcc(g++) -c -fPIC <sourcefilelist ...>
    gcc(g++) -o <libname> -shared <objfilelist ...>
    # 示例
    gcc -c -fPIC fun1.c fun2.c fun3.c
    gcc -o libfun.dll -shared fun1.o fun2.o fun3.o

    # 一步到位
    gcc(g++) -o <libname> -fPIC -shared <sourcefilelist ...>
    # 示例
    gcc -o libfun.dll -fPIC  -shared fun1.c fun2.c fun3.c
#### 使用
    先将使用到对应静态库的源文件编译为.o文件，再进行链接
    gcc(g++) <ofilelist...> -L<dir> -l<lib>
    # 示例
    gcc main.o hello.o -L../lib -lfun1 -lfun2 -lfun3
    # 或者
    gcc main.o hello.o ../lib/libfun1.dll ../lib/libfun2.dll ../lib/libfun3.dll


# 初始化
## 构造函数

## c++ 11 之后的统一初始化

## c++2a之后的指派初始化（推荐）

``` c++
struct Employee
{
    /* data */
    char name;
    int Num;
    float Length;
    
};

Employee emp{.name='C', .Num=10, .Length = 150}; // 指派初始化
/* 
 * 优点 ：如何更改了增加或者更改了成员的顺序等，在一定程度上不会影响初始化内容的错误
 *  
*/

```



