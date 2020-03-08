#include <iostream>
#include <string>

using namespace std;

class Item_base
{
public:
	int x;
	Item_base(const std::string &book = "",
		double sales_price = 0.0) :isbn(book), price(sales_price) {}
	std::string book() const
	{
		return isbn;
	}
	// virtual：定义为虚函数，则在派生类中可以对其进行重新定义；
	virtual double net_price(size_t n) const
	{
		return n * price;
	}
private:
	string isbn;
protected:
	double price;
};

class Bulk_item : public Item_base
{
public:
	// 派生类的构造函数；
	Bulk_item(const std::string &book = "", double sales_price = 0.0, size_t qty = 0,
		double disc_rate = 0.0) :Item_base(book, sales_price), min_qty(qty), discount(disc_rate) {}

	void test()
	{
		// cout << x << endl;
		cout << price << endl;	// 成员函数，可以使用父类中的protected成员；
		// cout << isbn << endl;	// 但是不能使用父类中的private成员；
	}

	void test2(const Bulk_item &d, const Item_base &b)
	{
		//cout << d.x << endl;
		cout << d.price << endl;
		//cout << b.x << endl;	// public成员没问题；
		//cout << b.price << endl;	// 错误；protected成员可以在类的内部使用或者是对它的友元使用，可以被继承，但是不能被调用；
	}
	// 只有虚函数才能够重写；
	double net_price(size_t cnt) const
	{
		if (cnt >= min_qty)	//如果购买的数量大于最小打折数量，则打折；
			return cnt * (1 - discount) *price;
		else
			return cnt * price;
	}
private:
	size_t min_qty;
	double discount;
};

void print_total(ostream &os, Item_base *item, size_t n)
{
	os << "ISBN:" << item->book() << "\tnumber sold:" << n << "\ttotal price:" << item->net_price(n) << endl;
}

int main()
{
	Item_base* a = new Item_base("HTL2018-006", 11.0);
	Bulk_item* b = new Bulk_item("HTL2018-007", 22.0, 2, 0.05);

	print_total(cout, a, 2);
	print_total(cout, b, 3); // 动态绑定：在定义的时候print_total是指向基类对象的指针或者引用，
							//   在调用的时候可以根据情况调用基类对象的虚函数，也可以根据情况调用派生对象的虚函数；

	// 数组中有5个指针，都指向基类对象的指针，其可以指向基类的对象，也可以指向该基类的派生类对象；（非常重要）
	Item_base* books[5];
	books[0] = new Item_base("HTL2018-001", 10.0);
	books[1] = new Bulk_item("HTL2018-002", 20.0, 6, 0.05);
	books[2] = new Item_base("HTL2018-003", 30.0);
	books[3] = new Bulk_item("HTL2018-004", 40.0, 4, 0.15);
	books[4] = new Bulk_item("HTL2018-005", 50.0,2,0.18);

	int num[5];
	num[0] = 2;
	num[1] = 10;
	num[2] = 1;
	num[3] = 5;
	num[4] = 3;

	cout << endl;
	for (int i = 0; i < 5; i++)
	{	// 在调用的时候会根据books[i]是传入的基类对象还是派生类对象，动态调用相应的函数；实现的效果就是多态；
		print_total(cout, books[i], num[i]);
	}

	return 0;
}