#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> dp;

int main()
{
	cin >> n >> m;

	dp = vector<int>(n + 1);

	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		dp[i] = dp[i - 1] + temp;
	}

	while (m--)
	{
		int from, to;
		cin >> from >> to;

		cout << dp[to] - dp[from - 1] << "\n";
	}

	return 0;
}