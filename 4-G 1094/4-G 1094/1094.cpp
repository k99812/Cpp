#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int x, ret;

int main()
{
	cin >> x;
	while (x != 1)
	{
		if (x & 1) ret++;
		x /= 2;
	}

	cout << ret + 1 << "\n";
	return 0;
}
