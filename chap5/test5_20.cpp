#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string str1,str2;
    int flag = 0;
    while (cin >> str1)
    {
        if (str1 == str2)
        {
            cout << str1 << endl;
            flag = 1;
            break;
        }
        str2 = str1;
    }
    if (flag == 0)
    {
        cout << "no same." << endl;
    }
}
