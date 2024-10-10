#include<iostream>
#include<algorithm>

using namespace std;

int n, a[24], b[24], dp[104];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 100; j > a[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
		}
	}

	cout << dp[100] << "\n";

	return 0;
}