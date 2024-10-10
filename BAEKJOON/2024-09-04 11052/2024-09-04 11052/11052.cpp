#include<iostream>
#include<algorithm>

#define MAX_NUM 1000 + 4
#define MAX_DP 10000 + 4

using namespace std;

int n, a[MAX_NUM], dp[MAX_DP];

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + a[j]);
		}
	}

	cout << dp[n] << "\n";

	return 0;
}