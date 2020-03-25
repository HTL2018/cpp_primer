#include <iostream>
#include <memory>
#include "smart_point.h"

using namespace std;

class Dog{

};

void demo2()
{
	std::auto_ptr<double> pd(new double); //智能指针实际上是用模板定义的一个类；
	*pd = 28.5;

	std::auto_ptr<Dog> pDog(new Dog());
	smart_pointer<Dog> spDog(new Dog()); //自己写的智能指针，编译可以通过，但是实际上是不能用的，只是为了大致的理解智能指针的框架；

	std::cout << *pd << std::endl;
}

void demo1()
{
	double d;
	d = 25.5;

	double *pd = new double;
	*pd = 25.5;

	Dog * pDog = new  Dog();

	//省略
	std::cout << d << std::endl;
	std::cout << *pd << std::endl;

	/*if (xxx) //可能我们new了一个普通指针，且进行了delete,但是可能触发了异常抛出，最后没有delete，因为类似的原因也会进行内存泄漏，因此普通指针存在很大隐患；
		throw exception();*/

	delete pDog;
	delete pd;//new和delete必须配对使用，否则会引起内存泄漏；如果在下面demo1被多次调用且没有进行delete的话，会不断new新的内存且不释放，时间长后电脑死机；这就是普通指针存在的问题；

	return;
}

int main()
{
	demo1();
	demo2();
	return 0;
}