/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第9题：合并表记录
// 题目：输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
// 样例输入：
// 9876673
// 样例输出：
// 37689

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n)
	{
		int table[10];
		int result = 0;
		for (int i = 0; i < 10; ++i)
		{
			table[i] = 0;
		}
		while (n != 0)
		{
			int unit = n % 10;
			if (table[unit] == 0)
			{
				result = result * 10 + unit;
				table[unit]++;
			}
			n = n / 10;
		}
		cout << result << endl;
	}
	return 0;
}