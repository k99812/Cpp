#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
pair<int, int> start;
int n, SharkSize = 2, cnt;

int bfs(vector<vector<int>>& map)
{
	vector<vector<int>> visited(n, vector<int>(n));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	queue<pair<int, int>> q;

	q.push({ start.first, start.second });
	visited[start.first][start.second] = 1;
	int dist = 0;

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		if (dist == visited[y][x]) continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx] || map[ny][nx] > SharkSize) continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });

			if (map[ny][nx] != 0 && map[ny][nx] < SharkSize)
			{
				pq.push({ ny, nx });
				dist = visited[ny][nx];
			}
		}
	}

	if (pq.empty()) return 0;

	start = pq.top();
	map[start.first][start.second] = 0;

	if (++cnt >= SharkSize)
	{
		cnt = 0;
		++SharkSize;
	}

	return visited[start.first][start.second] - 1;
}

int main()
{
	cin >> n;

	vector<vector<int>> map(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 9)
			{
				start = { i, j };
				map[i][j] = 0;
			}
		}
	}

	int ret = 0;
	while (true)
	{
		int time = bfs(map);
		ret += time;
		if (!time) break;
	}

	cout << ret << "\n";

	return 0;
}