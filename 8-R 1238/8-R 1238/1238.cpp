#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int INF = 1e9;
int n, m, x, a, b, c, distCome[1004], distBack[1004], ret = -1;
vector<pair<int, int>> grap[1004], grap2[1004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int* dist, vector<pair<int,int>>* g)
{
	dist[x] = 0;
	pq.push({ 0, x });

	while (pq.size())
	{
		int here = pq.top().second, here_dist = pq.top().first;
		pq.pop();

		if (here_dist != dist[here]) continue;

		for (pair<int, int> p : g[here])
		{
			int next = p.second, next_dist = p.first;

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
	cin >> n >> m >> x;

	fill(&distCome[0], &distCome[1004], INF);
	fill(&distBack[0], &distBack[1004], INF);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;

		grap[a].push_back(make_pair(c, b));
		grap2[b].push_back(make_pair(c, a));
	}

	dijkstra(distCome, grap);
	dijkstra(distBack, grap2);

	for (int i = 1; i <= n; i++)
	{
		if (i == x) continue;
		
		ret = max(ret, distCome[i] + distBack[i]);
	}

	cout << ret << "\n";

	return 0;
}