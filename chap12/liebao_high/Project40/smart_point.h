#pragma once
template<typename T>
class smart_pointer //自己定义一个简单的智能指针
{
private:
	T* m_pRawPointer; //此处是普通指针；
public://构造器
	smart_pointer(T* pData) : m_pRawPointer(pData) {}

	//复制构造函数
	smart_pointer(const smart_pointer & anotherSP);

	//重载解引用*操作符
	T& operator* () const
	{
		return *(m_pRawPointer);
	}

	//重载成员操作符
	T* operator-> () const
	{
		return m_pRawPointer;
	}
};