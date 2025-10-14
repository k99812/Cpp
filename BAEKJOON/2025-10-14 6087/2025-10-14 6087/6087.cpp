#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

const int INF = INT32_MAX;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m;
vector<vector<int>> board, dist;
pair<int, int> start, end_;

void bfs()
{
	queue<pair<int, int>> q;

	q.push(start);
	dist[start.first][start.second] = 0;

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			while (true)
			{
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				if (board[ny][nx] == 1) break;

				if (dist[ny][nx] == INF)
				{
					dist[ny][nx] = dist[y][x] + 1;
					q.push({ ny, nx });
				}

				ny = ny + dy[i];
				nx = nx + dx[i];
			}
		}
	}
}

int main()
{
	cin >> m >> n;

	start = { -1, -1 };
	board = vector<vector<int>>(n, vector<int>(m));
	dist = vector<vector<int>>(n, vector<int>(m, INF));

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == '.') board[i][j] = 0;
			else if (s[j] == '*') board[i][j] = 1;
			else
			{
				board[i][j] = 2;
				if (start.first == -1) start = { i, j };
				else end_ = { i, j };
			}
		}
	}

	bfs();

	cout << dist[end_.first][end_.second] - 1 << "\n";

	return 0;
}