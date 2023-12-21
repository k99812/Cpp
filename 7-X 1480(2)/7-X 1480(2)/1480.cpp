#include<iostream>
#include<algorithm>

using namespace std;

int n, m, c, a[15], dp[24][1 << 13][24];

int go(int idx, int bIsUse, int w)
{
	if (w > c) return -1e9;
	if (idx == m) return 0;

	int& ret = dp[idx][bIsUse][w];
	if (ret) return ret;

	ret = max(ret, go(idx + 1, bIsUse, 0));
	for (int i = 0; i < n; i++)
	{
		if (!(bIsUse & (1 << i)))
		{
			ret = max(ret, go(idx, bIsUse | (1 << i), w + a[i]) + 1);
		}
	}
	return ret;
}

int main()
{
	cin >> n >> m >> c;

	for (int i = 0; i < n; i++) cin >> a[i];

	cout << go(0, 0, 0) << "\n";

	return 0;
}