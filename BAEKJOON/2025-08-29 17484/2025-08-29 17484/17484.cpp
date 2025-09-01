#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 1e9;
const int dy[] = { 1, 1, 1 };
const int dx[] = { -1, 0, 1 };

int n, m;
vector<vector<int>> board;

int go(int y, int x, int dir)
{
	int ret = INF;

	for (int i = 0; i < 3; i++)
	{
		if (dir == i) continue;

		int ny = y + dy[i], nx = x + dx[i];

		if (nx < 0 || nx >= m) continue;
		if (ny >= n) return board[y][x];
		
		ret = min(ret, go(ny, nx, i) + board[y][x]);
	}

	return ret;
}

int main()
{
	cin >> n >> m;

	board = vector<vector<int>>(n, vector<int>(m));

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