#include<iostream>
#include <string>

using namespace std;

/*
 *	一般数据成员定义为 private;
 *		函数		   public;
 *
 *	公有成员可以在类外部如main()函数中调用；
 *	私有成员 不
 *	
 *	若类没指定，一般默认为私有的；
 */

class Sales_item
{
public:
	Sales_item(std::string book, unsigned units, double amount)
		: isbn(book), units_sold(units), revenue(amount)
	{}

	double avg_price()	const
	{
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}

	bool same_isbn(const Sales_item &rhs) const
	{
		return isbn == rhs.isbn;
	}

	void add(const Sales_item &rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
	}

private:
	std::string isbn; // 书号；
	unsigned units_sold; // 销售金额;
	double revenue; // 总金额；

};

class Person
{
	// 成员
public: 
	Person(const std::string &nm, const std::string &addr):name(nm),address(addr)
	{
		// name = nm;
		// address = addr;
	}
	std::string getName()
	{
		return name;
	}

	std::string getName() const
	{
		return name;
	}

	std::string getAdress() const
	{
		return address;
	}

private:
	std::string name;
	std::string address;
};

int main()
{
	Person a("张飞", "花园街5号");

	// cout << a.name << "," << a.address;

	cout << endl;

	cout << a.getName() << "," << a.getAdress() << endl;

	Sales_item x(std::string("dfs"), 2, 20);
	Sales_item y(std::string("dfs"), 6, 48);

	if (x.same_isbn(y))
		x.add(y);

	cout << "两个销售单的平均价:" << x.avg_price() << endl;

	cout << "Hello 类！" << endl;

	system("pause");
	return 0;
}