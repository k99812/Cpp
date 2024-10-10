#include<iostream>
#include<algorithm>

using namespace std;

const int INF = 1e9;
int n, k, dp[10004], temp;

int main()
{
	cin >> n >> k;

	fill(&dp[0], &dp[10003], INF);
	dp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		for (int j = temp; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - temp] + 1);
		}
	}

	(dp[k] == INF) ? cout << -1 << "\n" : cout << dp[k] << "\n";

	return 0;
}