/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第11题：数字颠倒
// 题目：输入一个整数，将这个整数以字符串的形式逆序输出。

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string s;
	while (n)
	{
		s.push_back(n % 10 + '0');
		n /= 10;
	}
	cout << s << endl;
	return 0;
}