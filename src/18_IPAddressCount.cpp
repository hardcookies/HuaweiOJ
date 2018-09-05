/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第18题：识别有效的IP地址和掩码并进行分类统计
// 题目：请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，
// 不合法的地址和掩码单独归类。 
// 输入：多行字符串。每行一个IP地址和掩码，用~隔开。
// 输出：统计A、B、C、D、E、错误IP地址或错误掩码、私有IP的个数，中间以空格隔开。

/* 我知道为什么之前的错误了，因为不合法则单独归类 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 将字符串转化为数字，-1代表错误值。
int byte2int(string byte)
{
	int num = 0;
	if (byte.empty())
		return -1;
	for (int i = 0; i < byte.size(); ++i)
	{
		if (isdigit(byte[i]))
			num = num * 10 + byte[i] - '0';
		else
			return -1;
	}
	if (num > 255)
		num = -1;
	return num;
}

// 分隔各个字段数值，并添加到vector中。
void getBytes(string& s, vector<int>& v)
{
	string::size_type pos1, pos2;
	string a_byte;
	pos2 = s.find('.');
	pos1 = 0;
	while (pos2 != string::npos)
	{
		a_byte = s.substr(pos1, pos2-pos1);
		v.push_back(byte2int(a_byte));
		pos1 = pos2 + 1;
		pos2 = s.find('.', pos1);
	}
	if (pos1 != s.size())
		v.push_back(byte2int(s.substr(pos1)));
}


void getResult(int cnt[7], vector<int>& address, vector<int>& mask)
{
	// 检查IP地址是否有效
	bool addValid = true;
	if (address.size() != 4)
		addValid = false;
	for (int i = 0; i < 4; ++i)
	{
		if (address[i] == -1)
			addValid = false;
	}

	// 检查掩码格式是否有效
	bool maskValid = true;
	if (mask.size() != 4)
		maskValid = false;
	for (int i = 0; i < 4; ++i)
	{
		if (mask[i] == -1)
			maskValid = false;
	}

	// 格式没错，判断内容。
	if (maskValid)
	{
		maskValid = false;
		long bm;
		bm = (mask[0] << 24) | (mask[1] << 16) | (mask[2] << 8) | mask[3];
		for (int i = 1; i < 32; ++i)
		{
			if (bm == ~((1 << i) - 1))
			{
				maskValid = true;
				break;
			} 
		}
	}

	// 对IP地址和掩码分类
	if (addValid && maskValid)
	{
		// 划分5类
		if (address[0] > 0 && address[0] < 127)
			cnt[0]++;
		if (address[0] > 127 && address[0] < 192)
			cnt[1]++;
		if (address[0] > 191 && address[0] < 224)
			cnt[2]++;
		if (address[0] > 223 && address[0] < 240)
			cnt[3]++;
		if (address[0] > 239)
			cnt[4]++;

		// 判断私网
		if (address[0] == 10)
			cnt[6]++;
		if (address[0] == 172 && address[1] > 15 && address[1] < 32)
			cnt[6]++;
		if (address[0] == 192 && address[1] == 168)
			cnt[6]++;
	}
	else
		cnt[5]++;
}

int main(int argc, char const *argv[])
{
	string str;
	int count[7] = {0};			// 分别代表A, B, C, D, E, e, p计数。
	while (cin >> str)
	{
		string address, mask;
		vector<int> address_val, mask_val;
		string::size_type pos;

		// 以~分隔字符串，得到IP地址和掩码字符串。
		pos = str.find('~');
		address = str.substr(0, pos);
		mask = str.substr(pos+1);

		// 得到地址和掩码数值
		getBytes(address, address_val);
		getBytes(mask, mask_val);

		// 检验并处理地址及掩码
		getResult(count, address_val, mask_val);

	}
	// 输出结果
	for (int i = 0; i < 7; ++i)
		cout << count[i] << " ";
	return 0;
}