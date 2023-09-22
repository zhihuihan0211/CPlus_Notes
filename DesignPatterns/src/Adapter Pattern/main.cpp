#include <iostream>

// 目标接口
class Target
{
public:
    virtual void request() = 0;
};

// 源类（需要适配的类）
class Adaptee
{
public:
    void SpecificRequest()
    {
        std::cout << "Adaptee's Specific Request() !" << std::endl;
    }
};

//典型的适配器
class Adapter : public Target, private Adaptee
{

public:
    void request() override
    {
        SpecificRequest();
    }

};

int main()
{
 
    Target* adapter = new Adapter();

    adapter->request();

    delete adapter;
    return 0;
}
