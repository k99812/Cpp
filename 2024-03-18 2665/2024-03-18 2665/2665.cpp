#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>

#define INF 1e9

using namespace std;

const int dy[] = { -1 , 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m[54][54], dist[54][54];
string s;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(const pair<int, int>& cordinate)
{
	dist[cordinate.first][cordinate.second] = 0;
	pq.push({ 0, cordinate.first * 100 + cordinate.second });

	while (pq.size())
	{
		int here_y = pq.top().second / 1000, here_x = pq.top().second % 1000;
		int here_dist = pq.top().first;
		pq.pop();

		if (here_dist != dist[here_y][here_x]) continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = here_y + dy[i], nx = here_x + dx[i];
			int next_dist = 0;

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (m[ny][nx] == 0) next_dist = 1;

			if (dist[ny][nx] > dist[here_y][here_x] + next_dist)
			{
				dist[ny][nx] = dist[here_y][here_x] + next_dist;
				pq.push({ dist[ny][nx], ny * 1000 + nx });
			}
		}
	}
}

int main()
{
	cin >> n;

	fill(&dist[0][0], &dist[53][54], INF);

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			m[i][j] = (int)s[j] - '0';
		}
	}

	dijkstra({ 0, 0 });

	cout << dist[n - 1][n - 1] << "\n";

	return 0;
}