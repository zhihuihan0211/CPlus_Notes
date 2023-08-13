#include <iostream>
#include "initial.h"




int main(int argc, char *argv[])
{

    Employee emp{.name='C', .Num=10, .Length = 150}; // 指派初始化

    std::cout << "emo: name : " <<emp.name << ": Num  " << emp.Num <<std::endl;
    std::cout << "Hello world!" << std::endl;

    return 0;
}
