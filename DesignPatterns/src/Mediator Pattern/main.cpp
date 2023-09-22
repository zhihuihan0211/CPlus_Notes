#include <iostream>
#include <string>
#include <vector>


class Colleague;

class Mediator
{
public:
    virtual void SendMessage(const std::string& message, Colleague* colleague ) = 0;

};

class Colleague
{
protected:
    Mediator* m_Mediator;

public:
    Colleague(Mediator* mediator)
        :m_Mediator(mediator)
    {
        
    }

    virtual void Send(const std::string& message) = 0;

    virtual void receivemessage(const std::string& message) = 0;

};

class ConcreteMediator :public Mediator
{
private:
    std::vector<Colleague*> m_colleagues;
public:
    void AddColleague(Colleague* colleague)
    {
        m_colleagues.push_back(colleague);
    }

    void SendMessage(const std::string& message, Colleague* sender) override
    {
        for(std::vector<Colleague *>::iterator colleagetIter = m_colleagues.begin(); colleagetIter != m_colleagues.end();colleagetIter++)
        {//我们可以通过 *it 来获取当前迭代器指向的对象
            if(*colleagetIter == sender)
            {
                (*colleagetIter)->receivemessage(message);
            }
        }
        // for (Colleague*collageItem : m_colleagues)
        // {
        //     /* code */
        // }
        
    }
};

class ConcreteColleague : public Colleague
{
public:

    ConcreteColleague(Mediator* mediator)
        :Colleague(mediator)
    {

    }

    void Send(const std::string& message) override
    {
        std::cout << "Sending message: " << message << std::endl;
        m_Mediator->SendMessage(message, this);
    }

    void receivemessage(const std::string& message) override
    {
        std::cout << "Received message: " << message << std::endl;
    }
    
};



int main()
{
 
    ConcreteMediator mediator;

    ConcreteColleague colleague1(&mediator);
    ConcreteColleague colleague2(&mediator);

    mediator.AddColleague(&colleague1);
    mediator.AddColleague(&colleague2);

    colleague1.Send("Hello, colleague2!");
    colleague2.Send("Hi, colleague1!");

    return 0;
}
