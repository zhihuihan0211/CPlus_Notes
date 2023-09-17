#include <iostream>
#include <unordered_map>

class Flyweight
{
public:
    virtual void Operation(const std::string& extrinsicState) = 0;
};

class ConcreteFlyweight : public Flyweight
{
private:
    std::string intrinsicState;

public:

    ConcreteFlyweight(const std::string& intrisic) 
        : intrinsicState(intrisic)
    {}

    void Operation(const std::string& extrinsicState) override
    {
        std::cout << "Intrinsic State: " << intrinsicState 
            << ", Extrinsic State: " << extrinsicState << std::endl;   
    }

};


class FlyweightFactory
{
private:
    std::unordered_map<std::string, Flyweight*> FlyweightMap;

    public:
    Flyweight* GetFlyWeight(const std::string& key)
    {
        if(FlyweightMap.find(key) == FlyweightMap.end())
        {
            FlyweightMap[key] = new ConcreteFlyweight(key);
        }
        return FlyweightMap[key];
    }

};


int main()
{
    FlyweightFactory factory;
    Flyweight* fw1 = factory.GetFlyWeight("A");
    Flyweight* fw2 = factory.GetFlyWeight("B");
    Flyweight* fw3 = factory.GetFlyWeight("A"); // 重复使用相同的享元对象

    fw1->Operation("X");
    fw2->Operation("Y");
    fw3->Operation("Z");

    delete fw1;
    delete fw2;
    delete fw3;

    
    return 0;
}
