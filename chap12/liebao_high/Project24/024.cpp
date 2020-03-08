#include <iostream>

using namespace std;

class Dog
{
public:
	Dog(string n, int a, double w):name(n),age(a),weight(w){}
	operator int() const	// 转换函数；
	{
		return age; // 此处转换操作符的函数返回值必须是整型；
	}
	operator double() const	// 转换函数；
	{
		return weight; // 此处转换操作符的函数返回值必须是整型；
	}

private:
	int age;
	double weight;
	string name;
};

int main()
{
	int a, b;
	double c = 0.0;
	
	a = 10;
	b = a;

	Dog d("Bill",6,15.0);
	// 调用第一个转换函数；
	b = d;
	cout << b << endl;
	// 调用第二个转换函数
	c = d;
	cout << c << endl;
	 
	return 0;
}