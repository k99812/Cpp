#include<iostream>
#include<algorithm>

#define MAX_N 54

using namespace std;

int a, b, c, dp[MAX_N][MAX_N][MAX_N];

int go(int x, int y, int z)
{
	if (x <= 0 || y <= 0 || z <= 0)
	{
		return 1;
	}
	else if (x > 20 || y > 20 || z > 20)
	{
		return go(20, 20, 20);
	}

	int& ret = dp[x][y][z];
	if (ret) return ret;

	if (x < y && y < z)
	{
		ret = go(x, y, z - 1) + go(x, y - 1, z - 1) - go(x, y - 1, z);
	}
	else
	{
		ret = go(x - 1, y, z) + go(x - 1, y - 1, z) + go(x - 1, y, z - 1) - go(x - 1, y - 1, z - 1);
	}

	return ret;
}

int main()
{
	while (cin >> a >> b >> c)
	{
		if (a == -1 && b == -1 && c == -1) break;
		fill(&dp[0][0][0], &dp[MAX_N - 1][MAX_N - 1][MAX_N], 0);

		cout << "w(" << a << ", " << b << ", " << c << ") = " << go(a, b, c) << "\n";
	}

	return 0;
}