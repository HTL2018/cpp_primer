#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<int, string> a;
	map<string, int> score;
	multimap<int, string> ma;

	//									key键 value值
	a.insert(map<int, string>::value_type(1, "One"));
	a.insert(map<int, string>::value_type(2, "Two"));
	a.insert(map<int, string>::value_type(3, "Three"));
	a.insert(make_pair(-1, "Minus One"));
	a.insert(pair<int, string>(1000, "One Thousand"));
	a[1000000] = "One Million";	//该方法不能用在multimap中，前面三个方法可以用；

	score.insert(make_pair("张飞", 99));
	score.insert(make_pair("刘备", 56));
	score["关羽"] = 87;

	cout << "最简单的查找：" << endl;	// map特有的操作；
	cout << score["刘备"] << endl;
	cout << a[3] << endl;

	cout << endl << endl;


	cout << "map里一共有：" << a.size() << "个key--value对数据" << endl;
	cout << "这些数据是：" << endl;
	map<int, string>::const_iterator i;
	for (i = a.begin(); i != a.end(); ++i)
	{
		cout << "Key: " << i->first;
		cout << "  Value: " << i->second.c_str();
		cout << endl;
	}

	ma.insert(multimap<int, string>::value_type(3, "Three"));
	ma.insert(multimap<int, string>::value_type(45, "Forty Five"));
	ma.insert(make_pair(-1, "Minus One"));
	ma.insert(pair<int, string>(1000, "One Thousand"));
	ma.insert(pair<int, string>(4, "Four"));
	ma.insert(pair<int, string>(1000, "One Thousand"));	//在于重复数据的时候就需要使用multimap;

	cout << endl << "multimap里有" << ma.size() << "个数据." << endl;
	multimap<int, string>::const_iterator im;
	for (im = ma.begin(); im != ma.end(); ++im)
	{
		cout << "Key: " << im->first;
		cout << " Value: " << im->second.c_str();
		cout << endl;
	}
	cout << "multimap里有" << ma.count(1000) << "个1000！" << endl;

	multimap<int, string>::const_iterator fi;
	fi = ma.find(45);
	if (fi != ma.end())
	{
		cout << "找到了:" << fi->first << "=" << fi->second.c_str();
	}
	else {
		cout << "没找到" << endl;
	}

	fi = ma.find(1000);
	if (fi != ma.end())
	{
		cout << "找到了1000！" << endl;
		size_t n = ma.count(1000);
		for (size_t i = 0; i < n; ++i)
		{
			cout << "\t Key: " << fi->first;
			cout << ", Value [" << i << "] =";
			cout << fi->second << endl;
			++fi;
		}
	}
	else {
		cout << "没找到1000！" << endl;
	}

	if (ma.erase(-1) > 0)
		cout << endl << "删除-1成功！" << endl;

	multimap<int, string>::iterator iElementFound = ma.find(45);
	if (iElementFound != ma.end())
	{
		ma.erase(iElementFound);
		cout << "删除45成功!" << endl;
	}

	for (im = ma.begin(); im != ma.end(); ++im)
	{
		cout << "Key: " << im->first;
		cout << " Value: " << im->second.c_str();
		cout << "1" << endl;
		cout << endl;
	}
	ma.erase(ma.lower_bound(1000), ma.upper_bound(1000));	// 删除了所有的1000键值对；
	for (im = ma.begin(); im != ma.end(); ++im)
	{
		cout << "Key: " << im->first;
		cout << " Value: " << im->second.c_str();
		cout << "2" << endl;
		cout << endl;
	}

	//system("pause");
	return 0;

}



