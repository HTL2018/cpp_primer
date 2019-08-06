#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int i = 0;
    vector<int> num_list;
    while(cin >> i)
    {
        num_list.push_back(i);
    }
    for (auto i : num_list)
    {
        cout << i << " ";
    }
    return 0;
}
