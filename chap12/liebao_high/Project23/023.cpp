#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename numberType>	
struct IsMultiple // 用来判断 element 是否是 m_Divisor 的整数倍
{
	numberType m_Divisor;
	// 构造函数；
	IsMultiple(const numberType& divisor)
	{
		m_Divisor = divisor;
	}
	// 一元谓词
	bool operator() (const numberType& element) const
	{
		return ((element % m_Divisor) == 0);
	}
};

int main()
{
	vector<int> vecIntegers;
	for (int i = 33; i <= 100; ++i)
	{
		vecIntegers.push_back(i);
	}

	IsMultiple<int> a(4);
	vector<int>::iterator iElement;	// 用来存放返回值的迭代器； 
	iElement = find_if(vecIntegers.begin(), vecIntegers.end(), a);
	if (iElement != vecIntegers.end())
	{
		cout << "第一个4的整数倍的数是：" << *iElement << endl;
	}

	return 0;
}