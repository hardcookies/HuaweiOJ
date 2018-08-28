/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第12题：字符串反转
// 题目：写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	while (cin >> s)
	{
		int n = s.size();
		for (int i = 0; i < n/2; i++)
		{
			char temp = s[i];
			s[i] = s[n-1-i];
			s[n-1-i] = temp;
		}
		cout << s << endl;
	}
	return 0;
}