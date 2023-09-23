#include <iostream>
#include <vector>

class  Visitor;

class Element
{
public:
    virtual void Accept(Visitor& visitor) =0;
};

class ConcreteElementA : public Element
{
public:
    void Accept(Visitor& visitor) override;

    std::string OperationA()
    {
        return " ConcreteElementA";  
    }
};

class ConcreteElementB : public Element
{
public:
    void Accept(Visitor& visitor) override;

    std::string OperationB()
    {
        return " ConcreteElementB";  
    }
};

class Visitor
{
public:
    virtual void visit(ConcreteElementA& Element) = 0;
    virtual void visit(ConcreteElementB& Element) = 0;
};

class ConcerteVisitor1 : public Visitor
{
public:
    void visit(ConcreteElementA& Element) override
    {
       std::cout << "Visitor 1 is visiting " << Element.OperationA() << std::endl; 
    }

    void visit(ConcreteElementB& Element) override
    {
       std::cout << "Visitor 1 is visiting " << Element.OperationB() << std::endl; 
    }
};



class ConcreteVisitor2 : public Visitor
{
public:
    void visit(ConcreteElementA& Element) override
    {
       std::cout << "Visitor 2 is visiting " << Element.OperationA() << std::endl; 
    }

    void visit(ConcreteElementB& Element) override
    {
       std::cout << "Visitor 2 is visiting " << Element.OperationB() << std::endl; 
    }

};

// 对象结构
class ObjectStructure
{
private:
    std::vector<Element*> m_Elements;

public:
    void Add(Element* element)
    {
        m_Elements.push_back(element);
    }

    void accept(Visitor& visitor)
    {
        for(Element* element : m_Elements)
        {
            element->Accept(visitor);
        }
    }
};

void ConcreteElementA::Accept(Visitor& visitor) 
{
    visitor.visit(*this);
}

void ConcreteElementB::Accept(Visitor& visitor) 
{
    visitor.visit(*this);
}


int main()
{
    ObjectStructure objectStructure;
    objectStructure.Add(new ConcreteElementA);
    objectStructure.Add(new ConcreteElementB);

    ConcerteVisitor1 visitor1;
    ConcreteVisitor2 visitor2;

    objectStructure.accept(visitor1);
    objectStructure.accept(visitor2);

    return 0;
}

