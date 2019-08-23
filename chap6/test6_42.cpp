#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//注意 "s" 和 "df" 不能换为: 'df' 和 's'
string make_plural(size_t ctr, const string &word, const string &ending="s")
{
    return (ctr > 1) ? word+ending : word;
}
int main()
{
    cout << make_plural(2, "df") << endl;
    return 0;
}
