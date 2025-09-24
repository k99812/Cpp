#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Info
{
	int y, x, cnt;
};

const int INF = 1e9;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const int hy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
const int hx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int k, n, m;
vector<vector<int>> board;

bool isValid(int y, int x)
{
	if (y < 0 || x < 0 || y >= n || x >= m) return false;
	return true;
}

int bfs()
{
	if (board[0][0] == 1) return -1;

	vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(k + 1, INF)));
	queue<Info> q;
	q.push({ 0, 0, 0 });

	dist[0][0][0] = 0;
	
	while (q.size())
	{
		int y = q.front().y, x = q.front().x, cnt = q.front().cnt;
		q.pop();

		int ny, nx, ncnt;
		if (cnt < k)
		{
			for (int i = 0; i < 8; i++)
			{
				ny = y + hy[i], nx = x + hx[i], ncnt = cnt + 1;

				if (!isValid(ny, nx)) continue;
				if (dist[ny][nx][ncnt] != INF || board[ny][nx] == 1) continue;

				q.push({ ny, nx, ncnt });
				dist[ny][nx][ncnt] = dist[y][x][cnt] + 1;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			ny = y + dy[i], nx = x + dx[i], ncnt = cnt;

			if (!isValid(ny, nx)) continue;
			if (dist[ny][nx][ncnt] != INF || board[ny][nx] == 1) continue;

			q.push({ ny, nx, ncnt });
			dist[ny][nx][ncnt] = dist[y][x][cnt] + 1;
		}
	}

	int ret = INF;
	for (int i = 0; i <= k; i++)
	{
		ret = min(ret, dist[n - 1][m - 1][i]);
	}

	return ret == INF ? -1 : ret;
}

int main()
{
	cin >> k >> m >> n;

	board = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	cout << bfs() << "\n";

	return 0;
}