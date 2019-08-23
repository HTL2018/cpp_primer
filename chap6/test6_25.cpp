#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    string str1;

    for (int i = 1; i != argc; ++i)
        str1 += string(argv[i]) + " ";

    cout << str1 << endl;
    return 0;
}
