#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//文件不能执行,因为get_size的头文件未知
int main()
{
    do
    {
        int sz = get_size();
    }while (sz <= 0)

    return 0;
}
