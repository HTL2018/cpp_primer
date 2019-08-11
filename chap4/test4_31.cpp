#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec (10,1);
    vector<int>::size_type cnt = ivec.size();
    cout << cnt << endl;
    for (vector<int>::size_type ix=0; ix != ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;

    for (auto i : ivec)
    {
        cout << i << endl;
    }

    return 0;
}
