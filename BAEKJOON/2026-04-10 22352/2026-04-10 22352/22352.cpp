#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m;
vector<vector<int>> before, after;

bool bfs()
{
	if (before == after) return true;

	queue<pair<int, int>> q;
	
	int bf = -1, af = -1;
	for (int i = 0; i < n; i++)
	{
		bool find = false;
		for (int j = 0; j < m; j++)
		{
			if (before[i][j] != after[i][j])
			{
				bf = before[i][j], af = after[i][j];

				q.push({ i, j });
				before[i][j] = af;

				find = true;
				break;
			}
		}

		if (find) break;
	}

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (before[ny][nx] != bf) continue;

			q.push({ ny, nx });
			before[ny][nx] = af;
		}
	}

	return before == after;
}

int main()
{
	cin >> n >> m;

	before.assign(n, vector<int>(m));
	after.assign(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> before[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> after[i][j];
		}
	}

	cout << (bfs() ? "YES\n" : "NO\n");

	return 0;
}