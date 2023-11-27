#include<iostream>
#include<algorithm>

using namespace std;

int n, dp[10004], c, m1, m2;

int main()
{

	while (true)
	{
		scanf_s("%d %d.%d", &n, &m1, &m2);
		int cost = m1 * 100 + m2;
		if (cost == 0) break;

		fill(&dp[0], &dp[10004], 0);

		for (int i = 0; i < n; i++)
		{
			scanf_s("%d %d.%d", &c, &m1, &m2);
			int price = m1 * 100 + m2;
			for (int j = price; j <= cost; j++)
			{
				dp[j] = max(dp[j], dp[j - price] + c);
			}
		}
		cout << dp[cost] << "\n";
	}

	return 0;
}