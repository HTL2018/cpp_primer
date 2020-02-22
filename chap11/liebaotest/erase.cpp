#include <iostream>
#include <set>

using namespace std;

typedef multiset<int> MSETINT;

int main()
{
	MSETINT a;
	
	a.insert(43);
	a.insert(78);
	a.insert(78);
	a.insert(-1);
	a.insert(124);

	MSETINT::const_iterator i;

	cout << "multiset里有" << a.size() << "个数据。" << endl;
	cout << "每一个数据是： " << endl;
	for (i = a.begin(); i != a.end(); ++i)
		cout << *i << endl;

	cout << "要删除的数据是：";
	int nNumberToErase = 0;
	cin >> nNumberToErase;

	a.erase(nNumberToErase);
	cout << "删除后：" << endl;
	cout << "multiset里有" << a.size() << "个数据。" << endl;
	cout << "每一个数据是： " << endl;
	for (i = a.begin(); i != a.end(); ++i)
		cout << *i << endl;

	return 0;

}