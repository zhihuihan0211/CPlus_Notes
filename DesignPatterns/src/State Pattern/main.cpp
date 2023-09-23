#include <iostream>


class State
{
public:
    virtual void handle() =0;

};

class ConcreteStateA : public State
{
public:
    void handle() override
    {
        std::cout<< "State A  Handled! " << std::endl;
    }

};

class ConcreteStateB : public State
{
public:
    void handle() override
    {
        std::cout<< "State B  Handled! " << std::endl;
    }

};

class Context
{
private:
    State* m_State;

public:
    Context()
        :m_State(nullptr)
    {}

    void SetState(State* newState)
    {
        m_State = newState;
    }

    void Request()
    {
        if(m_State)
        {
            m_State->handle();
        }
        else
        {
            std::cout << "Current state : is Null! " <<std::endl; 
        }
    }

};

int main()
{
    Context context;

    // 初始状态为 State A
    context.SetState(new ConcreteStateA);
    context.Request();  // 输出 "State A handled"

    // 切换到 State B
    context.SetState(new ConcreteStateB);
    context.Request();  // 输出 "State B handled" 
    
    return 0;
}