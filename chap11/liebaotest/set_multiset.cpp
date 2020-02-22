#include <iostream>
#include <set>

using namespace std;

template <typename Container>	// 此处进行函数声明，写作模板函数；
void PrintContents(const Container & c);

int main()
{
	set<int> a;
	multiset<int> ma;

	a.insert(60);
	a.insert(-1);
	a.insert(3000);
	a.insert(60);	//setcc会自动的进行排序，并且会去除掉重复的元素只保留一个；

	cout << "set里有" << a.count(3000) << "个3000" << endl;

	PrintContents(a);
	//cout << "显示set里面的数据: " << endl;
	//set<int>::const_iterator i = a.begin();
	//while (i != a.end())
	//{
	//	cout << *i << endl;
	//	++i;
	//}
	cout << endl;

	ma.insert(3000);
	ma.insert(a.begin(), a.end());
	ma.insert(3000);

	cout << "multiset里有" << ma.count(3000) << "个3000" << endl;

	cout << "显示multiset里面的数据: " << endl;

	PrintContents(ma);
	/*set<int>::const_iterator i2 = ma.begin();
	while (i2 != ma.end())
	{
		cout << *i2 << endl;
		++i2;
	}*/
	cout << endl;

	system("pause");

	return 0;
}

// 此处进行函数定义，写作模板函数；
template <typename Container>	
void PrintContents(const Container & c)
{
	Container::const_iterator i = c.begin();
	while(i != c.end())
	{
		cout << *i << endl;
		++i;
	}
	cout << endl;
}