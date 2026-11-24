#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, t;
vector<int> arr, psum;
vector<vector<int>> dp;

int main()
{
	cin >> n;
	arr.assign(n + 1, 0);
	psum.assign(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		psum[i] += psum[i - 1] + arr[i];
	}

	cin >> t;

	dp.assign(3 + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1 * t; j <= n; j++)
		{
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - t] + (psum[j] - psum[j - t]));
		}
	}

	cout << dp[3][n] << "\n";

	return 0;
}