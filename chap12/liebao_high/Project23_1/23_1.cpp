#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename elementType>
class CMultiply // 乘法
{
public:
	elementType operator() (const elementType& elem1, const elementType& elem2)
	{
		return elem1 * elem2;
	}
};

int main()
{
	vector<int> a, b;

	for (int i = 0; i < 10; ++i)
		a.push_back(i);

	for (int j = 100; j < 110; ++j)
		b.push_back(j);

	vector<int> vecResult;	// 存储结果的迭代器
	vecResult.resize(10);
	// STL算法
	transform(a.begin(), a.end(), b.begin(), vecResult.begin(), CMultiply<int>());
	// 对于向量的循环建议不要用 int ，用 size_t;
	for (size_t nIndex = 0; nIndex < vecResult.size(); ++nIndex)	// 输出相乘之后的结果；
		cout << vecResult[nIndex] << ' ';
	cout << endl;

	cout << "hello 二元函数对象！" << endl;
	return 0;
}