#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

const int INF = 1e9;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m[130][130], dist[130][130], cnt;
priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

void dijkstra()
{
	dist[0][0] = m[0][0];
	pq.push({ dist[0][0], 0, 0 });

	while (pq.size())
	{
		int y, x, here_dist;
		tie(here_dist, y, x) = pq.top();
		pq.pop();

		if (here_dist != dist[y][x]) continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];
			int next_dist = m[ny][nx];
			
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (dist[ny][nx] > dist[y][x] + next_dist)
			{
				dist[ny][nx] = dist[y][x] + next_dist;
				pq.push({ dist[ny][nx], ny, nx });
			}
		}
	}
}

int main()
{
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}

		fill(&m[0][0], &m[129][130], 0);
		fill(&dist[0][0], &dist[129][130], INF);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> m[i][j];
			}
		}

		dijkstra();

		cout << "Problem " << ++cnt << ": " << dist[n - 1][n - 1] << "\n";
	}

	return 0;
}