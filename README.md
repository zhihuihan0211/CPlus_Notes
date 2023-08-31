# CPlus_Notes 现代 c++ 笔记

**一些在线编辑器**  
* https://www.onlinegdb.com/

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


## explicit（显式）关键字
- explicit 修饰构造函数时，可以防止隐式转换和复制初始化

- explicit 修饰转换函数时，可以防止隐式转换，但 [按语境转换](https://zh.cppreference.com/w/cpp/language/implicit_conversion) 除外
```C++
struct A
{
	A(int) { }
	operator bool() const { return true; }
};

struct B
{
	explicit B(int) {}
	explicit operator bool() const { return true; }
};

void doA(A a) {}

void doB(B b) {}

int main()
{
	A a1(1);		// OK：直接初始化
	A a2 = 1;		// OK：复制初始化
	A a3{ 1 };		// OK：直接列表初始化
	A a4 = { 1 };		// OK：复制列表初始化
	A a5 = (A)1;		// OK：允许 static_cast 的显式转换 
	doA(1);			// OK：允许从 int 到 A 的隐式转换
	if (a1);		// OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
	bool a6(a1);		// OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
	bool a7 = a1;		// OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
	bool a8 = static_cast<bool>(a1);  // OK ：static_cast 进行直接初始化

	B b1(1);		// OK：直接初始化
	B b2 = 1;		// 错误：被 explicit 修饰构造函数的对象不可以复制初始化
	B b3{ 1 };		// OK：直接列表初始化
	B b4 = { 1 };		// 错误：被 explicit 修饰构造函数的对象不可以复制列表初始化
	B b5 = (B)1;		// OK：允许 static_cast 的显式转换
	doB(1);			// 错误：被 explicit 修饰构造函数的对象不可以从 int 到 B 的隐式转换
	if (b1);		// OK：被 explicit 修饰转换函数 B::operator bool() 的对象可以从 B 到 bool 的按语境转换
	bool b6(b1);		// OK：被 explicit 修饰转换函数 B::operator bool() 的对象可以从 B 到 bool 的按语境转换
	bool b7 = b1;		// 错误：被 explicit 修饰转换函数 B::operator bool() 的对象不可以隐式转换
	bool b8 = static_cast<bool>(b1);  // OK：static_cast 进行直接初始化

	return 0;
}
```



## SFINAE
**模板替换失败并不是错误！**


## concept 概念

*   
*   
*   

# c++ 20 设计模式

## 一些c++世界中重要的概念

### CRTP 奇异递归模板模式

### MIxin 继承

### 旧风格的静态多态


### 概念（concept）与静态多态

### 属性

## SOLID 设计原则
* 
* 
* 
* 
* 









