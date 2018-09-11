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
// 思路：找到中间点，左边求LIS，右边求LDS (逆序LIS)，比较所有中间点。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* binary search the first number > num */
int ceilIndex(vector<int> &nums, int n, int num)
{
    int start = 0, end = n - 1;
    while (end - start > 1)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] >= num)
            end = mid;
        else
            start = mid;
    }
    return end;
}

/* The length LIS (longest increasing subsequence) */
int LIS(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    vector<int> tail(nums.size(), 0);
    int length = 1;
    
    tail[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] < tail[0])
            // new smallest value
            tail[0] = nums[i];
        else if (nums[i] > tail[length - 1])
            // nums[i] extends largest subsequence
            tail[length++] = nums[i];
        else
            // find the best candidate and discard same length lists
            tail[ceilIndex(tail, length, nums[i])] = nums[i];
    }
    
    return length;
}

/* 对所给队形指定最高位置，使其左侧为LIS，右侧为LDS，返回总长度。 */
int LIDS(vector<int> &queue, int pos)
{
	int result;
	vector<int> left, right;

	for (int i = 0; i <= pos; ++i)
		left.push_back(queue[i]);
	for (int i = queue.size() - 1; i >= pos; --i)
		right.push_back(queue[i]);

	result = LIS(left) + LIS(right) - 1;
	return result;
}

int main(int argc, char const *argv[])
{
	// 输入数据
	int n;
	while (cin >> n)
	{
		vector<int> line;
		for (int i = 0; i < n; ++i)
		{
			int height;
			cin >> height;
			line.push_back(height);
		}

		// 指定最高位置位于首位之间得到LIDS
		int maxLen = 0;
		for (int i = 0; i < line.size(); ++i)
		{
			maxLen = max(maxLen, LIDS(line, i));
		}

		// 踢出人数为总人数减去最长
		cout << line.size() - maxLen << endl;
	}

	return 0;
}