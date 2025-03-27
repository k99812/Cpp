#include<iostream>
#include<algorithm>
#include<vector>

#define MOD 10007
#define MAX_N 52

using namespace std;

int n;
vector<vector<int>> dp;

void combi()
{
	for (int i = 0; i <= MAX_N; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;

		for (int j = 1; j < i; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
}

int main()
{
	cin >> n;

	dp.resize(MAX_N + 1, vector<int>(MAX_N + 1));

	combi();

	int ret = 0;
	int sign = 1;

	for (int i = 1; i <= n / 4; i++)
	{
		int num = (dp[13][i] * dp[52 - 4 * i][n - 4 * i]) % MOD;
		ret = (ret + sign * num + MOD) % MOD;
		sign = -sign;
	}

	cout << ret << "\n";

	return 0;
}