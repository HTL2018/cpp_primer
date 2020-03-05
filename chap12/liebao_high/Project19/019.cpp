#include <iostream>

using namespace std;

class String
{
public:
	String(char const *chars = "");

	String &operator=(String const &); // (1)
	String &operator=(char const *); // (2)
	String &operator=(char); // (3)

	void print();

private:
	char *ptrChars; // 私有成员是一个字符指针；
};

void String::print()
{
	cout << ptrChars << endl;
}

String &String::operator=(String const &str)
{
	// 首先判断所占内存大小是否一样，如果不同需要重新分配内存；
	if (strlen(ptrChars) != strlen(str.ptrChars))
	{
		char *ptrHold = new char[strlen(str.ptrChars) + 1];
		delete[] ptrChars;	// 每一个new的成员都需要进行delete;
		ptrChars = ptrHold;
	 }
	std::strcpy(ptrChars, str.ptrChars);
	return *this;  // 赋值操作必须返回对*this指针的引用；
}

String::String(char const *chars)
{
	// 如果是Null指针，则将chars变为空字符串；
	chars = chars ? chars : ""; 
	// +1 是因为用字符数组来保存，字符数组的最后一位是\0，因此加1；
	ptrChars = new char[std::strlen(chars) + 1];
	std::strcpy(ptrChars, chars);
}

int main()
{
	String s("hello");
	String s2("HTL2018");
	s.print();
	s2.print();

	s = s2; // 赋值操作；
	s.print();

	// s = "dfa";	 // 调用赋值操作符重载方式(2)，但是要定义相关函数，本程序中没有再定义，只是简单说明一下；
	// s = 'A';		 // 调用赋值操作符重载方式(3)，但是要定义相关函数，本程序中没有再定义，只是简单说明一下；

	return 0;
}