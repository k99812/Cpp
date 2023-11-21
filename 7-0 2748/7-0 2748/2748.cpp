#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
ll n, a[94];

ll go(ll idx)
{
	if (idx == 0 || idx == 1) return idx;

	ll& ret = a[idx];
	if (ret) return ret;

	return ret = go(idx - 1) + go(idx - 2);
}

int main()
{
	cin >> n;

	cout << go(n) << "\n";

	return 0;
}