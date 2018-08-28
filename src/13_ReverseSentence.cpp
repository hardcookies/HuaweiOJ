/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第13题：句子逆序
// 题目：将一个英文语句以单词为单位逆序排放。

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
	string word;
	stack<string> sstack;
	while (cin >> word)
		sstack.push(word);
	string reverse;
	while (!sstack.empty())
	{
		reverse.append(sstack.top());
		sstack.pop();
		if (!sstack.empty())
			reverse.append(" ");
	}
	cout << reverse << endl;
	return 0;
}