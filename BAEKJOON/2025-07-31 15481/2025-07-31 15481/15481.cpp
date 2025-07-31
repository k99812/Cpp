#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int n, m, LOG;
vector<vector<pair<int, int>>> graph;
vector<pair<int, int>> edge;
vector<vector<int>> LCA_parent;
vector<int> depth, parent;

int getRoot(int num)
{
	if (num == parent[num]) return parent[num];
	return parent[num] = getRoot(parent[num]);
}

void unionParent(int a, int b)
{
	int rootA = getRoot(a), rootB = getRoot(b);

	if (rootA != rootB)
	{
		if (rootA < rootB)
		{
			parent[rootB] = rootA;
		}
		else
		{
			parent[rootA] = rootB;
		}
	}
}

void dfs(int now, int par)
{
	for (const pair<int, int>& itr : graph[now])
	{
		int next = itr.second;
		if (next == par) continue;

		depth[next] = depth[now] + 1;
		LCA_parent[next][0] = now;

		dfs(next, now);
	}
}

void init()
{
	for (int j = 1; j < LOG; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			LCA_parent[i][j] = LCA_parent[LCA_parent[i][j - 1]][j - 1];
		}
	}
}

int LCA(int a, int b)
{
	if (depth[a] < depth[b]) swap(a, b);

	int diff = depth[a] - depth[b];
	for (int j = LOG - 1; j >= 0; j--)
	{
		if (diff >= (1 << j))
		{
			a = LCA_parent[a][j];
			diff -= (1 << diff);
		}
	}

	if (a == b) return a;

	for (int j = LOG - 1; j >= 0; j--)
	{
		if (LCA_parent[a][j] && LCA_parent[a][j] != LCA_parent[b][j])
		{
			a = LCA_parent[a][j];
			b = LCA_parent[b][j];
		}
	}

	return LCA_parent[a][0];
}

int main()
{
	cin >> n >> m;

	LOG = ceil(log2(n)) + 1;
	graph = vector<vector<pair<int, int>>>(n + 1);
	LCA_parent = vector<vector<int>>(n + 1, vector<int>(LOG));
	edge = vector<pair<int, int>>(m);
	depth = parent = vector<int>(n + 1);

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ w, v });
		graph[v].push_back({ w, u });
		edge[i] = { u, v };
	}

	return 0;
}