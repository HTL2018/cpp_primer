#include <iostream>
#include <cstddef>
#include <vector>
#include <iterator>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::begin;
using std::end;

int main()
{
    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    int *beg = begin(ia);
    int *last = end(ia);

    while (beg != last)
    {
        *beg = 0;
        ++beg;
    }

    for (auto i : ia)
    {
        cout << i << endl;
    }

    return 0;
}
