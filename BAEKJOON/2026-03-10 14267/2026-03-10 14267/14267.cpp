#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> dp;

void dfs(int now)
{
	for (const int next : graph[now])
	{
		dp[next] += dp[now];
		dfs(next);
	}
}

int main()
{
	cin >> n >> m;

	graph.assign(n + 1, vector<int>());
	dp.assign(n + 1, 0);

	for (int i = 0; i < n; i++)
	{
		int to;
		cin >> to;

		if (to == -1) continue;
		graph[to].push_back(i + 1);
	}

	for (int i = 0; i < m; i++)
	{
		int idx, w;
		cin >> idx >> w;

		dp[idx] += w;
	}

	dfs(1);

	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << " ";
	}
	cout << "\n";

	return 0;
}