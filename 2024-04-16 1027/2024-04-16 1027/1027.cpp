#include<iostream>
#include<algorithm>

#define INF 1000000004

using namespace std;

int n, a[54], cnt[54], ret;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		double pre = -INF;
		for (int j = i + 1; j < n; j++)
		{
			double now = 1.0 * (a[j] - a[i]) / (j - i);

			if (now <= pre) continue;

			pre = now;
			cnt[i]++, cnt[j]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		ret = max(ret, cnt[i]);
	}

	cout << ret << "\n";

	return 0;
}