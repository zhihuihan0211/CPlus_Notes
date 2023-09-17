#include <iostream>

class Product
{
public:
    virtual void Use()  =0;

};


class ConcreteProductA : public Product
{
public:
    void Use() override 
    {
         std::cout << "Using Concrete Product A" << std::endl;
    }
};

class ConcreteProductB : public Product
{
public:
    void Use() override 
    {
         std::cout << "Using Concrete Product B" << std::endl;
    }
};

class Factory
{
public:
    virtual Product*  CreateProduct() = 0;
};


class ConcreteFactoryA : public Factory
{
public:
   Product* CreateProduct() override 
    {
        return new ConcreteProductA();
    }
};


class ConcreteFactoryB : public Factory
{
public:
    Product* CreateProduct() override
    {
        return new ConcreteProductB();
    }
};



int main()
{
    Factory* factoryA = new ConcreteFactoryA();
    Product* productA = factoryA->CreateProduct();
    productA->Use();

    Factory* factoryB = new ConcreteFactoryB();
    Product* productB = factoryB->CreateProduct();
    productB->Use();

    delete factoryA;
    delete productA;
    delete factoryB;
    delete productB;

    return 0;
}
