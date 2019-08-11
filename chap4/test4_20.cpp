#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v1 {1,2,3,4,5,6,7,8,9};

    int j = 0;
    for (int i=0; i<(v1).size(); ++i)
    {
        j = ((v1[i]%2)?(2*v1[i]):v1[i]);
        v1[i] = j;
    }
    for (auto i : v1)
    {
        cout << i << endl;
    }
    return 0;
}
