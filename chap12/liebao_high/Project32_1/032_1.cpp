#include <iostream>

using namespace std;

enum COLOR {Red, Green, Blue, Yellow, White, Black, Brown};

class Animal
{
public:
	Animal(int);
	virtual ~Animal() { cout << "Animal的析构函数被调用...\n"; }
	virtual int GetAge() const { return itsAge; }
	virtual void SetAge(int age) { itsAge = age; }
	virtual void Sleep() const = 0;
	virtual void Eat() const = 0;
	virtual void Reproduce() const = 0;//生孩子
	virtual void Move() const = 0;
	virtual void Speak() const = 0;
private:
	int itsAge;
};

Animal::Animal(int age):itsAge(age)
{
	cout << "Animal的构造函数被调用...\n";
}

class Mammal : public Animal
{
public:
	Mammal(int age) :Animal(age)
	{
		cout << "Mammal构造函数被调用...\n";
	}
	virtual ~Mammal() { cout << "Mammal析构函数被调用...\n"; }
	// 此处只是重写了一个纯虚函数，还有4个纯虚函数没有重写，所以另外4个继承下来之后还是纯虚函数；所以Mammal还是抽象类；
	virtual void Reproduce() const 
	{
		cout << "Mammal reproduction depicted...\n";
	}
};

class Fish : public Animal
{
public:
	Fish(int age) :Animal(age)
	{
		cout << "Fish构造函数被调用...\n";
	}
	virtual ~Fish()
	{
		cout << "Fish析构函数被调用...\n";
	}
	virtual void Sleep() const { cout << "fish snoring...\n"; }
	virtual void Eat() const { cout << "fish feeding ...\n"; }
	virtual void Reproduce() const { cout << "fish laying eggs...\n"; }
	virtual void Move() const { cout << "fish swimming...\n"; }
	virtual void Speak() const {}
};

class Horse : public Mammal
{
public:
	Horse(int age, COLOR color) :Mammal(age), itsColor(color)
	{
		cout << "Horse构造函数被调用...\n";
	}
	virtual ~Horse()
	{
		cout << "Horse析构函数被调用...\n";
	}
	//此处没有重写Reproduce，所以Reproduce函数使用继承自Mammal类的函数；
	virtual void Speak() const { cout << "Whinny!...\n"; }
	virtual void Sleep() const { cout << "Horse snoring...\n"; }
	virtual COLOR GetItsColor() const { return itsColor; }
	virtual void Move() const { cout << "Horse runing...\n"; }
	virtual void Eat() const { cout << "Horse feeding ...\n"; }
	
protected:
	COLOR itsColor;
};

class Dog : public Mammal
{
public:
	Dog(int age, COLOR color) :Mammal(age), itsColor(color)
	{
		cout << "Dog构造函数被调用...\n";
	}
	virtual ~Dog()
	{
		cout << "Dog析构函数被调用...\n";
	}
	virtual void Speak() const { cout << "Whoof!...\n"; }
	virtual void Sleep() const { cout << "Dog snoring... \n"; }
	virtual void Eat() const { cout << "Dog eating...\n"; }
	virtual void Move() const { cout << "Dog runing...\n"; }
	virtual void Reproduce() const
	{
		cout << "Dogs reproducing...\n";
	}

protected:
	COLOR itsColor;
};

int main()
{
	Animal *pAnimal = 0;
	int choice;
	bool fQuit = false;

	while (fQuit == false)
	{
		cout << "(1)Dog (2)Horse (3)Fish (0)Quit: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			pAnimal = new Dog(5, Brown);
			break;
		case 2:
			pAnimal = new Horse(4, Black);
			break;
		case 3:
			pAnimal = new Fish(5);
			break;
		default:
			fQuit = true;
			break;
		}
		if (fQuit == false)
		{
			pAnimal->Speak();
			pAnimal->Eat();
			pAnimal->Reproduce();
			pAnimal->Move();
			pAnimal->Sleep();
			delete pAnimal; // 每次new的对象使用完之后，一定要delete，否则会出现内存泄漏的严重问题；
			cout << endl; 
		}
	}

	return 0;
}