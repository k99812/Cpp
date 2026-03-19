#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int n, m;
vector<vector<int>> board, visited;

bool bfs(pair<int, int> start)
{
	queue<pair<int, int>> q;
	q.push({ start });
	visited[start.first][start.second] = true;

	bool is_peak = true;
	int height = board[start.first][start.second];

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			
			if (board[ny][nx] > height)
			{
				is_peak = false;
			}
			
			if (!visited[ny][nx] && board[ny][nx] == height)
			{
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}

	return is_peak;
}

int main()
{
	cin >> n >> m;

	board.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]) continue;

			if (bfs({ i, j }))
			{
				cnt++;
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}