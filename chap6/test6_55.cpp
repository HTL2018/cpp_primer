#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int func(int a, int b);

int add(int a, int b)
{
    return (a+b);
}

int subtract(int a, int b)
{
    return (a-b);
}

int mul(int a, int b)
{
    return (a*b);
}

int divide(int a, int b)
{
    return (b!=0 ? (a/b) : 0);
}


using pFunc1 = int(*)(int a, int b);
typedef decltype(func) *pFunc2;
using pFunc3 = int(int a, int b);
using pFunc4 = decltype(func) *;
typedef int(*pFunc5) (int a, int b);
using pFunc6 = decltype(func);

vector<pFunc1> vec1;
vector<pFunc2> vec2;
vector<pFunc3*> vec3;
vector<pFunc4> vec4;
vector<pFunc5> vec5;
vector<pFunc6*> vec6;


int main()
{
    vector<decltype(func) *> vec{add, subtract, mul, divide};
    for (auto f: vec)
        std::cout << f(2,2) << std::endl;

    return 0;
}
