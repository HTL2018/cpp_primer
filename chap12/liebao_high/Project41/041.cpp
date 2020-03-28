#include <iostream>
#include "bs.h"

//注意：以下的方法不要用在头文件中；
//using namespace std;
using std::cout;
using std::endl;
//using namespace Bookstore; //这种方法会将命名空间中所有的名称自动的导入，所以不太好；有时候可以用什么导入什么，比如：using std::cout;
using Bookstore::Sales_item;

namespace bs = Bookstore; //此处bs为Bookstore的别名；使用bs等同于Bookstore;

class Ant //如果定义了一个类，没有说明位于的命名空间，则该类位于全局命名空间中；
{

};

namespace MyApp
{
	double pail;
	void processTrans()
	{
		Bookstore::Sales_item s;
		bs::Sales_item s2;
	}

	class Dog
	{};

	namespace Lib //命名空间可以进行嵌套；
	{
		class Query
		{};
	}
}

int main()
{
	//using namespace MyApp;
	cout << "hello" << endl;
	MyApp::processTrans(); // 要么前面要加上所用的命名空间，要么前面要(比如此处)加上using namespace MyApp;
	MyApp::Dog dog;

	//Bookstore::Sales_item item; //要加上所用的命名空间；
	Sales_item item;

	Bookstore::Dog d1;
	MyApp::Dog d2;

	MyApp::Lib::Query q;//在使用嵌套的命名空间中的类时，要把完整的命名空间写上；

	::Ant ant; //全局命名空间可以直接用::来代替；

	return 0;
}