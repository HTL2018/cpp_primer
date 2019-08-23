#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;

int Sum_int(initializer_list<int> il)
{
    int sum = 0;
    for (auto beg = il.begin(); beg != il.end(); ++beg)
    {
        sum += *beg;
    }
    return sum;
}

int main()
{
    int sum1 = 0;

    sum1 = Sum_int({1, 2, 3, 4, 5});

    cout << sum1 << endl;

    return 0;
}
