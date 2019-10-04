//输入的字符串如有空格,在遇到空格进行输出时会输出换行符;
#include <iostream>
#include <stdio.h>
#include <string.h>

using std::string;
using std::istream;

istream& read_file (istream& is)
{
    string buf;
    while (std::cin >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main()
{
    istream& is = read_file(std::cin);
    std::cout << is.rdstate() << std::endl;
    return 0;
}
