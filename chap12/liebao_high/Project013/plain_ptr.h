#pragma once
class AHasPtr {
public:
	AHasPtr(int *p, int i):ptr(p),val(i){}

	// 没有写复制构造函数，所以c++会自动生成一个默认的复制构造函数，只会复制指针的地址不会复制指针所指的对象；

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