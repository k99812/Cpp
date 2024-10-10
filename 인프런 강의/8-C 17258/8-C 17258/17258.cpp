#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, k, t, a, b, cnt[304], dp[304][304];
vector<pair<int, int>> v;

int go(int idx, int num, int prev)
{
	if (idx == v.size()) return 0;

	int& ret = dp[idx][num];
	if (ret) return ret;

	int cost = max(0, t - v[idx].second);
	int real_cost = prev >= cost ? 0 : cost - prev;

	if (num >= real_cost)
	{
		return ret = max(go(idx + 1, num - real_cost, cost) + v[idx].first, go(idx + 1, num, 0));
	}
	else
	{
		return ret = go(idx + 1, num, 0);
	}
}

int main()
{
	cin >> n >> m >> k >> t;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		for (int j = a; j < b; j++)
		{
			cnt[j] = min(t, ++cnt[j]);
		}
	}

	int nums = cnt[1];
	int time = 1;

	for (int i = 2; i <= n; i++)
	{
		if (nums != cnt[i])
		{
			v.push_back({ time, nums });
			nums = cnt[i];
			time = 0;
		}
		time++;
	}
	v.push_back({ time, nums });

	cout << go(0, k, 0) << "\n";

	return 0;
}