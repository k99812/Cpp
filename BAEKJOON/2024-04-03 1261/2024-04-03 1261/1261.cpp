#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

#define MAX_NUM 100 + 4
#define STAND_NUM 1000
#define INF 1e8

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, a[MAX_NUM][MAX_NUM], dist[MAX_NUM][MAX_NUM];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
string s;

void dijkstra()
{
	fill(&dist[0][0], &dist[MAX_NUM - 1][MAX_NUM], INF);

	dist[0][0] = 0;
	pq.push({ 0, 0 * STAND_NUM + 0 });

	while (pq.size())
	{
		int here_y = pq.top().second / STAND_NUM, here_x = pq.top().second % STAND_NUM;
		int here_dist = pq.top().first; 
		pq.pop();

		if (here_dist != dist[here_y][here_x]) continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = here_y + dy[i], nx = here_x + dx[i];
			int next_dist = 0;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (a[ny][nx] == 1) next_dist = 1;

			if (dist[ny][nx] > dist[here_y][here_x] + next_dist)
			{
				dist[ny][nx] = dist[here_y][here_x] + next_dist;
				pq.push({ dist[ny][nx], ny * STAND_NUM + nx });
			}
		}
	}
}

int main()
{
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j] - '0';
		}
	}

	dijkstra();

	cout << dist[n - 1][m - 1] << "\n";

	return 0;
}