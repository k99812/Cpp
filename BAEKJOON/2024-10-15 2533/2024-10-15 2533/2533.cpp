#include<iostream>
#include<algorithm>
#include<vector>

#define MAX_NUM 1000000 + 4

using namespace std;

int n, vistied[MAX_NUM], dp[MAX_NUM][2];
vector<int> grap[MAX_NUM];

void dfs(int idx)
{
	dp[idx][0] = 0;
	dp[idx][1] = 1;

	for (int next : grap[idx])
	{
		if (vistied[next]) continue;
		vistied[next] = 1;
		dfs(next);
		dp[idx][0] += dp[next][1];
		dp[idx][1] += min(dp[next][1], dp[next][0]);
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int from, to;
		cin >> from >> to;

		grap[from].push_back(to);
		grap[to].push_back(from);
	}

	vistied[1] = 1;
	dfs(1);

	cout << min(dp[1][0], dp[1][1]) << "\n";

	return 0;
}