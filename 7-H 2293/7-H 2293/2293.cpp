#include<iostream>
#include<algorithm>

using namespace std;

int n, k, temp, dp[10004];

int main()
{
	cin >> n >> k;

	dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		cin >> temp;

		cout << "\n";

		for (int j = temp; j <= k; j++)
		{
			dp[j] += dp[j - temp];
			cout << j <<" : " << dp[j] << "          ";
		}

		cout << "\n";
	}

	cout << dp[k] << "\n";

	return 0;
}