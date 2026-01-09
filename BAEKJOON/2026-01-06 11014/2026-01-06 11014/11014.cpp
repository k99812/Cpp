#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const int dy[] = { -1, 0, 1, -1, 0, 1 };
const int dx[] = { -1, -1, -1, 1, 1, 1 };

int c, n, m;
vector<vector<int>> board, adj;
vector<int> match, visited;

bool dfs(int now)
{
	for (int next : adj[now])
	{
		if (visited[next]) continue;
		visited[next] = true;

		if (match[next] == -1 || dfs(match[next]))
		{
			match[next] = now;
			return true;
		}
	}

	return false;
}

int main()
{
	cin >> c;

	while (c--)
	{
		cin >> n >> m;

		int size = n * m;
		board = vector<vector<int>>(n, vector<int>(m));
		adj = vector<vector<int>>(size, vector<int>());
		match = vector<int>(size, -1);

		int total = 0;

		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < m; j++)
			{
				board[i][j] = (str[j] == '.' ? 0 : 1);
				if(str[j] == '.') total++;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j += 2)
			{
				if (board[i][j] == 1) continue;

				int now = i * m + j;

				for (int d = 0; d < 6; d++)
				{
					int ny = i + dy[d], nx = j + dx[d];

					if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
					if (board[ny][nx] == 1) continue;

					int next = ny * m + nx;
					adj[now].push_back(next);
				}
			}
		}

		int max_matching = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j += 2)
			{
				if (board[i][j] == 1) continue;

				visited = vector<int>(size, false);

				int now = i * m + j;
				if (dfs(now))
				{
					max_matching++;
				}
			}
		}

		cout << total - max_matching << "\n";
	}

	return 0;
}