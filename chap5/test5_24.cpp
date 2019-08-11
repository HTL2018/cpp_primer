#include <iostream>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;

int main()
{
    int i1=0;
    int i2 = 0;

    while (cin >> i1 >> i2)
    {
        if (i2 == 0)
        {

            break;
        }
        cout << float(i1)/float(i2) << endl;

    }

    return 0;
}

