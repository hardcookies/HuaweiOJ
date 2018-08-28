/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第x题：假设一个球从任意高度自由落下，每次落地后反跳回原高度的一半;
// 再落下, 求它在第5次落地时，共经历多少米?第5次反弹多高？
// 输入：高度
// 输出：共经过多少米 第5次反弹高度

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	double height;
	while (cin >> height)
	{
		double journey = 0;
		for (int i = 0; i < 5; ++i)
		{
			journey += 1.5 * height;	// 第n次弹起后经历路程
			height /= 2;				// 第n次弹起后高度
		}

		// 落地高度需减去弹起高度
		cout << journey - height << endl;
		cout << height << endl;
	}
	return 0;
}

// 测试用例有问题，我明明正确显示返回为空。
// 76785
// 220757
// 2399.53
// 没有问题，发现牛客网的输入最好是 while (cin >> n)