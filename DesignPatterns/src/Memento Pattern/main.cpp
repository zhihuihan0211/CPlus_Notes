#include <iostream>
#include <string>

// 
class Memento
{
private:
    std::string state;

public:
    Memento(const std::string& SaveState)
        :state(SaveState)
    {
    }


    std::string GetState()const
    {
        return state;
    
    }

};

class Originator
{
private:
    std::string m_state;

public:
    void SetState(const std::string& state)
    {
        m_state = state;
    }

    std::string GetState() const{
        return m_state;
    }

    Memento CreateMemtro() const
    {
        return Memento(m_state);
    }

    void RestoreMementro(const Memento& memento)
    {
        m_state = memento.GetState();
    }

};

//负责人
class Caretaker
{
public:

    Caretaker() 
        : m_Memento("")
    {}

    void SaveMementro(const Memento& mementro)
    {
        m_Memento = mementro;
    }

    Memento GetMementro() const {   return m_Memento;   }

private:
    Memento m_Memento;

};

int main()
{

    Originator originator;
    Caretaker caretaker;

    // 设置初始状态
    originator.SetState("State 1");
    std::cout << "Current state: " << originator.GetState() << std::endl;

    // 保存备忘录
    caretaker.SaveMementro(originator.CreateMemtro());

    // 修改状态
    originator.SetState("State 2");
    std::cout << "Current state: " << originator.GetState() << std::endl;

    // 恢复状态
    originator.RestoreMementro(caretaker.GetMementro());
    std::cout << "Restored state: " << originator.GetState() << std::endl;

    return 0;
}