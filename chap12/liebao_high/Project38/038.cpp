#include <iostream>

using namespace std;

const int DefaultSize = 10;

//动态数组
class Array
{
public:
	Array(int itsSize = DefaultSize);
	~Array() { delete[] pType;} // 一般而言，在构造函数中new，则在析构函数中都要delete，new和delete一般配对使用，如果忘记delete，可能出现内存泄漏问题；

	// 运算符重载
	int& operator[](int offSet);
	const int& operator[](int offSet) const;

	//访问器，accessors
	int GetitsSize() const { return itsSize; }

	//异常类
	class xBoundary{}; //用于检测小标越界引发的异常；
	class xSize //写为类之后可以进行集成，然后具体的异常类都会简化；
	{
	public:
		xSize() {};
		xSize(int size):itsSize(size) {}
		~xSize() {}
		int GetSize() { return itsSize; }
		virtual void PrintError()
		{
			cout << "下标发生错误：" << itsSize << endl;
		}
	protected:
		int itsSize;
	};
	class xZero : public xSize
	{
	public:
		xZero(int size) : xSize(size) {};
		virtual void PrintError()
		{
			cout << "下标不能是0！" << endl;
		}
	};
	class xNegative : public xSize
	{
	public:
		xNegative(int size) : xSize(size) {};
		virtual void PrintError()
		{
			cout << "下标不能是负的！" << xSize::itsSize << endl;
		}
	};
	class xTooSmall : public xSize
	{
	public:
		xTooSmall(int size) : xSize(size) {};
		virtual void PrintError()
		{
			cout << "下标不能小于10：" << xSize::itsSize << endl;
		}
	};
	class xTooBig : public xSize
	{
	public:
		xTooBig(int size) : xSize(size) {};
		virtual void PrintError()
		{
			cout << "下标不能大于30000：" << xSize::itsSize << endl;
		}
	};
private:
	int *pType;
	int itsSize; 
};

//const用来读，非const用来写；
//非const函数的运算符重载，如果下标超过应有的大小，不在范围之内，就跑出异常；
int& Array::operator[](int offSet)
{
	int size = this->GetitsSize();
	if (offSet >= 0 && offSet < size)
	{
		return pType[offSet];
	}
	throw xBoundary();
}

//const函数的运算符重载，如果下标超过应有的大小，不在范围之内，就跑出异常；
const int& Array::operator[](int offSet) const
{
	int size = this->GetitsSize();
	if (offSet >= 0 && offSet < size)
	{
		return pType[offSet];
	}
	throw xBoundary();
}

Array::Array(int size) : itsSize(size)
{
	if (size == 0)
		throw xZero(size);
	else if (size < 0)
		throw xNegative(size);
	else if (size < 10)
		throw xTooSmall(size);
	else if (size > 30000) //此处的10和30000都只是进行说明，c++中并没有要求必须小于30000大于10；
		throw xTooBig(size);

	pType = new int[size];
	for (int i = 0; i < size; i++)
		pType[i] = 0;
}

int main()
{
	try //将可能发生异常的代码都放在try里面
	{
		Array a;
		Array intArray(20);
		Array b(6);
		/*b[6] = 88;
		b[22] = 9;
		cout << b[6] << endl;
		cout << "测试一下" << endl;*/

		//没有越界的都进行正常输出，越界的将检测到xBoundary然后跑出异常；
		for (int j = 0; j < 100; j++)
		{
			intArray[j] = j;
			cout << "intArray[" << j << "] okay..." << endl;
		}
	}
	catch (Array::xBoundary)
	{
		cout << "下标越界了。" << endl;
	}
	catch (Array::xSize& exp) //通过此手段就可以代替下面的catch，当然，此处简单了，在设计具体的异常类比如xZero的时候就需要多些一些东西，针对此处具体来说就是要对继承的虚函数重新进行定义；
	{
		exp.PrintError();
	}
	//catch (Array::xZero theException)
	//{
	//	cout << "下标不能是0." <<  endl;
	//}
	//catch (Array::xNegative theException) //通过变量theException来检查size;
	//{
	//	cout << "下标不能是负数：" << theException.GetSize() << endl;
	//}
	//catch (Array::xTooSmall theException)
	//{
	//	cout << "下标不能小于10：" << theException.GetSize() << endl;
	//}
	//catch (Array::xTooBig theException)
	//{
	//	cout << "下标不能大于30000：" << theException.GetSize() << endl;
	//}
	
	catch (...)
	{
		cout << "" << endl;
	}
	
	return 0;
}