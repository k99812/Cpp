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
		fill(&dp[0], &dp[10004], 0);

		cin >> n;
		int* coin = new int[n];
		for (int i = 0; i < n; i++) cin >> coin[i];
		cin >> m;

		dp[0] = 1;
		for (int k = 0; k < n; k++)
		{
			for (int i = coin[k]; i <= m; i++)
			{
				dp[i] += dp[i - coin[k]];
			}
		}

		delete(coin);
		cout << dp[m] << "\n";
	}

	return 0;
}