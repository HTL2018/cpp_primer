#pragma once
#ifndef _BS_H
#define _BS_H

#include <string>

//注意在头文件中不要用这种格式来导入命名空间，一般下面使用到的时候再前面写上其对应的命名空间；
//using namespace std;
//using std::cout;

namespace Bookstore
{
	class Dog //在命名空间Bookstore中有Dog，在命名空间MyApp中也有Dog，但是这是两个不同的Dog；
	{};

	class Sales_item
	{
	public:
		//构造函数
		Sales_item(const std::string &book = "") :isbn(book), units_sold(0), revenue(0.0) {}
		double avg_price() const;
	private:
		std::string isbn;
		unsigned units_sold;
		double revenue;
	};
}

//命名空间可以是不连续的；
namespace MyApp //这个命名空间和main.cpp中的命名空间MyApp的名称一样，c++在编译的时候会自动的将两个命名空间进行合并，也就是同一个命名空间的两个部分可以在两个文件中分开写；
{

}

#endif // !_BS_H
