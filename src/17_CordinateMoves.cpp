/*******************************************************************
Copyright(c) 2018, James Fan
All rights reserved.
*******************************************************************/

// 华为机试在线训练
// 第17题：坐标移动
// 题目：开发一个坐标计算工具，A表示向左移动，D表示向右移动，W表示向上移动，S表示
// 向下移动。从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果
// 输出到输出文件里面。
// 输入：合法坐标为方向+数字（两位以内），坐标之间以;分隔，非法坐标需要丢弃。
// 输出：当前位置坐标

/* 本地编译运行通过测试用例 17_1.input，牛客网无法通过。*/

#include <iostream>
#include <string>

using namespace std;

void vaildMove(string& move, int& x, int& y)
{
	int n = move.size();
	if (n > 1 && n < 4)
	{
		char dirc = move[0];
		int step = 0;
		if (n == 2 && isdigit(move[1]))
			step = move[1] - '0';
		if (n == 3 && isdigit(move[1]) && isdigit(move[2]))
			step = 10 * (move[1] - '0') + move[2] - '0';
		switch (dirc)
		{
			case 'A':
				x -= step;
				break;
			case 'D':
				x += step;
				break;
			case 'W':
				y += step;
				break;
			case 'S':
				y -= step;
				break;
		}
	}
}

int main(int argc, char const *argv[])
{
	int x = 0, y = 0;
	string s;
	while (cin >> s)
	{
		// 以;分隔字符串，得到每一步move
		string::size_type pos1, pos2;
		string move;
		pos2 = s.find(';');
		pos1 = 0;
		while (pos2 != string::npos)
		{
			move = s.substr(pos1, pos2-pos1);
			pos1 = pos2 + 1;
			pos2 = s.find(';', pos1);
			// 若合法则执行
			vaildMove(move, x, y);
		}
		// 输出最后坐标位置
		cout << x << ',' << y << endl;
	}
	return 0;
}