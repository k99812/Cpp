#include<iostream>
#include<algorithm>

using namespace std;

const int INF = 1e9;
int n, dp[1004][4], a[1004][4];

int go(int idx, int prev)
{
	if (idx > n)
	{
		return 0;
	}

	int& ret = dp[idx][prev];
	if (ret != INF) return ret;

	for (int i = 1; i <= 3; i++)
	{
		if (prev == i) continue;
		ret = min(ret, go(idx + 1, i) + a[idx][i]);
	}

	return ret;
}

int main()
{
	cin >> n;

	fill(&dp[0][0], &dp[1003][2], INF);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> a[i][j];
		}
	}

	cout << go(1, 0) << "\n";

	return 0;
}