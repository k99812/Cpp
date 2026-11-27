#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;

struct Node
{
	int now;
	ll cost;

	bool operator<(const Node& other) const
	{
		return cost > other.cost;
	}
};

const ll INF = 1e18;

int n, m, k;
vector<vector<Node>> graph;
vector<ll> dist;

void dijkstra(const vector<int>& targets)
{
	priority_queue<Node> pq;
	dist.assign(n + 1, INF);

	for (int t : targets)
	{
		if (dist[t] == 0) continue;
		dist[t] = 0;
		pq.push({ t, 0 });
	}

	while (pq.size())
	{
		auto [now, now_cost] = pq.top();
		pq.pop();

		if (now_cost > dist[now]) continue;

		for (const auto& [next, next_cost] : graph[now])
		{
			if (dist[next] > now_cost + next_cost)
			{
				dist[next] = now_cost + next_cost;
				pq.push({ next, dist[next] });
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	graph.assign(n + 1, vector<Node>());

	for (int i = 0; i < m; i++)
	{
		int u, v;
		ll c;
		cin >> u >> v >> c;

		graph[v].push_back({ u, c });
	}

	vector<int> targets(k);
	for (int i = 0; i < k; i++)
	{
		cin >> targets[i];
	}

	dijkstra(targets);

	int city = 0;
	ll max_dist = -1;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] > max_dist)
		{
			max_dist = dist[i];
			city = i;
		}
	}

	cout << city << "\n" << max_dist << "\n";

	return 0;
}