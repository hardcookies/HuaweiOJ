/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第8题：合并表记录
// 题目：数据表记录包含表索引和数值，请对表索引相同的记录进行合并，
// 即将相同索引的数值进行求和运算，输出按照key值升序进行输出。

#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n)
	{
		map<int, int> record;
		int index, value;
		while (n--)
		{
			cin >> index >> value;
			// 检查键值是否存在
			if (record.find(index) != record.end())
				record[index] += value;	
			else
				record[index] = value;
		}
		// map key本身就是按照从小到大排序
		for (auto iter = record.begin(); iter != record.end(); ++iter)
			cout << iter->first << " " << iter->second << endl;
	}
	return 0;
}