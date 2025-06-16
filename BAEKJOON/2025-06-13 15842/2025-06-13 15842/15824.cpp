#include<iostream>
#include<algorithm>
#include<vector>

#define MOD 1000000007

using namespace std;

typedef long long ll;

int n;
ll ret;
vector<ll> v, arr;

int main()
{
	cin >> n;

	v = arr = vector<ll>(n);

	for (ll& i : v)
	{
		cin >> i;
	}

	sort(v.begin(), v.end());

	arr[0] = 1;
	for (int i = 1; i < n; i++)
	{
		arr[i] = (arr[i - 1] * 2) % MOD;
	}

	for (int i = 0; i < n; i++)
	{
		ll maxNum = (v[i] * arr[i]) % MOD;
		ll minNum = (v[i] * arr[n - 1 - i]) % MOD;
		ret = (ret + maxNum - minNum + MOD) % MOD;
	}

	cout << ret << "\n";

	return 0;
}