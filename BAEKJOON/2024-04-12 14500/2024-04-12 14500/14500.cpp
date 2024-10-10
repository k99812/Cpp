#include<iostream>
#include<algorithm>

#define MAX_NUM 500 + 4

using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, 1 };
int n, m, a[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM], ret = -1;

void dfs(int y, int x, int idx, int score)
{
	if (idx == 4)
	{
		ret = max(ret, score);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny > n || nx > m) continue;
		if (visited[ny][nx]) continue;

		visited[ny][nx] = 1;
		dfs(ny, nx, idx + 1, score + a[ny][nx]);
		visited[ny][nx] = 0;
	}

	if (y + 1 < n && x - 1 >= 0 && x + 1 < m)
	{
		ret = max(ret, a[y][x - 1] + a[y][x] + a[y][x + 1] + a[y + 1][x]);
	}
	if (y - 1 >= 0 && x - 1 >= 0 && x + 1 < m)
	{
		ret = max(ret, a[y][x] + a[y - 1][x] + a[y][x - 1] + a[y][x + 1]);
	}
	if (y - 1 >= 0 && x - 1 >= 0 && y + 1 < n)
	{
		ret = max(ret, a[y][x] + a[y - 1][x] + a[y + 1][x] + a[y][x - 1]);
	}
	if (y - 1 >= 0 && x + 1 < m && y + 1 < n)
	{
		ret = max(ret, a[y][x] + a[y - 1][x] + a[y + 1][x] + a[y][x + 1]);
	}
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

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = 1;
			dfs(i, j, 1, a[i][j]);
			visited[i][j] = 0;
		}
	}

	cout << ret << "\n";

	return 0;
}