#include <iostream>
#include <set>

using namespace std;

typedef set<int> SETINT; // 定义别名；
int main()
{
	SETINT a;

	a.insert(43);
	a.insert(78);
	a.insert(-1);
	a.insert(124);

	SETINT::const_iterator i;

	for (i = a.begin(); i != a.end(); ++i)
	{
		cout << *i << endl;
	}

	SETINT::iterator i_found = a.find(78);	// find 可以用来对数据进行查找，但是不能对查找到的数据进行修改，因为set是进行排序了的。
	if (i_found != a.end())
	{
		cout << "找到了：" << *i_found << endl;
	}
	else
		cout << "没找到。" << endl;
}