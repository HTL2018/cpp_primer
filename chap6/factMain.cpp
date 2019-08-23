#include "Chapter6.h"
#include <iostream>

int main()
{
    std::cout << "5! is " << fact(5) << std::endl;
    std::cout << func() << std::endl;
    std::cout << abs(-9.28) << std::endl;
}

//在编译时要带上所有cpp文件,此处为 g++ fact.cpp factMain.cpp
