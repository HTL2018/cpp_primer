#include <iostream>
#include <string>

using namespace std;

class Animal
{
	// 成员略
};
// 下面的 : 就表示继承或者派生；
class Dog : public Animal
{
	// 成员略
};

class Cat : public Animal
{
	// 成员略
};

class Item_base
{
public:
	int x;
	Item_base(const std::string &book = "", 
		double sales_price = 0.0):isbn(book),price(sales_price){}
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
	Bulk_item(const std::string &book="",double sales_price=0.0,size_t qty=0,
		double disc_rate = 0.0):Item_base(book,sales_price),min_qty(qty),discount(disc_rate){}

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

int main()
{
	Animal a;
	Dog d;

	Item_base item("asdf", 9.9);
	cout << item.book() << "," << item.net_price(10) << endl;
	// cout << item.x << endl;
	// cout << item.isbn << endl;	// 错误；private成员不能在类外部使用；
	// cout << item.price << endl;	// 错误；protected成员可以在继承的类中的成员函数中使用，但是普通函数不行；

	Bulk_item item2("asdf", 9.9, 10, 0.12);
	cout << item2.book() << "," << item2.net_price(10) << endl;
	// cout << item2.x << endl;
	item2.test();
	item2.test2(item2, item);


	return 0;
}