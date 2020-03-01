#include <iostream>
#include <string>

using namespace std;

void doA()
{
	int a;
	a = 12;
}

void doB()
{
	int b;
	b = 99;
}

class First
{
public:
	int memi;
	double memd;
public:
	void doC()
	{
		memi = 22;
	}
	void doD()
	{
		doC();
	}
};

int height; // 全局作用域里的变量；

class ScreenB
{
public:
	typedef std::string::size_type index;
	void dummy_fcn(index height)
	{
		// 分别使用的是哪个 height ?
		cursor = width * height;	// 函数自身传入的参数，即 line：40 中的 height；
		// cursor = width * this->height;	// 使用的是对象的height，即 line：50中的height；
		// cursor = width * ::heiht;	// 加上 :: 表示使用的是全局作用域中的height ,即 line：34中的height；
	}

private:
	index cursor;
	index height, width;
};


class ScreenA
{
public:
	typedef std::string::size_type index;
	char get(index r, index c) const;
	index get_cursor() const;

private:
	std::string contents;
	index cursor;
	index height, width;
};

// 次数的index必须加上作用域，必须写为ScreenA::index,不能只写一个index;
ScreenA::index ScreenA::get_cursor() const
{
	return cursor;
}


// 虽然写在了函数外面，但是通过作用域操作符，相当于在类里面进行的函数定义
char ScreenA::get(index r, index c) const
{
	index row = r * width;
	return contents[row + c];
}

int main()
{
	ScreenA::index ht;

	ScreenA sa;
	ScreenB sb;
	
	doA();
	doB();
	First obj;
	First *ptr = &obj;
	obj.memi = 12;
	obj.doC();
	ptr->memi = 99;
	ptr->doC();


	return 0;
}