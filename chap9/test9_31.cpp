#include <iostream>
#include <stdio.h>
#include <list>
#include <forward_list>

using std::endl;
using std::cin;
using std::cout;
using std::list;
using std::forward_list;

int main()
{
    /*
    list<int> lis = { 0,1,2,3,4,5,6,7,8,9};
    auto iter = lis.begin();

    while(iter != lis.end())
    {
        if (*iter % 2)
        {
            iter =  lis.insert(iter, *iter);
            iter = next(iter, 2);
        }
        else
        {
            iter = lis.erase(iter);
        }
    }

    for (auto i : lis)
    {
        cout << i << endl;
    }
    */

    forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
    auto iter = flst.before_begin();
    auto curr = flst.begin();

    while(curr != flst.end())
    {
        if (*curr & 0x01)
        {
            iter = flst.insert_after(curr, *curr);
            curr++;
            curr++;
        }
        else
        {
            curr = flst.erase_after(iter);
            //iter = curr -1;
       }
    }

    for (auto i : flst)
    {
        cout << i << endl;
    }

    return 0;
}
