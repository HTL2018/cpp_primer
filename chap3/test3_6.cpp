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
    for (auto &c : str1)
    {
        c = char1;
    }
    cout << str1 << endl;
    return 0;
}
