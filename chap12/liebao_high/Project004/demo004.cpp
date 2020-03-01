#include <iostream>
#include <string>

using namespace std;

class Screen; //(只有)类声明；  

// 如下 X 中有一个成员是 Y；Y 中有一个成员是 X，则必须把一个类先声明出来；
class Y;

class X
{
	// 各种成员，略；
private:
	Y *ptr;
};

class Y
{
	// 各种成员，略；
private:
	X *ptr;
	X obj;
};

// 记录
class Record  // 这是一个完整的类：既是类定义，也是类声明；
{
public:
	typedef std::size_t size;
	// 三个构造函数，进行函数重载； 构造函数初始化列表；
	Record():byte_count(0){}
	Record(size s):byte_count(s){}
	Record(std::string s):name(s),byte_count(0){}

	// 成员函数
	size get_count() const { return byte_count; }
	std::string get_name() const { return name; }

private:
	size byte_count;
	std::string name; // 记录名称；
};

struct Person
{
public:
	Person(const std::string &nm, const std::string &addr):name(nm),address(addr){}
	std::string getName() const { return name; }
	std::string getAddress() const { return address; }

private:
	std::string name;
	std::string address;

};

int main()
{
	// 下面语句报错； 原因：类未定义，则在定义类时，不知道类中包含多少数据成员，没法分配内存；
	// Screen scr;
	
	// 但是可以定义一个指针（也可以定义一个引用，但是必须初始化），这种类一般用作前置声明；
	Screen *scr;

	Record r; // 类对象；在堆栈上创建类的对象；
	// class Record r; // 此行代码等价于上行代码；

	struct Person per("Bill", "花园街5号");
	cout << per.getName() << per.getAddress() << endl;


	Record *p = new Record; // 在堆上动态的创建对象； 注意必须用 new,后面使用delete;

	delete p;

	cout << "hello HuangTL" << endl;

	return 0;
}