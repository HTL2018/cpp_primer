#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // 改变了c的值,但是没有改变字符串
    string str1;
    char char1='X';

    getline(cin , str1);
    for (char c : str1)
    {
        c = char1;
    }
    cout << str1 << endl;
    return 0;
}
