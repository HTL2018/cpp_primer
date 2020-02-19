#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    //注意:输出结果是9,而不是期望的10
    //因为std::accumulate is a template function. The third parameter is _Tp __init
    // When "0" , an integer, had been specified here, the compiler deduced _Tp as
    // interger.As a result , when the following statments were being excuted :
    //  for (; __first != __last; ++__first)
    //  __init = __init + *__first;
    //  return __init;
    // all calculation would be converted to integer.:

    std::vector<double> vd = {1.0, 3.3, 5.7};
    std::cout << "test10_4 " << std::accumulate(vd.cbegin(), vd.cend(), 0) << std::endl;

    return 0;
}
