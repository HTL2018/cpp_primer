#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/*
标准模板库STL中有大量的算法，这些算法是对标准模板库STL中容器中的数据进行各种各样操作的算法，
这些算法需要函数对象作为参数，所以在使用STL算法的时候就需要去写函数对象，因为STL包括容器和算法都是使用模板来设计的
因此在设计函数对象的时候也应该设计模板，即带模板的函数对象；
*/
struct absInt
{	// 重载操作符：函数调用操作符
	int operator() (int val) {
		return val < 0 ? -val : val;
	}
};

// 普通的模板函数；
template<typename elementType>
void FuncDisplayElement(const elementType & element)
{
	cout << element << ' ';
}

// 带模板的函数对象；
template<typename elementType>
struct DisplayElement
{
	// 存储状态
	int m_nCount;
	// 构造器
	DisplayElement()
	{
		m_nCount = 0;
	}
	// 此处重载了函数调用操作符；
	void operator() (const elementType & element)
	{
		++m_nCount;
		cout << element << " ";
	}
};

int main()
{
	int i = 42;
	absInt absObj;
	unsigned int ui = absObj(i);	// absObj是一个对象，但是调用的时候和调用函数非常相似，故称为函数对象；

	cout << ui << endl;
	
	vector<int> a;
	for (int n = 0; n < 10; ++n)
	{
		a.push_back(n);
	}

	list<char> b;
	for (char c = 'a'; c < 'k'; ++c)
		b.push_back(c);

	// STL算法
	//for_each(a.begin(), a.end(), DisplayElement<int>());
	DisplayElement<int> mResult;
	mResult = for_each(a.begin(), a.end(), mResult);	// 相比之下，使用函数对象可以保存状态，实现更多的函数功能；
	cout << endl;
	cout << "数量：" << mResult.m_nCount << endl;

	for_each(b.begin(), b.end(), DisplayElement<char>());
	cout << endl;

	cout << "hello 函数对象" << endl;
	return 0;
}