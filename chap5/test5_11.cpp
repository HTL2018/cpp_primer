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
    int acnt = 0;
    int ecnt = 0;
    int icnt = 0;
    int ocnt = 0;
    int ucnt = 0;
    int line = 0;
    int tab = 0;
    int space1 = 0;
    for (auto i : str1)
    {
        if (i == 'i' || i== 'I')
        {
            ++icnt;
        }
        else if (i == 'o'|| i == 'O' )
        {
            ++ocnt;
        }
        else if (i == 'a'|| i == 'A')
        {
            ++acnt;
        }
        else if (i== 'u' || i == 'U')
        {
            ++ucnt;
        }
        else if (i=='e' || i == 'E')
        {
            ++ecnt;
        }
        else if (i == ' ')
        {
            space1++;
        }
        else if (i == '\t')
        {
            tab++;
        }
        else if (i == '\n')
        {
            line++;
        }

    }
    cout << acnt << ecnt << icnt << ocnt << ucnt << endl;
    cout << line << tab << space1 << endl;
    cout << acnt+ecnt+icnt+ocnt+ucnt << endl;
    return 0;
}
