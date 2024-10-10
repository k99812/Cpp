#include<iostream>
#include<algorithm>

using namespace std;

#define max_n 60000000004
typedef long long ll;
ll n, m, a[10004], ret, temp;

bool check(ll mid)
{
	temp = m;
	for (ll i = 0; i < m; i++) temp += mid / a[i];
	return temp >= n;
}

int main()
{
	cin >> n >> m;

	for (ll i = 0; i < m; i++) cin >> a[i];

	ll low = 1, hi = max_n, mid;

	if (n <= m)
	{
		cout << n;
		return 0;
	}

	while (low <= hi)
	{
		mid = (low + hi) / 2;
		if (check(mid))
		{
			ret = mid;
			hi = mid - 1;
		}
		else low = mid + 1;
	}

	temp = m;
	for (ll i = 0; i < m; i++) temp += ((ret - 1) / a[i]);

	for (ll i = 0; i < m; i++)
	{
		if (ret % a[i] == 0) temp++;
		if (temp == n)
		{
			cout << i + 1 << "\n";
			return 0;
		}
	} 

	return 0;
}