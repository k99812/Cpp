#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m;
vector<vector<int>> grid, visited;

int go(int y, int x, int p, int dir)
{
	visited[y][x] = true;
	int ret = grid[y][x];

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;

		int cost = (dir == -1 || dir == i ? 1 : 2);
		
		if (p >= cost) ret = max(ret, go(ny, nx, p - cost, i) + grid[y][x]);
	}

	visited[y][x] = false;

	return ret;
}

int main()
{
	cin >> n >> m;

	grid = visited = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}

	int y, x, p;
	cin >> y >> x >> p;

	int ret = go(y, x, p, -1);

	cout << ret << "\n";

	return 0;
}