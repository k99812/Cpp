#include<iostream>
#include<algorithm>
#include<queue>

#define MAX_NUM 100 + 4

using namespace std;

struct cordi
{
	int z;
	int y;
	int x;
};

const int dy[] = { -1, 0, 1, 0, 0, 0 };
const int dx[] = { 0, 1, 0, -1, 0, 0 };
const int dz[] = { 0, 0, 0, 0, -1, 1 };
int n, m, h, a[MAX_NUM][MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM][MAX_NUM];
queue<cordi> q;

int bfs()
{
	while (q.size())
	{
		int z = q.front().z, y = q.front().y, x = q.front().x;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = z + dz[i], ny = y + dy[i], nx = x + dx[i];

			if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m) continue;
			if (a[nz][ny][nx] == -1) continue;
			if (visited[nz][ny][nx]) continue;

			visited[nz][ny][nx] = visited[z][y][x] + 1;
			q.push({ nz, ny, nx });
		}
	}

	int cnt = 0;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[k][i][j] == -1) continue;
				if (visited[k][i][j] == 0)
				{
					return 0;
				}
				cnt = max(cnt, visited[k][i][j]);
			}
		}
	}

	return cnt;
}

int main()
{
	cin >> m >> n >> h;

	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[k][i][j];
				if (a[k][i][j] == 1)
				{
					q.push({ k, i, j });
					visited[k][i][j] = 1;
				}
			}
		}
	}

	cout << bfs() - 1 << "\n";

	return 0;
}