#include<iostream>
#include<algorithm>

using namespace std;

struct status
{
	int time;
	int pay;
};
int n, k, dp[104][100004];
status Walk[104], Cycle[104];

int go(int idx, int time)
{
	if (time > k) return -1e9;
	if (idx == n) return 0;

	int& ret = dp[idx][time];
	if (ret) return ret;

	ret = -1e9;
	ret = max(ret, go(idx + 1, time + Walk[idx].time) + Walk[idx].pay);
	ret = max(ret, go(idx + 1, time + Cycle[idx].time) + Cycle[idx].pay);

	return ret;
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> Walk[i].time >> Walk[i].pay >> Cycle[i].time >> Cycle[i].pay;
	}

	cout << go(0, 0) << "\n";

	return 0;
}