#include<iostream>
#include<algorithm>

#define MAX_NUM 500 + 4
#define INF 1e9

using namespace std;

int T, k, a[MAX_NUM], sum[MAX_NUM], dp[MAX_NUM][MAX_NUM];

int go(int y, int x)
{
	if (y == x) return 0;

	cout << "y : " << y << " x : " << x << "\n";

	int& ret = dp[y][x];
	if (ret != INF) return ret;

	for (int i = y; i < x; i++)
	{
		ret = min(ret, go(y, i) + go(i + 1, x) + sum[x] - sum[y - 1]);
	}

	return ret;
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> k;

		fill(&a[0], &a[MAX_NUM], 0);
		fill(&sum[0], &sum[MAX_NUM], 0);
		fill(&dp[0][0], &dp[MAX_NUM - 1][MAX_NUM], INF);

		for (int i = 1; i <= k; i++)
		{
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
		}

		cout << go(1, k) << "\n";
	}

	return 0;
}	