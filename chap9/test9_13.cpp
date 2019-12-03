#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::cout;
using std::endl;

int main()
{
    list<int> val_list = {1, 2, 2, 3, 4, 2};
    vector<int> val_vector(10, 1);

    vector<double> val (val_list.begin(), val_list.end());
    vector<double> val1 (val_vector.begin(), val_vector.end());

    for (auto i:val_list)
    {
        cout << i << endl;
    }

    for (auto i_vector:val_vector)
    {
        cout << i_vector << endl;
    }

    for (auto i_val:val)
    {
        cout << i_val << endl;
    }

    for (auto i_val1:val1)
    {
        cout << i_val1 << endl;
    }

    return 0;
}
