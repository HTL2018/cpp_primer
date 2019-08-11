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
    cout << "Please enter two string:" << endl;
    cin >> str1 >> str2;
    do
    {
        if (str1.size() < str2.size())
        {
            cout << str1 << endl;
        }
        else if (str1.size() == str2.size())
        {
            cout << "same length" << endl;
        }
        else
        {
            cout << str2 << endl;
        }
    }while (cin >> str1 >> str2);

    return 0;
}
