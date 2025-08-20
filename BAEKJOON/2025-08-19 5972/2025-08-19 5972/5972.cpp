#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int INF = INT32_MAX;

int n, m;
vector<int> dist;
vector<vector<pair<int, int>>> graph;

int dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, 1 });
	dist[1] = 0;

	while (pq.size())
	{
		int now = pq.top().second, now_dist = pq.top().first;
		pq.pop();

		if (dist[now] != now_dist) continue;

		for (const pair<int, int>& p : graph[now])
		{
			int next = p.first, next_dist = p.second;

			if (dist[next] > dist[now] + next_dist)
			{
				dist[next] = dist[now] + next_dist;
				pq.push({ dist[next], next });
			}
		}
	}

	return dist[n];
}

int main()
{
	cin >> n >> m;

	dist = vector<int>(n + 1, INF);
	graph = vector<vector<pair<int, int>>>(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;

		graph[a].push_back({ b, cost });
		graph[b].push_back({ a, cost });
	}

	cout << dijkstra() << "\n";

	return 0;
}