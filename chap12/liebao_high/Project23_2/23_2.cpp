#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// 定义二元谓词；实现功能：将字符串全部转化为小写；
class CCompareStringNoCase
{
public:
	bool operator() (const string& str1, const string& str2) const
	{
		string str1LowerCase;
		str1LowerCase.resize(str1.size());
		transform(str1.begin(), str1.end(), str1LowerCase.begin(), tolower); // 调用STL算法将 str1 全部转换为小写；

		string str2LowerCase;
		str2LowerCase.resize(str2.size());
		transform(str2.begin(), str2.end(), str2LowerCase.begin(), tolower); // 调用STL算法将 str2 全部转换为小写；

		return (str1LowerCase < str2LowerCase);
	}
};
int main()
{
	//set<string> names;
	set<string,CCompareStringNoCase> names;	// 增加二元谓词，实现不分大小写都能进行查找的功能；
	names.insert("Tina");
	names.insert("jim");
	names.insert("HTL2018");
	names.insert("Sam");
	names.insert("hello");

	set<string, CCompareStringNoCase>::iterator iNameFound = names.find("htl2018");
	if (iNameFound != names.end())
	{
		cout << "找到了！" << *iNameFound << endl;
	}
	else
	{
		cout << "没找到！" << *iNameFound << endl;
	}
	return 0;
}