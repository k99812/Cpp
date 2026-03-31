#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> dp;

int main()
{
	cin >> n;

	dp.assign(n + 2, 0);

	for (int i = 1; i <= n; i++)
	{
		int t, p;
		cin >> t >> p;

		dp[i] = max(dp[i], dp[i - 1]);

		if (i + t <= n + 1)
		{
			dp[i + t] = max(dp[i + t], dp[i] + p);
		}
	}
	
	dp[n + 1] = max(dp[n + 1], dp[n]);

	cout << dp[n + 1] << "\n";

	return 0;
}