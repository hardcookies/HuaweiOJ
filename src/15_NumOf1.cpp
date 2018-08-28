/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第15题：int型整数转二进制后1的个数
// 题目：输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int num = 0;
	while (n)
	{
		if (n & 1)
			++num;
		n = n >> 1;
	}
	cout << num << endl;
	return 0;
}