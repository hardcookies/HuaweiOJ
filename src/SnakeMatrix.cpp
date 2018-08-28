/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第x题：蛇形矩阵
// 题目：蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。
// 输入：行数N
// 输出：打印出一个N行的蛇形矩阵
// 样例输入
// 4
// 样例输出
// 1 3 6 10
// 2 5 9
// 4 8
// 7

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n)
	{
		// 定义起始数字
	 	int beg = 1;

	 	// 输出n行
	 	for (int i = 1; i <= n; ++i)
	 	{
	 		// 输出每行起始数字，与下一行起始数字间隔为i。
	 		cout << beg;

	 		// 输出该行剩下n-i个数，初始间隔为i+1，之后间隔加1。
	 		int item = beg;
	 		for (int j = 0, step = i + 1; j < n-i; j++, ++step)
	 		{
	 			item += step;
	 			cout << " " << item;
	 		}

	 		// 换行
	 		cout << endl;
	 		beg += i;
	 	}
	}
	return 0;
}
