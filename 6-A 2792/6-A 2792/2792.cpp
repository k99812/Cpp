#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

const ll INF = 1e18;
ll n, m, a[300004], ret = INF;

bool check(ll mid)
{
	ll sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += a[i] / mid;
		if (a[i] % mid) sum++;
	}
	return n >= sum;
}

int main()
{
	cin >> n >> m;

	ll low = 1, hi = 0, mid;

	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		hi = max(hi, a[i]);
	}

	while (low <= hi)
	{
		mid = (low + hi) / 2;
		if (check(mid))
		{
			ret = min(ret, mid);
			hi = mid - 1;
		}
		else low = mid + 1;
	}

	cout << ret << "\n";

	return 0;
}