#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_item
{
public:
	// 公有成员

	// 构造函数
	Sales_item():units_sold(0),revenue(0.0)
	{
		cout << "默认的构造函数被调用了！" << endl;
	}
	Sales_item(const std::string &book):isbn(book),units_sold(0),revenue(0.0)
	{
		cout << "构造函数Sales_item(const std::string &book)被调用了！" << endl;
	}

	// 复制构造函数
	Sales_item(const Sales_item &orig) :isbn(orig.isbn), units_sold(orig.units_sold), revenue(orig.revenue)
	{
		cout << "复制构造函数被调用了！" << endl;
	}
	// 赋值操作符
	Sales_item& operator=(const Sales_item &rhs)
	{
		cout << "赋值操作符被调用了！" << endl;
		isbn = rhs.isbn;
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
		return *this;
	}

private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};

class NoName
{
public:
	NoName():pstring(new std::string),i(0),d(0){}
	
	NoName(const NoName& other)
		:pstring(new std::string(*(other.pstring))),i(other.i),d(other.d)
	{
		cout << "NoName Copy Constructor" << endl;
	}
	
	NoName& operator=(const NoName &rhs)
	{
		cout << "NoName 赋值操作符" << endl;
		// 重点：重要的就是这两行，如果不自己再定义赋值操作符，就不会把 指针所指的字符串 赋值；
		// c++自己默认生成的赋值操作符的效果类似于： pstring = rhs.pstring;
		pstring = new std::string;
		*pstring = *(rhs.pstring);

		i = rhs.i;
		d = rhs.d;
		return *this;
	}

private:
	std::string *pstring;
	int i;
	double d;
};

Sales_item foo(Sales_item &item)
{
	Sales_item temp;
	temp = item;
	return temp;
}

int main()
{
	NoName x, y;
	NoName z(x);
	x = y;

	Sales_item a;
	Sales_item b("book-123");

	Sales_item c(b);
	a = b;
	Sales_item item = string("book-HTL");

	cout << endl << "试一下foo:" << endl;
	Sales_item ret;
	ret = foo(item);

	cout << endl << "试一下vector:" << endl;
	vector<Sales_item> svec(5);

	cout << endl << "试一下数组:" << endl;
	Sales_item primer_eds[] = {
		string("HTL001"),
		string("HTL002"),
		string("HTL003"),
		Sales_item()
	};
	
	return 0;
}