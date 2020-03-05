#pragma once
#ifndef POINTER_H
#define POINTER_H
// 避免重定义：比如你有两个C文件，这两个C文件都include了同一个头文件。而编译时，这两个C文件要一同编译成一个可运行文件，于是问题来了，大量的声明冲突。
class String;

// 智能指针：对指针使用进行计数；
class Pointer
{
public:
	Pointer();
	Pointer(String const &n);
	~Pointer();

	String &operator*();
	String *operator->() const;

private:
	String *ptr;
	static String errorMessage;
};

#endif