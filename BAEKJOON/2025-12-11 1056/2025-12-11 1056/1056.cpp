#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include <climits>

using namespace std;

typedef long long ll;

ll n;
map<ll, ll> dp;

bool check(ll num, int k, ll limit)
{
	ll ret = 1;
	for (int i = 0; i < k; i++)
	{
		if (limit / num < ret) return true;
		ret *= num;
	}
	return false;
}

ll power(ll num, ll k)
{
	ll ret = 1;
	for (int i = 0; i < k; i++)
	{
		if (LLONG_MAX / num < ret) return LLONG_MAX;
		ret *= num;
	}
	return ret;
}

ll get_num(ll n, int k)
{
	ll left = 1, right = 2e9;
	ll ret = 1;

	while (left <= right)
	{
		ll mid = (left + right) / 2;

		if (check(mid, k, n))
		{
			right = mid - 1;
		}
		else
		{
			ret = mid;
			left = mid + 1;
		}
	}

	return ret;
}

ll go(ll now)
{
	if (now == 1) return 0;

	if (dp.count(now)) return dp[now];

	ll ret = now - 1;

	for (int i = 2; i <= 60; i++)
	{
		ll base = get_num(now, i);

		if (base > 1)
		{
			ll p1 = power(base, i);
			ll cost1 = go(base) + 1 + (now - p1);
			ret = min(ret, cost1);
		}

		ll next_base = base + 1;

		if (next_base >= now) continue;

		ll p2 = power(next_base, i);

		if (p2 == LLONG_MAX) continue;

		ll cost2 = go(next_base) + 1 + (p2 - now);
		ret = min(ret, cost2);
	}

	return dp[now] = ret;
}

int main()
{
	cin >> n;

	cout << go(n) << "\n";

	return 0;
}