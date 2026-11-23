#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Edge
{
	int now, cost;

	bool operator<(const Edge& other) const
	{
		return cost > other.cost;
	}
};

int n, m, k;
vector<vector<pair<int, int>>> graph;
vector<priority_queue<int>> dist;

void dijkstra()
{
	priority_queue<Edge> pq;
	pq.push({ 1, 0 });
	dist[1].push(0);

	while (pq.size())
	{
		auto [now, now_cost] = pq.top();
		pq.pop();

		if ((int)dist[now].size() == k && now_cost > dist[now].top()) continue;

		for (const auto& [next, next_cost] : graph[now])
		{
			int nc = now_cost + next_cost;

			if ((int)dist[next].size() < k)
			{
				dist[next].push(nc);
				pq.push({ next, nc });
			}
			else if (dist[next].top() > nc)
			{
				dist[next].pop();
				dist[next].push(nc);
				pq.push({ next, nc });
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	graph.assign(n + 1, {});
	dist.assign(n + 1, priority_queue<int>());

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		graph[from].push_back({ to, cost });
	}

	dijkstra();

	for (int i = 1; i <= n; i++)
	{
		int ret = dist[i].size() == k ? dist[i].top() : -1;
		cout << ret << "\n";
	}

	return 0;
}