#include<iostream>
#include<algorithm>

using namespace std;

int n, dp[304], step[304];

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> step[i]; 
	}

	dp[0] = 0;
	dp[1] = step[1];
	dp[2] = step[1] + step[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + step[i], dp[i - 3] + step[i - 1] + step[i]);
	}

	cout << dp[n] << "\n";

	return 0;
}