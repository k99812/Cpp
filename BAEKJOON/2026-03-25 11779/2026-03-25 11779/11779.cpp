#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Edge
{
	int v, cost;

	bool operator<(const Edge& other) const
	{
		return cost > other.cost;
	}
};

const int INF = 1e9;

int n, m, start, finish;
vector<vector<Edge>> graph;

void dijkstra()
{
	vector<int> dist(n + 1, INF), parents(n + 1, 0);
	priority_queue<Edge> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (pq.size())
	{
		int now = pq.top().v, now_cost = pq.top().cost;
		pq.pop();

		if (dist[now] != now_cost) continue;

		for (const Edge& edge : graph[now])
		{
			int next = edge.v, next_cost = now_cost + edge.cost;

			if (dist[next] > next_cost)
			{
				dist[next] = next_cost;
				pq.push({ next, next_cost });
				parents[next] = now;
			}
		}
	}

	vector<int> cities;

	for (int cur = finish; cur != start; cur = parents[cur])
	{
		cities.push_back(cur);
	}
	cities.push_back(start);

	cout << dist[finish] << "\n" << cities.size() << "\n";

	reverse(cities.begin(), cities.end());

	for (int i = 0; i < cities.size(); i++)
	{
		cout << cities[i] << " ";
	}
	cout << "\n";
}

int main()
{
	cin >> n >> m;

	graph.assign(n + 1, vector<Edge>());

	for (int i = 0; i < m; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		graph[u].push_back({ v, cost });
	}

	cin >> start >> finish;

	dijkstra();

	return 0;
}