#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    string str;
    vector<string> num_list;
    while(cin >> str)
    {
        num_list.push_back(str);
    }
    for (auto str1 : num_list)
    {
        cout << str1 << " ";
    }
    return 0;
}
