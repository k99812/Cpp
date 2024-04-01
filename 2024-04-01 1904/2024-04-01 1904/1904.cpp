#include<iostream>
#include<algorithm>

#define MAX_NUM 1000000 + 4
#define MOD 15746

using namespace std;

int n, dp[MAX_NUM];

int main()
{
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
	}

	cout << dp[n] << "\n";

	return 0;
}