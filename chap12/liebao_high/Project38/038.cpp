#include <iostream>

using namespace std;

const int DefaultSize = 10;

//动态数组
class Array
{
public:
	Array(int itsSize = DefaultSize);

private:
	int *pType;
	int itsSize; 
};

Array::Array(int size) : itsSize(size)
{
	pType = new int[size];
	for (int i = 0; i < size; i++)
		pType[i] = 0;
}

int main()
{
	cout << "测试一下" << endl;
	return 0;
}