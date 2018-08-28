#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int c;
	int n = 0;
	while ((c = getchar()) != EOF)
	{
		++n;
		cout << c << endl;
	}
	cout << "total: " << n << endl;
	// 文件里的输入会自带一个换行？是的 LF
	return 0;
}