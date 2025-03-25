#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Info
{
	int y,
		x,
		dir;
};

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const int leftTurn[] = { 3, 2, 0, 1 };
const int rightTurn[] = { 2, 3, 1, 0 };

int n, m;
vector<vector<int>> map;
vector<vector<vector<int>>> visited;
Info start, endpoint;

int bfs()
{
	queue<pair<Info, int>> q;
	q.push({ start, 0 });
	visited[start.y][start.x][start.dir] = true;

	while (q.size())
	{
		int y = q.front().first.y, x = q.front().first.x,
			dir = q.front().first.dir, cnt = q.front().second;
		q.pop();

		if (y == endpoint.y && x == endpoint.x && dir == endpoint.dir)
		{
			return cnt;
		}

		for (int i = 1; i <= 3; i++)
		{
			int ny = y + dy[dir] * i, nx = x + dx[dir] * i;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
			if (map[ny][nx]) break;
			if (visited[ny][nx][dir]) continue;

			visited[ny][nx][dir] = true;
			q.push({{ ny, nx, dir }, cnt + 1 });
		}

		int leftDir = leftTurn[dir], rightDir = rightTurn[dir];

		if (!visited[y][x][leftDir])
		{
			visited[y][x][leftDir] = true;

			q.push({{ y, x, leftDir }, cnt + 1 });
		}

		if (!visited[y][x][rightDir])
		{
			visited[y][x][rightDir] = true;

			q.push({{ y, x, rightDir }, cnt + 1 });
		}
	}

	return -1;
}

int main()
{
	cin >> n >> m;

	map.resize(n, vector<int>(m));
	visited.resize(n, vector<vector<int>>(m, vector<int>(4)));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	cin >> start.y >> start.x >> start.dir;
	cin >> endpoint.y >> endpoint.x >> endpoint.dir;

	start.y--, start.x--, start.dir--;
	endpoint.y--, endpoint.x--, endpoint.dir--;

	cout << bfs() << "\n";

	return 0;
}