/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第4题：字符串分隔
// 题目：连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
// 长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。

#include <iostream>
#include <string>

using namespace std;

void partition(string str)
{
    // 字符串为空
    if (str.empty())
        return;
    // 分隔子串的个数
    int n = str.size() / 8;
    // 输出完整子串
    for (int i = 0; i < n; ++i)
    {
        cout << str.substr(i*8, 8) << endl;
    }
    // 输出补齐部分
	if (str.size() % 8 == 0)
        return;
    string remainder = str.substr(n*8);
    string patch(8 - remainder.size(), '0');
    remainder = remainder + patch;
    cout << remainder << endl;
}
int main(int argc, char const *argv[])
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    partition(str1);
    partition(str2);    
    return 0;
}