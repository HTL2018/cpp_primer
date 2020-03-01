#include <iostream>
#include <string>

using namespace std;

// 此处需要加Screen类的声明，要不然下面的Dog类定义时，找不到会报错；
class Screen;

class Dog
{
public:
	// 将foo定义为了友元函数，所以可以去访问类中的私有成员；
	int foo(Screen& screen);
	// 虽然没有将koo定义为友元函数，故不能访问相应的私有成员，但是可以访问公有成员函数area();
	int koo(Screen& screen);

	// 略
};

class Screen
{
public:
	typedef std::string::size_type index;

	Screen(int ht=0, int wd=0):contents(ht*wd,' '),cursor(0),height(ht),width(wd){}

	// 略

	// 计算面积
	int area() const
	{
		return height * width;
	}

	// 将函数 calcArea 设为 Screen 的友元函数；
	friend int calcArea(Screen &);
	// 将类 Window_Mgr 设为 Screen 的友元类；
	friend class Window_Mgr;
	// 将类中的某个函数定义为友元函数，不再将整个类定义为友元类；
	friend int Dog::foo(Screen &);

private:
	std::string contents;
	index cursor;
	int height, width;
};

// 这个类时不能访问Screen 类中的私有数据成员的，为了可以访问可以将这个类设为Screen类的友元类；
class Window_Mgr // 窗口管理类 - 对Screen进行管理
{
public:
	void relocate(int r, int c, Screen& s)
	{
		s.height += r;
		s.width += c;
	}

	// 略
};

int Dog::foo(Screen& screen)
{
	return screen.height * screen.width;
}
int Dog::koo(Screen& screen)
{
	return screen.area();
}

// 这个函数不是类的成员函数，因此不能访问类中的私有成员；为了可以进行访问在类中将其定义为类的友元；
int calcArea(Screen & screen)
{
	return screen.height * screen.width;
}

int main()
{
	Screen a(60,100);

	cout << a.area() << endl;

	Window_Mgr wm;
	wm.relocate(20, 100, a);

	cout << calcArea(a) << endl;

	Dog dog;

	cout << dog.foo(a) << endl;
	cout << dog.koo(a) << endl;

	cout << "HTL2018 OK" << endl;

	return 0;
}