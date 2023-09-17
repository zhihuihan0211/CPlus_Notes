#include <iostream>

// 策略接口

class Strategy
{
public:
    virtual void execute() = 0;
};


//具体策略

class ConcreteStrategy1:public Strategy
{
public:
    void execute() override
    {
        std::cout << "Executing Strategy 1" << std::endl;
    }

};

// 具体策略2
class ConcreteStrategy2 : public Strategy {
public:
    void execute() override {
        std::cout << "Executing Strategy 2" << std::endl;
    }
};

// 上下文类
class Context 
{

public:
    Context(Strategy* start) :m_strategy(start)
    {}

    void SetStartegy(Strategy* start)
    {
        m_strategy = start;
    }

    void executeStrategy()
    {
        if(m_strategy)
            m_strategy->execute();
        else
        {
            std::cout << "Error: m_strategy is Null" << std::endl;
        }
    }

private:
    Strategy* m_strategy;

};

int main()
{
    ConcreteStrategy1 strategy1;
    ConcreteStrategy2 strategy2;

    Context context(&strategy1);
    context.executeStrategy();

    context.SetStartegy(&strategy2);
    context.executeStrategy(); 
    
    return 0;
}