#include <iostream>

class SubsystemA
{
public:
    void operationA()
    {
        std::cout<< "Subsystem A Operation!" <<std::endl;
    }

};

class SubsystemB
{
public:
    void operationB()
    {
        std::cout<< "Subsystem B Operation!" <<std::endl;
    }

};


class SubsystemC
{
public:
    void operationC()
    {
        std::cout<< "Subsystem C Operation!" <<std::endl;
    }

};

// Facde object class
class Facade
{
private:
    SubsystemA m_subA;
    SubsystemB m_subB;
    SubsystemC m_subC;

public:
    Facade()
    {
        // 在外观类的构造函数中初始化子系统对象
    }

    void Operation()
    {
        m_subA.operationA();
        m_subB.operationB();
        m_subC.operationC();
    }
};


int main()
{
    // 客户端代码只需要与外观类交互
    Facade facade;
    facade.Operation();

    return 0;
}

// 在这个示例中，我们有以下关键要点：

// SubsystemA、SubsystemB 和 SubsystemC 分别代表子系统的一部分，每个子系统具有自己的操作。

// Facade 是外观类，它组合了这些子系统，并提供了一个统一的接口 operation()，客户端只需要与外观类交互。

// 在 main 函数中，我们创建了一个外观对象 facade，并通过它来调用子系统的操作。客户端代码不需要了解子系统的复杂性，只需要调用外观类的方法即可。

// 外观模式有助于减少客户端与子系统之间的耦合，提高了代码的可维护性和可读性。
// 它还允许你将子系统的实现细节隐藏起来，从而降低了对子系统的直接访问。这在需要将复杂性封装起来的情况下非常有用。
// 外观模式也常用于库或框架中，以提供简化的接口供用户使用。
