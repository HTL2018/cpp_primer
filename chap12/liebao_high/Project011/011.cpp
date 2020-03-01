#include <iostream>
#include <string>

using namespace std;

class NoName
{
public:
	NoName(): pstring(new std::string), i(0), d(0)
	{
		// 打开文件；
		// 打开数据库；
		// 动态分配内存；
		cout << "构造函数被调用了！" << endl;
	}
	
	NoName(const NoName &other);
	NoName& operator=(const NoName &rhs);

	~NoName();
private:
	std::string *pstring;
	int i;
	double d;
};

NoName& NoName::operator=(const NoName &rhs)
{
	pstring = new std::string;
	*pstring = *(rhs.pstring);
	i = rhs.i;
	d = rhs.d;
	return *this;
}

NoName::NoName(const NoName &other)
{
	pstring = new std::string;
	*pstring = *(other.pstring);
	i = other.i;
	d = other.d;
}

NoName::~NoName()
{
	// 关闭文件；
	// 关闭数据库连接；
	// 回收动态分配的内存；
	cout << "析构函数被调用了！" << endl;
	delete pstring;
}

int main()
{
	// 创建对象的时候调用构造函数；
	NoName a;

	NoName *p = new NoName;

	cout << "HTL2018" << endl;

	delete p;
	return 0;
	// 在main函数结束之后调用析构函数，对象被清除掉；
}