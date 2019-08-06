#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> num_list;
    int num1 = 0;
    while (cin >> num1)
    {
        num_list.push_back(num1);
    }

    if (num_list.empty())
    {
        cout << "no integer." << endl;
        return -1;
    }

    if (num_list.size() == 1)
    {
        cout << "only 1 integer." << endl;
        return -1;
    }

    /* //输出相邻对的数之和
    for (int i=0; i<num_list.size()-1; ++i)
    {
        cout << num_list[i]+num_list[i+1] << " ";
    }
    */
    for (int i=0; i<num_list.size()/2; ++i)//此处如果总数为奇数,中间位置的数舍弃了
    {
        cout << num_list[i]+num_list[num_list.size()-i-1] << " ";
    }

    return 0;
}
