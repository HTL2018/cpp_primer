#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	Person(const std::string &nm, const std::string &addr)
	{
		this->name = nm;
		this->address = addr;
	}

	std::string getName() const
	{
		return this->name;
	}

	std::string getAdress() const
	{
		return this->address;
	}

private:
	std::string name;
	std::string address;

};


class Screen // 屏幕上的窗口
{
public:
	typedef std::string::size_type index;
	Screen(index ht=0, index wd=0):contents(ht*wd,'A'),cursor(0),height(ht),width(wd),access_ctr(0)
	{}
	char get() const { return contents[cursor]; }
	char get(index r, index c) const
	{
		index row = r * width;
		return contents[row + c];
	}

	// 函数声明，在类的外部进行定义；
	Screen& move(index r, index c); //不使用更简单的写法时可以将此处的三个 Screen& 换为 void；对应的函数定义时也要改变
	Screen& set(index r, index c, char ch);
	Screen& set(char c);
	const Screen& display(std::ostream &os) const	// 只读取不改变，定义为const更安全
	{
		++access_ctr;
		do_display(os);
	}

	Screen& display(std::ostream &os)
	{
		++access_ctr; 
		do_display(os);
		return *this;
	}

private:
	std::string contents;
	index cursor;
	index height, width;
	mutable size_t access_ctr; // 计数器:调用display的次数；加上mutable是为了可以在const中对其进行修改；

	void do_display(std::ostream &os) const
	{
		os << contents;
	}
};

/*
// 将光标移动到指定位置
void Screen::move(index r, index c)
{
	index row = r * width;
	cursor = row + c;

}
*/

// 更简单的写法要不move函数对应变成如下形式
Screen& Screen::move(index r, index c)
{
	index row = r * width;
	cursor = row + c;
	return *this;
}

// 改变指定位置的字符
Screen& Screen::set(index r, index c, char ch)
{
	index row = r * width;
	contents[row + c] = ch;
	return *this; // 此时的this指针就必须写上；
}

// 改变当前光标位置的字符
Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this; // 此时的this指针就必须写上；因为返回类型不再是 void
}

int main()
{
	Person p("HTL2018", "莲花街100号");
	cout << p.getName() << endl;

	Person p2("HTL20182020", "莲花街100号2020");
	cout << p2.getName() << endl;

	Screen myScreen(5,3);
	cout << myScreen.get() << endl;
	cout << myScreen.get(3,2) << endl;
	
	myScreen.set(3, 2, 'B');
	cout << myScreen.get(3,2) << endl;

	// 重点
	//myScreen.move(2, 3);
	//myScreen.set('C');
	//更简单的写法
	myScreen.move(2, 3).set('C').display(cout).set('K').display(cout); // 与上面两行实现相同的功能；
	cout << endl; 
	myScreen.move(4, 0).set('X').move(4, 1).set('Y').move(4, 2).set('Z');
	cout << myScreen.get() << endl;
	myScreen.display(cout);
	cout << endl;

	return 0;
} 