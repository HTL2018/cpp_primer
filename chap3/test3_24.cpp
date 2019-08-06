#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    vector<int> num_list;
    int num=0;
    while (cin >> num)
    {
        num_list.push_back(num);
    }
    /* //输出相邻对的和
    vector<int>::iterator it;
    for (auto it = num_list.begin(); it+1 != num_list.end(); ++it)
    {
        cout << (*it)+*(it+1) << endl;
    }
    */
    vector<int>::iterator it;
    auto beg = num_list.begin();
    auto end = num_list.end();
    auto mid = num_list.begin() + (end - beg)/2;//注意;此处不能写为beg+end,因为对于两个迭代器没有操作符"+"
    for (auto it = num_list.begin(); it != mid; ++it)
    {
        //因为end指向的是容器中最后一个元素中的下一个位置,所以要减去1.
        cout << *it + *(end - (it - beg)-1) << endl;
    }

    return 0;
}
