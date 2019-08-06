#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

int main()
{
    vector<int> vec1;
    for (decltype(vec1.size()) ix=0; ix != 10; ++ix)
        vec1.push_back(ix);

    vector<int> vec2(10,42);
    vector<int> vec3{42,42,42,42,42,42,42,42,42,42};
    return 0;
}
