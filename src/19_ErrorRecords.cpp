/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第19题：简单错误记录
// 题目：开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
// 输入：一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
// 输出：将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct
{
	string name;
	int line;
	int num;
}Error;

int main(int argc, char const *argv[])
{
	vector<Error> errors;
	string str;
	int n;
	while (cin >> str >> n)
	{
		// 确定文件名称
		string name = str;
		for (int i = str.size() - 1; i >= 0; --i)
		{
			if (str[i] == '\\')
			{
				name = str.substr(i + 1);
				break;
			}
		}
		if (name.size() > 16)
			name = name.substr(name.size() - 16);
		
		// 已有记录中查找
		bool found = false;
		for (int i = 0; i < errors.size(); ++i)
		{
			if (errors[i].name == name && errors[i].line == n)
			{
				errors[i].num++;
				found = true;
				break;
			}
		}

		// 没有找到则添加新的记录
		if (!found)
		{
			Error e;
			e.name = name;
			e.line = n;
			e.num = 1;
			errors.push_back(e);
		}

		// 保持最多八条记录
		if (errors.size() > 8)
		{
			errors.erase(errors.begin());
		}
	}

	// 输出结果
	for (int i = 0; i < errors.size(); i++)
		cout << errors[i].name << " " << errors[i].line << " " << errors[i].num << endl;
	return 0;
}