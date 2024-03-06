#include<iostream>
#include<algorithm>

using namespace std;

const int INF = 1e9;
int n, dp[1000004];

int go(int num)
{
	if (num == 1)
	{
		return 0;
	}

	int& ret = dp[num];
	if (ret != INF) return ret;

	if (num % 3 == 0)
	{
		ret = min(ret, go(num / 3) + 1);
	}
	if (num % 2 == 0)
	{
		ret = min(ret, go(num / 2) + 1);
	}
	ret = min(ret, go(num - 1) + 1);

	return ret;
}

int main()
{
	cin >> n;

	fill(&dp[0], &dp[1000004], INF);

	cout << go(n) << "\n";

	return 0;
}