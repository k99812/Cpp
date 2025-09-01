#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 1e9;
const int dx[] = { -1, 0, 1 };

int n, m;
vector<vector<int>> board;
vector<vector<vector<int>>> dp;

int go(int y, int x, int dir)
{
	if (y == n) return 0;

	int& ret = dp[y][x][dir + 1];
	if (ret != INF) return ret;

	for (int i = 0; i < 3; i++)
	{
		int ny = y + 1, nx = x + dx[i];

		if (nx < 0 || nx >= m || dir == i) continue;

		ret = min(ret, go(ny, nx, i) + board[y][x]);
	}

	return ret;
}

int main()
{
	cin >> n >> m;

	board = vector<vector<int>>(n, vector<int>(m));
	dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(4, INF)));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	int ans = INF;
	for (int i = 0; i < m; i++)
	{
		ans = min(ans, go(0, i, -1));
	}

	cout << ans << "\n";

	return 0;
}