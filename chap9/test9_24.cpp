#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec0;

    cout << vec0.at(0) << endl;
    cout << vec0[0] << vec0.front() << *vec0.begin() << endl;

    return 0;
}
