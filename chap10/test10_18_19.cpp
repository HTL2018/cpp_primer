#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 读取输入后，调用unique，erase后打印vector的内容;
void elimdups(std::vector<std::string> &vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

void biggies_partition(std::vector<std::string> &vs, std::size_t sz)
{
    elimdups(vs);

    auto privot = partition(vs.begin(), vs.end(), [sz](const std::string &s){
            return s.size() >= sz;
            });

    for(auto it = vs.cbegin(); it != privot; ++it)
        std::cout << *it << " ";
}

void biggies_stable_partition(std::vector<std::string> &vs, std::size_t sz)
{
    elimdups(vs);

    auto privot = stable_partition(vs.begin(), vs.end(), [sz](const std::string &s){
            return s.size() >= sz;
            });

    for(auto it = vs.cbegin(); it != privot; ++it)
        std::cout << *it << " ";
}

int main()
{
    // test10.18
    std::vector<std::string> v{
        "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"
    };

    std::cout << "test10.18: ";
    std::vector<std::string> v1(v);
    biggies_partition(v1, 4);
    std::cout << std::endl;

    // test10.19
    std::cout << "test10.19: ";
    std::vector<std::string> v2(v);
    biggies_stable_partition(v2, 4);
    std::cout << std::endl;

    return 0;
}
