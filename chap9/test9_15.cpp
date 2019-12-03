#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::list;

int main()
{
    vector<int> vec0 {1,2,3,4,2};
    vector<int> vec1 {1,2,4,3,2};

    if (vec0 == vec1)
    {
        cout << "=" << endl;
    }
    else
    {
        if (vec0 < vec1)
        {
            cout << "vec0 < vec1" << endl;
        }
        else
        {
            cout << "vec0 > vec1" << endl;
        }
    }

    return 0;
}

