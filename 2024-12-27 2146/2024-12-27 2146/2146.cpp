#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n;

void divide(int cnt, const pair<int, int>& start, vector<vector<int>>& m, vector<vector<int>>& visited)
{
	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = 1;
	m[start.first][start.second] = cnt;

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];
			
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx] || !m[ny][nx]) continue;
			
			visited[ny][nx] = 1;
			m[ny][nx] = cnt;
			q.push({ ny, nx });
		}
	}
}

int bfs(int cnt, const vector<vector<int>>& m, vector<vector<int>>& visited)
{
	fill(visited.begin(), visited.end(), vector<int>(n, 0));
	queue<pair<int, int>> q;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (m[i][j] == cnt)
			{
				q.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx] || m[ny][nx] == cnt) continue;
			if (m[ny][nx])
			{
				return visited[y][x];
			}

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main()
{
	cin >> n;

	vector<vector<int>> m(n);
	for (vector<int>& v : m) v.resize(n);

	vector<vector<int>> visited(n);
	for (vector<int>& v : visited) v.resize(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m[i][j];
		}
	}

	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j]) continue;
			if (!m[i][j]) continue;

			divide(cnt, { i, j }, m, visited);
			++cnt;
		}
	}

	int ret = INT32_MAX;
	for (int i = 1; i < cnt; i++)
	{
		ret = min(ret, bfs(i, m, visited) - 1);
	}

	cout << ret << "\n";

	return 0;
}