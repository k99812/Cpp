#include<iostream>
#include<algorithm>

using namespace std;

int n, m, a[100004], sum, mx, ret;

bool check(int mid)
{
	if (mid < mx) return false;
	int temp = mid;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (mid - a[i] < 0)
		{
			cnt++;
			mid = temp;
		}
		mid -= a[i];
	}
	if (mid != temp) cnt++;
	return cnt <= m;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}

	int low = 0, hi = sum, mid;

	while (low <= hi)
	{
		mid = (low + hi) / 2;
		if (check(mid))
		{
			hi = mid - 1;
			ret = mid;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << ret << "\n";

	return 0;
}