#include <iostream>
int main()
{
	int i = 0, &r = i;
	
	auto a = r;
	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	auto &g = ci;

	std::cout << a << std::endl;	
	a =  42;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	b = 42;
	std::cout << a << std::endl;
	std::cout << c << std::endl;
	c = 42;
	std::cout << c << std::endl;
	
	int f = 42;
	d = &f;
	
	//e = 42;
	//g = 42;
	return 0;

}
