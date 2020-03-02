#include <iostream>

using namespace std;

class Person
{
	// 重载操作符：加法
public:
	// 注意：1.传入的应该是引用；2.传入参数写一个就行，第一个默认在this指针中；
	void operator+(const Person& rhs)
	{
		cout << "执行了重载的加法操作" << endl;
	}
};

int main()
{
	int a, b;
	a = 12;
	b = 9;
	cout << a + b << endl;
	
	Person p1, p2;
	
	p1 + p2;

	cout << "Hello HTL2018" << endl;

	return 0;
}