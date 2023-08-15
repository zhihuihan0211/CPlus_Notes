#include <iostream>
#include "initial.h"
#include "LogMessage.cpp"

/// @brief
/// @param argc
/// @param argv
/// @return


int main(int argc, char *argv[])
{

    Employee emp{.name = 'C', .Num = 10, .Length = 150}; // 指派初始化

    PrintLogMessage("********************************************");

    std::cout << "emo: name : " << emp.name << ": Num  " << emp.Num << std::endl;
    std::cout << "Hello world!" << std::endl;

    std::pair m_Pair{"Hello ", 5};

    auto [name, num] { m_Pair };
    
    std::cout << "name: " << name << std::endl;
    std::cout << "Num: " << num << std::endl;

    return 0;
}
