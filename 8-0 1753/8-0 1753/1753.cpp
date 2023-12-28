#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int INF = 1e9;
int V, E, K, u, v, w, dist[20004];
vector<pair<int, int>> grap[20004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	cin >> V >> E >> K;
	fill(&dist[0], &dist[20004], INF);

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		grap[u].push_back({ w, v });
	}

	pq.push({ 0, K });
	dist[K] = 0;

	while (pq.size())
	{
		int here = pq.top().second, here_dist = pq.top().first;
		pq.pop();

		if (dist[here] != here_dist) continue;

		for (pair<int, int> there : grap[here])
		{
			int n_dist = there.first, n_there = there.second;

			if (dist[n_there] > dist[here] + n_dist)
			{
				dist[n_there] = dist[here] + n_dist;
				pq.push({ dist[n_there], n_there });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}