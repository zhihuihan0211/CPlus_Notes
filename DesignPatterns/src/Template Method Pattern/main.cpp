#include <iostream>

// 不推荐这种方�?
using namespace std;


class AbstractClass
{

public:

    // 模板方法，定义了算法的骨�?
    void templateMethod()
    {
        // 算法执行流程
        step1();

        step2();

        step3();
    }

/* 也可以考虑将 这些步骤放在protected 中 */

    // 抽象方法，子类必须提供具体实�?
    virtual void step1() = 0;
    virtual void step2() = 0;   

    // 钩子方法，子类可以选择覆盖
    virtual void step3() {
        std::cout << "Default implementation of step3" << std::endl;
    }

};

class ConcreteClass : public AbstractClass
{
public:

    virtual void  step1() override      //virtual 可以省略
    {
         std::cout << "ConcreateClass : Step1 !" << std::endl;
    }

    virtual void  step2() override      //virtual 可以省略
    {
         std::cout << "ConcreateClass : Step2 !" << std::endl;
    }

    virtual void  step3() override      //virtual 可以省略
    {
    std::cout << "ConcreteClass: Custom implementation of Step 3" << std::endl;
    }

};


int main()
{

    AbstractClass* AbsObjePtr = new ConcreteClass();
    AbsObjePtr->templateMethod();

    return 0;
}

/**
 * 在这个示例中，AbstractClass 定义了模板方�? templateMethod，以及两个抽象方�? step1 �? step2，还有一个钩子方�? step3�?
 * ConcreteClass 继承�? AbstractClass 并提供了具体实现�?
 * 你可以看到，�? templateMethod 中，步骤1和步�?2是必需的，但步�?3是可选的，并且在 ConcreteClass 中被覆盖以提供自定义实现�?
 * 通过使用模板方法模式，你可以确保算法的骨架在所有子类中保持一致，但允许子类根据需要提供特定的实现。这有助于提高代码的可维护性和扩展性�?
*/