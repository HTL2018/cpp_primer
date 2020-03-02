#include <iostream>
#include <string>

using namespace std;

class Dog
{
};

class Cat
{
};

class Sales_item {
public:
	Sales_item(const std::string &book, const unsigned units, const double amount)
		:isbn(book), units_sold(units), revenue(amount) {}
	Sales_item& operator+=(const Sales_item&);
	Sales_item& operator-=(const Sales_item&);
	friend std::ostream& operator<< (std::ostream&, const Sales_item&);
private:
	std::string isbn;
	unsigned units_sold;
	double revenue;

};
// 把 += 运算符定义为成员函数，把 + 运算符定义为非成员函数；这是使用习惯；
// 因为 +=  一般改变了原有对象的数据，而 + 则没有，所以 += 定义为成员函数，而 + 定义为非成员函数；
Sales_item operator+(const Sales_item&, const Sales_item&);
Sales_item operator-(const Sales_item&, const Sales_item&);

std::ostream& operator<< (std::ostream& out, const Sales_item& s)
{
	out << s.isbn << "\t" << s.units_sold << "\t" << s.revenue;
	return out;
}

Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
	// 此处默认使用 this 指针，等效于：this->units_sold += rhs.units_sold;
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

// 注意此处绝对不能返回一个引用，因为加的结果存到了一个新的对象里；
Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret += rhs;
	return ret;
}

Sales_item& Sales_item::operator-=(const Sales_item& rhs)
{
	// 此处第一个参数默认使用 this 指针；
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}

// 注意此处绝对不能返回一个引用，因为加的结果存到了一个新的对象里；
Sales_item operator-(const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret -= rhs;
	return ret;
}

int main()
{
	Dog dog;
	Cat cat;

	int a = 12, b = 6, c;
	c = a + b;

	Sales_item item1(string("0-201-12345-X"), 10, 120.0);
	Sales_item item2(string("0-201-12345-X"), 20, 200.0);

	// 验证重载的 + 运算符；
	Sales_item result = item1 + item2;
	cout << result << endl;

	// 验证重载的 += 运算符；
	Sales_item item3(string("0-201-12345-X"), 5, 70.0);
	result += item3;
	cout << result << endl;

	// 测试 重载的 -= 运算符；
	result -= item2;
	cout << result << endl;

	// 测试 重载的 - 运算符；
	result = item2 - item1;
	cout << result << endl;

	return 0;
}