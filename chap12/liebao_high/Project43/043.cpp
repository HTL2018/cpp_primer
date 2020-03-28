#include <iostream>

using namespace std;

class Item_base
{
public:
	virtual double net_price(size_t n) const
	{
		//局部类，就是类位于函数中，用也只能在函数中用；
		class Cat
		{

		};
		Cat cat;

		return n * price;
	}

	class Dog
	{

	};

public:
	std::string isbn;
protected:
	double price;
};

class Bulk_item : public Item_base
{
public:
	double net_price(std::size_t cnt) const
	{
		if (cnt > min_qty)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
private:
	std::size_t min_qty;
	double discount;
};

//实际上char ,int  ,double占用的是同一块内存，使用其中最大的（也就是double：8个字节）
union TokenValue
{
	char cval;
	int ival;
	double dval;
};

//位域 一般使用无符号整型来创建 
typedef unsigned int Bit; // 整型：4个字节，32位

class File{ //位域类
public:
	Bit mode : 2; //使用2位给mode;
	Bit modified : 1;
	Bit prot_owner : 3;
	Bit prot_group : 3;
	Bit prot_world : 3;
	// ...
};

enum { READ = 01, WRITE = 02 };

//extern "C"来调用外部的C程序；
extern "C" void show(const char *);

int main()
{ 
	show("hello extern \"C\"\n");

	Item_base *pItem = new Item_base(); //使用new操作符创建对象；来分配对象所用的内存；

	allocator<Item_base> a; //使用allocator来创建对象，分配内存；
	a.allocate(100); //分配的内存大小指定为100;

	//RTTI ： 运行时对象类型识别,主要用在不能使用虚函数的时候；
	Item_base *bp = new Item_base();
	Bulk_item *dp = new Bulk_item();
	
	Item_base *bp2 = dp; //正确；将派生类对象转换为基类对象，向上转型，是允许的；
	//Bulk_item *dp2 = bp; //错误；将基类对象转换为派生类对象，这么做是不允许的；
	Bulk_item *dp2 = dynamic_cast<Bulk_item*>(bp);//如果想将基类对象转换为派生类对象，可以使用动态类型变换，dynamic_cast属于RTTI的一种；

	if (typeid(Bulk_item) == typeid(*dp)) cout << "Bulk_item类型" << endl;
	cout << typeid(*bp).name() << endl; //可以将类名输出；属于RTTI，运行时类型识别；
	cout << typeid(*dp).name() << endl; //可以将类名输出；属于RTTI，运行时类型识别；

	//类成员指针
	//std::string Item_base ::* p = &Item_base.isbn; //字符串指针；
	double(Item_base::* pmf)(std::size_t) const = &Item_base::net_price; //函数指针；

	//嵌套类
	Item_base::Dog dog;

	//虽然之后a，但是调用的时候返回的是a对应的ASCII码97；
	TokenValue myToken = { 'a' };
	cout << myToken.ival << endl;

	File myFile; //使用位域非常节省内存；
	myFile.mode = WRITE;
	myFile.modified = 1;

	int x;
	volatile int y; //加上volatile表示是易失的；加上volatile实际上是告诉c++不要对变量y进行优化（c++会对默认对程序进行优化，优化的时候会改变在内存中的位置）；

	return 0;
}