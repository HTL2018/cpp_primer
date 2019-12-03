#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::vector<std::string> v;
    for (std::string buffer; std::cin >> buffer; v.push_back(buffer))
    {
        std::cout << v.capacity() << endl;
    }

    return 0;
}
