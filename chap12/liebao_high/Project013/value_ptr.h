#pragma once
class CHasPtr {
public:
	// 每次创建一个新的对象,这样就每创建一个就指向一个新的分配的内存；
	CHasPtr(const int &p, int i):ptr(new int(p)), val(i) {}

	// 定义复制构造函数，赋值操作符，析构函数（三规则）
	CHasPtr(const CHasPtr &orig):ptr(new int(*orig.ptr)),val(orig.val){}
	CHasPtr& operator=(const CHasPtr&);

	~CHasPtr() { delete ptr; }


	int *get_ptr() const { return ptr; }
	int get_int() const { return val; }

	void set_ptr(int *p) { ptr = p; }
	void set_int(int i) { val = i; }

	int get_ptr_val() const { return *ptr; }
	void set_ptr_val(int val)const { *ptr = val; }	// 改变指针所指的对象； 

private:
	int val;
	int *ptr;
};

CHasPtr& CHasPtr::operator=(const CHasPtr &rhs)
{
	*ptr = *rhs.ptr;	// 注意不是简单的复制指针的地址；
	val = rhs.val;
	return *this;
}