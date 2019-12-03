#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <list>

using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    list<const char*> old  {"a","b","c"};
    vector<string> new_val;

    new_val.assign(old.begin(), old.end());

    for (auto p : new_val)
    {
        cout << p << endl;
    }

    return 0;
}
