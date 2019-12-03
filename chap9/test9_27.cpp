#include <stdio.h>
#include <iostream>
#include <list>
#include <forward_list>

using std::endl;
using std::cin;
using std::cout;
using std::list;
using std::begin;
using std::end;
using std::forward_list;

int main()
{
    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};

    auto prev = flst.before_begin();
    auto curr = flst.begin();

    while (curr != flst.end())
    {
        if (*curr & 0x01)
        {
            curr = flst.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }

    for (auto i : flst)
    {
        cout << i << endl;
    }

    return 0;
}
