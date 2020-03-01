#include <iostream>
#include "plain_ptr.h"
#include "value_ptr.h"
#include "smart_ptr.h"

using namespace std;

void test_AHasPtr()
{
	int i = 42;
	AHasPtr p1(&i, 42);
	AHasPtr p2 = p1;
	cout << p2.get_ptr_val() << endl;

	p1.set_ptr_val(0);
	cout << p2.get_ptr_val() << endl;

	// 新创建一个指针，然后将其复制个 指针ptr;
	int *ip = new int(42);
	AHasPtr ptr(ip, 10);
	cout << ptr.get_ptr_val() << endl;
	// 删除指针所指的对象，但是指针仍然存在，此时指针ptr变成了野指针；  
	delete ip;	
	cout << ptr.get_ptr_val() << endl;
}

void test_BHasPtr()
{
	int obj = 0;

	BHasPtr ptr1(&obj, 42);
	BHasPtr ptr2(ptr1);
	cout << ptr1.get_ptr_val() << ", " << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ", " << ptr2.get_int() << endl;
	cout << "修改以后： " << endl;
	ptr2.set_ptr_val(2);
	ptr2.set_int(22);
	cout << ptr1.get_ptr_val() << ", " << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ", " << ptr2.get_int() << endl;
}

void test_CHasPtr()
{
	// 比较像普通的变量，修改b的值不会改变a的值，因此称之为值类型；
	int a, b;
	a = 5;
	b = a;
	b = 9;

	int obj = 0;

	CHasPtr ptr1(obj, 42);
	CHasPtr ptr2(ptr1);
	cout << ptr1.get_ptr_val() << ", " << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ", " << ptr2.get_int() << endl;
	ptr2.set_ptr_val(6);
	ptr2.set_int(48);
	cout << "修改以后：" << endl;
	cout << ptr1.get_ptr_val() << ", " << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ", " << ptr2.get_int() << endl;
}

int main()
{
	cout << "常规指针：" << endl;
	test_AHasPtr();
	cout << endl;
	cout << "值型类（深复制）：" << endl;
	test_CHasPtr();
	cout << endl;
	cout << "智能指针：" << endl;
	test_BHasPtr();

	return 0;
}