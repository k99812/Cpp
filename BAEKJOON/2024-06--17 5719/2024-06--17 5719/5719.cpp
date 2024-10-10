#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 500 + 4
#define INF 1e9

using namespace std;

int n, m, s, d, dist[MAX_NUM], grap[MAX_NUM][MAX_NUM];

void dijkstra(int start)
{
	fill(&dist[0], &dist[MAX_NUM], INF); 
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (pq.size())
	{
		int here = pq.top().second, here_dist = pq.top().first;
		pq.pop();

		if (here_dist != dist[here]) continue;
		
		for (int next = 0; next < n; next++)
		{
			if (grap[here][next] == -1) continue;

			int next_dist = grap[here][next];

			if (dist[next] > dist[here] + next_dist)
			{
				dist[next] = dist[here] + next_dist;
				pq.push({ dist[next], next });
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
		int next = q.front();
		q.pop();

		for (int i = n - 1; i >= 0; i--)
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

		fill(&grap[0][0], &grap[MAX_NUM - 1][MAX_NUM], -1);

		cin >> s >> d;

		for (int i = 0; i < m; i++)
		{
			int u, v, p;
			cin >> u >> v >> p;
			grap[u][v] = p;
		}

		dijkstra(s);
		eraseEdge();
		dijkstra(s);

		cout << (dist[d] == INF ? -1 : dist[d]) << "\n";
	}

	return 0;
}