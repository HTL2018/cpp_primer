#include <iostream>

using  namespace std;

class Base {	//Äã°Ö°Ö
	friend class Frnd;
	friend class D2;
protected:
	int i;
};

// Äã
class D1 : public Base {
	friend class Frnd;
	friend class D2;
private:
	int j;
};

// ÎÒ°Ö°Ö
class Frnd {
public:
	int mem(Base b) { return b.i; }
	int mem(D1 d) { return d.j; }
};

// ÎÒ
class D2 : public Frnd {
public:
	int mem(Base b) { return b.i; }
	int mem(D1 d) { return d.j; }

};

int main()
{
	Base a;
	D1 b;
	Frnd c;
	D2 d;

	return 0;
}