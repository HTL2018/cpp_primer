#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    vector<int> v1 (10,4);
    for (auto it = v1.begin(); it != v1.end(); ++it)//利用迭代器改变容器中的值
    {
        *it = 2 * (*it);
    }

    for (auto i : v1)//输出容器中的每一个值
    {
        cout << i << endl;
    }

    return 0;
}
