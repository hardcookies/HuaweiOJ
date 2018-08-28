/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第10题：字符个数统计
// 题目：编写一个函数，计算字符串中含有的不同字符的个数。
// 字符在ACSII码范围内(0~127)。不在范围内的不作统计。

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char c;
	int num[128] = {0};
	int count = 0;
	while ((c = getchar()) != EOF)
	{
		if (c >= 0 && c <= 127)
			num[c]++;
	}
	for (int i = 0; i < 128; ++i)
	{
		if (num[i] > 0)
			++count;
	}
	cout << count << endl;
	return 0;
}