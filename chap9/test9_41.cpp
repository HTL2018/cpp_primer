#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main()
{
    vector<char>  v {'p', 'e', 'z', 'y'};

    string str(v.cbegin(), v.cend());

    cout << str << endl;

    return 0;
}
