#include<iostream>
#include<algorithm>

using namespace std;

int n, a[24], b[24], dp[104], MaxPlesure;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	fill(&dp[0], &dp[104], -1);


	for (int i = 0; i < n; i++)
	{
		for (int j = 100; j >= 0; j--)
		{
			dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
			MaxPlesure = max(dp[j], MaxPlesure);
		}
	}

	return 0;
}