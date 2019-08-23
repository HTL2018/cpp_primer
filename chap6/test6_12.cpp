#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void switch_num(int &i,int &j)
{
    int trans = 0;
    trans = i;
    i = j;
    j = trans;
}
int main()
{
    int i = 0;
    int j = 0;
    cin >> i >> j ;
    switch_num(i, j);
    cout << i << " " << j << endl;
    return 0;
}
