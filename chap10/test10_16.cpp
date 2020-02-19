#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 读取输入后，调用unique，erase后打印vector的内容；
void elimdups(std::vector<std::string> &vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

void biggies(std::vector<std::string> &vs, std::size_t sz)
{
    using std::string;
    elimdups(vs);

    // 根据长度进行排序，同样长度的按字母序进行排列；
    std::stable_sort(vs.begin(), vs.end(), [](string const& lhs, string const& rhs){
            return lhs.size() < rhs.size();
            });

    // 返回第一个长度大于等于 sz 的迭代器；
    auto wc = std::find_if(vs.begin(), vs.end(), [sz](string const& s){
            return s.size() >= sz;
            });

    // 输出 biggies;
    std::for_each(wc, vs.end(), [](const string&s){
            std::cout << s << " ";
            });

}

int main()
{
    std::vector<std::string> v
    {
        "1234", "1234", "1234", "hi~", "alan", "cp"
    };
    std::cout << "test10_16.cpp: ";
    biggies(v, 3);
    std::cout << std::endl;

    return 0;
}
