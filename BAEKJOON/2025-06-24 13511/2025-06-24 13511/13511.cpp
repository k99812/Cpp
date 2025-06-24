#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

int n, m, Log;
vector<int> depth;
vector<ll> dist;
vector<vector<int>> parent;
vector<vector<pair<int, int>>> tree;

void dfs(int idx, int par)
{
	for (const pair<int, int>& itr : tree[idx])
	{
		int next = itr.first, cost = itr.second;

		if (next == par) continue;

		depth[next] = depth[idx] + 1;
		parent[next][0] = idx;
		dist[next] = dist[idx] + cost;

		dfs(next, idx);
	}
}

void connect()
{
	for (int j = 1; j < Log; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

int LCA(int a, int b)
{
	if (depth[a] < depth[b])
	{
		swap(a, b);
	}

	int diff = depth[a] - depth[b];

	for (int j = Log - 1; j >= 0; j--)
	{
		if (diff >= (1 << j))
		{
			a = parent[a][j];
			diff -= (1 << j);
		}
	}

	if (a == b) return a;

	for (int j = Log - 1; j >= 0; j--)
	{
		if (parent[a][j] && parent[a][j] != parent[b][j])
		{
			a = parent[a][j];
			b = parent[b][j];
		}
	}

	return parent[a][0];
}

ll getDist(int a, int b)
{
	int lca = LCA(a, b);
	return dist[a] + dist[b] - 2 * dist[lca];
}

int getKthNode(int a, int b, int k)
{
	int lca = LCA(a, b);
	int distA = depth[a] - depth[lca];

	if (distA >= k - 1)
	{
		for (int i = Log - 1; i >= 0; i--)
		{
			if (k - 1 >= (1 << i))
			{
				a = parent[a][i];
				k -= (1 << i);
			}
		}
		return a;
	}
	else
	{
		k = depth[a] + depth[b] - 2 * depth[lca] - (k - 1);
		for (int i = Log - 1; i >= 0; i--)
		{
			if (k >= (1 << i))
			{
				b = parent[b][i];
				k -= (1 << i);
			}
		}
		return b;
	}
}

int main()
{
	cin >> n;

	Log = ceil(log2(n)) + 1;
	depth = vector<int>(n + 1);
	dist = vector<ll>(n + 1);
	parent = vector<vector<int>>(n + 1, vector<int>(Log));
	tree = vector<vector<pair<int, int>>>(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;

		tree[a].push_back({ b, cost });
		tree[b].push_back({ a, cost });
	}

	dfs(1, 0);
	connect();

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int flag, a, b;
		cin >> flag >> a >> b;

		if (flag == 1)
		{
			cout << getDist(a, b) << "\n";
		}
		else
		{
			int k;
			cin >> k;
			cout << getKthNode(a, b, k) << "\n";
		}
	}

	return 0;
}