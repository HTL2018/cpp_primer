#include <iostream>

using std::cin;
using std::endl;
using std::cout;
using std::begin;
int main()
{
    int ia[3][4] =
        {
        { 0, 1, 2, 3 },
        { 4, 5, 6, 7 },
        { 8, 9, 10, 11 }
    };
    /* //范围for循环
    for (const int (&row)[4] : ia )
        for (int col : row )
            cout << col << endl;
    */

    /* //使用下标
    for (size_t i =0 ; i != 3; ++i)
        for (size_t j = 0; j != 4; ++j)
        {
            cout << ia[i][j] << endl;
        }
    */

    for (int (*i)[4] = ia; i != ia+3; ++i )
        for (int *j = *i; j != *i+4; ++j)
        {
            cout << *j << endl;
        }
    return 0;
}
