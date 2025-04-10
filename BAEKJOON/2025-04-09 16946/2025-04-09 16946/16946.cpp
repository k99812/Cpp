#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m;
vector<vector<int>> map, visited;

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;

	vector<pair<int, int>> walls;
	int cnt = 1;
	while (q.size())
	{
		int cy = q.front().first, cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx])
			{
				walls.push_back({ ny, nx });
				visited[ny][nx] = true;
				continue;
			}

			visited[ny][nx] = true;
			q.push({ ny, nx });
			cnt++;
		}
	}

	for (const pair<int, int>& wall : walls)
	{
		map[wall.first][wall.second] += cnt;
		visited[wall.first][wall.second] = false;
	}
}

int main()
{
	cin >> n >> m;

	map = visited = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] || visited[i][j]) continue;
			bfs(i, j);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << map[i][j] % 10;
		}
		cout << "\n";
	}

	return 0;
}