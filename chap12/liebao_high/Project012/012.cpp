#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

class CDemo
{
public:
	CDemo(int pa, const char *cstr)		// 注意此处要加 const，否则会有错误：C2664...
	{
		this->a = pa;
		// 因为第二个数据成员是指针，所以需要用new操作符动态的在堆上分配存储空间，然后把指针传进来的字符串用strcpy_s()进行拷贝；
		this->str = new char[1024];
		strcpy_s(this->str,1024, cstr);
	}

	// 如果自己不写c++会自动生成一个复制构造函数，实现的是浅复制；  
	CDemo(CDemo& obj)
	{
		this->a = obj.a;
		this->str = obj.str; // 这是浅复制；如果不自己写构造函数，系统自动生成的构造函数就是这种效果，实现的是浅复制；
		// this->str = new char[1024];
		// if (str != 0)
		// 	strcpy_s(this->str, 1024, obj.str);
	}

	~CDemo()
	{
		delete str; // 用new创建之后要在此处delete进行删除；
	}

public:
	int a;
	char *str;
};

int main()
{
	CDemo A(10,"hello");

	cout << A.a << ", " << A.str << endl;

	CDemo B = A; // 复制；
	cout << "A: " << A.a << ", " << A.str << endl;
	cout << "B: " << B.a << ", " << B.str << endl;
	B.a = 3;
	B.str[0] = 'k';
	cout << "修改后： " << endl;
	cout << "A: " << A.a << ", " << A.str << endl;
	cout << "B: " << B.a << ", " << B.str << endl;

	return 0;
}