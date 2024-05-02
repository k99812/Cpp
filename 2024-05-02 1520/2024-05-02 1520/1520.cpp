#include<iostream>
#include<algorithm>

#define MAX_NUM 500 + 4

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, a[MAX_NUM][MAX_NUM], dp[MAX_NUM][MAX_NUM];

int go(int y, int x)
{
	if (y == n - 1 && x == m - 1)
	{
		return 1;
	}

	int& ret = dp[y][x];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny > n || nx > m) continue;
		if (a[ny][nx] >= a[y][x]) continue;

		ret += go(ny, nx);
	}

	return ret;
}

int main()
{
	cin >> n >> m; 

	fill(&dp[0][0], &dp[MAX_NUM - 1][MAX_NUM], -1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	cout << go(0, 0) << "\n";

	return 0;
}