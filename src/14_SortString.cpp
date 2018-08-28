/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第14题：字串的连接最长路径查找
// 题目：给定n个字符串，请对n个字符串按照字典序排列。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<string> s;
	while (n--)
	{
		string str;
		cin >> str;
		s.push_back(str);
	}
	// 比较模版函数，默认从小到大。greater<string>()
	sort(s.begin(), s.end());
	for (string str : s)
		cout << str << endl;
	return 0;
}