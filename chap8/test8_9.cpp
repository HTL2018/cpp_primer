#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>

using std::istringstream;

istringstream& read_string (istringstream& is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main()
{
    istringstream iss("hello");
    read_string(iss);

    return 0;
}
