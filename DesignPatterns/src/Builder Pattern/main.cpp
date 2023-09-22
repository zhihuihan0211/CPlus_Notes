#include <iostream>
#include <string>

class Product
{
private: 
    std::string m_PartA;
    std::string m_PartB;
    std::string m_PartC;

public:
    void SetPartA(const std::string& PartA)
    {
        m_PartA = PartA;
    }

    void SetPartB(const std::string& PartB)
    {
        m_PartB = PartB;
    }

    void SetPartC(const std::string& PartC)
    {
        m_PartC = PartC;
    }

    void Show()
    {
        std::cout << "Part A: " << m_PartA << std::endl;
        std::cout << "Part B: " << m_PartB << std::endl;
        std::cout << "Part C: " << m_PartC << std::endl;
    }

};

class Builder
{

public:

virtual void BuildPartA() = 0;
virtual void BuildPartB() = 0;
virtual void BuildPartC() = 0;

virtual Product GetResult() = 0;

};

class ConcreteBuilder : public Builder
{
private:
    Product* m_Product;

public:
    ConcreteBuilder()
    {
        m_Product = new Product();
    }


    void BuildPartA() override
    {
        m_Product->SetPartA("Part A");
    }
    void BuildPartB() override
    {
        m_Product->SetPartB("Part B");

    }
    void BuildPartC() override
    {
        m_Product->SetPartC("Part C");

    }

    Product GetResult() override
    {
        return *m_Product;
    }

};

// 
class Director
{
private:
    Builder* m_Builder;

public:
    Product construct()
    {
        m_Builder->BuildPartA();
        m_Builder->BuildPartB();
        m_Builder->BuildPartC();
        return m_Builder->GetResult();
    }
    void SetBuilder(Builder* builder) {
        m_Builder = builder;
    }

};


int main()
{

    ConcreteBuilder builder;
    Director director;
    director.SetBuilder(&builder);

    Product product = director.construct();
    product.Show();
  

    return 0;
}

//在这个示例中，我们有以下关键要点：

// Product 是要构建的复杂对象，它包含了多个部分（Part A、Part B 和 Part C）的属性。

// Builder 是抽象构建器类，定义了构建产品各个部分的抽象方法以及获取最终产品的方法。

// ConcreteBuilder 是具体构建器类，实现了抽象构建器类的方法，并负责构建产品的各个部分。

// Director 是指挥者类，负责协调构建器来构建产品。客户端通过指挥者来创建产品，而不需要直接与构建器交互。

// 在 main 函数中，我们创建了一个具体构建器 ConcreteBuilder 和一个指挥者 Director。通过指挥者，我们构建了一个产品，并通过 show() 方法展示了产品的各个部分。

// 构建器模式的优点是能够构建复杂的对象，并且可以根据需要定制对象的部分属性。这有助于将构建细节与