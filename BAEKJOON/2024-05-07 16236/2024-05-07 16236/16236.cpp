#include<iostream>
#include<algorithm>
#include<queue>

#define MAX_NUM 20 + 4

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, a[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM], cnt, SharkSize = 2, ret;
pair<int, int> start;

int bfs()
{
	fill(&visited[0][0], &visited[MAX_NUM - 1][MAX_NUM], 0);
	int dist = 0;
	queue<pair<int, int>> q;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	q.push({ start.first, start.second });
	visited[start.first][start.second] = 1;

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		if (visited[y][x] == dist) continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
			if (a[ny][nx] > SharkSize) continue;
			if (!a[ny][nx] || a[ny][nx] == SharkSize)
			{
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
			}
			else if (a[ny][nx] < SharkSize)
			{
				if (!dist) cnt++;
				visited[ny][nx] = visited[y][x] + 1;
				dist = visited[ny][nx];
				pq.push({ ny,nx });
			}
		}
	}

	if (!pq.size()) return 0;

	start = { pq.top().first, pq.top().second };
	a[start.first][start.second] = 0;

	if (cnt == SharkSize)
	{
		SharkSize++;
		cnt = 0;
	}

	return visited[start.first][start.second] - 1;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];

			if (a[i][j] == 9)
			{
				start = { i, j };
				a[i][j] = 0;
			}
		}
	}

	while (true)
	{
		int sec = bfs();
		ret += sec;
		if (!sec) break;
	}

	cout << ret << "\n";

	return 0;
}