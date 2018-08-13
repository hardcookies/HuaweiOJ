/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第3题：明明的随机数
// 题目：明明有一组随机数，请你完成“去重”和“排序”工作。
// 输入：输入多行，先输入随机数的个数，在分别输入随机数。
// 输出：返回多行，处理后的结果。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;    // number of random numbers
    cin >> n;
    int number;
    vector<int> array;
    for (int i = 0; i < n; ++i)
    {
        cin >> number;
        array.push_back(number);
    }
    
    // sort the numbers
    sort(array.begin(), array.end());
    
    // delete the repeated numbers
    for (auto it = array.begin(); it!= array.end(); )
    {
        if (*it == *(it-1))
            it = array.erase(it);
        else
            ++it;
    }
    
    // output the result
    // cout << "The result :" << endl;
    for (int i : array)
        cout << i << endl;
    
    return 0;
}