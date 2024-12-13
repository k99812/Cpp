#include<iostream>
#include<algorithm>
#include<vector>

#define INF 1e9

using namespace std;

int n, c;

int main()
{
	cin >> c >> n;
	int num = 20 * 100;
	vector<int> dp(num, INF);

	dp[0] = 0;

	while (n--)
	{
		int cost, people;
		cin >> cost >> people;

		for (int i = people; i < num; i++)
		{
			dp[i] = min(dp[i], dp[i - people] + cost);
		}
	}

	int ret = INF;
	for (int i = c; i < num; i++)
	{
		ret = min(ret, dp[i]);
	}

	cout << ret << "\n";

	return 0;
}