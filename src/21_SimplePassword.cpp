/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第21题：简单密码
// 题目：通过手机按键数字对应字母对密码加密：1--1， abc--2, def--3, ghi--4, 
// jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0。把密码中出现的小写字母
// 都变成对应的数字，数字和其他的符号都不做变换。且密码中没有空格，密码中出现的大
// 写字母则变成小写之后往后移一位。
// 输入：密码明文
// 输出：加密密码

#include <iostream>
#include <string>

using namespace std;

char abc2num(char c)
{
	int n = c - 'a' + 1;
	if (n <= 3)
		return '2';
	else if (n <= 6)
		return '3';
	else if (n <= 9)
		return '4';
	else if (n <= 12)
		return '5';
	else if (n <= 15)
		return '6';
	else if (n <= 19)
		return '7';
	else if (n <= 22)
		return '8';
	else
		return '9';
}

void encrypt(string &s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		if (islower(s[i]))
			s[i] = abc2num(s[i]);
		if (isupper(s[i]))
		{
			if (s[i] != 'Z')
				s[i] = 'a' + s[i] - 'A' + 1;
			else
				s[i] = 'a';
		}
	}
}

int main(int argc, char const *argv[])
{
	string str;
	while (cin >> str)
	{
		encrypt(str);
		cout << str << endl;
	}
	return 0;
}