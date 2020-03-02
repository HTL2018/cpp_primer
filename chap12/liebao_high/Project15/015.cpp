#include <iostream>
#include <string>

using namespace std;

class Dog
{

};

class Sales_item
{
// 需要将重构操作符的函数设为友元函数，这样才能访问类的私有成员；
friend ostream& operator<<(ostream& out, const Sales_item& s);
friend istream& operator>>(istream& in, Sales_item& s);

public:
	Sales_item(string book, unsigned units, double price):
		isbn(book),units_sold(units),revenue(units * price){}
	Sales_item():units_sold(0),revenue(0.0){}
private:
	string	isbn;
	unsigned units_sold;
	double revenue;
};

// 返回类型必须为 ostream&,且第一个参数类型为ostream&;
ostream& operator<<(ostream& out, const Sales_item& s)
{
	out << s.isbn << "\t" << s.units_sold << "\t" << s.revenue;
	return out;
}

// 输出操作符设为const,输入不再设为const，因为输入要进行改变；
istream& operator>>(istream& in, Sales_item& s)
{
	double price;
	in >> s.isbn >> s.units_sold >> price;
	// 检查输入错误
	if (in)
		s.revenue = s.units_sold * price;
	else // 如果输入错误，返回为空字符串，0,0.0
		s = Sales_item();
	s.revenue = s.units_sold * price;

	return in;
}

int main()
{
	Dog a;
	int b = 0;

	cout << "hello HTL2018" << endl;

	Sales_item item(string("0-201-78354-X"),2,25.00);
	// 此时就可以进行输出，因为上面已经定义了输出操作符的重构函数；
	cout << item << endl;

	cin >> item;
	cout << item << endl;

	//cout << a << endl; // 此处不能直接输出 a ，因为没有定义a的输出操作符的重载，程序不知道如何输出；
	cout << b << endl;

	return 0;
} 