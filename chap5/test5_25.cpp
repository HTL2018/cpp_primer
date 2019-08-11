#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>

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
        try {
            if (i2 == 0)
            {
                throw runtime_error("The second number not be 0.");
            }
            cout << float(i1)/float(i2) << endl;
        } catch (runtime_error err) {
                cout << err.what()
                     << "\nTry Again? Enter y or n" << endl;
                char c;
                cin >> c;
                if (!cin || c == 'n')
                    break;
            }

    }

    return 0;
}

