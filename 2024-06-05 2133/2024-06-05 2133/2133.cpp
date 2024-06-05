#include<iostream>
#include<algorithm>

using namespace std;

int n, dp[34];

int main()
{
	cin >> n;

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		if (i % 2 != 0) dp[i] = 0;
		else
		{
			dp[i] = dp[i - 2] * dp[2];
			for (int j = i - 4; j >= 0; j -= 2)
			{
				dp[i] += dp[j] * 2;
			}
		}
	}

	cout << dp[n] << "\n";

	return 0;
}