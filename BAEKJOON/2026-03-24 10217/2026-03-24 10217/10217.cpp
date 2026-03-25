#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct Edge
{
	int v, cost, dist;

	bool operator>(const Edge& other) const
	{
		return dist > other.dist;
	}
};

const int INF = 1e9;

int T, n, m, k;
vector<vector<int>> dp;

int dijkstra(const vector<vector<Edge>>& graph)
{
	dp.assign(n + 1, vector<int>(m + 1, INF));
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	pq.push({ 1, 0, 0 });
	dp[1][0] = 0;

	while (pq.size())
	{
		int now = pq.top().v, now_cost = pq.top().cost, now_dist = pq.top().dist;
		pq.pop();

		if (now_dist != dp[now][now_cost]) continue;
		if (now == n) break;

		for (const Edge& e : graph[now])
		{
			int next = e.v, next_cost = e.cost + now_cost, total_dist = e.dist + now_dist;

			if (next_cost <= m && dp[next][next_cost] > total_dist)
			{
				for (int i = next_cost; i <= m; i++)
				{
					if (dp[next][i] < total_dist) break;

					dp[next][i] = total_dist;
				}

				pq.push({ next, next_cost, dp[next][next_cost] });
			}
		}
	}

	int ret = INF;
	for (int i = 0; i <= m; i++)
	{
		ret = min(ret, dp[n][i]);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> T;

	while (T--)
	{
		cin >> n >> m >> k;

		vector<vector<Edge>> graph(n + 1);

		for (int i = 0; i < k; i++)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;

			graph[u].push_back({ v, c, d });
		}

		int ret = dijkstra(graph);
		if (ret == INF) cout << "Poor KCM\n";
		else cout << ret << "\n";
	}

	return 0;
}