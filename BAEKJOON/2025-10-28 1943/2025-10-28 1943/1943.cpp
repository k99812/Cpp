#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;

int main()
{
	int t = 3;

	while (t--)
	{
		cin >> n;

		int sum = 0, max_price = 0;
		vector<pair<int, int>> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].first >> arr[i].second;
			sum += arr[i].first * arr[i].second;
			max_price = max(max_price, arr[i].first);
		}

		int half = sum / 2;
		
		if (sum % 2 != 0)
		{
			cout << 0 << "\n";
			continue;
		}

		vector<int> dp(half + 1, -1);
		dp[0] = 0;

		for (const pair<int, int>& p : arr)
		{
			int value = p.first, cnt = p.second;

			for (int price = 0; price <= half; price++)
			{
				if (dp[price] >= 0)
				{
					dp[price] = 0;
				}
				else if (price >= value && dp[price - value] >= 0 && dp[price - value] < cnt)
				{
					dp[price] = dp[price - value] + 1;
				}
				else
				{
					dp[price] = -1;
				}
			}
		}

		cout << (dp[half] >= 0 ? 1 : 0) << "\n";
	}

	return 0;
}