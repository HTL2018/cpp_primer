#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::fill_n;

template<typename Sequence>
auto print(Sequence const& seq) -> std::ostream&
{
    for (const auto& i : seq)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> vec;
    list<int> lst;
    int i;
    while (cin >> i)
        lst.push_back(i);

    copy(lst.cbegin(), lst.cend(), back_inserter(vec));

    vector<int> v;
    v.reserve(10);
    fill_n(v.begin(), 10, 0);

    print(v);
    print(vec);
}
