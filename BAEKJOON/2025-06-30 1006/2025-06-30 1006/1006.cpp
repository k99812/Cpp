#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 1e9;

int T, n, w;
vector<int> out, in;
vector<vector<int>> dp;

void solve()
{
	for (int i = 2; i <= n; i++)
	{
		int up = (out[i] + out[i - 1] <= w) ? 1 : 2;
		int down = (in[i] + in[i - 1] <= w) ? 1 : 2;
		int vert = (in[i] + out[i] <= w) ? 1 : 2;

		dp[0][i] = min(dp[1][i - 1] + up, dp[2][i - 1] + 1);
		dp[1][i] = min(dp[0][i - 1] + down, dp[2][i - 1] + 1);
		dp[2][i] = min({ dp[0][i] + 1, dp[1][i] + 1,
			dp[2][i - 1] + vert, dp[2][i - 2] + up + down });
	}
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> n >> w;

		out = vector<int>(n + 1);
		in = vector<int>(n + 1);
		dp = vector<vector<int>>(3, vector<int>(n + 1, INF));

		for (int i = 1; i <= n; i++)
		{
			cin >> out[i];
		}

		for (int i = 1; i <= n; i++)
		{
			cin >> in[i];
		}

		if (n == 1) 
		{
			cout << ((in[1] + out[1] <= w) ? 1 : 2) << "\n";
			continue;
		}

		int ret = INF;

		dp[0][1] = 1;
		dp[1][1] = 1;
		dp[2][1] = (in[1] + out[1] <= w) ? 1 : 2;
		dp[2][0] = 0;
		solve();
		ret = min(ret, dp[2][n]);

		if (out[1] + out[n] <= w)
		{
			dp[2][0] = INF; 
			dp[0][1] = 1; 
			dp[1][1] = INF; 
			dp[2][1] = 2;
			solve();
			ret = min(ret, dp[1][n]);
		}

		if (in[1] + in[n] <= w)
		{
			dp[2][0] = INF; 
			dp[0][1] = INF; 
			dp[1][1] = 1;
			dp[2][1] = 2;
			solve();
			ret = min(ret, dp[0][n]);
		}

		if (out[1] + out[n] <= w && in[1] + in[n] <= w)
		{
			dp[2][0] = INF; 
			dp[0][1] = INF;
			dp[1][1] = INF;
			dp[2][1] = 2;
			solve();
			ret = min(ret, dp[2][n - 1]);
		}

		cout << ret << "\n";
	}

	return 0;
}