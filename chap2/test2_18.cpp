#include <iostream>
int main()
{/*
	int i = 1;
	int a = 2;
	int b = 3;
	int *p = &i;
	
	std::cout << *p << std::endl;
        std::cout << p << std::endl;
	
	*p = 3;	//改变指针所指对象的值;
	
	std::cout << i << std::endl;

	std::cout << *p << std::endl;
	std::cout << p << std::endl;


        p = &b;  //改变指针的值;

        std::cout << *p << std::endl;
        std::cout << p << std::endl;
*/

	int a=0, b=1;
	int *p1=&a, *p2=p1; //p1存放着变量a的地址,或者说p1是指向变量a的指针;

	p1 = &b; //改变指针的值;

	std::cout << p1 << std::endl;

	std::cout << *p2 << std::endl;

	*p2 = b; //改变指针所指对象的值;

	std::cout << *p2 << std::endl;


	return 0;

}
