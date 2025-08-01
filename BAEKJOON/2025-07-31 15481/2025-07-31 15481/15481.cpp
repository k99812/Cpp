#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

struct Edge
{
	int w, u, v, idx;

	bool operator<(const Edge& other) const
	{
		return w < other.w;
	}
};

int n, m, LOG;
vector<vector<pair<int, int>>> mst_graph;
vector<vector<int>> LCA_parent, maxEdge;
vector<int> depth, parent;
vector<long long> answers;
vector<Edge> edges;

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
		if (rootB < rootA) swap(rootA, rootB);
		parent[rootB] = rootA;
	}
}

bool isSameRoot(int a, int b)
{
	int rootA = getRoot(a), rootB = getRoot(b);
	return rootA == rootB;
}

void dfs(int now, int par)
{
	for (const pair<int, int>& itr : mst_graph[now])
	{
		int next = itr.first, next_dist = itr.second;
		if (next == par) continue;

		depth[next] = depth[now] + 1;
		LCA_parent[next][0] = now;
		maxEdge[next][0] = next_dist;

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
			maxEdge[i][j] = max(maxEdge[i][j - 1], maxEdge[LCA_parent[i][j - 1]][j - 1]);
		}
	}
}

int LCA(int a, int b)
{
	int maxNum = 0;

	if (depth[a] < depth[b]) swap(a, b);

	int diff = depth[a] - depth[b];
	for (int j = LOG - 1; j >= 0; j--)
	{
		if (diff >= (1 << j))
		{
			maxNum = max(maxNum, maxEdge[a][j]);
			a = LCA_parent[a][j];
			diff -= (1 << j);
		}
	}

	if (a == b) return maxNum;

	for (int j = LOG - 1; j >= 0; j--)
	{
		if (LCA_parent[a][j] && LCA_parent[a][j] != LCA_parent[b][j])
		{
			maxNum = max({ maxNum, maxEdge[a][j], maxEdge[b][j] });
			a = LCA_parent[a][j];
			b = LCA_parent[b][j];
		}
	}

	maxNum = max({ maxNum, maxEdge[a][0], maxEdge[b][0] });

	return maxNum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	LOG = ceil(log2(n)) + 1;
	mst_graph = vector<vector<pair<int, int>>>(n + 1);
	LCA_parent = maxEdge = vector<vector<int>>(n + 1, vector<int>(LOG));
	edges = vector<Edge>(m);
	answers = vector<long long>(m);
	depth = parent = vector<int>(n + 1);

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = { w, u, v, i };
	}

	sort(edges.begin(), edges.end());

	for (int i = 1; i <= n; i++) parent[i] = i;

	long long mstSum = 0;
	int edgeCnt = 0;
	vector<bool> isInMst(m, false);

	for (int i = 0; i < m; i++)
	{
		const Edge& now_edge = edges[i];
		if (!isSameRoot(now_edge.u, now_edge.v))
		{
			unionParent(now_edge.u, now_edge.v);
			mstSum += now_edge.w;
			mst_graph[now_edge.u].push_back({ now_edge.v, now_edge.w });
			mst_graph[now_edge.v].push_back({ now_edge.u, now_edge.w });
			isInMst[i] = true;
			edgeCnt++;
			if (edgeCnt == n - 1) break;
		}
	}

	dfs(1, 0);
	init();

	for (int i = 0; i < m; i++)
	{
		const Edge& now_edge = edges[i];

		if (isInMst[i])
		{
			answers[now_edge.idx] = mstSum;
		}
		else
		{
			int max_path = LCA(now_edge.u, now_edge.v);
			answers[now_edge.idx] = mstSum - max_path + now_edge.w;
		}
	}

	for (int i = 0; i < m; i++) cout << answers[i] << "\n";

	return 0;
}