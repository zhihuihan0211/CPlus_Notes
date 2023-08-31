# CPlus_Notes 现代 c++ 笔记

# 初始化

## 结构化绑定

结构化绑定允许多个变量，这些变量使用数组、结构体、pair或元组中的元素以初始化(c+17/20)

``` c++
例如:
    array values{11, 22, 33};

    //结构化绑定 
    auto [x, y, z] { values };

    //注意结构化绑定必须使用auto关键字


    std::pair m_Pair{"Hello ", 5};
    auto [name, num] { m_Pair };

    std::cout << "name: " << name << std::endl;
    std::cout << "Num: " << num << std::endl;
    
    //还可以结合引用使用
    //......

```

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


## 类型推断
### auto
**auto 推断会去除引用和const限定符**，所以会创建副本    
可以使用 auto& 或 const auto&     
工具函数：as_const() 返回其引用参数的const引用版本

### decltype
**decltype 未去除引用和const 限定符**






