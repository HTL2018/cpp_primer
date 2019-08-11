#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int i1=0;
    int i2 = 0;

    while (cin >> i1 >> i2)
    {
        if (i2 == 0)
        {
            cout << "The second number can not be 0." << endl;
            break;
        }
        else
        {
            cout << float(i1)/float(i2) << endl;
        }
    }

    return 0;
}
