/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第5题：进制转换
// 题目：写出一个程序，接受一个十六进制的数值字符串，输出
// 该数值的十进制字符串（支持多组同时输入）。

#include <iostream>
#include <string>

using namespace std;

void Hex2Dec(string hex)
{
	string table = "0123456789ABCDEF";

	string prefix = hex.substr(0, 2);
	if (prefix == "0X" || prefix == "0x")
	{
		int dex = 0;		// 十进制数

		// 转化为十进制
		for (int i = 2; i < hex.size(); ++i)
		{
			int index;
			for (int j = 0; j < 16; ++j)
			{
				if (hex[i] == table[j])
					index = j;
			}
			dex = dex * 16 + index;
		}

		// 输出结果
		cout << dex << endl;
	}
}

int main(int argc, char const *argv[])
{
	string hex;
	while (cin >> hex)
	{
		Hex2Dec(hex);
	}
	return 0;
}

/* 牛逼的解法 */
// int main(int argc, char const *argv[])
// {
// 	int a;
// 	while (cin >> hex >>a)
// 	{
// 		cout << a << endl;
// 	}
// 	return 0;
// }