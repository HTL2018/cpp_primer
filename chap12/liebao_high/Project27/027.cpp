#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		a = 10; b = 20; c = 30; a2 = 100; a3 = 200;
	}
	int a;
	int a2;
	int a3;
protected:
	int b;
private:
	int c;
};

class B1 : public A	// 公有继承
{
public:
	void test()
	{
		cout << a << endl;
		cout << b << endl;   // 可以；protected成员进行了继承；
		//cout << c << endl; //错误；因为private成员没有继承；
	}

};

class B2 : private A
{
public:
	using A::a2; // 通过using A::a2将a2保持为原有的public;称之为修改继承访问（去除个别成员）；
	void test()
	{
		// private继承之后将原来的protected成员和public成员都变成了private的；
		cout << a << endl;
		cout << b << endl;
		//cout << c << endl; // 错误，因为c是类A中private的，此处没有继承，不能使用；
	}

};

class B3 : protected A
{
public:
	void test()
	{
		// protected继承之后将原来的protected成员和public成员都变成了portected的；
		cout << a << endl;
		cout << b << endl;
		//cout << c << endl; //错误，因为c是类A中private的，此处没有继承，不能使用；
	}
};

class B4 : A  //默认为private继承；等效于：class B4 : private A
{
	int b4; //默认是private成员；
};

struct B5 : A	// 默认是public继承；等效于 struct B5 : public A
{
	int b5; //默认是public成员；
};

class C : public B1 // 私有继承
{
public:
	void test()
	{
		cout << a << endl;
		cout << b << endl;
		// cout << c << endl;
	}
};

int main()
{
	//public继承
	B1 b1;
	cout << b1.a << endl;
	//b1.b;	// 错误；虽然类 B1 从类 A 中继承了b,但是protected b只能在类A中使用，不能再类外面使用；
	//b1.c;	// 错误；作为 private 类 B1 没有从类 A 中继承 pricate 成员；
	b1.test();

	//private继承，将原有类中的public和protected成员都变成了private成员；
	B2 b2;
	//cout << b2.a << endl;	//错误
	//cout << b2.b << endl;	//错误
	//cout << b2.c << endl;	//错误
	cout << b2.a2 << endl;
	//cout << b2.a3 << endl; //错误；
	b2.test();

	//protected继承，将原有类中的public和protected成员都变成了protected成员；
	B3 b3;
	//cout << b3.a << endl;// 错误，protected成员可以在继承的子类中使用，但是不能再类外使用
	//cout << b3.b << endl;// 错误，protected成员可以在继承的子类中使用，但是不能再类外使用
	//cout << b3.c << endl;// 错误；作为 private 类 B3 没有从类 A 中继承 pricate 成员；
	b3.test();

	return 0;
}