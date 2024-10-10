#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
ll n, m, ret, sum;

bool check(ll mid, const vector<ll>& v)
{
	ll cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		cnt += v[i] / mid;
	}
	return cnt >= m;
}

int main()
{
	cin >> n >> m;
	vector<ll> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	ll low = 1, hi = 1e9, mid;

	while (low <= hi)
	{
		mid = (low + hi) / 2;
		if (check(mid, v))
		{
			ret = mid;
			low = mid + 1;
		}
		else hi = mid - 1;
	}

	cout << sum - m * ret << "\n";

	return 0;
}