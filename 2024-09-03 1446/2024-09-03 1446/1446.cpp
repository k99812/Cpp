#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 10000 + 4
#define INF 1e9

using namespace std;

int n, d, dist[MAX_NUM];
vector<pair<int, int>> grap[MAX_NUM];

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 0 });
	dist[0] = 0;

	while (pq.size())
	{
		int here = pq.top().second, here_dist = pq.top().first;
		pq.pop();
		
		if (dist[here] != here_dist) continue;
		
		for (const pair<int, int>& p : grap[here])
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
	cin >> n >> d;

	fill(&dist[0], &dist[MAX_NUM], INF);

	for (int i = 0; i < n; i++)
	{
		int start, arrive, cost;
		cin >> start >> arrive >> cost;

		grap[start].push_back({ cost, arrive });
	}

	for (int i = 0; i < d; i++)
	{
		grap[i].push_back({ 1, i + 1 });
	}

	dijkstra();

	cout << dist[d] << "\n";

	return 0;
}