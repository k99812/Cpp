#include<iostream>
#include<algorithm>

using namespace std;

int n, s, m, temp, vol[54], dp[54][1004];

int main()
{
	cin >> n >> s >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> vol[i];
	}

	dp[0][s] = 1;

	for (int i = 1; i <= n  ; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (dp[i - 1][j])
			{
				temp = j + vol[i];
				if (temp <= m) dp[i][temp] = 1;

				temp = j - vol[i];
				if (temp >= 0) dp[i][temp] = 1;
			}
		}
	}

	for (int i = m; i >= 0; i--)
	{
		if (dp[n][i])
		{
			cout << i << "\n";
			return 0;
		}
	}

	cout << -1 << "\n";

	return 0;
}