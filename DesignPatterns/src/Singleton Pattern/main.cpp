#include <iostream>

class Singleton
{
public:

    static Singleton& getInstance()
    {
        static Singleton Instance;
        return Instance;
    }

    //
    void ShowMessage()
    { 
        std::cout << "Hello from Singleton!" << std::endl;
    }

    Singleton(const Singleton& ) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton(){}

    ~Singleton(){}
};

int main()
{
    Singleton& instance1 = Singleton::getInstance();
    instance1.ShowMessage();

    Singleton& instance2 = Singleton::getInstance();
    instance2.ShowMessage();

    // 两个实例应该是同一个对象，因此它们的地址相同
    if (&instance1 == &instance2) 
    {
        std::cout << "Both instances are the same." << std::endl;
    } 
    else 
    {
        std::cout << "Instances are different." << std::endl;
    }
    
    return 0;
}