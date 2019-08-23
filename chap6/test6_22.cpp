#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int*& p,int*& q)
{
    int trans=0;
    trans = *p;
    *p = *q;
    *q = trans;
}

int main()
{
    int i = 2;
    int j = 3;

    int *i1 = &i;
    int *j1 = &j;

    swap(i1, j1);
    cout << *i1 << " " << *j1 << endl;
    return 0;
}
