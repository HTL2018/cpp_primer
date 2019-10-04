#include "test7_13.h"
#include <stdio.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    Sales_data total(cin);
    if (!total.isbn().empty())
    {
        std::istream &is = cin;
        while(is){
            Sales_data trans(is);
            if (!is) break;
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print (cout, total) << endl;
    } else {
        cout << "No data?!" << endl;
        return -1;
    }
    return 0;
}
