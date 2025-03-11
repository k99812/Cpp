#include<iostream>
#include<algorithm>
#include<vector>

#define MOD 1000000000

using namespace std;

int n;

int main()
{
	cin >> n;

	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(10, vector<int>(1 << 10)));

	for (int i = 1; i <= 9; i++)
	{
		dp[1][i][1 << i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int bit = 0; bit < (1 << 10); bit++)
			{
				if (!dp[i][j][bit]) continue;

				if (j > 0)
				{
					int nextBit = bit | (1 << j - 1);
					dp[i + 1][j - 1][nextBit] = (dp[i + 1][j - 1][nextBit] + dp[i][j][bit]) % MOD;
				}

				if (j < 9)
				{
					int nextBit = bit | (1 << j + 1);
					dp[i + 1][j + 1][nextBit] = (dp[i + 1][j + 1][nextBit] + dp[i][j][bit]) % MOD;
				}
			}
		}
	}

	int ret = 0;
	for (int i = 0; i <= 9; i++)
	{
		ret = (ret + dp[n][i][(1 << 10) - 1]) % MOD;
	}

	cout << ret << "\n";

	return 0;
}