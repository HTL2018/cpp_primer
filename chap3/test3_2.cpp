#include <iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
     //一次输入一整行
    string line;

    while (getline(cin, line))
    {
        cout << line << endl;
    }


    /* //一次读入一个词
    string word;
    while(cin >> word)
    {
        cout << word << endl;
    }
    */

    return 0;
}
