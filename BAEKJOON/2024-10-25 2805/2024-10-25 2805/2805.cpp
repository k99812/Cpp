#include<iostream>
#include<algorithm>

#define MAX_NUM 2000000000
#define MAX_ARR 1000000

using namespace std;

typedef long long ll;
ll n, m, a[MAX_ARR], ret = -1;

bool check(ll mid)
{
	ll sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] > mid)
		{
			sum += (a[i] - mid);
		}
	}

	return sum >= m;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	ll left = 0, right = MAX_NUM;
	while (left <= right)
	{
		ll mid = (left + right) / 2;

		if (check(mid))
		{
			ret = max(ret, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ret << "\n";

	return 0;
}