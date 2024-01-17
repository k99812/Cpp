#include<iostream>
#include<algorithm>

using namespace std;

int n, m, t, dp[44], cnt[44];

int go(int idx)
{
	cout << "idx : " << idx << " \n";
	if (idx >= n - 1)
	{
		cout << "return : " << idx << "\n";
		return 1;
	}
	if (cnt[idx]) return go(idx + 1);

	int& ret = dp[idx];
	if (ret != -1) return ret;

	ret = 0;
	if (!cnt[idx + 1])
	{
		ret += (go(idx + 2) + go(idx + 1));
	}
	else
	{
		ret += go(idx + 1);
	}

	return ret;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> t;
		t--; cnt[t] = 1;
	}

	fill(&dp[0], &dp[44], -1);

	cout << go(0) << "\n";

	return 0;
}