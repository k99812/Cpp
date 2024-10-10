#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define INF 1e9
#define MAXSIZE 100004

using namespace std;

const int dx[] = { -1, 1, 2 };
int n, k, dist[100004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start)
{
	dist[start] = 0;
	pq.push({ 0, start });

	while (pq.size())
	{
		int here = pq.top().second, here_dist = pq.top().first;
		pq.pop();

		if (here_dist != dist[here]) continue;

		for (int i = 0; i < 3; i++)
		{
			int next = dx[i] == 2 ? here * dx[i] : here + dx[i];
			int next_dist = dx[i] == 2 ? 0 : 1;

			if (next < 0 || next >= MAXSIZE) continue;

			if (dist[next] > dist[here] + next_dist)
			{
				dist[next] = dist[here] + next_dist;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main()
{
	cin >> n >> k;

	fill(&dist[0], &dist[100004], INF);

	dijkstra(n);

	cout << dist[k] << "\n";

	return 0;
}