#include<iostream>

using namespace std;

class father
{
	// 成员：略
public:
	int X;
};

class son : public father
{
	// 新的成员
public:
	int Y;
};

class Base1
{
public:
	Base1(int i)
	{
		b1 = i;
		cout << "Base1的构造函数被调用。" << endl;
	}
	void Print() const
	{
		cout << b1 << endl;
	}
private:
	int b1;
};

class Base2
{
public:
	Base2(int i)
	{
		b2 = i;
		cout << "Base2的构造函数被调用。" << endl;
	}
	void Print() const
	{
		cout << b2 << endl;
	}
private:
	int b2;
};

class Base3
{
public:
	Base3()
	{
		b3 = 0;
		cout << "Base3定义的缺省参数的构造函数被调用。" << endl;
	}
	void Print() const
	{
		cout << b3 << endl;
	}
private:
	int b3;
};

class Member
{
public:
	Member(int i)
	{
		m = i;
		cout << "Member的构造函数被调用。" << endl;
	}
	int GetM()
	{
		return m;
	}
private:
	int m;
};

// 这个派生类继承了Base1,Base2,Base3三个基类；调用基类的顺序以此处进行继承时的声明顺序为准；
class Derived : public Base2, public Base1, public Base3
{
public:
	Derived(int i, int j, int k, int l);
	void Print();
private:
	int d;
	Member mem;// 定义成员对象，成员对象也要先于派生类进行构造；
};

// 调用基类的顺序和此处初始化列表中的基类顺序，无关；  // 调用的时候，会默认的调用缺省的Base3();
// 注意：如果写为：Derived::Derived(int i, int j, int k, int l) :mem(k)则会默认的调用缺省参数的Base1(),Base2(),Base3(),如果自己没有写缺省的构造函数，C++会自动写一个；
Derived::Derived(int i, int j, int k, int l) : Base1(i), Base2(j), mem(k)
{
	d = l;
	cout << "Derived的构造函数被调用。" << endl;
}

void Derived::Print()
{
	Base1::Print();
	Base2::Print();
	Base3::Print();
	cout << mem.GetM() << endl;
	cout << d << endl;
}

int main()
{
	son a; // a是一个son,创建son对象，必须先创建father对象，这样才能进行继承；
	a.X = 1;
	a.Y = 2;
	
	Derived obj(1, 2, 3, 4);
	obj.Print();

	return 0;
}