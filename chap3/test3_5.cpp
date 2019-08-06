#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string str1, str2;
    getline(cin, str1);
    while(getline(cin, str2))
    {
        str1 = str1 + ' ';
        str1 += str2;
    }
    cout << str1 << endl;
    return 0;
}
