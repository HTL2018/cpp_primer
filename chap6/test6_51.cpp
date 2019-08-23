#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void f()
{
    cout << "nothing" << endl;
}

void f(int a)
{
    cout << a << endl;
}

void f(int a, int b)
{
    cout << a << b << endl;
}

void f(double a, double b)
{
    cout << a << b << endl;
}

int main()
{
    //f(2.22, 42);
    return 0;
}
