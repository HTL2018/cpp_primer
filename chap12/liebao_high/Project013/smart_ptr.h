#pragma once
class U_Ptr
{

	friend class BHasPtr;	// 因为需要操作私有成员，因此做成友元类；
private:
	int *ip;
	size_t use; // 计数
	U_Ptr(int *p):ip(p),use(1){}
	~U_Ptr() { delete ip; }
};
class BHasPtr {
public:
	BHasPtr(int *p, int i):ptr(new U_Ptr(p)), val(i){}

	// 定义复制构造函数；
	BHasPtr(const BHasPtr &orig) :ptr(orig.ptr), val(orig.val)
	{
		++ptr->use;	// 复制，多了一个对象，所以要把智能指针中的计数要加一；
	}
	BHasPtr& operator=(const BHasPtr&);

	// 定义析构函数；
	~BHasPtr()
	{
		// 析构的时候先--，在删除指针的时候，要先判断是否use已经为0；
		if (--ptr->use == 0) delete ptr;
	}

	int *get_ptr() const { return ptr->ip; } // 通过ptr->ip找到智能指针ptr中的普通指针ip；
	int get_int() const { return val; }

	void set_ptr(int *p) { ptr->ip = p; }
	void set_int(int i) { val = i; }

	int get_ptr_val() const { return *ptr->ip; }
	void set_ptr_val(int val)const { *ptr->ip = val; }	// 改变指针所指的对象； 

private:
	int val;
	U_Ptr *ptr;	// 智能指针；
};

// 定义赋值操作符；
BHasPtr& BHasPtr::operator=(const BHasPtr &rhs)
{
	++rhs.ptr->use;	// 右边对象的计数先加1，左边对象再减1，这样允许自己赋值个自己，当计数为0的时候就删除指针；
	if (--ptr->use == 0) delete ptr;

	ptr = rhs.ptr; // 浅复制；
	val = rhs.val;
	return *this;
}