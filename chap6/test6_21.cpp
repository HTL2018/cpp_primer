#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int compare(const int i,const int *j)
{
    if (i > *j)
    {
        return (i);
    }
    else
    {
        return (*j);
    }
}

int main()
{
    int i1 , j1;
    int max_num;
    cin >> i1;
    cin >> j1;
    max_num = compare(i1, &j1);
    cout << max_num << endl;
    return 0;
}
