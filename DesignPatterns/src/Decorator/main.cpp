#include <iostream>
#include <vector>

//
class Coffee
{
public:
    virtual void Brew() = 0;

    virtual ~Coffee(){}
};

class SimpleCoffee:public Coffee
{
public:

    void Brew() override 
    {
        std::cout << "Brewing a simple coffee" << std::endl;
    }
};

// 装饰器抽象类
class CoffeeDecorator:public Coffee
{
protected: 
    Coffee* m_coffee;

public:
    CoffeeDecorator(Coffee* coffee) : m_coffee(coffee){}

    void Brew() override
    {
        m_coffee->Brew();
    }
};

// 具体装饰器1
class MilkDecorator : public CoffeeDecorator
{
public :
    MilkDecorator(Coffee* coffee):CoffeeDecorator(coffee) // 这里使用了委托构造函数初始化父类
    {

    }
    void Brew() override            //实现自己的制作流程
    {
        CoffeeDecorator::Brew();
        AddMilk();
    }

    void AddMilk()
    {
        std::cout << "Adding milk to the coffee" << std::endl;
    }

};

// 具体装饰器2
class SugarDecorator: public CoffeeDecorator
{
public:
    SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee)
    {

    }

    void Brew() override
    {
        CoffeeDecorator::Brew();
        AddSugar();
    }

    void AddSugar()
    {
        std::cout << "Adding Sugar to the coffee" << std::endl; 
    }

};


int main()
{
    Coffee* coffee = new SimpleCoffee();
    coffee->Brew();

    std::cout << "-------------------------------------------" << std::endl;

    Coffee* milkCoffee = new MilkDecorator(new SimpleCoffee());
    milkCoffee->Brew();

    std::cout << "-------------------------------------------" << std::endl;

    Coffee* sugarMilkCoffee = new SugarDecorator(new MilkDecorator(new SimpleCoffee()));
    sugarMilkCoffee->Brew();

    std::cout << "-------------------------------------------" << std::endl;


    return 0;
}
