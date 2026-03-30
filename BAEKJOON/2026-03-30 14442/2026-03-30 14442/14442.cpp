#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

struct Info
{
	int y, x, k;
};

const int INF = 1e9;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m, k;
vector<vector<int>> board;
vector<vector<vector<int>>> visited;

void bfs()
{
	queue<Info> q;
	visited[0][0][0] = 1;
	q.push({ 0, 0, 0 });

	while (q.size())
	{
		int y = q.front().y, x = q.front().x, ck = q.front().k;
		q.pop();

		if(y == n - 1 && x == m - 1)
		{
			cout << visited[y][x][ck] << "\n";
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i], nk = ck;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (board[ny][nx] == 1)
			{
				if (++nk <= k && visited[ny][nx][nk] == INF)
				{
					visited[ny][nx][nk] = visited[y][x][ck] + 1;
					q.push({ ny, nx, nk });
				}
				continue;
			}
			if (visited[ny][nx][nk] != INF) continue;

			visited[ny][nx][nk] = visited[y][x][ck] + 1;
			q.push({ ny, nx, nk });
		}
	}

	cout << -1 << "\n";
}

int main()
{
	cin >> n >> m >> k;

	board.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<vector<int>>(m, vector<int>(k + 1, INF)));

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = str[j] - '0';
		}
	}

	bfs();

	return 0;
}