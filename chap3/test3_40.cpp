    #include <iostream>
    #include <cstddef>
    #include <vector>
    #include <iterator>
    #include <cstring>

    using std::cin;
    using std::endl;
    using std::cout;
    using std::vector;
    using std::begin;
    using std::end;
    using std::string;

int main()
{
    const char str1[] ="afsdfsda ";
    const char str2[] = "wrq ";
     char largestr[] {20};

    strcpy(largestr, str1);
    strcat(largestr, str2);

    cout << largestr << endl;

    return 0;
}
