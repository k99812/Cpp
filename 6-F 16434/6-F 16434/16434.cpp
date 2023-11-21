#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
ll n, atk, t[130000], a[130000], h[130000], ret;

bool check(ll mid)
{
	ll MaxHp = mid;
	ll NowAtk = atk;
	for (int i = 0; i < n; i++)
	{
		if (t[i] == 1)
		{
			ll cnt = h[i] / NowAtk + (h[i] % NowAtk ? 1 : 0);
			mid -= (cnt - 1) * a[i];
		}
		else
		{
			NowAtk += a[i];
			mid = min(mid + h[i], MaxHp);
		}
		if (mid <= 0) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> atk;

	for (int i = 0; i < n; i++)
	{
		cin >> t[i] >> a[i] >> h[i];
	}

	ll lo = 1, hi = 1e18 + 4, mid;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (check(mid))
		{
			ret = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	
	cout << ret << "\n";

	return 0;
}