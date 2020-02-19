#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::fill_n;
using std::vector;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    fill_n(v.begin(), v.size(), 0);

    for (auto i : v)
        cout << v[i] << endl;

    return 0;
}
