#include <iostream>

using namespace std;

class A
{
public:
	static std::size_t object_count()
	{
		return 100;
	}
protected:
	static const std::size_t obj_count = 99;
};

class B : public A
{
public:
	void f(const B &b,B *b2)
	{
		// static成员变量
		cout << A::obj_count << endl; // 通过 基类名::成员名 来访问static成员；
		cout << B::obj_count << endl; // 通过 子类名::成员名 来访问static成员；
		cout << b.obj_count << endl;	 // 通过 对象.成员名 来访问static成员；
		cout << b2->obj_count << endl;  // 通过 指针->成员名 来访问static成员；
		cout << obj_count << endl; //直接访问；

		// static成员函数(5种方法）
		cout << A::object_count() << endl;
		cout << B::object_count() << endl;
		cout << b.object_count() << endl;
		cout << b2->object_count() << endl;
		cout << object_count() << endl;
	}
};

class C : public B
{

};

int main()
{
	B b;
	b.f(b, &b);

	return 0;
}