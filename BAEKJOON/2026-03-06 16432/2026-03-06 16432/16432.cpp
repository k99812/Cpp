#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<vector<int>> graph, dp;
vector<int> ate;

int dfs(int date, int prev)
{
	if (date == n)
	{
		for (const int i : ate) cout << i << "\n";
		exit(0);
	}

	int& ret = dp[date][prev];
	if (ret != -1) return ret;

	ret = 0;

	for (int now : graph[date])
	{
		if (now == prev) continue;

		ate.push_back(now);
		ret = dfs(date + 1, now);
		ate.pop_back();
	}

	return ret;
}

int main()
{
	cin >> n;

	graph.assign(n, vector<int>());
	dp.assign(n, vector<int>(10, -1));

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int a;
			cin >> a;
			graph[i].push_back(a);
		}
	}

	dfs(0, 0);

	cout << -1 << "\n";

	return 0;
}