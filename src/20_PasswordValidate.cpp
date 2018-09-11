/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第20题：密码验证合格程序
// 题目：密码要求：1.长度超过8位；2.包括大小写字母、数字、其他符号，以上四种至少三种。
// 3.不能有相同长度超过2的子串重复。
// 输入：一组或多组长度超过2的字符串。每组占一行。
// 输出：如果符合要求输出：OK，否则输出NG。

#include <iostream>
#include <string>

using namespace std;

/* 返回最长重复子串长度 */
int LRSubStr(string s)
{
	int n = s.size();

	// LCSRe(Longest Common Repeating Suffix)
	int LCSRe[n+1][n+1];
	int result = 0;

	memset(LCSRe, 0, sizeof(LCSRe));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = i+1; j <= n; ++j)
		{
			// 为防止重叠要求(j-i) > LCSRe[i-1][j-1]
			if (s[i-1] == s[j-1] && LCSRe[i-1][j-1] < (j-i))
			{
				LCSRe[i][j] = LCSRe[i-1][j-1] + 1;

				// 更新最长长度
				if (LCSRe[i][j] > result)
					result = LCSRe[i][j];
			}
			else
				LCSRe[i][j] = 0;
		}
	}
	return result;
}

bool isValidate(string s)
{
	// 第1个条件
	if (s.size() <= 8)
		return false;

	// 第2个条件
	int character[4] = {0};
	for (int i = 0; i < s.size(); ++i)
	{
		if (isupper(s[i]))
			character[0] = 1;
		else if (islower(s[i]))
			character[1] = 1;
		else if (isdigit(s[i]))
			character[2] = 1;
		else
			character[3] = 1;
	}
	if (character[0] + character[1] + character[2] + character[3] < 3)
		return false;

	//第3个条件
	if (LRSubStr(s) > 2)
		return false;
	else
		return true;
}
int main(int argc, char const *argv[])
{
	string str;
	while (cin >> str)
	{
		if (isValidate(str))
			cout << "OK" << endl;
		else
			cout << "NG" << endl;
	}
	return 0;
}