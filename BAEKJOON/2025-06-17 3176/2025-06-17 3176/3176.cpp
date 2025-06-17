#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int n, k, LOG;
vector<int> depth;
vector<vector<int>> parent, mnEdge, mxEdge;
vector<vector<pair<int, int>>> graph;

void dfs(int idx, int par)
{
	for (const pair<int, int>& p : graph[idx])
	{
		int next = p.first, next_dist = p.second;

		if (next == par) continue;
		depth[next] = depth[idx] + 1;
		parent[next][0] = idx;
		mnEdge[next][0] = next_dist;
		mxEdge[next][0] = next_dist;
		dfs(next, idx);
	}
}

void init()
{
	for (int j = 1; j < LOG; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
			mnEdge[i][j] = min(mnEdge[i][j - 1], mnEdge[parent[i][j - 1]][j - 1]);
			mxEdge[i][j] = max(mxEdge[i][j - 1], mxEdge[parent[i][j - 1]][j - 1]);
		}
	}
}

pair<int, int> LCA(int a, int b)
{
	int minNum = INT32_MAX, maxNum = INT32_MIN;

	if (depth[a] < depth[b])
	{
		swap(a, b);
	}

	int diff = depth[a] - depth[b];

	for (int j = LOG - 1; j >= 0; j--)
	{
		if (diff >= (1 << j))
		{
			minNum = min(minNum, mnEdge[a][j]);
			maxNum = max(maxNum, mxEdge[a][j]);
			a = parent[a][j];
			diff -= (1 << j);
		}
	}

	if (a == b) return { minNum, maxNum };

	for (int j = LOG - 1; j >= 0; j--)
	{
		if (parent[a][j] && parent[a][j] != parent[b][j])
		{
			minNum = min(min(minNum, mnEdge[a][j]), mnEdge[b][j]);
			maxNum = max(max(maxNum, mxEdge[a][j]), mxEdge[b][j]);
			a = parent[a][j];
			b = parent[b][j];
		}
	}

	minNum = min(min(minNum, mnEdge[a][0]), mnEdge[b][0]);
	maxNum = max(max(maxNum, mxEdge[a][0]), mxEdge[b][0]);

	return { minNum, maxNum };
}

int main()
{
	cin >> n;

	LOG = ceil(log2(n)) + 1;
	depth = vector<int>(n + 1);
	parent = mnEdge = mxEdge = vector<vector<int>>(n + 1, vector<int>(LOG));
	graph = vector<vector<pair<int, int>>>(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, dist;
		cin >> a >> b >> dist;
		graph[a].push_back({ b, dist });
		graph[b].push_back({ a, dist });
	}

	dfs(1, 0);
	init();

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		pair<int, int> ret = LCA(a, b);
		cout << ret.first << " " << ret.second << "\n";
	}

	return 0;
}