#include <iostream>

using namespace std;

class String
{
public:
	String(char const *chars = "");

	char &operator[](std::size_t index) throw(String);
	char &operator[](std::size_t index) const throw(String);

	void print();

private:
	char *ptrChars; // 有一个私有成员是字符指针；
	static String errorMessage;
};

void String::print()
{
	cout << ptrChars << endl;
}

// 定义越界异常信息；
String String::errorMessage("Subscript out of range.");

// 定义可变成员函数；
char &String::operator[](std::size_t index) throw(String)
{
	cout << "nonconst" << endl;
	// 首先检查索引是否越界，如果越界抛出异常信息；
	if (index >= std::strlen(ptrChars))
		throw errorMessage;
	return ptrChars[index];
}

// 定义常量成员函数；
char &String::operator[](std::size_t index) const throw(String)
{
	cout << "const" << endl;
	// 首先检查索引是否越界，如果越界抛出异常信息；
	if (index >= std::strlen(ptrChars))
		throw errorMessage;
	return ptrChars[index];
}

String::String(char const *chars)
{
	// 如果是空指针就变成空字符串；
	chars = chars ? chars : "";
	ptrChars = new char[std::strlen(chars) + 1];
	std::strcpy(ptrChars, chars);
}

int main()
{
	String s("Hello");
	s.print();

	cout << s[0] << endl;

	s[0] = 'A';
	s.print();

	String const s2("HTL2018");
	cout << s2[2] << endl;

	return 0; 
}