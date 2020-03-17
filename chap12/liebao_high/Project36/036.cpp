#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//int compare(const double &v1, const double &v2)
//{
//	if (v1 < v2) return -1;
//	if (v1 > v2) return 1;
//	return 0;
//}
//
//int compare(const string &v1, const string &v2)
//{
//	if (v1 < v2) return -1;
//	if (v1 > v2) return 1;
//	return 0;
//}

template <typename T> // typename也可以写class; T也可以用其他代替，比如用Object代替T，但是下面的T都要换成Object；
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) return -1;
	if (v1 > v2) return 1;
	return 0;
}

template <class T>
T absVal(T val) // 由此可知函数的返回值类型和传入的参数类型一致；可以实现求绝对值的功能；
{
	return val > 0 ? val : -val;
}

template<typename T1, typename T2>
T1& print(T1& s, T2 val) // 可以通过选择将val输出到s中，s可以是文件流，也可以是字符串流；
{
	s << val;
	return s;
}

template <class T>
const T& bigger(const T& v1, const T& v2) //返回两者中的大数；注意此处因为传入类型为const，且返回的是v1或者v2中的一个，所以返回值类型应该加上const；
{
	return v1 > v2 ? v1 : v2;
}

int main()
{
	double dval = -0.88;
	float fval = -12.3;
	string oristr = "this is a test.";
	string desstr;
	ostringstream oss(desstr);
	ofstream outFile("result.dat");

	print(cout, -3) << endl;//此时T2为int;
	print(cout, dval) << endl;//此时T2为double;
	print(cout, fval) << endl;//此时T2为float;
	print(cout, oristr) << endl;//此时T2为字符串流;
	cout << endl;

	//输出到文件
	print(outFile, -3) << endl;
	print(outFile, dval) << endl;
	print(outFile, fval) << endl;
	print(outFile, oristr) << endl;
	outFile.close();// 关闭文件；

	//输出到字符串流
	print(oss, -3) << endl;
	print(oss, dval) << endl;
	print(oss, fval) << endl;
	print(oss, oristr) << endl;
	cout << oss.str() << endl; //将oss进行输出；

	cout << absVal(dval) << endl;
	cout << absVal(fval) << endl;

	double d1 = 1.11;
	double d2 = 9.56;
	cout << compare(d1, d2) << endl;//此处c++会自动从函数模板实例化出对应的类型；此处实例化出double类型的函数；

	string s1("hihihi");
	string s2("world");
	cout << compare(s1, s2) << endl;//此处c++会自动从函数模板实例化出对应的类型；此处实例化出string类型的函数；

	cout << endl;
	double a = 1.23;
	double b = 5.89;
	cout << bigger(a, b) << endl;
	cout << bigger(s1, s2) << endl;

	return 0;
}