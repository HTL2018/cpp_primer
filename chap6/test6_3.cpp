#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int mult(int i)
{
    int mul = 1;
    while (i>1)
    {
        mul = mul *i;
        --i;
    }
    return mul;
}

int main()
{
    cout << "please enter a intergate:" << endl;
    int i=1;
    if(cin >> i)
    {

        if (i > 0)
        {
            cout << mult(i) << endl;
        }
    }

    return 0;
}
