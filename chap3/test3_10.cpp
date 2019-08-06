#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{

    string str1;
    string str2;

    getline(cin , str1);
    for (auto c : str1)
    {
        if (!ispunct(c))
        {
            str2 = str2 + c;
        }
    }
    cout << str1 << endl;
    cout << str2 << endl;
    return 0;
}
