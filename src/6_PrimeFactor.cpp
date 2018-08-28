/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第6题：质数因子
// 题目：输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）

#include <iostream>
#include <string>

using namespace std;

/* 函数声明 */
bool isPrime(int n);
int MinPrime(long n);

/* 判断质数 */
bool isPrime(int number)
{
	for (int i = 2; i < number; ++i)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}

/* 最小质数因子 */
int MinPrimeFactor(long number)
{
	for (int i = 2; i < number; ++i)
	{
		if (number % i == 0)
		{
			if (isPrime(i))
				return i;
		}
	}
	return number;
}

/* 接口函数 */
string getResult(long DataInput)
{
	string result;
	int mp;
	while (DataInput != 1)
	{
		mp = MinPrimeFactor(DataInput);
		result = result + to_string(mp) + " ";
		DataInput = DataInput / mp;
	}
	return result;
}

/* 测试程序 */
int main(int argc, char const *argv[])
{
	long input;
	cin >> input;
	cout << getResult(input) << endl;
	return 0;
}