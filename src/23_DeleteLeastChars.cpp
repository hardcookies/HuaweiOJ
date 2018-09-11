/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第23题：删除字符串中出现次数最少的字符
// 题目：实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。
// 输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。

#include <iostream>
#include <climits>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	while (cin >> str)
	{
		// 建立字符-出现次数表
		map<char, int> map;
		for (auto c : str)
		{
			if (map.find(c) == map.end())
				map[c] = 1;		// map中不存在
			else
				map[c]++;		// map中存在
		}

		// 查找出现次数最少字符
		set<char> lch;
		int least = INT_MAX;
		for (auto iter = map.begin(); iter != map.end(); ++iter)
		{
			if (iter->second < least)
				least = iter->second;
		}
		for (auto iter = map.begin(); iter != map.end(); ++iter)
		{
			if (iter->second == least)
				lch.insert(iter->first);
		}

		// 删除出现次数最少的字符
		auto it = str.begin();
		while (it != str.end())
		{
			if (lch.count(*it))
				str.erase(it);
			else
				++it;
		}

		// 输出结果
		cout << str << endl;
	}
	return 0;
}