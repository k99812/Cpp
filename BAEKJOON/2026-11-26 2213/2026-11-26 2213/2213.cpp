#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> weight, ans;
vector<vector<int>> graph, dp;

int dfs(int idx, int parent, bool picked)
{
	int& ret = dp[idx][picked];
	if (ret != -1) return ret;

	ret = picked ? weight[idx] : 0;

	for (const int next : graph[idx])
	{
		if (parent == next) continue;

		if (picked == 1)
		{
			ret += dfs(next, idx, 0);
		}
		else
		{
			ret += max(dfs(next, idx, 0), dfs(next, idx, 1));
		}
	}

	return ret;
}

void trace(int idx, int parent, bool parentPicked)
{
	bool pick = false;
	if (!parentPicked && dp[idx][1] > dp[idx][0])
	{
		pick = true;
		ans.push_back(idx);
	}

	for (const int next : graph[idx])
	{
		if (next == parent) continue;
		trace(next, idx, pick);
	}
}

int main()
{
	cin >> n;
	weight.assign(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> weight[i];
	}

	graph.assign(n + 1, vector<int>());

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dp.assign(n + 1, vector<int>(2, -1));

	int maxWeight = max(dfs(1, 0, 0), dfs(1, 0, 1));
	trace(1, 0, false);

	sort(ans.begin(), ans.end());

	cout << maxWeight << "\n";
	for (const int x : ans)
	{
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}