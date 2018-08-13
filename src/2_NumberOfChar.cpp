/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第2题：计算字符个数
// 题目：写出一个程序，接受一个由字母和数字组成的字符串，和一个
// 字符，然后输出输入字符串中含有该字符的个数。不区分大小写。

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    char c;
    cin >> s >> c;
    
    int num = 0;
    for (char ch : s)
    {
        if (toupper(ch) == toupper(c))
            ++num;
    }
    cout << num;

    return 0;
}