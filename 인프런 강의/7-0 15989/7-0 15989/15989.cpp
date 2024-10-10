#include<iostream>
#include<algorithm>

using namespace std;

int n, dp[10004], t;

int main()
{
	cin >> n;

	dp[0] = 1;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 10000; j++)
		{
			if (j - i >= 0) dp[j] += dp[j - i];
		}
	}

	while (n--)
	{
		cin >> t;
		cout << dp[t] << "\n";
	}

	return 0;
}