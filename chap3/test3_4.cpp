#include <iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    /* //输出较大字符
    if (str1 == str2)
    {
        cout << "The two string are same." << endl;
    }
    else
    {
        if (str1 > str2)
        {
            cout << str1 << endl;
        }
        else
        {
            cout << str2 << endl;
        }
    }
    */

    if (str1.size() == str2.size())
    {
        cout << "Length is same." << endl;
    }
    else
    {
        if (str1.size() > str2.size())
        {
            cout << str1 << endl;
        }
        else
        {
            cout << str2 <<endl;
        }
    }
    return 0;
}
