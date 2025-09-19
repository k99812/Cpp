#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 1e9;

int n, k;
vector<int> dp, coffe;

int main()
{
	cin >> n >> k;

	coffe = vector<int>(n);
	dp = vector<int>(k + 1, INF);

	for (int i = 0; i < n; i++)
	{
		cin >> coffe[i];
	}

	dp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		int c = coffe[i];
		for (int j = k; j >= c; j--)
		{
			if (dp[j - c] == INF) continue;

			dp[j] = min(dp[j], dp[j - c] + 1);
		}
	}

	cout << (dp[k] == INF ? -1 : dp[k]) << "\n";

	return 0;
}