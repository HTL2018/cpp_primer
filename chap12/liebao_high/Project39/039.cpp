//#include <iostream>
//#include <new>
//
//using namespace std;
//
//class Dog
//{
//public:
//	Dog()
//	{
//		parr = new int[1000000]; //4MB  因为int是4个字节
//	}
//private:
//	int *parr;
//};
//
//int main()
//{
//	Dog *pDog;
//	try {
//		for (int i = 1; i < 10000; i++) //40GB!
//		{
//			pDog = new Dog();
//			cout << i << ":new Dog 成功。" << endl;
//		}
//	}
//	catch (bad_alloc err)
//	{
//		cout << "new Dog 失败： " << err.what() << endl;
//	}
//	
//	return 0;
//}


//#include <iostream>
//#include <bitset>
//#include <string>
//#include <stdexcept>
//
//using namespace std;
//
//int main()
//{
//	try
//	{
//		//string s("1010110010"); //此语句可以正常使用；
//		string s("10ab110010");
//		bitset<10> b(s);
//		cout << "bitset ok" << endl;
//	}
//	catch (invalid_argument err)
//	{
//		cout << "bitset error: " << err.what() << endl;
//	}
//	return 0;
//}

//#include <iostream>
//#include <stdexcept>
//
//using namespace std;
//
//class student
//{
//public:
//	student(int age)
//	{
//		if (age < 0 || age>150)
//			throw out_of_range("年龄不能小于0或大于150");
//		this->m_age = age;
//	}
//private:
//	int m_age;
//};
//
//int main()
//{
//	try {
//		student Tom(200);
//		cout << "学生没错。" << endl;
//	}
//	catch (out_of_range err)
//	{
//		cout << "学生出错：" << err.what() << endl;
//	}
//	return 0;
//}

#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	try
	{
		Stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		cout << "pop: " << st.pop() << endl;
		cout << "top: " << st.top() << endl;
		cout << "pop: " << st.pop() << endl;
		cout << "pop: " << st.pop() << endl;
		cout << "top: " << st.top() << endl;
		
	}
	catch (const exception& e)
	{
		cerr << "发生异常: " << e.what() << endl;
	}

	cout << "Hello Stack." << endl;

	return 0;
}
