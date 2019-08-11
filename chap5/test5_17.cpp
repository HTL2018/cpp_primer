#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> v2 {1,2,3,4,5,6,7,8,9};
    vector<int> v1 {1,2,3,4,5,6};

    if (v1.size() <= v2.size())
    {
        int i = 0;
        for (; i < v1.size() && v1[i]==v2[i]; ++i)
        {
            ;
        }
        if (i = v1.size()-1)
        {
            cout << "True." << endl;
        }
        else
        {
            cout << "False." << endl;
        }
    }
    else
    {
        cout << "False." << endl;
    }
    return 0;
}

