#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, temp, dp[504][504], ret;
vector<vector<int>> grap(504);

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> temp;

			grap[i].push_back(temp);
		}
	}

	dp[0][0] = grap[0].front();

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + grap[i][j]);
			}
			else if (j == i)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + grap[i][j]);
			}
			else
			{
				dp[i][j] = max(dp[i][j], max(dp[i - 1][j - 1] + grap[i][j], dp[i - 1][j] + grap[i][j]));
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		ret = max(ret, dp[n - 1][i]);
	}

	cout << ret << "\n";

	return 0;
}