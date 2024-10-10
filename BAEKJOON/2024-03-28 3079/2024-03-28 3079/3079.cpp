#include<iostream>
#include<algorithm>

#define MAX_NUM 100000 + 4

using namespace std;

typedef long long ll;

ll n, m, t[MAX_NUM], ret;

bool check(ll mid)
{
	ll temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp += mid / t[i];
	}
	return temp >= m;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	sort(t, t + n);

	ll low = 0, high = t[0] * m, mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (check(mid))
		{
			ret = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << ret << "\n";

	return 0;
}