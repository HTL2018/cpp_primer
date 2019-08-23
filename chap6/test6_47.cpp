#include <iostream>
#include <vector>
#define NDEBUG

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using Iter = vector<string>::const_iterator;

void print(Iter first, Iter last)
{
#ifndef NDEBUG
    cout << __func__ << ": array size is " <<endl;
#endif
    if (first != last)
    {
        cout << (last - first) << endl;
        cout << *first << " ";
        print(first+1, last);
    }
}

int main()
{

    vector<string> vec1 {"fa", "sdf","dsfa"};
    print(vec1.cbegin(),vec1.cend());

    return 0;
}
