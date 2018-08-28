/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第x题：汽水瓶
// 输入：n行正整数，表示空瓶数。0代表输入结束。
// 输出：每组一行，代表最多可以喝汽水数。

#include <iostream>

using namespace std;

/* 递归求解 */
int bottlesToDrink(int n)
{
	if (n < 2)
		return 0;
	if (n == 2)
		return 1;
	int bottles;
	bottles = n/3 + bottlesToDrink(n/3 + n%3);
	return bottles;
}

int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		cout << bottlesToDrink(n) << endl;
	}
	return 0;
}