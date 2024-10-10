#include<iostream>
#include<algorithm>

#define MAX_NUM 1000 + 4

using namespace std;

const int dy[] = { 1, 0, 1 };
const int dx[] = { 0, 1, 1 };
int n, m, a[MAX_NUM][MAX_NUM], dp[MAX_NUM][MAX_NUM];

int dfs(int y, int x)
{
	if (y == n - 1 && x == m - 1)
	{
		return a[y][x];
	}

	int& ret = dp[y][x];
	if (ret != -1) return ret;

	for (int i = 0; i < 3; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		ret = max(ret, dfs(ny, nx) + a[y][x]);
	}

	return ret;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	fill(&dp[0][0], &dp[MAX_NUM - 1][MAX_NUM], -1);
	cout << dfs(0, 0) << "\n";

	return 0;
}