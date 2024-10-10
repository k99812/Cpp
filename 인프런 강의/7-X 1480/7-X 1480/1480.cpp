#include<iostream>
#include<algorithm>

using namespace std;

int n, m, c, a[15], dp[24][1 << 14][24];

int go(int idx, int bIsUse, int capcity)
{
	if (idx == m) return 0;

	int& ret = dp[idx][bIsUse][capcity];
	if (ret) return ret;

	ret = max(ret, go(idx + 1, bIsUse, c));
	for (int i = 0; i < n; i++)
	{
		bool use = (1 << i) & bIsUse;
		bool enough = (capcity - a[i]) >= 0;
		if (!use && enough) ret = max(ret, go(idx, bIsUse | (1 << i), capcity - a[i]) + 1);
	}

	return ret;
}

int main()
{
	cin >> n >> m >> c;

	for (int i = 0; i < n; i++) cin >> a[i];

	cout << go(0, 0, c) << "\n";

	return 0;
}