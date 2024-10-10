#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 1000 + 4
#define INF 1e9

using namespace std;

int n, m, s, l, x, y, d, dist[MAX_NUM];
vector<pair<int, int>> grap[MAX_NUM];

void dijkstra(int start)
{
	fill(&dist[0], &dist[MAX_NUM], INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (pq.size())
	{
		int here_dist = pq.top().first, here = pq.top().second;
		pq.pop();

		if (here_dist != dist[here]) continue;

		for (pair<int, int> n : grap[here])
		{
			int next_dist = n.first, next = n.second;

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
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> d;

		grap[x].push_back({ d, y });
	}

	cin >> s >> l;

	dijkstra(s);

	cout << dist[l] << "\n";

	return 0;
}