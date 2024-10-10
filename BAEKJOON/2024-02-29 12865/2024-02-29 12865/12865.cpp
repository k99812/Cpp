#include<iostream>
#include<algorithm>

using namespace std;

int n, m, w, v, dp[100004];

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> w >> v;

		for (int j = m; j >= w; j--)
		{
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}

	cout << dp[m] << "\n";

	return 0;
}