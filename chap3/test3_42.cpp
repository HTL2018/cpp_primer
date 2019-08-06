#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec1 {1, 2, 3, 4, 2,3,4,5,6};
    int len1 = vec1.size();

    int ca[len1];

    int index1 = 0;

    for (auto i : vec1)
    {
        ca[index1] = i;
        ++index1;
    }

    for (auto i1 : ca)
        cout << i1 << endl;

    return 0;
}
