#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string str1;
    /*
    while (cin >> str1)
    {
        cout << str1 << endl;
    }
    */

    /*
    for (;cin >> str1;)
    {
        cout << str1 << endl;
    }
    */

    /*
    for (int i=0; i<10; ++i)
    {
        cout << i << endl;
    }
    */

    int i = 0;
    while (i < 10)
    {
        cout << i << endl;
        ++i;
    }



    return 0;
}
