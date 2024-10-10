#include<iostream>
#include<algorithm>

using namespace std;

int n, m, a[1004], dp[1004][2][34];

int go(int idx, int tree, int cnt)
{
	if (cnt < 0) return -1e9;
	if (idx == n) return cnt == 0; 

	int& ret = dp[idx][tree][cnt];
	if (ret != -1) return ret;

	return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == a[idx] - 1);
}

int main()
{
	cin >> n >> m;

	fill(&dp[0][0][0], &dp[1003][1][34], -1);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << max(go(0, 1, m - 1), go(0, 0, m)) << "\n";

	return 0;
}