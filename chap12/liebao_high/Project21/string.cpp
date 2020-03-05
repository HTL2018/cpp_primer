#include <iostream>
#include <cstring>
#include "string.h"

String::String(char const *chars)
{
	// 如果是空指针就变为空字符串；
	chars = chars ? chars : "";
	ptrChars = new char[std::strlen(chars) + 1];
	std::strcpy(ptrChars, chars);
}

String::String(String const &str)
{
	ptrChars = new char[std::strlen(str.ptrChars) + 1];
	std::strcpy(ptrChars, str.ptrChars);
}

String::~String()
{
	delete[] ptrChars;
}

void String::display() const
{
	std::cout << ptrChars << std::endl;
}