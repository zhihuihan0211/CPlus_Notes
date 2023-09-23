#include <iostream>
#include <string>
#include <vector>

class Command
{
public:
    virtual void execute() = 0;
};

class ConcreteCommand : public Command
{
private:
    std::string action;

public:

    ConcreteCommand(const std::string& act) : action(act)
    {
    }

    void execute() override 
    {
        std::cout << "Executing command: " << action << std::endl;
    }

};

class Receiver
{
public:
    void PerformAction(const std::string& action)
    {
        std::cout << "Receiver is performing action: " << action << std::endl;
    }
};

class Invoker
{
private:
    Command* m_command;

public:
    void SetCommand(Command* Cmd)
    {
        m_command = Cmd;
    }

    void ExecuetCommadn()
    {
        if(m_command)
        {
            m_command->execute();
        }
    }

};


int main()
{
    Receiver receiver;
    ConcreteCommand command("Action 1");
    command.execute();

    Invoker invoker;
    invoker.SetCommand(&command);
    invoker.ExecuetCommadn();

    return 0;
}