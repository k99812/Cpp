#include<iostream>
#include<algorithm>

using namespace std;

int d, p, l, c, dp[100004];

int main()
{
	cin >> d >> p;

	for (int i = 0; i < p; i++)
	{
		cin >> l >> c;

		dp[0] = c;
		for (int j = d; j >= l; j--)
		{
			dp[j] = max(dp[j], min(dp[j - l], c));
		}
	}

	cout << dp[d] << "\n";

	return 0;
}