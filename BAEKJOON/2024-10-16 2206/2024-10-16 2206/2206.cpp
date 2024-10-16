#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

#define MAX_NUM 1000 + 4
#define INF 1e9

using namespace std;

struct Data
{
	int y,
		x,
		bWallIsDestroy;
};

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, a[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM][2];

int bfs()
{
	queue<Data> q;
	q.push({ 0,0,0 });
	visited[0][0][0] = 1;

	while (q.size())
	{
		int y = q.front().y, x = q.front().x, bWallIsDestroy = q.front().bWallIsDestroy;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx][bWallIsDestroy] != INF) continue;
			if (a[ny][nx] == 1)
			{
				if (bWallIsDestroy) continue;
				else
				{
					int NextWall = 1;
					visited[ny][nx][NextWall] = visited[y][x][bWallIsDestroy] + 1;
					q.push({ ny, nx, NextWall });
				}
			}
			else
			{
				visited[ny][nx][bWallIsDestroy] = visited[y][x][bWallIsDestroy] + 1;
				q.push({ ny, nx, bWallIsDestroy });
			}
		}
	}

	if (visited[n - 1][m - 1][0] == INF && visited[n - 1][m - 1][1] == INF) return -1;
	else
	{
		return min(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1]);
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j] - '0';
		}
	}

	fill(&visited[0][0][0], &visited[MAX_NUM - 1][MAX_NUM - 1][2], INF);

	cout << bfs() << "\n";

	return 0;
}