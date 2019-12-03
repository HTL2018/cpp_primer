#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::end;
using std::begin;

int main()
{
    int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };

    vector<int> vec_ia(begin(ia), end(ia));
    list<int > list_ia(begin(ia), end(ia));

    auto it = vec_ia.begin();
    auto it1= list_ia.begin();

    while(it != vec_ia.end())
    {
        if (*it % 2)
        {
            it = vec_ia.erase(it);
            it1++;
        }
        else
        {
            it1 = list_ia.erase(it1);
            it++;
        }
    }

    for (auto i : vec_ia)
    {
        cout << i << " ";
    }

    cout << endl;

    for (auto i0 : list_ia)
    {
        cout << i0 << " ";
    }

    cout << endl;
    for (auto i1 : ia)
    {
        cout << i1 << " ";
    }

    return 0;
}
