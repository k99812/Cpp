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

const int INF = 1e9;
const int s = 1, t = 2;

int n, m;
vector<int> dist, dp;
vector<vector<Edge>> graph;

void dijkstra()
{
	priority_queue<Edge> pq;

	pq.push({ t, 0 });
	dist[t] = 0;

	while (pq.size())
	{
		auto [now, now_dist] = pq.top();
		pq.pop();

		if (now_dist > dist[now]) continue;

		for (const auto& [next, next_dist] : graph[now])
		{
			if (dist[next] > dist[now] + next_dist)
			{
				dist[next] = dist[now] + next_dist;
				pq.push({ next, dist[next] });
			}
		}
	}
}

int dfs(int now)
{
	if (now == t) return 1;

	int& ret = dp[now];
	if (ret != -1) return ret;

	ret = 0;

	for (const auto& [next, cost] : graph[now])
	{
		if (dist[now] <= dist[next]) continue;

		ret += dfs(next);
	}

	return ret;
}

int main()
{
	cin >> n >> m;
	graph.assign(n + 1, {});
	dist.assign(n + 1, INF);
	dp.assign(n + 1, -1);

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	dijkstra();

	cout << dfs(s) << "\n";

	return 0;
}