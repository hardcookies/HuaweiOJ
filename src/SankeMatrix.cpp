/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第x题：蛇形矩阵
// 题目：蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。
// 函数：void GetResult(int Num, int * pResult);
// 说明：int Num: 正整数N，int* rResult: 指向存放蛇形矩阵的字符串指针
// 输出：打印出蛇形矩阵

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
 {
 	int n;
 	cin >> n;

 	// 定义起始数字
 	int beg = 1;

 	// 输出n行
 	for (int i = 1; i <= n; ++i)
 	{
 		// 输出每行起始数字，与下一行起始数字间隔为i。
 		cout << beg << " ";

 		// 输出该行剩下n-i个数，初始间隔为i+1，之后间隔加1。
 		int item = beg;
 		for (int j = 0, step = i + 1; j < n-i; j++, ++step)
 		{
 			item += step;
 			cout << item << " ";
 		}

 		// 换行
 		cout << endl;
 		beg += i;
 	}
 	return 0;
 } 
