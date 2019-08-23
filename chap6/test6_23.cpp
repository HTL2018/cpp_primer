#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;

void print_int(int i)
{
    cout << i << endl;
}

void print_array(int (&arr) [2])
{
    for (auto elem : arr)
    {
        cout << elem << endl;
    }
}

void print_array1(const int *beg, const int *end)
{
    while (beg != end)
    {
        cout << *beg++ << endl;
    }
}

void print_array2(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        cout << ia[i] << endl;
    }
}

void print_str_arr(const char *cp)
{
    if (cp)
    {
        while (*cp)
        {
            cout << *cp++;
        }
    }
}

int main()
{
    int i=0;
    int j[2]={1,2};
    char ch[5] = "pezy";

    print_int(i);
    print_array(j);
    print_array1(begin(j), end(j));
    print_array2(j, end(j)-begin(j));
    print_str_arr(ch);

    return 0;
}
