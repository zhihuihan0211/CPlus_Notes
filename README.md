# CPlus_Notes
现代 c++ 笔记


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



