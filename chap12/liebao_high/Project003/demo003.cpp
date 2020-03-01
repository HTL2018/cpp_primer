#include <string>
#include <iostream>

using namespace std;

class Screen {
public:

	typedef std::string::size_type index; // 定义类型别名，在下面的代码中 index 等同于 std::string::size_type；

	// 构造函数	整个函数的定义在类的内部：内联函数；
	Screen(index ht = 0, index wd = 0):contents(ht * wd, 'A'),cursor(0),height(ht),width(wd)
	{}
	// 对一个构造函数进行声明
	Screen(index ht, index wd, const std::string &conts);

	// 成员函数
	char get() const;

	// 成员函数		在类内部对函数进行声明，外部对函数进行定义
	inline char get(index r, index c) const;	// 函数重载；

private:
	std::string contents;
	index cursor;
	index height, width;
};

Screen::Screen(index ht, index wd, const std::string &conts):contents(conts),cursor(0), height(ht), width(wd)
{}

// 若无inline,则不再是内联函数；
inline char Screen::get() const
{
	return contents[cursor];
}

char Screen::get(index r, index c) const
{
	index row = r * width;
	return contents[row + c];
}

int main()
{

	Screen a(10, 100);
	cout << a.get() << endl;
	cout << a.get(2, 8) << endl;

	Screen b(3, 6, "hello screen class");
	cout << b.get() << endl;
	cout << b.get(1, 2) << endl;

	// index在上面类中是public的，因此在类的外部也可以使用；
	Screen::index idx;

	cout << "测试一下。" << endl;
	return 0;
}