#include<iostream>
#include<algorithm>

using namespace std;

#define MAX_NUM 1000 + 4
#define INF 1e9

int n, dp[MAX_NUM][3][3], rgb[MAX_NUM][3];

int go(int idx, int prev, int first)
{
	if (idx == n)
	{
		return 0;
	}

	int& ret = dp[idx][prev][first];
	if (ret != INF) return ret;

	for (int i = 0; i < 3; i++)
	{
		if (idx && i == prev) continue;
		if (idx == n - 1 && first == i) continue;
		if (!idx) first = i;
		ret = min(ret, go(idx + 1, i, first) + rgb[idx][i]);
	}

	return ret;
}

int main()
{
	cin >> n;

	fill(&dp[0][0][0], &dp[MAX_NUM - 1][2][3], INF);

	for (int i = 0; i < n; i++)
	{
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}

	cout << go(0, 0, 0) << "\n";

	return 0;
}