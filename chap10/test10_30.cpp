#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> vec(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
    std::sort(vec.begin(), vec.end());
    std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "));
}
