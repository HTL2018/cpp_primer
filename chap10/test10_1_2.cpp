#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

int main()
{
    //std::vector<int> v = {1, 2, 3, 4, 5, 6, 6, 6, 2};
    //std::cout << "test 10.01" << " "<< std::count(v.cbegin(), v.cend(), 6) << std::endl;

    std::list<std::string> l = {"aaa", "aaa", "aa", "cc"};
    std::cout << "test10_1_vector" << " " << std::count(l.cbegin(), l.cend(), "aa") << std::endl;

    return 0;
}
