#include<iostream>
#include<algorithm>

using namespace std;

int n, a[20][20], dp[20][20][3];

bool check(int y, int x, int dir)
{
	if (dir == 0 || dir == 2)
	{
		if (a[y][x] == 0) return true;
	}
	else if (dir == 1)
	{
		if (a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0) return true;
	}
	return false;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	dp[0][1][0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];

			if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

			if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
			if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];
		}
	}

	int ret = dp[n][n][0];
	ret += dp[n][n][1]; ret += dp[n][n][2];

	cout << ret << "\n";

	return 0;
}