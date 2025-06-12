#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int n, m, LOG;
vector<int> depth;
vector<vector<int>> graph, parent;

void dfs(int idx, int par)
{
	for (const int& next : graph[idx])
	{
		if (next == par) continue;
		depth[next] = depth[idx] + 1;
		parent[next][0] = idx;
		dfs(next, idx);
	}
}

void connect()
{
	for (int j = 1; j < LOG; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

int LCA(int a, int b)
{
	if (depth[a] < depth[b]) swap(a, b);

	int diff = depth[a] - depth[b];

	for (int i = LOG - 1; i >= 0; i--)
	{
		if (diff >= (1 << i))
		{
			a = parent[a][i];
			diff -= (1 << i);
		}
	}

	if (a == b) return a;

	for (int i = LOG - 1; i >= 0; i--)
	{
		if (parent[a][i] != 0 && parent[a][i] != parent[b][i])
		{
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	return parent[a][0];
}

int main()
{
	cin >> n;
	LOG = ceil(log2(n)) + 1;
	depth = vector<int>(n + 1);
	graph = vector<vector<int>>(n + 1);
	parent = vector<vector<int>>(n + 1, vector<int>(LOG));

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	parent[1][0] = 1;
	dfs(1, 1);
	connect();

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << LCA(a, b) << "\n";
	}

	return 0;
}