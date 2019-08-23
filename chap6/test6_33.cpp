#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using Iter = vector<string>::const_iterator;

void print(Iter first, Iter last)
{
    if (first != last)
    {
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
