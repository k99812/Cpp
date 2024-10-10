#include<iostream>
#include<algorithm>

#define MAX_NUM 20
#define INF 1e9

using namespace std;

int n, a[MAX_NUM][MAX_NUM], dp[MAX_NUM][1 << MAX_NUM];

int go(int idx, int visited)
{
	if (idx == n)
	{
		return 0;
	}

	int& ret = dp[idx][visited];
	if (ret != INF) return ret;

	for (int i = 0; i < n; i++)
	{
		if (visited & (1 << i)) continue;
		ret = min(ret, go(idx + 1, visited | (1 << i)) + a[idx][i]);
	}

	return ret;
}

int main()
{
	cin >> n;

	fill(&dp[0][0], &dp[MAX_NUM - 1][1 << 20], INF);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	cout << go(0, 0) << "\n";

	return 0;
}