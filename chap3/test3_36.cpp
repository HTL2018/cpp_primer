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

/*  //比较数组是否相等
int main()
{
    int num1[] = {1, 2, 3};
    int ib[] = {1, 2, 3};
    int ic[] = {1, 3};
    int num2[] = {1, 2, 4};

    int *beg = begin(num1);
    int *last = end(num1);
    int *beg1 = begin(num2);
    int *last1 = end(num2);

    if (last-beg != last1-beg1)
    {
        cout << "not equal" << endl;
    }
    else
    {
        while (beg != last && (*beg == *beg1))
        {
            ++beg;
            ++beg1;
        }
        if (beg == last)
        {
            cout << "equal" << endl;
        }
        else
        {
            cout << " not equal" << endl;
        }
    }
    return 0;
}
*/

int main()
{
    vector<int> val1 {1, 2, 3};
    vector<int> val2 {1,2,3};
    vector<int> val3 {1, 2};
    vector<int> val4 {1, 2, 4};

    vector<int> v1(val1);
    vector<int> v2(val4);
    if (v1.size() != v2.size())
    {
        cout << "not equal"<< endl;
    }
    else
    {
        int i = 0;
        while (i != v1.size() && v1[i]==v2[i])
        {
            ++i;
        }
        if (i == v1.size())
        {
            cout << "equal" << endl;
        }
        else
        {
            cout << "not equal" << endl;
        }
    }
}

