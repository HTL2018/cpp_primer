#include <iostream>

using namespace std;

enum COLOR {Red, Green, Blue, Yellow, White, Black, Brown};

class Animal
{
public:
	Animal(int);
	virtual ~Animal() { cout << "Animal析构函数被调用...\n"; }
	virtual int GetAge() { return itsAge; }
	virtual void SetAge(int age) { itsAge = age; }
private:
	int itsAge;
};

Animal::Animal(int age) : itsAge(age)
{
	cout << "Animal的构造函数被调用...\n";
}

class Horse : virtual public Animal
{
public:
	Horse(COLOR color, int height, int age);
	virtual ~Horse() { cout << "Horse析构函数被调用...\n"; }
	virtual void Whinny() const { cout << "Whinny!..."; }
	virtual int GetHeight() const { return itsHeight; }
	virtual COLOR GetColor() const { return itsColor; }
private:
	int  itsHeight;
	COLOR itsColor;
};

//此处虽然有Animal(age)但是不执行；
Horse::Horse(COLOR color, int height, int age) :Animal(age),itsColor(color), itsHeight(height)
{
	cout << "Horse构造函数被调用...\n";
}

class Bird : virtual public Animal
{
public:
	Bird(COLOR color, bool migrates, int age);
	virtual ~Bird() { cout << "Bird析构函数被调用...\n"; }
	//鸟叫
	virtual void Chirp() const { cout << "Chirp..."; }
	virtual void Fly() const
	{
		cout << "I can fly!";
	}
	virtual bool GetMigration() const { return itsMigration; }
	virtual COLOR GetColor() const { return itsColor; }
private:
	bool itsMigration;
	COLOR itsColor;
};

//此处虽然有Animal(age)但是不执行；
Bird::Bird(COLOR color, bool migrates, int age) :Animal(age),itsColor(color), itsMigration(migrates)
{
	cout << "Bird的构造函数被调用...\n";
}

class Pegasus : public Horse, public Bird //多继承，类Pegasus既继承了Horse又继承了Bird;
{
public:
	void Chirp()  const { Whinny(); } //此处重写了；
	Pegasus(COLOR,int, bool, long,int);
	~Pegasus() { cout << "Pegasus析构函数被调用...\n";}
	virtual long GetNumberBelievers() const
	{
		return itsNumberBelievers;
	}
private:
	long itsNumberBelievers;
};

Pegasus::Pegasus(COLOR aColor, int height, bool migrates, long numBelieve, int age) 
	:Horse(aColor,height, age), Bird(aColor, migrates,age), itsNumberBelievers(numBelieve),
	Animal(age) //在使用虚基类的时候，必须加上此句，只有此处会执行；
{
	cout << "Pegasus构造函数被调用...\n";
}

int main()
{
	Pegasus *pPeg = new Pegasus(Red,5, true, 10,2);
	pPeg->Fly(); 
	cout << endl;
	pPeg->Whinny();
	cout << endl;
	pPeg->Chirp();//因为重写，效果和上一行一样；
	cout << endl;
	cout << "有" << pPeg->GetNumberBelievers() << "人相信世界上有飞马." << endl;

	//pPeg->GetColor();//错误，会出现二义性问题，继承的父类Bird和Horse中都有GetColor()程序不知道访问哪一个；
	COLOR color = pPeg->Bird::GetColor(); //可以通过这种方式解决此类二义性问题；
	cout << "飞马的颜色： " << color << endl; //因为此处使用enum，且初始化为Red，所以颜色应该是0；

	//pPeg->GetColor(); //菱形二义性问题；用虚基类来解决；

	delete pPeg;
	return 0;
}