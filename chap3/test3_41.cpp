#include <iostream>
#include <vector>
#include <cstring>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;

int main()
{

    int int_arr[] = {1,2 ,2 ,3, 4, 5};
    vector<int> vec1(begin(int_arr), end(int_arr));

    for (auto i : vec1)
    {
        cout << i << endl;
    }
    return 0;
}
