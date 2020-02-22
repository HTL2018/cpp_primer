#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>


using std::string;
using std::cin;
using std::cout;
using std::remove_if;
using Map = std::map<std::string, std::size_t>;

using std::string;
using std::cin;
using std::cout;
using std::remove_if;
using Map = std::map<std::string, std::size_t>;
auto count()
{
	Map counts;
	for (string w; cin >> w; ++counts[w]);
	return counts;
}

auto print(Map const& m)
{
	for (auto const& kv : m)
		cout << kv.first << " : " << kv.second << "\n";
}

int main()
{
    cout << "[test11_3] Enter a few words please: \n";
	print(count());

    return 0;
}

