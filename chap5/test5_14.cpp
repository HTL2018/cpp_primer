#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string str1,str2;
    int cnt_same1 = 0;
    int cnt = 1;
    int first_time = 0;
    string same_str1=" ", same_str2=" ";
    while (cin >> str1)
    {
        if (str1 == str2)
        {
            ++cnt;
            if (!first_time)
            {
            same_str1 = str2;
            cnt_same1 = cnt;
            first_time = first_time + 1;
            }
            else if (first_time)
            {
            if (cnt > cnt_same1)
            {
                same_str1 = str2;
                cnt_same1 = cnt;
            }

            }
        }

        else if(cnt > 1)
        {
            cnt = 1;
        }
        str2 = str1;
    }

    if (cnt_same1 == 1)
    {
        cout << "no same." << endl;
    }
    else
    {
        cout << same_str1 << "  " << cnt_same1 << endl;
    }

    return 0;
}
