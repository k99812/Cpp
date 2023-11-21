#include<iostream>
#include<algorithm>

using namespace std;

int n, dp[1000004];

void go(int here)
{
	if (here == 0) return;
	cout << here << " ";
	if (here % 3 == 0 && dp[here] == dp[here / 3] + 1) go(here / 3);
	else if (here % 2 == 0 && dp[here] == dp[here / 2] + 1) go(here / 2);
	else if (here -1 >= 0 && dp[here] == dp[here - 1] + 1) go(here - 1);
	return;
}

int main()
{
	cin >> n;

	fill(&dp[0], &dp[1000003], 1e9);

	dp[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!(i % 3)) dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (!(i % 2)) dp[i] = min(dp[i / 2] + 1, dp[i]);
		dp[i] = min(dp[i - 1] + 1, dp[i]);
	}
	cout << dp[n] << "\n";
	go(n);
	return 0;
}