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

// 此处传入的是对象 item；
void print_total_1(ostream &os, const Item_base item, size_t n)
{
	os << "ISBN: " << item.book() << "\tnumber sold: " << n << "\ttotal price: " << item.net_price(n) << endl;
}
// 此处传入的是指针 *item；
void print_total_2(ostream &os, const Item_base *item, size_t n)
{
	os << "ISBN: " << item->book() << "\tnumber sold: " << n << "\ttotal price: " << item->net_price(n) << endl;
}
// 此处传入的是引用 &item；
void print_total_3(ostream &os, const Item_base &item, size_t n)
{
	os << "ISBN: " << item.book() << "\tnumber sold: " << n << "\ttotal price: " << item.net_price(n) << endl;
}

int main()
{
	Item_base item("asdf", 9.9);
	Bulk_item item2("asdf", 9.9, 10, 0.12);

	// 所以在动态绑定，多态的时候，不要用对象转换，可以用指针转换或者引用转换；
	print_total_1(cout, item, 10);
	print_total_1(cout, item2, 10);	 // 此处传入的 item 是派生类，派生类到基类可以自动转换；这是对象转换，对象转换有问题！（此处应该打折，但是没有打折）

	cout << endl;
	print_total_2(cout, &item, 10); // 传入的就是基类，没有问题；
	print_total_2(cout, &item2, 10);	 // 此处传入的 item 是派生类，派生类到基类可以自动转换；这是指针转换，打折了，没有问题。

	cout << endl;
	print_total_3(cout, item, 10);	// 传入的就是基类，没有问题；
	print_total_3(cout, item2, 10);	 // 此处传入的 item 是派生类，派生类到基类可以自动转换；这是引用转换，打折了，没有问题。

	// item2 = item; //错误；
	Bulk_item *p = static_cast<Bulk_item *>(&item); //如果想将基类转换为派生类，可以强制转换，但是一般不用这个特性；
	cout << p->net_price(10) << endl;

	return 0;
}