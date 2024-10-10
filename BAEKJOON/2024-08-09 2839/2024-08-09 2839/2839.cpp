#include<iostream>
#include<algorithm>

#define MAX_NUM 5000 + 4 

using namespace std;

int n, dp[MAX_NUM];

int main()
{
	cin >> n;

	int cnt = 0;

	dp[3] = 1, dp[5] = 1;

	for (int i = 6; i <= n; i++)
	{
		if (dp[i - 3])
		{
			dp[i] = dp[i - 3] + 1;
		}

		if (dp[i - 5])
		{
			dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;
		}
	}

	cout << (dp[n] == 0 ? -1 : dp[n]) << "\n";

	return 0;
}