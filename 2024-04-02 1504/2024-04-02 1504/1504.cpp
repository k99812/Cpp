#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define NODE 800 + 4
#define INF 98765432

using namespace std;

int n, e, dist[NODE], a, b, c, v1, v2;
vector<pair<int, int>> grap[NODE];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start)
{
	fill(&dist[0], &dist[NODE], INF);

	dist[start] = 0;
	pq.push({ 0, start });

	while (pq.size())
	{
		int here = pq.top().second, here_dist = pq.top().first;
		pq.pop();

		if (dist[here] != here_dist) continue;

		for (pair<int, int> nx : grap[here])
		{
			int next = nx.second, next_dist = nx.first;

			if (dist[next] > dist[here] + next_dist)
			{
				dist[next] = dist[here] + next_dist;
				pq.push({ dist[next], next });
			}
		}
	}
}

int go()
{
	int ret = INF;

	dijkstra(1);

	int DistToV1 = dist[v1], DistToV2 = dist[v2];

	dijkstra(v1);

	int V1ToN = dist[n], V1ToV2 = dist[v2];

	dijkstra(v2);

	int V2ToN = dist[n];

	ret = min(ret, DistToV1 + V1ToV2 + V2ToN);
	ret = min(ret, DistToV2 + V1ToV2 + V1ToN);

	return ret >= INF ? -1 : ret;
}

int main()
{
	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;

		grap[a].push_back({ c, b });
		grap[b].push_back({ c, a });
	}

	cin >> v1 >> v2;

	cout << go() << "\n";

	return 0;
}