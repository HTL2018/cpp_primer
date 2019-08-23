#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double abs(double i)
{
    if (i<0)
    {
        i = i * (-1);
    }

    return i;
}

int main()
{

    cout << "please enter a number:" << endl;
    double i;
    if (cin >> i)
    {
        cout << abs(i) << endl;
    }
    return 0;
}
