#include <iostream>

using std::cin;
using std::cout;
using std::endl;

size_t count_calls(int i)
{
    static size_t ctr=0;
    int a = 0;

    while (i>0)
    {
        ctr += i;
        a += i;
        --i;
    }
    return a;
}

int main()
{
    int b;
    cout << "enter:";
    cin >> b;
    for (size_t i=0; i!=10; ++i)
        cout << count_calls(b) << endl;

    return 0;
}
