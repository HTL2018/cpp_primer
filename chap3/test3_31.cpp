#include <iostream>
#include <cstddef>

using std::cin;
using std::endl;
using std::cout;

int main()
{
    int num[10]={};
    for (size_t i = 0; i < 10; ++i)
    {
        num[i] = i;
    }
    for (size_t i1 = 0; i1 < 10; ++i1)
    {
        cout << num[i1] << " ";
    }
    return 0;
}
