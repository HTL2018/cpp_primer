#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person():age(0){}
	Person(const std::string &nm):name(nm),age(0) {}
public:
	std::string name;
	int age;
	// int age=0; // 不可以这样初始化，如果需要在初始化列表里进行初始化；
};

// 有时只能使用初始化列表进行初始化
class Dog
{
public:
	Dog()
	{
		this->legs = 4;
	}
private:
	std::string name;
	int legs;
	// 有时只能使用初始化列表进行初始化，比如上面在定义legs时加了const,即上面一行变为： const int legs;
	// 同时引用类型的成员和没有默认构造函数的类类型，再加上如上的const类型这三种必须只能使用初始化列表进行初始化。
	// int legs = 4; // 错误，注意在c++中不能这样进行赋值或初始化，需要初始化可以在初始化列表进行初始化；
};

class Sales_item
{
public:
	
	// 为了解决构造函数隐式创建类的隐患，最好是在构造函数前都加上explicit
	explicit Sales_item(const std::string &book, int units, double price)
		:isbn(book), units_sold(units), revenue(units*price)
	{
		// 可以通过初始化列表进行初始化，亦可以通过如下赋值形式，但是下面赋值形式比较慢。
		// 比较慢的原因是：在C++中无论是否进行列表初试化，c++都会进行此操作，下面的赋值形式相当于进行初始化列表之后进行的二次赋值，所以较慢。
		// 所以建议一般直接使用初始化列表进行初始化；
		// this->book = isbn;
		// this->units_sold = units;
		// this->price = units*price;
	}
	explicit Sales_item(const std::string &book):isbn(book),units_sold(0),revenue(0.0){}
	explicit Sales_item(std::istream &is) { is >> *this; }
	// c++的构造函数永远不用加const,即使是不变的。虽然有时加上也可以正常使用。
	explicit Sales_item(int units, double price)
	{
		this->units_sold = price;
		this->revenue = units * price;
	}

	explicit Sales_item() :units_sold(0), revenue(0.0) {}	// 如果对第2个Sales_item的构造函数中的book参数进行默认初始化，则可以省略此行构造函数；
	
	// 可以将isbn初始化为10个A，这是字符串类型中带有的构造函数决定了可以这样操作；
	// Sales_item():isbn(10,'A'),units_sold(0),revenue(0.0){}

	bool same_isbn(const Sales_item &rhs) const
	{
		return isbn == rhs.isbn;
	}

	// 友元
	friend istream& operator>>(std::istream&, Sales_item&);
private:
	// 注意：此处定义的顺序决定了初始化的顺序，和初始化列表的书写顺序无关，初始化列表的顺序可以任意写；
	std::string isbn;
	unsigned units_sold;
	double revenue;
};

inline istream& operator>>(std::istream& in, Sales_item& s)
{
	double price;
	// 输入
	in >> s.isbn >> s.units_sold >> price;
	if (in)
		s.revenue = s.units_sold * price;
	else
		s = Sales_item();
}

int main()
{
	Person a("HTL2018");
	Person b;	// 注意不能写为 Person b();不能加括号；

	Sales_item item1;	// 调用的是 line：24的构造函数；
	Sales_item item2("fdsa");	// 调用的是 line：22的构造函数；



	Sales_item *p = new Sales_item();	// 注意使用指针,new进行创建之后，要delete指针。此处的小括号可以省略；

	Sales_item myobj; // 注意此处不能加小括号,即，不能写作：Sales_item myobj();写成这样c++会将myobj当做函数；下面的执行就会报错；
	if (myobj.same_isbn(item2))
	{
		cout << "相同" << endl;
	}

	cout << a.name << endl;
	cout << a.age << endl;

	delete p;

	return 0;
}