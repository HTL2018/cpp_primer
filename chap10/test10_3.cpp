#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::vector<int> v = { 1, 2, 3, 4 };
    std::cout << "test10_3" << " " << std::accumulate(v.cbegin(), v.cend(), 0) << std::endl;

    return 0;
}
