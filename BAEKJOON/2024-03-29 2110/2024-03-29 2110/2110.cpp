#include<iostream>
#include<algorithm>

#define INF 1000000000 + 4
#define NUM 200000 + 4

using namespace std;

typedef long long ll;

int n, c;
ll a[NUM], ret;

bool check(ll mid)
{
	int cnt = 1, installPos = a[0];

	for (int i = 1; i < n; i++)
	{
		if (a[i] - installPos >= mid)
		{
			cnt++;
			installPos = a[i];
		}
	}

	return cnt >= c;
}

int main()
{
	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	ll low = 0, high = INF, mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (check(mid))
		{
			ret = max(ret, mid);
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << ret << "\n";

	return 0;
}