#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n, p;
ll point;
vector<ll> v;

int main()
{
	cin >> n >> point >> p;

	v = vector<ll>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	if (n == 0)
	{
		cout << 1 << "\n";
		return 0;
	}

	if (n == p && v.back() >= point)
	{
		cout << -1 << "\n";
		return 0;
	}

	int rank = lower_bound(v.begin(), v.end(), point, greater<ll>()) - v.begin() + 1;

	cout << rank << "\n";

	return 0;
}