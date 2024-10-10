#include<iostream>
#include<algorithm>

using namespace std;

int n, m, a[100004], ret, mx;

bool check(int mid)
{
	int temp = mid;
	int cnt = 1;

	for (int i = 0; i < n; i++)
	{
		if (mid - a[i] < 0)
		{
			cnt++;
			mid = temp;
		}
		mid -= a[i];
	}
	return cnt <= m;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
	}

	int low = mx, hi = 1000000004, mid;

	while (low <= hi)
	{
		mid = (low + hi) / 2;
		if (check(mid))
		{
			ret = mid;
			hi = mid - 1;
		}
		else low = mid + 1;
	}

	cout << ret << "\n";

	return 0;
}