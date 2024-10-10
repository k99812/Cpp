#include<iostream>
#include<algorithm>

#define MAX_NUM 10 + 2
#define INF 1e9

using namespace std;

int n, k, a[MAX_NUM][MAX_NUM], dp[MAX_NUM][1 << MAX_NUM];

int go(int idx, int visited)
{
	if (visited == (1 << n) - 1)
	{
		return 0;
	}

	int& ret = dp[idx][visited];
	if (ret != INF) return ret;

	for (int i = 0; i < n; i++)
	{
		if (visited & (1 << i)) continue;

		ret = min(ret, go(i, visited | (1 << i)) + a[idx][i]);
	}

	return ret;
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	fill(&dp[0][0], &dp[MAX_NUM - 1][1 << MAX_NUM], INF);

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}

	cout << go(k, 1 << k) << "\n";

	return 0;
}