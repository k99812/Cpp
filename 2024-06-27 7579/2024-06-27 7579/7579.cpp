#include<iostream>
#include<algorithm>

using namespace std;

int n, m, c[104], a[104], dp[104][10004], sum;

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];

		sum += c[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j >= c[i]) 
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + a[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= sum; i++)
	{
		if (dp[n][i] >= m)
		{
			cout << i << "\n";
			break;
		}
	}

	return 0;
}