#include<iostream>
#include<algorithm>

#define MAX_NUM 10 + 4
#define INF 1e9

using namespace std;

int n, a[MAX_NUM][MAX_NUM], dp[MAX_NUM][1 << MAX_NUM];

int go(int here, int visited)
{
	if (visited == (1 << n) - 1)
	{
		return a[here][0] ? a[here][0] : INF;
	}

	int& ret = dp[here][visited];
	if (ret != INF) return ret;

	for (int i = 0; i < n; i++)
	{
		if (visited & (1 << i)) continue;
		if (!a[here][i]) continue;
		ret = min(ret, go(i, visited | (1 << i)) + a[here][i]);
	}

	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	fill(&dp[0][0], &dp[MAX_NUM - 1][1 << MAX_NUM], INF);
	cout << go(0, 1) << '\n';

	return 0;
}