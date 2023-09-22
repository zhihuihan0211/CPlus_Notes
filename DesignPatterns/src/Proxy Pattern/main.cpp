#include <iostream>


class Subject
{
public:
 virtual void Request() = 0;

};

class RealSubject : public Subject
{
public:
    void Request() override
    {
        std::cout << "RealSubject: Handling request" << std::endl; 
    }




};

class Proxy : public Subject
{
private:
    RealSubject* m_readlSubject;

public:
    Proxy() 
        : m_readlSubject(nullptr)
    {
    }

    void Request() override
    {
        if(m_readlSubject == nullptr)
        {
            m_readlSubject = new RealSubject();
        }
        m_readlSubject->Request();
    }
};


int main()
{
    Proxy proxy;

    // 客户端代码通过代理访问真实对象
    proxy.Request();

    return 0;
}

