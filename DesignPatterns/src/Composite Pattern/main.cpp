#include <iostream>
#include <string>
#include <vector>

class Component
{
public:
    virtual void Operation() = 0;

};

class Leaf : public Component
{
public:
    void Operation() override
    {
        std::cout << "Leaf operation" << std::endl;
    }

};

//
class Composite : public Component
{
private:
    std::vector<Component*> Childern;

public:
    void Add(Component* component)
    {
        Childern.push_back(component);
    }
    
    void Operation() override
    {
        std::cout << "Composite operation" << std::endl;
        for (Component* component : Childern) 
        {
            component->Operation();
        }
    }
};






int main()
{
    Leaf leaf1, leaf2;
    Composite composite;

    composite.Add(&leaf1);
    composite.Add(&leaf2);

    composite.Operation();
   
    return 0;
}