#include <iostream>

using std::cin;
using std::cout;
using std::endl;

size_t count_call()
{
    static size_t ctr=-1;
    return ++ctr;
}
int main()
{
    for (size_t i=0; i!=10; ++i)
    {
        cout << count_call() << endl;
    }
    return 0;
}
