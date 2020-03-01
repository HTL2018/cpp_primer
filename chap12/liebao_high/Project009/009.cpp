#include <iostream>
#include <string>

using namespace std;

class Dog
{
private:
	// 虽然此处定义的interestRate和Account类中一样，但是其作用域值在类Dog中，可以避免命名冲突；
	static double interestRate;
};

class Account
{
public:
	Account(std::string name, double money):
		owner(name),amount(money){}

	void applyint() { amount += amount * interestRate; }

	double getAmount() const
	{
		return this->amount;
	}

	void deposit(double money)
	{
		this->getAmount += money;
	}

	// 最好是将对应的成员函数也设置为静态的，静态的成员函数调用静态的数据成员；
	static double rate() { return interestRate;}
	static void rate(double newRate)
	{
		interestRate = newRate;
	}

private:
	std::string owner;
	double amount;
	// static double interestRate = 0.1; 错误写法，此处不允许进行初始化；
	static double interestRate;// 只有一个，即使初始化两个对象也公用同一个interestRate;
	// 只有一种例外：静态常量整型数据成员可以在此处进行初始化；其他都不行！
	static const int period = 30;

};

// 初始化方法；
double Account::interestRate = 0.015;

int main()
{
	// 只有在rate函数设置成静态的时候才可以这样用，否则不行！（在创建对象之前通过类调用静态数据成员）
	// 故而一般说静态函数不属于任何一个对象，因此静态函数就不能使用this指针（因为this指针代表当前对象）；
	Account::rate(0.026);

	Account a("HTL2018", 1000);
	Account b("HTL2020", 2000);

	a.deposit(500);
	b.deposit(600);

	cout << a.getAmount() << endl;
	cout << b.getAmount() << endl;
	cout << a.rate() << endl;
	a.rate(0.018);
	cout << b.rate() << endl;

	Account::rate(0.02);
	a.applyint();
	b.applyint();
	cout << a.getAmount() << endl;
	cout << b.getAmount() << endl;

	return 0;
}