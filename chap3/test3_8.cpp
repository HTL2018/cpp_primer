#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{

    string str1;
    char char1='X';

    getline(cin , str1);
    /*
    for (auto &c : str1)
    {
        c = char1;
    }
    */

    /* //传统for循环实现
    for (int i=0; i < str1.size(); i++)
    {
        str1[i] = char1;
    }
    cout << str1 << endl;
    */
    int i = 0;
    // 此处最好还是:decltype(str.size()) i = 0; 尽量不要把i定义成int型的.
    while(i < str1.size())
    {
        str1[i] = char1;
        i++;
    }
    cout << str1 << endl;
    return 0;
}
