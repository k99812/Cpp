#include<iostream>
#include<algorithm>

#define MAX_NUM 500 + 4
#define INF 1e9

using namespace std;

int n, dp[MAX_NUM][MAX_NUM];
pair<int, int> Matrix[MAX_NUM];

int go(int y , int x)
{
	if (y == x)
	{
		return 0;
	}

	int& ret = dp[y][x];
	if (ret != INF) return ret;

	for (int i = y; i < x; i++)
	{
		ret = min(ret, go(y, i) + go(i + 1, x) + Matrix[y].first * Matrix[i].second * Matrix[x].second);
	}

	return ret;
}

int main()
{
	cin >> n;

	fill(&dp[0][0], &dp[MAX_NUM - 1][MAX_NUM], INF);

	for (int i = 0; i < n; i++)
	{
		cin >> Matrix[i].first >> Matrix[i].second;
	}

	cout << go(0, n - 1) << "\n";

	return 0;
}