#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    vector<int> vec1_list;
    int val1 = 0;
    while (cin >> val1)
    {
        if (val1 <= 100)
        {
            vec1_list.push_back(val1);
        }
    }

    vector<int>::iterator it;
    for (auto it=vec1_list.begin(); it!=vec1_list.end(); ++it)
    {
        *it = *it / 10;
    }

    for (auto it=vec1_list.begin(); it!=vec1_list.end(); ++it)
    {
        cout << *it << endl;
    }


    return 0;
}
