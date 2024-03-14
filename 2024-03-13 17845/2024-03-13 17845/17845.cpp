#include<iostream>
#include<algorithm>

using namespace std;

int n, k, v, t, dp[10004];

int main()
{
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> v >> t;

		for (int j = n; j >= t; j--)
		{
			dp[j] = max(dp[j], dp[j - t] + v);
		}
	}

	cout << dp[n] << "\n";

	return 0;
}