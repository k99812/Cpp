#include<iostream>
#include<algorithm>

#define MAX_NUM 1000 + 4
#define INF 1e9

using namespace std;

const int dx[] = { -1, 0, 1 };
int n, m, a[MAX_NUM][MAX_NUM], dp[MAX_NUM][MAX_NUM][4];

int go(int y, int x, int dir)
{
	if (y == n)
	{
		return 0;
	}

	int& ret = dp[y][x][dir];
	if (ret != INF) return ret;

	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];

		if (nx < 0 || nx >= m || dir == i) continue;

		ret = min(ret, go(y + 1, nx, i) + a[y][x]);
	}

	return ret;
}

int main()
{
	cin >> n >> m;

	fill(&dp[0][0][0], &dp[MAX_NUM - 1][MAX_NUM - 1][4], INF);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	int ret = INF;
	for (int i = 0; i < m; i++)
	{
		ret = min(ret, go(0, i, 3));
	}

	cout << ret << "\n";

	return 0;
}