#include <iostream>

#include <string>

class Prototype
{
public:
    virtual Prototype* Clone() const = 0;

    virtual void PrintInfo() const = 0;
};

class ConcretePrototype : public Prototype
{
private:
    std::string m_data;

public:
    ConcretePrototype(const std::string& data):m_data(data)
    {}

    Prototype* Clone() const override
    {
        return new ConcretePrototype(*this);
    }
    void PrintInfo() const override
    {
        std::cout << "data : " << m_data << std::endl;
    }

};

int main()
{
    // 创建原型对象
    Prototype* prototype = new ConcretePrototype("Original Data");

    // 克隆原型对象
    Prototype* cloned = prototype->Clone();

    // 打印信息
    prototype->PrintInfo();
    cloned->PrintInfo();

    // 释放内存
    delete prototype;
    delete cloned;

    return 0;
}

