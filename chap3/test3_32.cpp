#include <iostream>
#include <cstddef>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::vector;

/* //数组拷贝
int main()
{
    int num[10]={};
    for (size_t i = 0; i < 10; ++i)
    {
        num[i] = i;
    }

    int num0[10]={};
    for (size_t i0 = 0; i0 < 10; ++i0)
    {
        num0[i0] = num[i0];
    }

    for (size_t i1 = 0; i1 < 10; ++i1)
    {
        cout << num[i1] << " ";
        cout << num0[i1] << " ";
    }
    return 0;
}
*/

// vector实现
int main()
{
    vector<int> val;
    for (int i=0; i != 10; ++i)
    {
        val.push_back(i);
    }

    // 拷贝可以通过初始化时: vector<int> val1(val) 直接实现
    vector<int> val1(10);
    for (int i1 = 0; i1 != 10; ++i1)
    {
        val1[i1] = val[i1];
    }

    for (int i2 = 0; i2 != 10; ++i2)
    {
        cout << val[i2] << " ";
        cout << val1[i2] << " ";
    }
    return 0;
}
