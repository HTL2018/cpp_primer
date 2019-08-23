#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void switch_num(int *p,int *q)
{
    int tran=0;
    int *trans = &tran;
    *trans = *p;
    *p = *q;
    *q = *trans;
}

int main()
{
    int i = 1, j = 2;
    switch_num(&i, &j);

    cout << i << j << endl;

    return 0;
}
