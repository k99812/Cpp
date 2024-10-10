#include<iostream>
#include<algorithm>

#define MAX_NUM 1024 + 4

using namespace std;

int n, m, x, x2, y, y2, temp, dp[MAX_NUM][MAX_NUM], ret;

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> temp;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + temp;
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> y >> x >> y2 >> x2;

		ret = dp[y2][x2] - dp[y2][x - 1] - dp[y - 1][x2] + dp[y - 1][x - 1];
		cout << ret << "\n";
	}

	return 0;
}