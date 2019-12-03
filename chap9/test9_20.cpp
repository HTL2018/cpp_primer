#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <deque>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::deque;
using std::string;
using std::list;

int main()
{
    list<int> list0 = {1,2,3,4,5,6,7,8,9};
    deque<int> deque0, deque1;

    for (auto i : list0)
    {
        if (i % 2 == 0)
        {
            deque0.push_back(i);
        }
        else
        {
            deque1.push_back(i);
        }
    }

    for (auto d : deque0)
    {
        cout << d << endl;
    }

    for (auto d0 : deque1)
    {
        cout << d0 << endl;
    }

    return 0;
}

