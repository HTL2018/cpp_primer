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
    cin >> str1;
    int acnt = 0;
    int ecnt = 0;
    int icnt = 0;
    int ocnt = 0;
    int ucnt = 0;
    for (auto i : str1)
    {
        if (i == 'i')
        {
            ++icnt;
        }
        else if (i == 'o')
        {
            ++ocnt;
        }
        else if (i == 'a')
        {
            ++acnt;
        }
        else if (i== 'u')
        {
            ++ucnt;
        }
        else if (i=='e')
        {
            ++ecnt;
        }
    }
    cout << acnt << ecnt << icnt << ocnt << ucnt << endl;
    cout << acnt+ecnt+icnt+ocnt+ucnt << endl;
    return 0;
}
