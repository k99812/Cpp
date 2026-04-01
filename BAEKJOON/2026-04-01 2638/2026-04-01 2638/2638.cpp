#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m;
vector<vector<int>> board, visited;

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (q.size())
	{
		int cy = q.front().first, cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] || board[ny][nx] == 1) continue;

			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
}

int go()
{
	int cnt = 0;
	while (true)
	{
		bool isClear = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1)
				{
					isClear = false;
					break;
				}
			}

			if (!isClear) break;
		}

		if (isClear) break;

		visited.assign(n, vector<int>(m, 0));
		bfs(0, 0);

		vector<pair<int, int>> target;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1)
				{
					int empty = 0;
					for (int d = 0; d < 4; d++)
					{
						int ny = i + dy[d], nx = j + dx[d];

						if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
						if (board[ny][nx] == 0 && visited[ny][nx] == 1)
						{
							empty++;
						}
					}

					if (empty >= 2) target.push_back({ i, j });
				}
			}
		}

		for (const pair<int, int>& p : target)
		{
			board[p.first][p.second] = 0;
		}

		cnt++;
	}

	return cnt;
}

int main()
{
	cin >> n >> m;

	board.assign(n, vector<int>(m, 0));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	cout << go() << "\n";

	return 0;
}