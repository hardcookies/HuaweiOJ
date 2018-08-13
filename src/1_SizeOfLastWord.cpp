/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第1题：字符串最后一个单词的长度
// 题目：计算字符串最后一个单词的长度，单词以空格隔开。
// 输入：一行字符串，非空，长度小于5000。
// 输出：整数N，最后一个单词的长度。

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    
    istringstream iss(str);
    string word;
    while(iss >> word)
        ;
    cout << word.size();
    
    return 0;
}