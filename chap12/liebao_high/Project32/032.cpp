#include <iostream>

using namespace std;

// 这是一个抽象类，也叫抽象数据类型（包含一个或者多个纯虚函数的类即抽象类）
class Shape
{
public:
	Shape(){}
	virtual ~Shape() {}	// 虚函数
	virtual double GetArea() = 0;	// 纯虚函数
	virtual double GetPerim() = 0;	// 纯虚函数
	virtual void Draw() = 0;	// 纯虚函数
};

//因为这是一个纯虚函数，可以写也可以不写，一般都不写！
void Shape::Draw()	//如果写，就要写一些有用的，这样在此基类的派生类中都可以调用这个函数；
{
	cout << "Abstract drawing 方法!\n";
}

class Circle : public Shape
{
public:
	Circle(int radius) : itsRadius(radius) {}
	virtual ~Circle() {} // 只要有一个成员函数是虚函数，都要把析构函数定义为虚函数；
	double GetArea() { return 3.14 * itsRadius * itsRadius; }
	double GetPerim() { return 2 * 3.14 * itsRadius; }
	void Draw();
private:
	int itsRadius;
};

void Circle::Draw()
{
	cout << "Circle drawing routine here!\n";
	Shape::Draw();
}

class Rectangle : public Shape
{
public:
	Rectangle(int len, int width):itsWidth(width),itsLength(len) {}
	virtual ~Rectangle() {}
	double GetArea() { return itsLength * itsWidth; }
	double GetPerim() { return 2 * itsLength*itsWidth; }
	virtual int GetLength() { return itsLength; }
	virtual int GetWidth() { return itsWidth; }
	void Draw();
private:
	int itsWidth;
	int itsLength;
};

void Rectangle::Draw()
{
	for (int i = 0; i < itsLength; i++)
	{
		for (int j = 0; j < itsLength; j++)
			cout << "x ";
		cout << "\n";
	}
	Shape::Draw();
}

class Square : public Rectangle
{
public:
	Square(int len);
	Square(int len, int width);
	virtual ~Square() {}
	double GetPerim() { return 4 * GetLength(); }
};

Square::Square(int len):Rectangle(len,len){} // 调用基类的函数来实现；
Square::Square(int len, int width):Rectangle(len,width)
{
	if (GetLength() != GetWidth())
		cout << "Error,not a square...a Rectangle??\n";
}

int main()
{
	//Shape a;// 错误，抽象类不能实例化；
	/* //测试代码：以下代码正确；
	Circle a(8);//因为派生类Circle将基类Shape中的纯虚函数都进行重写了，所以Circle不再是抽象类，所以可以实例化；
	a.Draw();

	Rectangle b(5, 10);
	b.Draw();

	cout << endl;

	Square c(8);
	c.Draw();
	*/

	int choice;
	bool fQuit = false;
	Shape *sp = nullptr;

	while (fQuit == false)
	{
		cout << "(1)Circle (2)Rectangle (3)Square (0)Quit: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			sp = new Circle(5); //如果是指针来创建对象需要用new来进行创建；
			break;
		case 2:
			sp = new Rectangle(4, 6);
			break;
		case 3:
			sp = new Square(5);
			break;
		case 0:
			fQuit = true;
			break;
		}
		if (fQuit == false)
		{
			sp->Draw();
			delete sp; // 对于new的对象，最后要delete；
			cout << endl;
		}
	}

	
	return 0;
}