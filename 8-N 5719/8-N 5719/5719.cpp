#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int INF = 1e9;
int n, m, s, d, u, v, p, grap[504][504], dist[504];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra()
{
	fill(&dist[0], &dist[504], INF);

	dist[s] = 0;
	pq.push({ 0, s });

	while (pq.size())
	{
		int here = pq.top().second, here_dist = pq.top().first;
		pq.pop();

		if (dist[here] != here_dist) continue;

		for (int i = 0; i < n; i++)
		{
			if (grap[here][i] == -1) continue;

			int next_dist = grap[here][i];

			if (dist[i] > dist[here] + next_dist)
			{
				dist[i] = dist[here] + next_dist;
				pq.push({ dist[i], i });
			}
		}
	}
}

void eraseEdge()
{
	queue<int> q;
	q.push(d);

	while (q.size())
	{
		int next = q.front(); q.pop();

		for (int i = 0; i < n; i++)
		{
			if (dist[next] == dist[i] + grap[i][next] && grap[i][next] != -1)
			{
				grap[i][next] = -1;
				q.push(i);
			}
		}
	}
}

int main()
{
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;

		cin >> s >> d;

		fill(&grap[0][0], &grap[503][504], -1);

		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> p;
			grap[u][v] = p;
		}

		dijkstra();
		eraseEdge();
		dijkstra();

		cout << (dist[d] == INF ? -1 : dist[d]) << "\n";
	}
	
	return 0;
}