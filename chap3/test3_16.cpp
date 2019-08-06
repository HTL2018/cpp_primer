#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10,42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    cout << v1.size() << endl;
    //cout << v1 << endl;
    cout << v2.size() << endl;
    for (auto v : v2)
    {cout << v << endl;}
    cout << v3.size() << endl;
    for (auto v : v3)
    {cout << v << endl;}
    cout << v4.size() << endl;
    for (auto v : v4)
    {cout << v << endl;}
    cout << v5.size() << endl;
    for (auto v : v5)
    {cout << v << endl;}
    cout << v6.size() << endl;
    for (auto v : v6)
    {cout << v << endl;}
    cout << v7.size() << endl;
    for (auto v : v7)
    {cout << v << endl;}
    return 0;
}
