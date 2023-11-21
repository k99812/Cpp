#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

ll n, m, a[300004], ret = 1e18;

bool check(int mid)
{
	int num = 0;
	for (int i = 0; i < m; i++)
	{
		num += a[i] / mid;
		if (a[i] % mid) num++;
	}
	return n >= num;
}

int main()
{
	cin >> n >> m;

	ll low = 1, hi = 0, mid;

	for (int i = 0; i < m; i++) cin >> a[i], hi = max(hi, a[i]);

	while (low <= hi)
	{
		mid = (low + hi) / 2;
		if (check(mid))
		{
			ret = min(ret, mid);
			hi = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << ret << "\n";

	return 0;
}