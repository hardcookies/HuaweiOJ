/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第7题：取近似值
// 题目：写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。
// 如果小数点后数值大于等于5,向上取整；小于5，则向下取整。

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	double a;
	while (cin >> a)
	{
		int b, c;
		b = a * 10;
		c = b - b/10*10;
		if (c >= 5)
			cout << b/10 + 1 << endl;
		else
			cout << b/10 << endl;
	}
	return 0;
}