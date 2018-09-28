/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第25题：数据分类处理
// 题目：采集输入大数据和分类规则，通过大数据分类处理程序，将大数据分类输出。

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef struct
{
	int pos;
	unsigned val;
}ElementInfo;

/* 返回num1是否连续包含num2的逻辑值 */
bool ContainNum(unsigned num1, unsigned num2)
{
	// 将数字转化为字符串以方便查找
	string str1 = to_string(num1);
	string str2 = to_string(num2);
	size_t found = str1.find(str2);
	if (found != string::npos)
		return true;
	else
		return false;
}

/* 返回数组arr中含有数字num的所有数的信息 */
vector<ElementInfo> ArrayContainNum(vector<unsigned> &arr, unsigned num)
{
	vector<ElementInfo> contain_result;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (ContainNum(arr[i], num))
		{
			ElementInfo element_info;
			element_info.pos = i;
			element_info.val = arr[i];
			contain_result.push_back(element_info);
		}
	}
	return contain_result;
}

int main(int argc, char const *argv[])
{
	// 输入数据
	int num_i, num_r;
	cin >> num_i;
	vector<unsigned> arr_i(num_i);
	for (int i = 0; i < num_i; ++i)
		cin >> arr_i[i];
	cin >> num_r;
	vector<unsigned> arr_r(num_r);
	for (int i = 0; i < num_r; ++i)
		cin >> arr_r[i];

	// 对arr_r进行排序
	sort(arr_r.begin(), arr_r.end());

	// 删除重复arr_r重复元素
	auto it = unique(arr_r.begin(), arr_r.end());
	arr_r.erase(it, arr_r.end());

	// 输出个数保存
	int total;

	// 根据规则处理数据
	for (int i = 0; i < arr_r.size(); ++i)
	{
		vector<ElementInfo> array_info = ArrayContainNum(arr_i, arr_r[i]);
		if (array_info.size() > 0)
		{
			cout << arr_r[i] << " " << array_info.size();
			for (auto element_info : array_info)
			{
				cout << " " << element_info.pos << " " << element_info.val;
			}
		}
	}
	return 0;
}