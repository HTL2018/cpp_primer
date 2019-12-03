#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using std::vector;
using std::endl;
using std::cin;
using std::cout;

//函数功能: 在vector总的前半部分中如果发现等于some_val的值,在其前面插入2*some_val;
void double_and_insert(std::vector<int>& v,int some_val)
{
    auto mid = [&]{return v.begin() + v.size()/2;};
    for (auto curr = v.begin(); curr != mid(); ++curr)
    {
        if (*curr == some_val)
        {
            cout << "some_val_before" << *curr << endl;
            ++(curr = v.insert(curr, 2 * some_val));
            cout << "some_val_after" << *curr << endl;
            //在some_val对应的指针处插入值后,指针回到some_val对应的地址处;
        }
    }
}

int main()
{
    vector<int> v{1,9,1,9,9,9,1,1};

    double_and_insert(v, 1);

    for (auto i : v)
    {
        cout << i << endl;
    }

    return 0;
}
