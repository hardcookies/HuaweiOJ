/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第24题：合唱队
// 题目：计算最少出列多少位同学，使得剩下的同学排成合唱队形。合唱队形是指这样的一
// 种队形：设K位同学从左到右依次编号为1，2，…，K，他们的身高分别为T1，T2，…，TK，
// 则他们的身高满足存在i（1<=i<=K）使得T1<T2<...<Ti-1<Ti>Ti+1>...>TK。
// 输入：第一行输入整数N，第二行输入N位同学的身高。
// 输出：最少需要列出的同学数目。

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	// 输入数据
	int n;
	while (cin >> n)	
	{
		int *arr = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		// lis[i]是以arr[i]结尾的最长递增序列的长度
		int *lis = new int[n];
		// lds[i]是以arr[i]起始的最长递减序列的长度
		int *lds = new int[n];

		for (int i = 0; i < n; ++i)
		{
			lis[i] = 1;
			lds[i] = 1;
		}

		// 计算lis[]
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
					lis[i] = lis[j] + 1;

		// 计算lds[]，相当于逆序计算lis[]
		for (int i = n - 2; i >= 0; --i)
			for (int j = n - 1; j > i; --j)
				if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
					lds[i] = lds[j] + 1;

		// lis和lds和最大时保证递增递减长度最大
		int maxLen = 0;
		for (int i = 0; i < n; ++i)
			if (maxLen < lis[i] + lds[i])
				maxLen = lis[i] + lds[i];

		// 输出结果
		cout << n - (maxLen - 1) << endl;
	}
	return 0;
}