#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

int n, LOG;
vector<int> ant, depth;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> parent;
vector<vector<ll>> dist;

void dfs(int idx, int par)
{
	for (const pair<int, int>& itr : graph[idx])
	{
		int next = itr.first, next_dist = itr.second;
		if (next == par) continue;
		depth[next] = depth[idx] + 1;
		parent[next][0] = idx;
		dist[next][0] = next_dist;
		dfs(next, idx);
	}
}

void build()
{
	for (int j = 1; j < LOG; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
			dist[i][j] = dist[i][j - 1] + dist[parent[i][j - 1]][j - 1];
		}
	}
}

int find(int node, ll energy)
{
	for (int j = LOG - 1; j >= 0; j--)
	{
		if (parent[node][j] && dist[node][j] <= energy)
		{
			energy -= dist[node][j];
			node = parent[node][j];
		}
	}
	return node;
}

int main()
{
	cin >> n;
	LOG = ceil(log2(n)) + 1;
	ant = depth = vector<int>(n + 1);
	graph = vector<vector<pair<int, int>>>(n + 1);
	parent = vector<vector<int>>(n + 1, vector<int>(LOG));
	dist = vector<vector<ll>>(n + 1, vector<ll>(LOG));

	for (int i = 1; i <= n; i++)
	{
		cin >> ant[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, dist;
		cin >> a >> b >> dist;

		graph[a].push_back({ b, dist });
		graph[b].push_back({ a, dist });
	}

	dfs(1, 0);
	build();

	for (int i = 1; i <= n; i++)
	{
		cout << find(i, ant[i]) << "\n";
	}

	return 0;
}