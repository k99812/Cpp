#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m;
vector<vector<int>> board, dp;

int dfs(int y, int x)
{
	if (y < 0 || x < 0 || y >= n || x >= m) return 1;

	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;

	int dir = board[y][x];
	int ny = y + dy[dir], nx = x + dx[dir];

	return dp[y][x] = dfs(ny, nx);
}

int main()
{
	cin >> n >> m;

	board = vector<vector<int>>(n, vector<int>(m));
	dp = vector<vector<int>>(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			if (str[j] == 'U') board[i][j] = 0;
			else if (str[j] == 'R') board[i][j] = 1;
			else if (str[j] == 'D') board[i][j] = 2;
			else board[i][j] = 3;
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dfs(i, j) == 1) ret++;
		}
	}

	cout << ret << "\n";

	return 0;
}