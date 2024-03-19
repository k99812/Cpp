#include<iostream>
#include<algorithm>

#define INF 40004

using namespace std;

int n, m, a[34], b, dp[34][INF];

int go(int idx, int weight)
{
	if (idx > n)
	{
		return 0;
	}
	if (weight == 0)
	{
		return 1;
	}

	int& ret  = dp[idx][weight];
	if (ret != -1) return ret;

	ret = max(ret, go(idx + 1, weight));
	ret = max(ret, go(idx + 1, abs(weight - a[idx])));
	ret = max(ret, go(idx + 1, weight + a[idx]));

	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> b;

		fill(&dp[0][0], &dp[33][INF], -1);

		if (b > 15000)
		{
			cout << "N ";
			continue;
		}
		
		if (go(0, b))
		{
			cout << "Y ";
		}
		else
		{
			cout << "N ";
		}
	}  

	return 0;
}