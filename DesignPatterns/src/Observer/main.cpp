#include <iostream>
#include <vector>


// 观察者接口
class  Observer
{
public:
virtual void Update(const std::string& message) = 0;

};

//具体观察者

class ConcreteObserver : public Observer
{
private:
std::string m_name;

public:
    ConcreteObserver(const std::string& name):m_name(name){}

    void Update(const std::string& message) override
    {
        std::cout << m_name << " received message: " << message << std::endl;
    }
};



//
class Subject
{
public:
    virtual void AddObserver(Observer* observer) = 0;
    virtual void RemoveObserver(Observer* observer) = 0;
    virtual void NotifyObservers(const std::string& message) = 0; 

};

class ConcreteSubject : public Subject
{

private:
    std::vector<Observer*> m_ObjectorList;
public:

    void AddObserver (Observer* observer) override
    {
        m_ObjectorList.push_back(observer);
    }

    void RemoveObserver (Observer* observer) override
    {
        if(!observer)
        {
            std::cout << "Warning : " << "remove Observer is Null" << std::endl;
            return ;
        }

        for(auto item = m_ObjectorList.begin();item!=m_ObjectorList.end(); ++item)
        {
            if(*item == observer)
            {
                m_ObjectorList.erase(item);
                break;
            }
        }
    }

    void NotifyObservers (const std::string& message) override
    {
        for(auto observer : m_ObjectorList)
        {
            observer->Update(message);
        }
    }

    void SetState(const std::string& message)
    {
        std::cout << "State changed to: " << message << std::endl;
        NotifyObservers(message);  
    }


};




int main()
{
    ConcreteSubject subject;

    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");

    subject.AddObserver(&observer1);
    subject.AddObserver(&observer2);

    subject.SetState("New state 1");
    
    subject.RemoveObserver(&observer1);
    
    subject.SetState("New state 2");

    
    return 0;
}
