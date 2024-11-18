#include<iostream>
#include<algorithm>
#include<vector>

#define MAX_NUM 10000 + 4

using namespace std;

int n, dp[MAX_NUM][2], visited[MAX_NUM];

void dfs(int here, const vector<vector<int>>& grap, const vector<int>& village)
{
	visited[here] = true;

	dp[here][0] = 0, dp[here][1] = village[here];

	for (int next : grap[here])
	{
		if (visited[next]) continue;

		dfs(next, grap, village);

		dp[here][0] += max(dp[next][1], dp[next][0]);
		dp[here][1] += dp[next][0];
	}
}

int main()
{
	cin >> n;

	vector<int> village(n + 1);
	vector<vector<int>> grap(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> village[i];
	}

	for (int i = 1; i < n; i++)
	{
		int from, to;
		cin >> from >> to;

		grap[from].push_back(to);
		grap[to].push_back(from);
	}

	dfs(1, grap, village);

	cout << max(dp[1][0], dp[1][1]) << "\n";

	return 0;
}