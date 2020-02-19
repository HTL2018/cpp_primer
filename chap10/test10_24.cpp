#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::find_if;
using std::bind;
using std::size_t;

auto check_size(string const& str, size_t sz)
{
    return str.size() < sz;
}

int main()
{
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7};
    string str("123456");
    auto result = find_if(vec.begin(), vec.end(), bind(check_size, str, std::placeholders::_1));
    if (result != vec.end())
        cout << *result << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
