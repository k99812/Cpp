#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
ll n, dp[34][34];

ll go(int all, int half)
{
	if (all == 0 && half == 0) return 1;
	
	ll& ret = dp[all][half];
	if (ret) return ret;

	if (half > 0) ret += go(all, half - 1);
	if (all > 0) ret += go(all - 1, half + 1);

	return ret;
}

int main()
{
	while (cin >> n)
	{
		if (n == 0) break;

		cout << go(n, 0) << "\n";
	}

	return 0;
}