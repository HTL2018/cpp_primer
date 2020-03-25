#pragma once
#ifndef STACK_H //自己写一个简单的堆栈
#define STACK_H

#include <deque>
#include <exception>

template<class T>
class Stack
{
protected:
	std::deque<T> c;
public:
	class ReadEmptyStack : public std::exception
	{
	public:
		virtual const char * what() const throw() //对标准异常中的what()进行重写；
		{
			return "read empty stack堆栈是空的。";
		}
	};

	bool empty() const
	{
		return c.empty();
	}

	void push(const T& elem)
	{
		c.push_back(elem);
	}

	T pop()
	{
		if (c.empty())
		{
			throw ReadEmptyStack();
		}
		T elem(c.back());
		c.pop_back();
		return elem;
	}

	T& top()
	{
		if (c.empty())
		{
			throw ReadEmptyStack();
		}
		return c.back();
	}
};

#endif // !STACK_H
