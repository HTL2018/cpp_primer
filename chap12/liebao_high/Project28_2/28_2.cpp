#include <iostream>

using namespace std;

enum BREED {A,B,C,D,E,F};

class Mammal
{
public:
	Mammal();
	~Mammal();

	//存取器函数
	int GetAge() const { return itsAge; }
	void SetAge(int age) { itsAge = age; }
	int GetWeight() const { return itsWeight; }
	void SetWeight(int weight) { itsWeight = weight; }

	void Speak() const { cout << "Mammal的声音！\n"; }
	void Sleep() const { cout << "shhh.I'm sleeping.\n"; }

protected:
	int itsAge;
	int itsWeight;
};

class Dog : public Mammal
{
public:
	Dog();
	~Dog();

	BREED GetBreed() const { return itsBreed; }
	void SetBreed(BREED breed) { itsBreed = breed; }

	void WagTail() const { cout << "Tail wagging...\n"; }
	void BegForFood() const { cout << "Begging for food...\n"; }

private:
	BREED itsBreed;
};

Mammal::Mammal() : itsAge(3), itsWeight(5)
{
	cout << "Mammal的构造函数被调用..." << endl;
}

Mammal::~Mammal()
{
	cout << "Mammal的析构函数被调用..." << endl;
}

Dog::Dog() : itsBreed(A)
{
	cout << "Dog的构造函数被调用..." << endl;
}

Dog::~Dog()
{
	cout << "Dog的析构函数被调用..." << endl;
}

int main()
{
	Dog Fido; // 会先调用基类的构造函数，再调用派生类的构造函数；
	Fido.Speak();	// 派生类继承了基类的 public 成员函数；
	Fido.WagTail();
	cout << "Fido is " << Fido.GetAge() << " years old" << endl;

	return 0;	// 会先调用派生类的析构函数，再调用基类的析构函数；
}