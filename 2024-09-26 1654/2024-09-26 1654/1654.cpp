#include<iostream>
#include<algorithm>

#define MAX_NUM 10000 + 4

using namespace std;

typedef long long ll;
int k, n;
ll a[MAX_NUM], m, ret = -1;

bool check(ll mid)
{
	int cnt = 0;

	for (int i = 0; i < k; i++)
	{
		cnt += a[i] / mid;
	}

	return cnt >= n;
}

int main()
{
	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
		m = max(m, a[i]);
	}

	ll low = 1, hight = m;
	while (low <= hight)
	{
		ll mid = (low + hight) / 2;
		if (check(mid))
		{
			low = mid + 1;
			ret = max(ret, mid);
		}
		else
		{
			hight = mid - 1;
		}
	}

	cout << ret << "\n";

	return 0;
}