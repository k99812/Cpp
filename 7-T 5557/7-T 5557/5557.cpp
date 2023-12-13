#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
ll n, a[104], dp[104][24];

ll go(int idx, ll num)
{
	if (num < 0 || num > 20) return 0;
	if (idx == n - 2)
	{
		if (num == a[n - 1]) return 1;
		return 0;
	}

	ll& ret = dp[idx][num];
	if (ret) return ret;

	ret += go(idx + 1, num + a[idx + 1]);
	ret += go(idx + 1, num - a[idx + 1]);

	return ret;
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << go(0, a[0]) << "\n";

	return 0;
}