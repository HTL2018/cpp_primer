#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v1 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    auto iter = v1.begin();
    while(iter != v1.end())
    {
        if (*iter % 2)
            iter = v1.insert(iter, *iter);
        cout << 'd' << endl;
        ++iter;

    }

    for (auto i : v1)
        cout << i << " ";

    return 0;
}
