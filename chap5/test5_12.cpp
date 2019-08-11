#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str1;
    getline(cin, str1);
    int ff_num = 0;
    int fl_num = 0;
    int fi_num = 0;
    if (str1.size() < 2)
    {
        cout << "None." << endl;
    }
    else
    {
        for (int i=0; i<str1.size()-1; ++i)
        {
            if (str1[i]=='f' && str1[i+1]=='f')
                ++ff_num;
            if (str1[i]=='f' && str1[i+1]=='l')
                ++fl_num;
            if (str1[i]=='f' && str1[i+1]=='i')
                ++fi_num;
        }
        cout << ff_num <<" " << fl_num << " " << fi_num << endl;
    }

    return 0;
}
