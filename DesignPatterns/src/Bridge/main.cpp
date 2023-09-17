#include <iostream>

class Implementor
{
public:
    virtual void OperationImpl() = 0;
};


class ConcreteImplementorA: public Implementor
{
public:
    void OperationImpl() override
    {
        std::cout << "Concrete Implementor A" << std::endl;
    }

};

class ConcreteImplementorB: public Implementor
{
public:
    void OperationImpl() override
    {
        std::cout << "Concrete Implementor B" << std::endl;
    }

};


//抽象类
class Abstraction
{
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* impl):implementor(impl)
    {
    }

    virtual void Operation() = 0;
};

// 具体抽象类 1
class ConcreteAbstractionA : public Abstraction
{
public:
    ConcreteAbstractionA(Implementor* impl) 
        :Abstraction(impl)
    {
    }

    void Operation() override 
    {
        std::cout << "Concrete Abstraction A - ";
        implementor->OperationImpl();
    }

};

// 具体抽象类 2
class ConcreteAbstractionB : public Abstraction
{
public:
    ConcreteAbstractionB(Implementor* impl) 
        :Abstraction(impl)
    {
    }

    void Operation() override 
    {
        std::cout << "Concrete Abstraction B - ";
        implementor->OperationImpl();
    }

};


int main()
{


    Implementor* implA = new ConcreteImplementorA();
    Implementor* implB = new ConcreteImplementorB();

    Abstraction* abs1 = new ConcreteAbstractionA(implA);
    Abstraction* abs2 = new ConcreteAbstractionB(implB);

    std::cout << "-------------------------------------------" << std::endl;
    abs1->Operation();

    abs2->Operation();


    std::cout << "-------------------------------------------" << std::endl;



    std::cout << "-------------------------------------------" << std::endl;


    return 0;
}
/**
 * 在这个示例中，我们有一个实现接口 Implementor，其中包含了 operationImpl() 方法。
 * 然后，我们创建了两个具体的实现类 ConcreteImplementorA 和 ConcreteImplementorB，它们分别提供了实现的不同功能。

    接着，我们定义了抽象类 Abstraction，它包含一个对实现对象的引用，并定义了一个抽象方法 operation()，
    该方法委托给实现对象的 operationImpl() 方法。
    我们创建了两个具体的抽象类 ConcreteAbstraction1 和 ConcreteAbstraction2，它们分别与不同的实现对象关联。

    在 main 函数中，我们创建了实现对象和抽象对象，并演示了如何使用桥模式来分离抽象和实现，从而能够动态地选择不同的实现。
    这种分离允许我们扩展系统的功能，同时保持高度的灵活性。
*/