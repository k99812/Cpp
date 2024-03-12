#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T, n, m, dp[10004];

int main()
{
	cin >> T;

	while (T--)
	{
		int a[24];
		fill(&dp[0], &dp[10004], 0);

		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		cin >> m;

		dp[0] = 1;
		for (int k = 0; k < n; k++)
		{
			for (int i = a[k]; i <= m; i++)
			{
				dp[i] += dp[i - a[k]];
			}
		}

		cout << dp[m] << "\n";
	}

	return 0;
}