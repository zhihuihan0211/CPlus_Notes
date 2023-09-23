#include <iostream>
#include <string>

class Handler
{
protected:
    Handler* NextHander;
public:
    Handler() :NextHander(nullptr)
    {

    }

    void SetNextHandle(Handler* nextHandle)
    {
        NextHander = nextHandle;
    }

    virtual void HandleRequest(const std::string& request) = 0;

};

class ConcreteHandlerA: public Handler
{
public:
    void HandleRequest(const std::string& request) override
    {
        if (request == "A")
        {
            std::cout << "Handler A: Handling request " << request << std::endl;
        } 
        else if (NextHander != nullptr) 
        {
            NextHander->HandleRequest(request);
        } 
        else 
        {
            std::cout << "Handler A: Cannot handle request " << request << std::endl;
        }
    }
};

class ConcreteHandlerB: public Handler
{
public:
    void HandleRequest(const std::string& request) override
    {
        if (request == "B")
        {
            std::cout << "Handler B: Handling request " << request << std::endl;
        } 
        else if (NextHander != nullptr) 
        {
            NextHander->HandleRequest(request);
        } 
        else 
        {
            std::cout << "Handler B: Cannot handle request " << request << std::endl;
        }
    }
};




int main()
{

    Handler* handlerA = new ConcreteHandlerA();
    Handler* handlerB = new ConcreteHandlerB();

    // 构建责任链
    handlerA->SetNextHandle(handlerB);

    // 发送请求到责任链
    handlerA->HandleRequest("A");
    handlerA->HandleRequest("B");
    handlerA->HandleRequest("C");

    delete handlerA;
    delete handlerB;

    return 0;
}